#include "permissionasignwidget.h"
#include "ui_permissionasignwidget.h"

PermissionAsignWidget::PermissionAsignWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PermissionAsignWidget)
{
    ui->setupUi(this);
}

PermissionAsignWidget::~PermissionAsignWidget()
{
    delete ui;
}
