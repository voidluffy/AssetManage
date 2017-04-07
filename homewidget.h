#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H
#include "basestylewidget.h"
#include "homecenteritem.h"
class HomeDynamicButtonWidget;

class HomeWidget: public QWidget
{
    Q_OBJECT
public:
    explicit HomeWidget(QWidget *parent = 0);
public slots:
    void startFirst();
signals:
    void goToMain();
private:
    void initUI();
private:
    HomeCenterItem  *m_scanBottomWidget;
    bool m_isFirst;
};


#endif // HOMEWIDGET_H
