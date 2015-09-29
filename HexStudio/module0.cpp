#include <QApplication>
#include "gui/src/qtmainwindow.h"

int main(int argc,char **argv)
{
    QApplication app(argc,argv);

    QtMainWindow main;
    main.show();

    return app.exec();
}
