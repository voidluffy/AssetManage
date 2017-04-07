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
//        QMessageBox::information(this,QString::fromLocal8Bit("�û��������벻��Ϊ��"),
//                QString::fromLocal8Bit("�������û�����������ٵ�¼��\n\n"),
//                QMessageBox::Yes);
//    }
//    else
//    {
//        accept();

//    }
}


void LoginWindow::initMyTitle()
{
    // ��Ϊ�����пؼ�����ˣ�����Ҫע��ؼ�raise()�����ĵ���˳��;
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

    //����ͼ;
    //	QLabel* pBack = new QLabel(this);
    //	QMovie *movie = new QMovie();
    //	movie->setFileName(":/Resources/LoginWindow/back.gif");
    //	movie->start();
    //	movie->stop();
    //	pBack->setMovie(movie);
    //	movie->start();
    //	pBack->move(0, 0);

    //ע��;
    ui->accountComboBox->setEditable(true);
    QLineEdit* lineEdit = ui->accountComboBox->lineEdit();
    lineEdit->setPlaceholderText(QStringLiteral("�û���"));

    ui->passwordEdit->setPlaceholderText(QStringLiteral("��¼����"));

    // ������е�С���̰�ť;
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
    //ui->loginButton->setGeometry(0,0,150,30); //��ť��λ�ü���С
    ui->passwordEdit->setLayout(passwordEditLayout);
    ui->passwordEdit->setTextMargins(0, 0, m_keyboardButton->width() + 12, 0);

    //ui->userHead->setPixmap(QPixmap(":/Resources/LoginWindow/HeadImage.png"));
    //ui->loginState->setIcon(QIcon(":/Resources/LoginWindow/LoginState/state_online.png"));
    //ui->loginState->setIconSize(QSize(13, 13));
}
