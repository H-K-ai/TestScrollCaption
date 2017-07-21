#include "testscrolltext.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestScrollText w;
    w.show();

    return a.exec();
}
