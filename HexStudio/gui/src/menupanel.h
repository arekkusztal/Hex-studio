#ifndef MENUPANEL_H
#define MENUPANEL_H

#include <QWidget>
#include <QPainter>
#include <QtGui>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>

class MenuPanel : public QWidget
{
    Q_OBJECT
public:
    explicit MenuPanel(QWidget *parent = 0);

signals:

public slots:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
};

#endif // MENUPANEL_H
