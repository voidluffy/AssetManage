#ifndef MAINCENTERWIDGET_H
#define MAINCENTERWIDGET_H
#include "basestylewidget.h"
#include "maincenterchildwidget.h"
#include <QStackedLayout>
#include <QPropertyAnimation>


class MainCenterWidget: public BaseStyleWidget
{
    Q_OBJECT
public:
    explicit MainCenterWidget(QWidget *parent = 0);
public slots:
    void goExamine();
    void goMain();
private slots:
    void goExamineFinished();
    void goMainFinished();
signals:
    void safeClicked();
    void cleanClicked();
    void youhuaClicked();
    void advtoolMoreClicked();
private:
    void initUI();
    void initAnimation();
    void initConnect();
private:
    //MainExamineWidget *m_examineWidget;
    MainCenterChildWidget *m_firstWidget;
    QStackedLayout  *m_stackedWidget;
    QPropertyAnimation  *m_examineAnimation;
    QPropertyAnimation  *m_returnAnimation;
};

#endif // MAINBOTTOMWIDGET_H
