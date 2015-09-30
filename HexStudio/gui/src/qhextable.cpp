#include "qhextable.h"
#include <QPainter>
#include <QtGui>



extern int len;

extern int *flen_p;
///
/// \brief How much vertically file was shifted, can't be bigger than |-len-| and should have been multiply of cols
///
int shift = 0;

///
/// \brief Should it have been in bus or in gui have no clue right now, rather gui
///
int hexFontSize = 12;

///
/// \brief
///
int quadLen     = 30;

struct MousePos
{
    float x; float y;
} mousepos;

struct Cell
{
    int x_1, x_2;
    int y_1, y_2;
} cell;

bool highlightCells = false;

byte posInCurrent   = 0;

int selectedByte    = -1;

///
/// \brief No, not asm/current.h ;). Current cell being edited.
///
int current         = -1;

extern unsigned char hexSrc[1024];
extern char *hexSource_p;

int cols = 32;

extern void GlobalRepaint(int);

QHexTable::QHexTable(QWidget *parent) :
    QWidget(parent)
{
    setMouseTracking(true);
  //  installEventFilter(this);
  //  this->setStyleSheet("QSplitter { border-color: rgb(255, 0, 0); color: rgb(145, 145, 145); height: 5px;background-color: rgb(225,230,234); }");
    setFocusPolicy(Qt::StrongFocus);
    repaint();
}

void QHexTable::paintEvent(QPaintEvent *)
{
    QPainter pen(this);
    pen.setPen(Qt::DotLine);

    QFont   font = pen.font();
    font.setPointSize(hexFontSize);
    font.setWeight(QFont::DemiBold);

    QPen qpen;

    int a = this->width();
    int b = this->height();
    int visRows = b/quadLen + 2;

    // Lines of HexTable
    for (int i=0;i<(cols+1)*quadLen;i+=quadLen)
    {
        pen.drawLine(i,0,i,b);
    }

    for (int i=0;i<b+quadLen;i+=quadLen)
    {
        pen.drawLine(0,i,a,i);
    }

    pen.drawLine(a-1,0,a-1,b);
    pen.setFont(font);

   // QString sHex = QString::number('a', 16).toUpper();
   // pen.drawText(8,28, sHex.rightJustified(2,'0') );

    QString sHex;
    ///Podmiana src
    unsigned char *hexIterator = (unsigned char*)hexSource_p; // hexSrc;
    int ecx = 0;
    bool colorFlag = 0;

    hexIterator += shift;

    pen.setPen(qpen);

    for (int i = 0;i<visRows+1;++i)
    {
        for (int j=0;j<cols;++j)
        {
            if (++ecx > *flen_p - shift)
                break;

            sHex = QString::number(*hexIterator++, 16).toUpper();

            if (colorFlag)
            {
                qpen.setColor(QColor(0,0,96,255));
            }
            else
            {
                qpen.setColor(Qt::black);
            }
            colorFlag = !colorFlag;
            pen.setPen(qpen);

            pen.drawText(6+quadLen*j,22+quadLen*i, sHex.rightJustified(2,'0') );
        }
    }

    /// SelectedByte = -1 for places where there is nothing to highlight, also for highlihting turned off
    if (selectedByte >= 0)
    {
        int highlightedCell = selectedByte - shift;
        cell.x_1 = (highlightedCell % cols) * quadLen;
        cell.x_2 = quadLen;
        cell.y_1 = (highlightedCell / cols) * quadLen;
        cell.y_2 = quadLen;

        qpen.setColor(Qt::blue);
        pen.setPen(qpen);
        pen.drawRect(cell.x_1,cell.y_1,cell.x_2,cell.y_2);
    }

  //  pen.drawText(550,550,QString::number(current));
    if (current >= 0)
    {
        int highlightedCell = current - shift;
        cell.x_1 = (highlightedCell % cols) * quadLen;
        cell.x_2 = quadLen;
        cell.y_1 = (highlightedCell / cols) * quadLen;
        cell.y_2 = quadLen;

        qpen.setColor(Qt::red);
        pen.setPen(qpen);


        pen.fillRect(cell.x_1,cell.y_1,cell.x_2,cell.y_2, QBrush(QColor(128,128,255,128)));
    }




}

void QHexTable::mousePressEvent(QMouseEvent *event)
{
    int i = event->pos().x();
    int j = event->pos().y();

    if (i > cols*quadLen)
    {
        current = -1;
        goto repaint;
    }
    current = i/quadLen + cols*(j/quadLen)+shift;
    posInCurrent = 0;

repaint:
    repaint();
    GlobalRepaint(0);
}

void QHexTable::keyPressEvent(QKeyEvent *event)
{
    if (current < 0)
        return;

    byte i64 = event->key();
    if ( (i64 < '0' || i64 > '9') && (i64 < 'A' || i64 > 'F') )
    {
        return;
    }

    /// podmiana src
    //QString sHex = QString::number(hexSrc[current], 16).toUpper();

    QString sHex = QString::number(hexSource_p[current], 16).toUpper();

    sHex[posInCurrent++] = i64;
    bool bStatus = false;

    int number = sHex.toUInt(&bStatus,16);

    ///podmiana src
    //hexSrc[current] = (byte)number;
    hexSource_p[current] = (byte)number;

    if (posInCurrent == 2)
    {
        posInCurrent = 0;
        current++;
    }

    repaint();
    GlobalRepaint(0);
}

void QHexTable::mouseMoveEvent(QMouseEvent *event)
{
   // if (!highlightCells)
   //     return;

    int i = event->pos().x();
    int j = event->pos().y();

    if (i > cols*quadLen)
    {
        selectedByte = -1;
        goto repaint;
    }

    selectedByte = i/quadLen + cols*(j/quadLen)+shift;


repaint:
    repaint();
}


void QHexTable::repaintme()
{
    repaint();
}
