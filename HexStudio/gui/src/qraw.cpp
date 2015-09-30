#include "qraw.h"

#include <QLabel>
#include <QSplitter>
#include <QTextEdit>
#include <QTabWidget>
#include "bus/src/file.h"


QHexTable *tab;
QASCIITable *ASCIITable;
QAddrVertical *addrVertical;

QRaw::QRaw(QWidget *parent) :
    QWidget(parent)
{
    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    tab = new QHexTable;
    ASCIITable = new QASCIITable;

    QAddrHorizontal *addrHorizontal = new QAddrHorizontal;
    addrHorizontal->setFixedHeight(16);

    QAddrHorizontal2 *addrHorizontal2 = new QAddrHorizontal2;
    addrHorizontal2->setFixedHeight(16);

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


    addrVertical->setFixedWidth(80);
    hLayoutASCII_CTR->setFixedWidth(420);

    splitter->addWidget(addrVertical);
    splitter->addWidget(hLayoutTab_CTR);
    splitter->addWidget(hLayoutASCII_CTR);


    ASCIITable->setStyleSheet("border: 1px solid red");


    QList<int> sizes;
    sizes << 20 << 200 << 20 ;

    splitter->setSizes(sizes);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(splitter);
    setLayout(layout);
}
