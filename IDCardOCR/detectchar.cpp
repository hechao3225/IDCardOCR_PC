/*************************************************************************
* 函数功能：识别字符
* 输入参数：待识别字符的图片
* 输出参数：识别出的字符串
* 返回值  ：无
* 其他说明：无
**************************************************************************/

#include "detectchar.h"
#include "capturescreen.h"
#include "ocrthread.h"

Mat DetectChar::image;
QImage DetectChar::Qimg;
Mat DetectChar::imageToOCR;

DetectChar::DetectChar(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    ui.tableWidget->horizontalHeader()->setStyleSheet(
                "QHeaderView::section{"
                "border:2px groove gray;"
                "border-radius:10px;"
                "padding:2px 4px;"
                "border-image: url(:/img/img/back4.jpg);"
                "font: 10pt '微软雅黑'}");
}

bool SortByM1( cv::Rect &v1, cv::Rect &v2)//注意：本函数的参数的类型一定要与vector中元素的类型一致  
{  
    return v1.x < v2.x;//升序排列  
} 

bool SortByM1Width( cv::Rect &v1, cv::Rect &v2)//注意：本函数的参数的类型一定要与vector中元素的类型一致  
{  
	return v1.width > v2.width;//降序排列  
} 

bool SortByM1Height( cv::Rect &v1, cv::Rect &v2)//注意：本函数的参数的类型一定要与vector中元素的类型一致  
{  
	return v1.height > v2.height;//降序排列  
} 

bool SortByM2( cv::Rect &v1, cv::Rect &v2)//注意：本函数的参数的类型一定要与vector中元素的类型一致  
{  
    return v1.y < v2.y;//升序排列  
} 

bool DetectChar::invokeTesseract(QString fileName,QString language){
    //use tesseract to get text
    QStringList args;
    args<<fileName
        <<QString("F:/MyWork/projects/IDCardOCR/IDCardOCR_Tesseract/result")
        <<QString("-l")
        <<language;
    QString program("F:/MyWork/projects/IDCardOCR/IDCardOCR_Tesseract/Tesseract-OCR/tesseract.exe");
    QProcess *tesseract=new QProcess;
    tesseract->start(program,args);
    if(tesseract->waitForFinished()){
        return true;
    }
    else{
        QMessageBox::information(this,QString("tesseractOCR"),QString("ocr start failed"),QString("ok"));
        return false;
    }
}

void DetectChar::ShowImg()
{
    QString fileOpenName = QFileDialog::getOpenFileName(this,tr("Fila Dailog"),"",tr("Image (*.png *.bmp *jpg *tif *GIF)"));
    if(fileOpenName.isEmpty())
		return;
	else
	{
        image = cv::imread(std::string((const char*)fileOpenName.toLocal8Bit()),1);
        Qimg.load(fileOpenName);
		if(image.empty())
		{
			QMessageBox::information(this,tr("Fail to open the image"),tr("Fail to open the image!"));
			return;
		}
		int width  = ui.ShowImg->width();
		int height = ui.ShowImg->height();

		if( Qimg.height() *4/3 < Qimg.width() )
		{
			width  = ui.ShowImg->width();
			height = width * Qimg.height()/Qimg.width();
		}
		else
		{		
			height = ui.ShowImg->height();
			width  = height * Qimg.width()/Qimg.height();
		}

        Qimg = Qimg.scaled(width,height,Qt::IgnoreAspectRatio);
		//打开图片前先清空
		ui.ShowImg->clear();
		ui.ShowImg->setPixmap(QPixmap::fromImage(Qimg));
		ui.ShowImg->show();
	}
}

void DetectChar::updateImage(QString fileName)
{
    QImage img;
    img.load(fileName);

    int width  = ui.ShowImg->width();
    int height = ui.ShowImg->height();

    if( img.height() *4/3 < img.width() )
    {
        width  = ui.ShowImg->width();
        height = width * img.height()/img.width();
    }
    else
    {
        height = ui.ShowImg->height();
        width  = height * img.width()/img.height();
    }

    img = img.scaled(width,height,Qt::KeepAspectRatio);
    //打开图片前先清空
    ui.ShowImg->clear();
    ui.ShowImg->setPixmap(QPixmap::fromImage(img));
    ui.ShowImg->show();
}

