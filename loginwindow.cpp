#include "LoginWindow.h"
#include "ui_LoginWindow.h"
#include <QPainter>
#include <QMovie>
#include <QHBoxLayout>
#include <QCursor>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    initWindow();
    initMyTitle();
    this->loadStyleSheet(":/Resources/LoginWindow/LoginWindow.css");
    //this->setStyleSheet("background-image:url(:/Resources/LoginWindow/back.png);border:1px solid black;");

    connect(ui->loginButton,SIGNAL(clicked()),SLOT(on_LoginpushButton_clicked()));//????????????????

    QPalette background;
    background.setBrush(QPalette::Background, QBrush(QPixmap(":/Resources/LoginWindow/back.png")));
    this->setPalette(background);
    this->setAutoFillBackground( true );

}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_LoginpushButton_clicked()
{
    accept();

//    if(ui->passwordEdit->text().isEmpty())
//    {
//        QMessageBox::information(this,QString::fromLocal8Bit("用户名和密码不能为空"),
//                QString::fromLocal8Bit("请输入用户名和密码后再登录！\n\n"),
//                QMessageBox::Yes);
//    }
//    else
//    {
//        accept();

//    }
}


void LoginWindow::initMyTitle()
{
    // 因为这里有控件层叠了，所以要注意控件raise()方法的调用顺序;
    m_titleBar->move(0, 0);
    m_titleBar->raise();
    m_titleBar->setBackgroundColor(0, 0, 0 , true);
    m_titleBar->setButtonType(MIN_BUTTON);
    m_titleBar->setTitleWidth(this->width());

    //ui->pButtonArrow->raise();
}

void LoginWindow::initWindow()
{


    ui->labelLog->setPixmap(QPixmap(":/Resources/LoginWindow/logo-login.png"));
    ui->labelVersion->setPixmap(QPixmap(":/Resources/LoginWindow/version-icon.png"));

    //背景图;
    //	QLabel* pBack = new QLabel(this);
    //	QMovie *movie = new QMovie();
    //	movie->setFileName(":/Resources/LoginWindow/back.gif");
    //	movie->start();
    //	movie->stop();
    //	pBack->setMovie(movie);
    //	movie->start();
    //	pBack->move(0, 0);

    //注释;
    ui->accountComboBox->setEditable(true);
    QLineEdit* lineEdit = ui->accountComboBox->lineEdit();
    lineEdit->setPlaceholderText(QStringLiteral("用户名"));

    ui->passwordEdit->setPlaceholderText(QStringLiteral("登录密码"));

    // 密码框中的小键盘按钮;
    m_keyboardButton = new QPushButton();
    m_keyboardButton->setObjectName("pButtonKeyboard");
    m_keyboardButton->setFixedSize(QSize(16, 16));
    m_keyboardButton->setCursor(QCursor(Qt::PointingHandCursor));

    QHBoxLayout* passwordEditLayout = new QHBoxLayout();
    passwordEditLayout->addStretch();
    passwordEditLayout->addWidget(m_keyboardButton);
    passwordEditLayout->setSpacing(0);
    passwordEditLayout->setContentsMargins(0, 0, 8, 0);

    //ui->loginButton->setFixedHeight(30);
    //ui->loginButton->setFixedWidth(100);
    //ui->loginButton->setGeometry(0,0,150,30); //按钮的位置及大小
    ui->passwordEdit->setLayout(passwordEditLayout);
    ui->passwordEdit->setTextMargins(0, 0, m_keyboardButton->width() + 12, 0);

    //ui->userHead->setPixmap(QPixmap(":/Resources/LoginWindow/HeadImage.png"));
    //ui->loginState->setIcon(QIcon(":/Resources/LoginWindow/LoginState/state_online.png"));
    //ui->loginState->setIconSize(QSize(13, 13));
}
