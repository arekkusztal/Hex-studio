#include "qaddrhorizontal2.h"




QAddrHorizontal2::QAddrHorizontal2(QWidget *parent) :
    QWidget(parent)
{
    repaint();
}

void QAddrHorizontal2::paintEvent(QPaintEvent*)
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

    for (int i=0;i<(cols)*12;i+=12)
    {
   //     pen.drawLine(i,0,i,b);        
        if (i == 36 || i == 84 || i == 132 || i == 180 || i == 228 || i == 276 || i == 324 || i == 372)
            pen.drawText(8+i,16, "d" );
        else
            pen.drawText(8+i,16, "-" );
    }

}
