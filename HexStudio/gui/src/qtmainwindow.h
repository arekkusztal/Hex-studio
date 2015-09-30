#ifndef QTMAINWINDOW_H
#define QTMAINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include "gui/src/qhextable.h"
#include "gui/src/qasciitable.h"
#include "gui/src/qaddrhorizontal.h"
#include "gui/src/qaddrhorizontal2.h"
#include "gui/src/qaddrvertical.h"
#include "gui/src/menupanel.h"
#include "gui/src/qmenupanel2.h"

class QtMainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit QtMainWindow(QWidget *parent = 0);

signals:

public slots:
    void wheelEvent(QWheelEvent *);
private:
  //  QGridLayout *layout;


};

#endif // QTMAINWINDOW_H
