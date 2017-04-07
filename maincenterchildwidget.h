#ifndef MAINCENTERCHILDWIDGET_H
#define MAINCENTERCHILDWIDGET_H

#include <QWidget>
#include <basestylewidget.h>
#include "staticbutton.h"
class MainCenterChildWidget:public BaseStyleWidget
{
    Q_OBJECT
public:
    explicit MainCenterChildWidget(QWidget *parent = 0);
signals:
    void safeClicked();
    void cleanClicked();
    void youhuaClicked();
    void advtoolMoreClicked();
private:
    void initUI();
    void initConnect();
private:
    StaticButton *m_safeButton;
    StaticButton *m_cleanButton;
    StaticButton *m_youhuaButton;
    StaticButton *m_advtoolMore;
};


#endif // MAINCENTERCHILDWIDGET_H
