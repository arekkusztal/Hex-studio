#ifndef QADDRHORIZONTAL2_H
#define QADDRHORIZONTAL2_H

#include <QWidget>
#include <QPainter>
#include <QtGui>

static int tFontSize = 10;
extern int cols;

class QAddrHorizontal2 : public QWidget
{
    Q_OBJECT
public:
    explicit QAddrHorizontal2(QWidget *parent = 0);

signals:

public slots:
    void paintEvent(QPaintEvent*);
};

#endif // QADDRHORIZONTAL2_H
