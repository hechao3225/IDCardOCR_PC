#include "detectchar.h"
#include "capturescreen.h"

#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    DetectChar w;
    w.setFixedSize(w.size().width(),w.size().height());
    w.show();
	return a.exec();
}
