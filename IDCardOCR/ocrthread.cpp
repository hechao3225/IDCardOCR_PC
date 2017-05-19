#include "ocrthread.h"

OCRThread::OCRThread()
{
    stopFlag=false;
}

//InfoType:0---其他 1.2---姓名 3.4---性别 5.6---民族 7.8---出生 9.10---住址 11.12---公民身份号码
bool OCRThread::isEligible(const Rect &candidate, int &infoType)
{
    infoType=0;//默认为其他
    //const float aspect = 4.5/0.3; //长宽比
    const int minArea = 100; //最小区域
    const int maxArea = 100000;  //最大区域

    int area = candidate.height * candidate.width;
    if( (area < minArea || area > maxArea)  )
        return false;
    else{//提取可能文字区域
        //根据文字区域根据相对位置及面积，判断身份信息类型
        //qDebug()<<"locate:"
        //        <<candidate.x<<","<<candidate.y<<","<<candidate.width<<","<<candidate.height;
        if(candidate.x<35*1.5&&candidate.x>35*0.5&&
           candidate.y<40*1.5&&candidate.y>40*0.5&&
           area<5000*1.5&&area>2500*0.5){//姓名
            infoType=1;
        }
        else if(candidate.x<115*1.5&&candidate.x>115*0.5&&
                candidate.y<40*1.5&&candidate.y>40*0.5&&
                area<4800*1.5&&area>2400*0.5){//姓名（不带Label）
            infoType=2;
        }
        else if(candidate.x<35*1.5&&candidate.x>35*0.5&&
                candidate.y<80*1.5&&candidate.y>80*0.5&&
                area<1500*1.5&&area>2400*0.5){//性别
            infoType=3;
        }
        else if(candidate.x<115*1.5&&candidate.x>115*0.5&&
                candidate.y<80*1.5&&candidate.y>80*0.5&&
                area<500*1.5&&area>500*0.5){//性别（不带Label）
            infoType=4;
        }
        else if(candidate.x<180*1.5&&candidate.x>180*0.5&&
                candidate.y<100*1.5&&candidate.y>100*0.5&&
                area<1800*1.5&&area>1800*0.5){//民族
            infoType=5;
        }
        else if(candidate.x<230*1.5&&candidate.x>230*0.5&&
                candidate.y<120*1.5&&candidate.y>120*0.5&&
                area<1200*1.5&&area>1200*0.5){//民族（不带Label）(x)
            infoType=6;
        }
        else if(candidate.x<35*1.5&&candidate.x>35*0.5&&
                candidate.y<120*1.5&&candidate.y>120*0.5&&
                area<4500*1.5&&area>4500*0.5){//出生
            infoType=7;
        }
        else if(candidate.x<115*1.5&&candidate.x>115*0.5&&
                candidate.y<145*1.5&&candidate.y>145*0.5&&
                area<4000*1.5&&area>4000*0.5){//出生（不带Label）
            infoType=8;
        }
        else if(candidate.x<35*1.5&&candidate.x>35*0.5&&
                candidate.y<160*1.5&&candidate.y>160*0.5&&
                area<25000*1.5&&area>12000*0.5){//住址
            infoType=9;
        }
        else if(candidate.x<115*1.5&&candidate.x>115*0.5&&
                candidate.y<190*1.5&&candidate.y>190*0.5&&
                area<30000*1.5&&area>14000*0.5){//住址（不带Label）
            infoType=10;
        }
        else if(candidate.x<35*1.5&&candidate.x>35*0.5&&
                candidate.y<250*1.5&&candidate.y>250*0.5&&
                area<7500*1.5&&area>7500*0.5){//公民身份号码
            infoType=11;
        }
        else if(candidate.x<215*1.5&&candidate.x>215*0.5&&
                candidate.y<250*1.5&&candidate.y>250*0.5&&
                area<8000*1.5&&area>8000*0.5){//公民身份号码（不带Label）
            infoType=12;
        }
        else{
            return false;
        }
        return true;
    }
}

