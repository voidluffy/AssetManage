#include "lookupassetwidget.h"
#include "ui_lookupassetwidget.h"

LookupAssetWidget::LookupAssetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LookupAssetWidget)
{
    ui->setupUi(this);
    connect(ui->pushButton_back, SIGNAL(clicked()), this, SIGNAL(goToMain()));
}

LookupAssetWidget::~LookupAssetWidget()
{
    delete ui;
}

void LookupAssetWidget::sMain(){
    this->autoFillBackground();
}
