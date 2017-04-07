#ifndef HOMECENTERITEM_H
#define HOMECENTERITEM_H
#include "basestylewidget.h"
class HomeDynamicButtonWidget;

class HomeCenterItem:public BaseStyleWidget
{
    Q_OBJECT
public:
    explicit HomeCenterItem(QWidget *parent = 0);
    void startFirstAnim();
signals:
private:
    void initUI();
private:
    HomeDynamicButtonWidget    *m_trashButton;
    HomeDynamicButtonWidget    *m_traceButton;
    HomeDynamicButtonWidget    *m_regButton;
    HomeDynamicButtonWidget    *m_pluginButton;
    HomeDynamicButtonWidget    *m_softButton;
    HomeDynamicButtonWidget    *m_cookiesButton;
    QList<HomeDynamicButtonWidget*>    m_buttonList;
};

#endif // HOMECENTERITEM_H