int OCRThread::CalculateDalteThresholdForAllImageMat(Mat normImage,Rect rect, int deltaRange, int deltaThreshold, float deltaRatio)
{
    int hIndex = 0, wIndex = 0, Color = 0, Position = 0, threshold = 0;

    float deltaProb[256], sumPixelNum = 0, tempProbValue = 0, maxProbValue = 0;

    const int deltaValue = 256;

    memset(deltaProb, 0, deltaValue*sizeof(float));

    //基于输入图像的概率部分确定阈值
    for (hIndex = rect.y; hIndex < rect.height -1 ; hIndex++)
    {
        for (wIndex = rect.x; wIndex < rect.width -1; wIndex++)
        {
            Position = hIndex * normImage.step[0] + wIndex;

            //将当前区域小于阈值部分不考虑
            if((unsigned char)normImage.data[Position] <= deltaThreshold)
                continue;

            //Color = currImage->imageData[Position] - normImage->imageData[Position];
            Color = (unsigned char)(normImage.data[Position]);
            deltaProb[Color]++;
            sumPixelNum++;
        }
    }

    //累积直方图概率和
    for (hIndex = 0; hIndex < deltaValue; hIndex++)
        deltaProb[hIndex] = deltaProb[hIndex]/sumPixelNum;

    int Imin = 0, Imax = 0, dImin = 0, dImax = 0;

    for (hIndex = 0; hIndex < deltaValue; hIndex++)
    {
        Imin = hIndex - deltaRange >= 0 ? hIndex - deltaRange : 0;
        Imax = hIndex;

        for (wIndex = Imin, tempProbValue = 0; wIndex <= Imax; wIndex++)
            tempProbValue += deltaProb[wIndex];

        if(tempProbValue > maxProbValue )
        {
            maxProbValue = tempProbValue;
            dImax = Imax; dImin = Imin;
        }
    }

    if(maxProbValue > deltaRatio)
    {
        maxProbValue = 0;
        for (wIndex = dImin; wIndex <= dImax; wIndex++)
        {
            if(maxProbValue < deltaProb[wIndex])
            {
                maxProbValue = deltaProb[wIndex];
                threshold = wIndex;
            }
        }
        if( threshold >= 245 )
            threshold = threshold * 5/6;
        return threshold;
    }
    else
        return 0;
}

bool OCRThread::invokeTesseract(QString fileName, QString language)
{
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
        emit startTesseractError();
        return false;
    }
}

void OCRThread::OstuBeresenThreshold(const Mat &in, Mat &out) //输入为单通道
{

    double ostu_T = threshold(in , out, 0,255 ,CV_THRESH_OTSU); //otsu获得全局阈值

    double min;
    double max;
    minMaxIdx(in,&min,&max);
    const double CI = 0.12;
    double beta = CI*(max - min +1)/128;
    double beta_lowT = (1-beta)*ostu_T;
    double beta_highT = (1+beta)*ostu_T;

    Mat doubleMatIn;
    in.copyTo(doubleMatIn);
    int rows = doubleMatIn.rows;
    int cols = doubleMatIn.cols;
    double Tbn;
    for( int i = 0; i < rows; ++i)
    {
       //获取第 i行首像素指针
        uchar * p = doubleMatIn.ptr<uchar>(i);
        uchar *outPtr = out.ptr<uchar>(i);

        //对第i 行的每个像素(byte)操作
        for( int j = 0; j < cols; ++j )
        {

            if(i <2 | i>rows - 3 | j<2 | j>rows - 3)
            {

                if( p[j] <= beta_lowT )
                    outPtr[j] = 0;
                else
                    outPtr[j] = 255;
            }
            else
            {
                Tbn = sum(doubleMatIn(Rect(i-2,j-2,5,5)))[0]/25 ;  //窗口大小25*25
                if( p[j] < beta_lowT | (p[j] < Tbn &&  (beta_lowT <= p[j] && p[j] >= beta_highT)))
                    outPtr[j] = 0;
                if( p[j] > beta_highT | (p[j] >= Tbn &&  (beta_lowT <= p[j] && p[j] >= beta_highT)))
                    outPtr[j] = 255;
            }
        }
    }

}

