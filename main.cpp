#include "Notepad.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{

    // ���ø�DPI����
    QApplication app(argc, argv);
    // ��������
    Notepad window;
    window.show();
    return app.exec();
}
