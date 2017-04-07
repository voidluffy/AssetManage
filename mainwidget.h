#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QTreeWidget>
#include "customtitledialog.h"
#include "lookupassetwidget.h"
#include "asignassetwidget.h"
#include "permissionasignwidget.h"
#include "homeselectwidget.h"
#include "homewidget.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public CustomTitleDialog
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    Ui::MainWidget *ui;

private slots:
    void showSelectedImage(QTreeWidgetItem * item, int column); //点击树节点事件
    void goSelect_item1();
    void goSelect_item2();
    void goToMain();

private:
    LookupAssetWidget *m_pLookupassetwidget;
    AsignAssetWidget *m_pAsignassetwidget;
    PermissionAsignWidget *m_pPermissionAsignwidget;
    HomeSelectWidget *m_pHomeselectwidget;
    HomeWidget*m_pHomewidget;
public:
    void initTreeWidgetMenu();
    void screen_normal();

};

#endif // MAINWIDGET_H
