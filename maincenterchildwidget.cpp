#include "maincenterchildwidget.h"
#include "staticbutton.h"
#include "backgroundbutton.h"
#include "buttonlabel.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

MainCenterChildWidget::MainCenterChildWidget(QWidget *parent) :
    BaseStyleWidget(parent)
{
    this->setStyleSheet("QWidget#firstWidget{background:white;}");
    this->setObjectName("firstWidget");
    this->initUI();
    this->initConnect();
}

void MainCenterChildWidget::initUI()
{
    m_safeButton = new StaticButton(":/main/safe_check");
    QLabel *safeLabel = new QLabel(tr("查杀修复"));
    safeLabel->setObjectName("mainBottomLabel");
    QVBoxLayout *safeLayout = new QVBoxLayout;
    safeLayout->addWidget(m_safeButton, 0, Qt::AlignCenter);
    safeLayout->addWidget(safeLabel, 0, Qt::AlignCenter);

    m_cleanButton = new StaticButton(":/main/clean");
    QLabel *cleanLabel = new QLabel(tr("dian nao qing li"));
    cleanLabel->setObjectName("mainBottomLabel");
    QVBoxLayout *cleanLayout = new QVBoxLayout;
    cleanLayout->addWidget(m_cleanButton, 0, Qt::AlignCenter);
    cleanLayout->addWidget(cleanLabel, 0, Qt::AlignCenter);

    m_youhuaButton = new StaticButton(":/main/youhua");
    QLabel *youhuaLabel = new QLabel(tr("you hua jia su"));
    youhuaLabel->setObjectName("mainBottomLabel");
    QVBoxLayout *youhuaLayout = new QVBoxLayout;
    youhuaLayout->addWidget(m_youhuaButton, 0, Qt::AlignCenter);
    youhuaLayout->addWidget(youhuaLabel, 0, Qt::AlignCenter);

    QHBoxLayout *staticLayout = new QHBoxLayout;
    staticLayout->addLayout(safeLayout);
    staticLayout->addLayout(cleanLayout);
    staticLayout->addLayout(youhuaLayout);
    staticLayout->setContentsMargins(10, 20, 10, 10);

    QLabel *routerTitle = new QLabel(tr("lu you qi wei shi"));
    QFont font = routerTitle->font();
    font.setBold(true);
    font.setPixelSize(15);
    routerTitle->setFont(font);

    QLabel *routerDes = new QLabel(tr("sheng ji lu youqi"));
    QVBoxLayout *routerTextLayout = new QVBoxLayout;
    routerTextLayout->addWidget(routerTitle, 0, Qt::AlignRight);
    routerTextLayout->addWidget(routerDes, 0, Qt::AlignRight);
    routerTextLayout->setContentsMargins(10, 10, 5, 15);

    StaticButton *routerButton = new StaticButton(":/main/routerdefender");
    QHBoxLayout *routerLayout = new QHBoxLayout;
    routerLayout->addLayout(routerTextLayout);
    routerLayout->addWidget(routerButton);

    QStringList advIconList, advNameList;
    advIconList << "360SoftManger" << "360JiShi" << "360MobileMgr" << "NetSpeed";
    advNameList << "guanjia" << "rengong" << "shou ji zhu you" << "kan dai " ;

    QHBoxLayout *advLayout = new QHBoxLayout;
    for(int i=0; i<advIconList.size(); i++)
    {
        BackgroundButton *backButton = new BackgroundButton;
        backButton->setIconsInfo(":/main/" + advIconList.at(i), ":/main/all_tool_bk", 1);
        backButton->setText(advNameList.at(i));
        advLayout->addWidget(backButton);
    }

    m_advtoolMore = new StaticButton(":/main/advtool_more");
    ButtonLabel *advLabel = new ButtonLabel;
    advLabel->setStyleSheet("QLabel{color:blue;}");
    advLabel->setText("geng duo");

    QVBoxLayout *moreLayout = new QVBoxLayout;
    moreLayout->addStretch();
    moreLayout->addWidget(m_advtoolMore, 0, Qt::AlignCenter);
    moreLayout->addSpacing(5);
    moreLayout->addWidget(advLabel, 0, Qt::AlignCenter);
    moreLayout->addStretch();


    advLayout->addLayout(moreLayout);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addLayout(routerLayout);
    rightLayout->addLayout(advLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(staticLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(rightLayout);

    this->setLayout(mainLayout);
}

void MainCenterChildWidget::initConnect()
{
    connect(m_safeButton, SIGNAL(buttonClicked()), this, SIGNAL(safeClicked()));
    connect(m_cleanButton, SIGNAL(buttonClicked()), this, SIGNAL(cleanClicked()));
    connect(m_youhuaButton, SIGNAL(buttonClicked()), this, SIGNAL(youhuaClicked()));
    connect(m_advtoolMore, SIGNAL(buttonClicked()), this, SIGNAL(advtoolMoreClicked()));
}
