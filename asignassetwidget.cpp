#include "asignassetwidget.h"
#include "ui_asignassetwidget.h"

AsignAssetWidget::AsignAssetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AsignAssetWidget)
{
    ui->setupUi(this);
    connect(ui->pushButton_back, SIGNAL(clicked()), this, SIGNAL(goToMain()));
}

AsignAssetWidget::~AsignAssetWidget()
{
    delete ui;
}
