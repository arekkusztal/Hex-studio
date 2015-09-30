#ifndef QRAW_H
#define QRAW_H


#include <QWidget>
#include <QGridLayout>
#include "gui/src/qhextable.h"
#include "gui/src/qasciitable.h"
#include "gui/src/qaddrhorizontal.h"
#include "gui/src/qaddrhorizontal2.h"
#include "gui/src/qaddrvertical.h"
#include "gui/src/menupanel.h"
#include "gui/src/qmenupanel2.h"

class QRaw : public QWidget
{
    Q_OBJECT
public:
    explicit QRaw(QWidget *parent = 0);

signals:

public slots:

};

#endif // QRAW_H