void DetectChar::ProcessClicked()
{
	if (image.empty())
	{
		QMessageBox::information(this,tr("Need to open the image"),tr("Please open the image!"));
		return ;
	};	
    QMessageBox infoBox;
    int returnBtn=infoBox.information(this,QStringLiteral("提示"),
                             QStringLiteral("是否进入手工辅助识别模式？是：手工截取后OCR，否：进行整图OCR"),
                             QStringLiteral("是"),
                             QStringLiteral("否"));
    if(returnBtn==0){
        //choose rectImg
        infoBox.close();
        QElapsedTimer t;
        t.start();
        while(t.elapsed()<1000)
            QApplication::processEvents();

        CaptureScreen *captureHelper=new CaptureScreen;
        connect(captureHelper, SIGNAL(signalCompleteCature(QPixmap)), this, SLOT(onCompleteCature(QPixmap)));
        captureHelper->show();

    }
    else{
        infoBox.close();
        QElapsedTimer t;
        t.start();
        while(t.elapsed()<1000)
            QApplication::processEvents();

        imageToOCR=image;
        cv::imwrite(imageToOCRName,imageToOCR);

        ui.tableWidget->setRowCount(ui.tableWidget->rowCount()+1);//增加一行

        myOCRThread = new OCRThread;
        //tesseract error,show error message
        connect(myOCRThread,SIGNAL(startTesseractError()),this,SLOT(showTesseractError()));
        //ocr is running,update ocr progress and realtime result
        connect(myOCRThread,SIGNAL(newOCRResult(const QString &,int,int)),this,SLOT(updateResult(const QString &,int,int)));
        //ocr done,update all results to IDCard Info Table
        connect(myOCRThread,SIGNAL(ocrDone()),this,SLOT(updateIDCardInfo()));
        //thread terminated,delete thread
        connect(myOCRThread,&QThread::finished,myOCRThread,&QThread::deleteLater);
        myOCRThread->start();
    }

}

void DetectChar::on_testPushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Fila Dailog"),"",tr("Image (*.png *.bmp *jpg *tif *GIF)"));
    if(fileName.isEmpty())
        return;
    updateImage(fileName);

    if(invokeTesseract(fileName,QString("chi_sim"))){
        QString resultFileName("F:/MyWork/projects/IDCardOCR/IDCardOCR_Tesseract/result.txt");
        QDesktopServices::openUrl(QUrl(QString(resultFileName)));
    }

}

void DetectChar::on_pushButton_clear1_clicked()
{
    ui.textEdit_IDCard->clear();
}

void DetectChar::updateResult(const QString &resultStr,int progressVal,int infoType)
{
    ui.ocrProgressBar->setValue(progressVal);
    if(!resultStr.isEmpty()){
        QTableWidgetItem *item = new QTableWidgetItem(resultStr);
        int column=0;
        if(infoType%2==0){
            ui.textEdit_IDCard->append(resultStr);
            switch(infoType){
                case 2:column=0;break;
                case 4:column=1;break;
                case 6:column=2;break;
                case 8:column=3;break;
                case 10:column=4;break;
                case 12:column=5;break;
            }
            if(!item->text().isEmpty())
                ui.tableWidget->setItem(ui.tableWidget->rowCount()-1,column,item);
        }
        else{
            QString result=resultStr;
            switch(infoType){
            case 1:{
                column=0;
                result.remove(0,3);
                item->setText(result);
                ui.textEdit_IDCard->append(result);
                break;
            }
            case 3:{
                column=1;
                result.remove(0,3);
                item->setText(result);
                break;
            }
            case 5:{
                column=2;
                result.remove(0,3);
                item->setText(result);
                ui.textEdit_IDCard->append(result);
                break;
            }
            case 7:{
                column=3;
                result.remove(0,3);
                item->setText(result);
                ui.textEdit_IDCard->append(result);
                break;
            }
            case 9:{
                column=4;
                result.remove(0,3);
                item->setText(result);
                ui.textEdit_IDCard->append(result);
                break;
            }
            case 11:{
                column=5;
                result.remove(0,6);
                item->setText(result);
                ui.textEdit_IDCard->append(result);
                break;
            }
            default:break;
            }
            if(!item->text().isEmpty())
                ui.tableWidget->setItem(ui.tableWidget->rowCount()-1,column,item);
        }

    }
}

