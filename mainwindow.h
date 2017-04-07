#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "shadowwidget.h"
#include "lookupassetwidget.h"
#include "permissionasignwidget.h"
#include "asignassetwidget.h"
#include "maincenterchildwidget.h"
#include <QParallelAnimationGroup>


class QStackedWidget;



class MainWindow: public ShadowWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
private:
    void initUI();
    void initConnect();
    void initAnim();
private slots:
    void playVideo();
    void showSkin();
    void showMenu();
    void showMin();
    void closeWidget();
    void goToMain();
    void goToSafe();
    void goToClean();
    void goToYouhua();
    void upAnimFinished();


private:

    QStackedWidget  *m_stackWidget;
    MainCenterChildWidget *m_bottomWidget;

    LookupAssetWidget *m_pLookupassetwidget;
    AsignAssetWidget *m_pAsignassetwidget;
    PermissionAsignWidget *m_pPermissionAsignwidget;

    QParallelAnimationGroup *m_upGroup;
    QParallelAnimationGroup *m_downGroup;
};

#endif // MAINWINDOW_H
