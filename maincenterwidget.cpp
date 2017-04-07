#include "maincenterwidget.h"
#include "maincenterchildwidget.h"

MainCenterWidget::MainCenterWidget(QWidget *parent) :
    BaseStyleWidget(parent)
{
    this->initUI();
    this->initAnimation();
    this->initConnect();
}

void MainCenterWidget::initUI()
{
    this->setGeometry(0, 440, 900, 160);
    m_stackedWidget = new QStackedLayout;
    m_firstWidget = new MainCenterChildWidget;
    BaseStyleWidget *whiteWidget = new BaseStyleWidget;
    whiteWidget->setStyleSheet("background:white;");
    //m_examineWidget = new MainExamineWidget;

    m_stackedWidget->addWidget(m_firstWidget);
    m_stackedWidget->addWidget(whiteWidget);
    //m_stackedWidget->addWidget(m_examineWidget);

    this->setLayout(m_stackedWidget);
}

void MainCenterWidget::initAnimation()
{
    QRect mainRect(0, 240, 900, 360);
    QRect origRect(0, 440, 900, 160);
    m_examineAnimation = new QPropertyAnimation(this, "geometry");
    m_examineAnimation->setDuration(200);
    m_examineAnimation->setStartValue(origRect);
    m_examineAnimation->setEndValue(mainRect);


    m_returnAnimation = new QPropertyAnimation(this, "geometry");
    m_returnAnimation->setDuration(200);
    m_returnAnimation->setStartValue(mainRect);
    m_returnAnimation->setEndValue(origRect);

}

void MainCenterWidget::initConnect()
{
    connect(m_examineAnimation, SIGNAL(finished()), this, SLOT(goExamineFinished()));
    connect(m_returnAnimation, SIGNAL(finished()), this, SLOT(goMainFinished()));
    connect(m_firstWidget, SIGNAL(safeClicked()), this, SIGNAL(safeClicked()));
    connect(m_firstWidget, SIGNAL(cleanClicked()), this, SIGNAL(cleanClicked()));
    connect(m_firstWidget, SIGNAL(youhuaClicked()), this, SIGNAL(youhuaClicked()));
    connect(m_firstWidget, SIGNAL(advtoolMoreClicked()), this, SIGNAL(advtoolMoreClicked()));
}

void MainCenterWidget::goExamine()
{
    m_examineAnimation->start();
    m_stackedWidget->setCurrentIndex(1);
}

void MainCenterWidget::goMain()
{
    m_returnAnimation->start();
    m_stackedWidget->setCurrentIndex(1);
}

void MainCenterWidget::goExamineFinished()
{
    m_stackedWidget->setCurrentIndex(2);
}

void MainCenterWidget::goMainFinished()
{
    m_stackedWidget->setCurrentIndex(0);
}
