#ifndef QADDRHORIZONTAL_H
#define QADDRHORIZONTAL_H

#include <QWidget>
#include <QPainter>
#include <QtGui>

extern int cols;
extern int quadLen;


class QAddrHorizontal : public QWidget
{
    Q_OBJECT
public:
    explicit QAddrHorizontal(QWidget *parent = 0);

signals:

public slots:
    void    paintEvent(QPaintEvent*);
};

#endif // QADDRHORIZONTAL_H
