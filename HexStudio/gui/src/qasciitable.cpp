#include "qasciitable.h"
#include <QPainter>
#include <QtGui>



extern int hexFontSize;

extern unsigned char hexSrc[100];// = "abcdefgkererererererersdfasdfldkg;asfjas;lkfjdsa;lfjasd;lk \
            //asdsadsagsdsgdacxmvn,vnaaaa";

extern char *hexSource_p;

extern int cols;

extern int len;

extern int *flen_p;

extern int shift;

extern int quadLen;

extern int hexFontSize;

extern int current;

int current2;

int celLen = 12;

extern int posInCurrent;

extern void GlobalRepaint(int);

struct Cell
{
    int x_1, x_2;
    int y_1, y_2;
} cell_2;

QASCIITable::QASCIITable(QWidget *parent) :
    QWidget(parent)
{
    repaint();
}


void QASCIITable::paintEvent(QPaintEvent *)
{
    QPainter pen(this);
    pen.setPen(Qt::DotLine);

    QFont   font = pen.font();
    font.setPointSize(12);
    font.setWeight(QFont::DemiBold);

    QPen qpen;

    int a = this->width();
    int b = this->height();
    int visRows = b/quadLen + 2;


    for (int i=0;i<b+30;i+=30)
    {
        pen.drawLine(0,i,a,i);
    }

    for (int i=8;i<(cols+1)*12;i+=12)
    {
        pen.drawLine(i,0,i,b);
    }


   // pen.setPen(Qt::SolidLine);
    pen.drawLine(0,0,0,b);


    QString sHex;
    /// Podmiana src
    unsigned char *hexIterator = (unsigned char*) hexSource_p;// hexSrc;
    int ecx = 0;

    hexIterator += shift;

    for (int i = 0;i<visRows+1;++i)
    {
        for (int j=0;j<cols;++j)
        {
            if (++ecx > *flen_p - shift)
                break;

           // sHex = QString::number(*hexIterator++, 16).toUpper();
            sHex = *hexIterator++;
            pen.drawText(6+celLen*j,10+quadLen*i,16,16,Qt::AlignCenter, sHex);
        }
    }

    if (current >= 0)
    {
        int highlightedCell = current - shift;
        cell_2.x_1 = 8 + (highlightedCell % cols) * celLen;
        cell_2.x_2 = celLen;
        cell_2.y_1 = (highlightedCell / cols) * quadLen;
        cell_2.y_2 = quadLen;

        qpen.setColor(Qt::red);
        pen.setPen(qpen);


        pen.fillRect(cell_2.x_1,cell_2.y_1,cell_2.x_2,cell_2.y_2, QBrush(QColor(128,128,255,128)));
    }


}

void QASCIITable::mousePressEvent(QMouseEvent *event)
{
    int i = event->pos().x()-6;
    int j = event->pos().y();

    if (i > cols*celLen)
    {
        current = -1;
        goto repaint;
    }
    current = i/celLen + cols*(j/quadLen)+shift;
    posInCurrent = 0;

repaint:
    repaint();
    GlobalRepaint(1);
}


void QASCIITable::repaintme()
{
    repaint();
}
