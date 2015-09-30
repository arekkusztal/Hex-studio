#include "qaddrvertical.h"


extern int shift;

static int tFontSize = 10;

QAddrVertical::QAddrVertical(QWidget *parent) :
    QWidget(parent)
{
    repaint();
}

void QAddrVertical::paintEvent(QPaintEvent *event)
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
    int visRows = b/quadLen + 2;

    int count = shift;
    for (int i=quadLen*2;i<b+quadLen;i+=quadLen)
    {
        pen.drawLine(0,i-quadLen,a,i-quadLen);
        pen.drawText(6,i-7,QString::number(count,16).toUpper().rightJustified(8,'0'));
        count+=32;
    }
    pen.drawLine(a-1,0,a-1,b);


    qpen.setColor(QColor(24,144,24,255));
    pen.setPen(qpen);

    int currentaddr = current < 0 ? 0 : current;
    pen.drawText(6,quadLen-7,QString::number(currentaddr,16).toUpper().rightJustified(8,'0'));


}
