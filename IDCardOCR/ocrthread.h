#ifndef OCRTHREAD_H
#define OCRTHREAD_H

#include <QThread>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QImage>
#include <QPixmap>
#include <QTextStream>
#include <QMessageBox>
#include <QProcess>
#include <QDebug>
#include <QDesktopServices>
#include <QMutexLocker>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include "detectchar.h"

using namespace cv;
using namespace std;

class OCRThread : public QThread
{
    Q_OBJECT

signals:
    void newOCRResult(const QString &str,int progressVal,int infoType);
    void ocrDone();
    void startTesseractError();

public:
    OCRThread();
    void stop(){
        stopFlag=true;
    }
    int CalculateDalteThresholdForAllImageMat(Mat normImage,Rect rect, int deltaRange, int deltaThreshold, float deltaRatio);
    bool invokeTesseract(QString fileName,QString language);
    Mat getRplane( const Mat & in );  //获得图片的R通道
    void OstuBeresenThreshold(const Mat & in, Mat & out);
    void posDetect(const Mat &in, vector<pair<Rect, int> > &rectsWithType);
    bool isEligible(const Rect & candidate, int &infoType);

protected:
    void run();

private:
    bool stopFlag;
    QMutex mutex;
    const char *imageToOCRName="F:/MyWork/projects/IDCardOCR/IDCardOCR_Tesseract/imageToOCR.jpg";
    const char *rectImgName="F:/MyWork/projects/IDCardOCR/IDCardOCR_Tesseract/rectImg.jpg";
};

#endif // OCRTHREAD_H
