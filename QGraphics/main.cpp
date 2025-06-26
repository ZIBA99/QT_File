#include <QApplication>
#include "Graphics.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Graphics view;
    view.show();

    return app.exec();
}