Mat OCRThread::getRplane(const Mat &in)
{
     vector<Mat> splitBGR(in.channels()); //容器大小为通道数3
     split(in,splitBGR);
     //return splitBGR[2];  //R分量

     if(in.cols > 700 |in.cols >600)
     {
         Mat resizeR( 450,600 , CV_8UC1);
         cv::resize( splitBGR[2] ,resizeR ,resizeR.size());

         return resizeR;
     }
     else
       return splitBGR[2];

}

void OCRThread::posDetect(const Mat &in, vector<pair<Rect,int> > & rectsWithType )
{
    //Mat threshold_R;
    //OstuBeresenThreshold(in ,threshold_R ); //二值化
    //cv::imwrite(imageToOCRName,threshold_R);
    //cv::imshow("threshold",threshold_R);

    //利用阈值二值化
    Mat testRectClone = in.clone();
    cv::threshold(testRectClone, testRectClone, 120, 255, CV_THRESH_BINARY);
    //imshow("threshold",testRectClone);
    //waitKey(0);
    //输入图像
    //输出图像
    //单元大小，这里是3*3的8位单元
    //腐蚀位置，为负值取核中心
    erode(testRectClone,in,Mat(3,3,CV_8U),Point(-1,-1),2);
    //imshow("erodeMat",in);
    //waitKey(0);
    Mat imgInv(in.size(),in.type(),cv::Scalar(255));
    Mat threshold_Inv = imgInv - in; //黑白色反转，即背景为黑色
    //cv::imshow("threshold_Inv",threshold_Inv);
    //waitKey(0);
    Mat element = getStructuringElement(MORPH_RECT ,Size(18 ,13));  //闭形态学的结构元素
    morphologyEx(threshold_Inv ,threshold_Inv,CV_MOP_CLOSE,element);
    //cv::imshow("morphologyEx",threshold_Inv);
    //waitKey(0);

    vector< vector <Point> > contours;
    findContours(threshold_Inv ,contours,CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);//只检测外轮廓
    //对候选的轮廓进行进一步筛选
    vector< vector <Point> > ::iterator itc = contours.begin();

    while( itc != contours.end())
    {
        Rect mr = boundingRect(Mat( *itc )); //返回每个轮廓的最小有界矩形区域
        int infoType=0;
        if(mr.size().width==0||mr.size().height==0){
            itc = contours.erase(itc);
        }
        if(!isEligible(mr,infoType))  //判断矩形轮廓是否符合要求
        {
            itc = contours.erase(itc);
        }
        else
        {
            rectsWithType.push_back(make_pair(mr,infoType));
            ++itc;
        }
    }

}

void OCRThread::run()
{
    while(!stopFlag){
        QMutexLocker locker(&mutex);
        Mat imgRplane = getRplane(DetectChar::imageToOCR); //获得原始图像R分量
        vector<pair<Rect,int> >  rects;
        posDetect(imgRplane,rects);  //获得身份证文字区域
        int progressVal=0;
        for(pair<Rect,int> rect:rects){
             if(rect.first.x-5<0||rect.first.y-5<0)continue;
             Rect imageRect(rect.first.x-5,rect.first.y-5,rect.first.width+10,rect.first.height+10);
             Mat curImage=DetectChar::image(imageRect);
             qDebug()<<"locate:"
                     <<rect.first.x<<","<<rect.first.y<<","<<rect.first.width<<","<<rect.first.height<<","
                     <<rect.first.width*rect.first.height<<","<<rect.second;
             cvtColor(curImage, curImage, cv::COLOR_BGR2GRAY);
             //cv::threshold(curImage, curImage, 100, 255, CV_THRESH_BINARY);
             cv::imwrite(imageToOCRName,curImage);
             //cv::imshow("rects:",curImage);

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
                 progressVal+=1.0/rects.size()*100;
                 emit newOCRResult(in.readAll(),progressVal,rect.second);
                 resultFile.close();
                 //QDesktopServices::openUrl(QUrl(QString(resultFileName)));
             }
             //waitKey(0);
        }
        emit ocrDone();
        stop();//ocr done,close thread
    }

}
