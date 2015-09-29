#ifndef QHEXTABLE_H
#define QHEXTABLE_H

#include <QWidget>
#include "../../bus/inc/types.h"

class QHexTable : public QWidget
{
    Q_OBJECT
public:
    explicit QHexTable(QWidget *parent = 0);
    void     repaintme();

signals:

public slots:
    void    paintEvent(QPaintEvent*);
    void    mouseMoveEvent(QMouseEvent*);
    void    mousePressEvent(QMouseEvent*);
    void    keyPressEvent(QKeyEvent*);
};

#endif // QHEXTABLE_H
