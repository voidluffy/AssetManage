#include "customtitledialog.h"
#include "ui_customtitledialog.h"
#include <QDesktopWidget>
#include "myhelper.h"
#include "iconhelper.h"
CustomTitleDialog::CustomTitleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomTitleDialog)
{
    ui->setupUi(this);

//    myHelper::FormInCenter(this);
    this->InitStyle();

    dialog = new QDialog;
    ui->verticalLayout_content->addWidget(dialog);
    dialog->show();
}

CustomTitleDialog::~CustomTitleDialog()
{
    delete ui;
}

void CustomTitleDialog::doClose()
{
    close();
}

QWidget *CustomTitleDialog::getContentWidget()
{
    return ui->widget;
}

QDialog *CustomTitleDialog::getContentDialog()
{
    return dialog;
}

void CustomTitleDialog::InitStyle()
{
    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    location = this->geometry();
    max = false;
    mousePressed = false;

    //安装事件监听器,让标题栏识别鼠标双击
    ui->lab_Title->installEventFilter(this);

    IconHelper::Instance()->SetIcon(ui->btnMenu_Close, QChar(0xf00d), 10);
    IconHelper::Instance()->SetIcon(ui->btnMenu_Max, QChar(0xf096), 10);
    IconHelper::Instance()->SetIcon(ui->btnMenu_Min, QChar(0xf068), 10);
    IconHelper::Instance()->SetIcon(ui->btnMenu, QChar(0xf0c9), 10);
    IconHelper::Instance()->SetIcon(ui->lab_Ico, QChar(0xf015), 12);
}

bool CustomTitleDialog::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick) {
        this->on_btnMenu_Max_clicked();
        return true;
    }
    return QObject::eventFilter(obj, event);
}

void CustomTitleDialog::mouseMoveEvent(QMouseEvent *e)
{
    if (mousePressed && (e->buttons() && Qt::LeftButton) && !max) {
        this->move(e->globalPos() - mousePoint);
        e->accept();
    }
}

void CustomTitleDialog::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        mousePressed = true;
        mousePoint = e->globalPos() - this->pos();
        e->accept();
    }
}

void CustomTitleDialog::mouseReleaseEvent(QMouseEvent *)
{
    mousePressed = false;
}

void CustomTitleDialog::mouseDoubleClickEvent(QMouseEvent *e)
{
    on_btnMenu_Max_clicked();
}

void CustomTitleDialog::on_btnMenu_Close_clicked()
{
//    qApp->exit();
    doClose();
}

void CustomTitleDialog::on_btnMenu_Max_clicked()
{
    if (max) {
        this->setGeometry(location);
        IconHelper::Instance()->SetIcon(ui->btnMenu_Max, QChar(0xf096), 10);
        ui->btnMenu_Max->setToolTip("最大化");
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
        IconHelper::Instance()->SetIcon(ui->btnMenu_Max, QChar(0xf079), 10);
        ui->btnMenu_Max->setToolTip("还原");
    }
    max = !max;
}

void CustomTitleDialog::on_btnMenu_Min_clicked()
{
    this->showMinimized();
}

void CustomTitleDialog::setTitle(QString str)
{
    ui->lab_Title->setText(str);
    this->setWindowTitle(str);
}

void CustomTitleDialog::showMaximized()
{
    this->show();
    max = false;
    on_btnMenu_Max_clicked();
}

void CustomTitleDialog::changeMax()
{
    on_btnMenu_Max_clicked();
}
