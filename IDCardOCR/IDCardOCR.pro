

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IDCardOCR
TEMPLATE = app


SOURCES += \
    detectchar.cpp \
    main.cpp \
    capturescreen.cpp \
    ocrthread.cpp

HEADERS  += \
    detectchar.h \
    capturescreen.h \
    ocrthread.h

FORMS    += \
    detectchar.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    ocr_res.qrc



#-----------openCV lib配置---------------
INCLUDEPATH += F:/MyWork/openCV/openCVlib/include \
               F:/MyWork/openCV/openCVlib/include/opencv \
               F:/MyWork/openCV/openCVlib/include/opencv2

win32:CONFIG(debug, debug | release):{
LIBS +=  -LF:/MyWork/openCV/openCVlib/x64/vc14/lib \
-lopencv_core2413d \
-lopencv_imgproc2413d \
-lopencv_highgui2413d \
-lopencv_ml2413d \
-lopencv_video2413d \
-lopencv_features2d2413d \
-lopencv_calib3d2413d \
-lopencv_objdetect2413d \
-lopencv_contrib2413d \
-lopencv_legacy2413d \
-lopencv_flann2413d \
-lopencv_ml2413d   \
-lopencv_calib3d2413d  \
-lopencv_gpu2413d  \
-lopencv_ts2413d   \
-lopencv_nonfree2413d  \
-lopencv_ocl2413d  \
-lopencv_photo2413d    \
-lopencv_stitching2413d    \
-lopencv_superres2413d     \
-lopencv_superres2413d

} else : win32:CONFIG(release, debug | release):{
LIBS +=  -LF:/MyWork/openCV/openCVlib/x64/vc14/lib \
-lopencv_core2413 \
-lopencv_imgproc2413 \
-lopencv_highgui2413 \
-lopencv_ml2413 \
-lopencv_video2413 \
-lopencv_features2d2413 \
-lopencv_calib3d2413 \
-lopencv_objdetect2413 \
-lopencv_contrib2413 \
-lopencv_legacy2413 \
-lopencv_flann2413  \
-lopencv_ml2413   \
-lopencv_calib3d2413  \
-lopencv_gpu2413  \
-lopencv_ts2413   \
-lopencv_nonfree2413  \
-lopencv_ocl2413  \
-lopencv_photo2413    \
-lopencv_stitching2413    \
-lopencv_superres2413     \
-lopencv_superres2413
}
