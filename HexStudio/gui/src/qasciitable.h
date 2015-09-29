#ifndef QASCIITABLE_H
#define QASCIITABLE_H

#include <QWidget>


class QASCIITable : public QWidget
{
    Q_OBJECT
public:
    explicit QASCIITable(QWidget *parent = 0);
    void     repaintme();

signals:

public slots:
    void    paintEvent(QPaintEvent*);
    void    mousePressEvent(QMouseEvent*);

};

#endif // QASCIITABLE_H
