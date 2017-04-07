#include "homeselectwidget.h"
#include "ui_homeselectwidget.h"

HomeSelectWidget::HomeSelectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeSelectWidget)
{
    ui->setupUi(this);
    ui->pushButton->setGeometry(10,10,200,200); //前两个参数是位置坐标，后两个参数是按钮的尺寸。
//    ui->pushButton->setStyleSheet("QPushButton{background-color:black;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"  "QPushButton:hover{background-color:white; color: black;}"

//                                "QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }" );

    connect(ui->pushButton, SIGNAL(clicked()), this, SIGNAL(select_item1()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SIGNAL(select_item2()));

    //ui->widget->setStyleSheet("background-color:rgb(255,255,255)");

}

HomeSelectWidget::~HomeSelectWidget()
{
    delete ui;
}
