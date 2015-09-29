#include "qaddrhorizontal.h"


int tFontSize = 10;

QAddrHorizontal::QAddrHorizontal(QWidget *parent) :
    QWidget(parent)
{

    repaint();
}

void QAddrHorizontal::paintEvent(QPaintEvent *event)
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

    // Lines of HexTable
    int count = 0;
    for (int i=0;i<(cols)*quadLen;i+=quadLen)
    {
        pen.drawLine(i,0,i,b);
        pen.drawText(8+i,16, QString::number(count++,16).toUpper().rightJustified(2,'0') );
    }

}
