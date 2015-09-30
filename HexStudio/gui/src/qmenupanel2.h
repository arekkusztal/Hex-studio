#ifndef QMENUPANEL2_H
#define QMENUPANEL2_H

#include <QWidget>
#include <QPainter>
#include <QtGui>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>

class QMenuPanel2 : public QWidget
{
    Q_OBJECT
public:
    explicit QMenuPanel2(QWidget *parent = 0);

signals:

public slots:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);

};

#endif // QMENUPANEL2_H
