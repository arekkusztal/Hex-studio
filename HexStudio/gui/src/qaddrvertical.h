#ifndef QADDRVERTICAL_H
#define QADDRVERTICAL_H

#include <QWidget>
#include <QPainter>
#include <QtGui>

extern int quadLen;

extern int shift;

extern int current;

class QAddrVertical : public QWidget
{
    Q_OBJECT
public:
    explicit QAddrVertical(QWidget *parent = 0);

signals:

public slots:
    void    paintEvent(QPaintEvent*);
};

#endif // QADDRVERTICAL_H
