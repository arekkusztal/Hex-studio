#include "menupanel.h"
#include <QPushButton>
#include <QTextEdit>
#include <QImage>


extern int readfile(const char *filename);

static int tFontSize = 10;
static int bSize = 30;
static int imgSize = 20;
QImage img,img2,img3,img4,img5,img6,img7,img8,img9,img10,img11,img12,img13;

MenuPanel::MenuPanel(QWidget *parent) :
    QWidget(parent)
{
    img.load(":res/new_1.png","PNG");
    img2.load(":res/load_1.png","PNG");
    img3.load(":res/save_1.png","PNG");
    img4.load(":res/saveAll_1.png","PNG");
    img5.load(":res/find_1.png","PNG");
    img6.load(":res/rep_1.png","PNG");
    img7.load(":res/close_1.png","PNG");
    img8.load(":res/closeAll_1.png","PNG");
    img9.load(":res/cut_1.png","PNG");
    img10.load(":res/copy_1.png","PNG");
    img11.load(":res/paste_1.png","PNG");
    img12.load(":res/undo_1.png","PNG");
    img13.load(":res/redo_1.png","PNG");

   // setFocusPolicy(Qt::StrongFocus);
    repaint();

}

void MenuPanel::mousePressEvent(QMouseEvent *event)
{
    int x = event->pos().x();
    int y = event->pos().y();

    QString file1Name;

    if (x < 30)
    {
        y = 3;
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Not yet implemented !");
        messageBox.setFixedSize(500,200);
    }
    else if (x >= 30 && x <= 60)
    {
        file1Name = QFileDialog::getOpenFileName(this,tr("Open XML File 1"), "/home",
             tr("All files (*.*);;Linux object (*.o);;Windows object (*.obj);;Exe files (*.exe)"));
        if (file1Name.size() != 0)
            readfile(file1Name.toStdString().c_str());
    }
    else if (x > 60 && x <= 60 )
        y = 5;
}


void MenuPanel::paintEvent(QPaintEvent *event)
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

    pen.drawLine(27,5,27,b-5);
    pen.drawLine(102,5,102,b-5);
    pen.drawLine(152,5,152,b-5);
    pen.drawLine(202,5,202,b-5);
    pen.drawLine(277,5,277,b-5);
    pen.drawLine(327,5,327,b-5);

    pen.drawImage(QRect(5,5,imgSize,imgSize),img);
    pen.drawImage(QRect(30,5,imgSize,imgSize),img2);
    pen.drawImage(QRect(55,5,imgSize,imgSize),img3);
    pen.drawImage(QRect(80,5,imgSize,imgSize),img4);
    pen.drawImage(QRect(105,5,imgSize,imgSize),img5);
    pen.drawImage(QRect(130,5,imgSize,imgSize),img6);
    pen.drawImage(QRect(155,5,imgSize,imgSize),img7);
    pen.drawImage(QRect(180,5,imgSize,imgSize),img8);
    pen.drawImage(QRect(205,5,imgSize,imgSize),img9);
    pen.drawImage(QRect(230,5,imgSize,imgSize),img10);
    pen.drawImage(QRect(255,5,imgSize,imgSize),img11);
    pen.drawImage(QRect(280,5,imgSize,imgSize),img12);
    pen.drawImage(QRect(305,5,imgSize,imgSize),img13);



}
