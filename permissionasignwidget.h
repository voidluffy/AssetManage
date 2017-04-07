#ifndef PERMISSIONASIGNWIDGET_H
#define PERMISSIONASIGNWIDGET_H

#include <QWidget>

namespace Ui {
class PermissionAsignWidget;
}

class PermissionAsignWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PermissionAsignWidget(QWidget *parent = 0);
    ~PermissionAsignWidget();

private:
    Ui::PermissionAsignWidget *ui;
};

#endif // PERMISSIONASIGNWIDGET_H
