#include "Notepad.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{

    // 启用高DPI缩放
    QApplication app(argc, argv);
    // 设置字体
    Notepad window;
    window.show();
    return app.exec();
}
