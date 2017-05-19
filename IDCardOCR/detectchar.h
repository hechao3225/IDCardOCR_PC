#ifndef DETECTCHAR_H
#define DETECTCHAR_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include "ui_detectchar.h"
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QImage>
#include <QPixmap>
#include <QTextStream>
#include <qmessagebox.h>
#include <QProcess>
#include <QDebug>
#include <QDesktopServices>
#include <QScreen>
#include <QElapsedTimer>
#include <QTextCodec>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "ocrthread.h"

using namespace cv;
using namespace std;

#define VL_MIN(x,y) (((x)<(y))?(x):(y))
#define VL_MAX(x,y) (((x)>(y))?(x):(y))

class DetectChar : public QMainWindow
{
	Q_OBJECT

    friend class OCRThread;

public:
	DetectChar(QWidget *parent = 0);
    Mat getCVImage(){
        return image;
    }
    QImage getQImage(){
        return Qimg;
    }
    Mat getImageToOCR(){
        return imageToOCR;
    }
    bool invokeTesseract(QString fileName,QString language);
    void updateImage(QString fileName);

    static Mat image;
    static QImage Qimg;
    static Mat imageToOCR;

private:
	Ui::DetectCharClass ui;
	QString strResult;
    const char *imageToOCRName="F:/MyWork/projects/IDCardOCR/IDCardOCR_Tesseract/imageToOCR.jpg";
    const char *rectImgName="F:/MyWork/projects/IDCardOCR/IDCardOCR_Tesseract/rectImg.jpg";

    OCRThread *myOCRThread;

private slots:
	void ShowImg();
	void ProcessClicked();
    void on_testPushButton_clicked();
    void on_pushButton_clear1_clicked();

public slots:
    void updateResult(const QString &resultStr, int progressVal, int infoType);
    void updateIDCardInfo();
    void showTesseractError();
public slots:
    void onCompleteCature(QPixmap captureImage);
};

bool SortByM1( cv::Rect &v1, cv::Rect &v2);

bool SortByM2( cv::Rect &v1, cv::Rect &v2);

#endif // DETECTCHAR_H
