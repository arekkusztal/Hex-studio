#include "qtmainwindow.h"

#include <QLabel>
#include <QSplitter>
#include <QTextEdit>
#include <QTabWidget>
#include "bus/inc/configurations.h"
#include "bus/inc/globally.h"
#include "bus/src/file.h"


MenuPanel *menuPanel;
QMenuPanel2 *menuPanel2;


QRaw *rawscreen;

void GlobalRepaint(int widget)
{
 /*   if (widget == 0)
    {
        ASCIITable->repaint();
        addrVertical->repaint();
    }
    else if (widget == 1)
    {
        tab->repaint();
        addrVertical->repaint();
    }
    else if (widget == 67)
    {
        tab->repaint();
        addrVertical->repaint();
        ASCIITable->repaint();
    } */
    //else if (widget == 2)


}

///TEST
///
extern int readfile(const char *filename);

void showMessage(const char *message)
{
    QMessageBox messageBox;
    messageBox.critical(0,"Error",message);
    messageBox.setFixedSize(500,200);
}


void QtMainWindow::wheelEvent(QWheelEvent *event)
{
    if (event->delta()>0)
    {
        shift -= 32;
        if (shift < 0)
        {
            shift = 0;
            goto END;
        }
    }
    else if (shift < *flen_p)
    {
        shift += 32;
    }
    GlobalRepaint(67);

END:
    return;
}

QtMainWindow::QtMainWindow(QWidget *parent) :
    QWidget(parent)
{

    ///TEST
    readfile("/home/arek67/RD/a.o");
    flen_p      = &((File*)filenames[0])->flen;
    hexSource_p =  ((File*)filenames[0])->fcontent;
    /////////////////////////////////////////

    QVBoxLayout *vlayout = new QVBoxLayout;
    this->resize(1540,800);



    menuPanel = new MenuPanel;
    menuPanel->setFixedHeight(30);

    menuPanel2 = new QMenuPanel2;
    menuPanel2->setFixedHeight(30);


    vlayout->addWidget(menuPanel);
    vlayout->addWidget(menuPanel2);


    setLayout(vlayout);


    QTabWidget *files = new QTabWidget;



    QTabWidget *raw = new QTabWidget;
    rawscreen = new QRaw;

    raw->addTab(rawscreen,tr("Raw view"));
    QWidget *wid = new QWidget;
    raw->addTab(wid,tr("fdump"));
    raw->setStyleSheet("QTabBar::tab { width: 100px; height: 20px; }");


    files->setStyleSheet("QTabBar::tab { width: 100px; height: 20px; }");
    files->addTab(raw,"file.o");
    vlayout->addWidget(files);   

}


void addFile()
{

}