void DetectChar::updateIDCardInfo()
{
    //display whole info in a ui table
    //...
    ui.ocrProgressBar->setValue(100);
    QMessageBox::information(this,QStringLiteral("OCR Info"),QStringLiteral("ocr done"),QString("ok"));
}

void DetectChar::showTesseractError()
{
    QMessageBox::information(this,QString("tesseractOCR"),QStringLiteral("识别程序启动失败"),QString("ok"));
}

void DetectChar::onCompleteCature(QPixmap captureImage)
{
    captureImage.save(QString(rectImgName),"jpg");
    image = cv::imread(std::string(rectImgName),1);
    imageToOCR=image;
    cv::imwrite(imageToOCRName,imageToOCR);

    updateImage(imageToOCRName);
/*
 * 颜色提取算法
 * 搜索字符所在的区域，利用红色分量和蓝色分量图
    vector<Mat> sbgr(image.channels());
    split(image, sbgr);
    int rectX = 0, rectY = 0 , rectWidth = 0, rectHeight = 0;
    if( sbgr[2].rows/10 < 80 )
    {
        rectX = 0;
        rectY = sbgr[2].rows - 80;
        rectWidth = sbgr[2].cols/2;
        rectHeight = 80;
    }
    else if(sbgr[2].cols/2 < 430 )
    {
        rectX = 0;
        rectY = sbgr[2].rows*9/10;
        rectWidth = 430;
        rectHeight = sbgr[2].rows/10;
    }
    else
    {
        rectX = 0;
        rectY = sbgr[2].rows*9/10;
        rectWidth = sbgr[2].cols/2;
        rectHeight = sbgr[2].rows/10;
    }
    Rect rect(rectX, rectY, rectWidth, rectHeight);
    //Rect rect(0, sbgr[2].rows*9/10, sbgr[2].cols/2, sbgr[2].rows/10);
    Mat redDigtersZone	= sbgr[2](rect);
    Mat blueDigtersZone	= sbgr[0](rect);
    Mat greenDigtersZone= sbgr[1](rect);
    imshow("MaskRedRect",redDigtersZone);
    imshow("MaskBlueRect",blueDigtersZone);
    imshow("MaskgreenRect",greenDigtersZone);
    waitKey(0);

    int ImagePosition = 0;
    for( int nrow = 0; nrow < blueDigtersZone.rows; nrow++)
    {
        for(int ncol = 0; ncol < blueDigtersZone.cols; ncol++)
        {
            ImagePosition = nrow * redDigtersZone.step[0] + ncol;
            if ( uchar(blueDigtersZone.data[ImagePosition]) >= 190  &&
                 uchar(redDigtersZone.data[ImagePosition]) <= 40 &&
                 uchar(greenDigtersZone.data[ImagePosition]) <= 40)
                blueDigtersZone.at<uchar>(nrow,ncol) = 255;
            else
                blueDigtersZone.at<uchar>(nrow,ncol) = 0;
        }
    }
    imshow("MaskBlue",blueDigtersZone);
    //write to t2.jpg
    const char *fileName="F:/MyWork/projects/IDCardOCR/IDCardOCR_Tesseract/t2.jpg";
    cv::imwrite(fileName,blueDigtersZone);
*/
    //invoke tesseract to get text
    QString language("chi_sim");
    if(invokeTesseract(imageToOCRName,language)){
        QString resultFileName("F:/MyWork/projects/IDCardOCR/IDCardOCR_Tesseract/result.txt");
        QFile resultFile(resultFileName);
        if(!resultFile.open(QFile::ReadOnly|QFile::Text)){
            qDebug()<<"cannot open the result file!"<<endl;
        }
        QTextStream in(&resultFile);
        in.setCodec(QTextCodec::codecForName("UTF-8"));
        while(!in.atEnd())
            ui.textEdit_IDCard->append(in.readLine());
        in.flush();
        resultFile.close();
        QDesktopServices::openUrl(QUrl(QString(resultFileName)));
    }
}
