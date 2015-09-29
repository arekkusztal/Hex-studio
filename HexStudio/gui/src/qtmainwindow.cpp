#include "qtmainwindow.h"

#include <QLabel>
#include <QSplitter>
#include <QTextEdit>
#include "bus/inc/configurations.h"
#include "bus/inc/globally.h"


QHexTable *tab;
QASCIITable *ASCIITable;
QAddrVertical *addrVertical;
MenuPanel *menuPanel;
void GlobalRepaint(int widget)
{
    if (widget == 0)
    {
        ASCIITable->repaint();
        addrVertical->repaint();
    }
    else if (widget == 1)
    {
        tab->repaint();
        addrVertical->repaint();
    }
    //else if (widget == 2)


}

QtMainWindow::QtMainWindow(QWidget *parent) :
    QWidget(parent)
{

    QVBoxLayout *vlayout = new QVBoxLayout;
  //  this->setMinimumSize(1424,768);
    this->resize(1540,800);

    tab = new QHexTable;
    ASCIITable = new QASCIITable;



    QSplitter *splitter = new QSplitter(Qt::Horizontal);
  //  splitter->addWidget(tab);
    QTextEdit *editor1 = new QTextEdit;
    editor1->setStyleSheet("QTextEdit { padding-left:10; padding-top:10; padding-bottom:10; padding-right:10}");

    QAddrHorizontal *addrHorizontal = new QAddrHorizontal;
    addrHorizontal->setFixedHeight(16);

    QAddrHorizontal2 *addrHorizontal2 = new QAddrHorizontal2;
    addrHorizontal2->setFixedHeight(16);

    menuPanel = new MenuPanel;
    menuPanel->setFixedHeight(30);

    QVBoxLayout *hLayoutTab = new QVBoxLayout;
    hLayoutTab->addWidget(addrHorizontal);
    hLayoutTab->addWidget(tab);
    QWidget *hLayoutTab_CTR = new QWidget;


    QVBoxLayout *hLayoutASCII = new QVBoxLayout;
    hLayoutASCII->addWidget(addrHorizontal2);
    hLayoutASCII->addWidget(ASCIITable);
    QWidget *hLayoutASCII_CTR = new QWidget;

    addrVertical = new QAddrVertical;

    hLayoutTab_CTR->setLayout(hLayoutTab);
    hLayoutASCII_CTR->setLayout(hLayoutASCII);

    splitter->addWidget(addrVertical);
    splitter->addWidget(hLayoutTab_CTR);
    splitter->addWidget(hLayoutASCII_CTR);


    ASCIITable->setStyleSheet("border: 1px solid red");

    QList<int> sizes;
    sizes << 20 << 200 << 20 ;

    splitter->setSizes(sizes);
    vlayout->addWidget(menuPanel);
    vlayout->addWidget(splitter);


    addrVertical->setFixedWidth(80);
    hLayoutASCII_CTR->setFixedWidth(420);
    setLayout(vlayout);

}
