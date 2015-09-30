#include "qmenupanel2.h"
#include <QPushButton>
#include <QTextEdit>
#include <QImage>


static int tFontSize = 10;
static int bSize = 30;
static int imgSize = 20;

QImage *images = new QImage[20];

QMenuPanel2::QMenuPanel2(QWidget *parent) :
    QWidget(parent)
{
    images[0].load(":res/sections_1.png","PNG");
    repaint();
}

void QMenuPanel2::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    pen.setPen(Qt::DotLine);

    QFont   font = pen.font();
    font.setPointSize(tFontSize);
    font.setWeight(QFont::DemiBold);

    QPen qpen;
    qpen.setColor(Qt::black);
    pen.setFont(font);
    qpen.setColor(QColor(144,24,24,255));
    pen.setPen(qpen);


    int a = this->width();
    int b = this->height();



    pen.setPen(Qt::SolidLine);
    qpen.setColor(QColor(205,210,214,255));
    pen.setPen(qpen);

    pen.drawLine(0,0,a,0);
    pen.drawLine(0,b-1,a,b-1);


    pen.drawImage(QRect(5,5,imgSize,imgSize),images[0]);

}

void QMenuPanel2::mousePressEvent(QMouseEvent *event)
{

}
