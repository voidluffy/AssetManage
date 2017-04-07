#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QTreeWidget>

MainWidget::MainWidget(QWidget *parent) :
    CustomTitleDialog(parent),
    ui(new Ui::MainWidget)
{
    //ui->setupUi(this);

    ui->setupUi(getContentDialog());
    this->setStyleSheet("background-color:rgb(0,0,128)");

    //窗口最大化显示
    //setWindowState(Qt::WindowMaximized);

    //initTreeWidgetMenu();


    m_pLookupassetwidget = new LookupAssetWidget;
    m_pAsignassetwidget = new AsignAssetWidget;
    m_pPermissionAsignwidget = new PermissionAsignWidget;
    m_pHomeselectwidget = new HomeSelectWidget;
    m_pHomewidget = new HomeWidget;


    ui->stackedWidget->addWidget(m_pHomeselectwidget);
    ui->stackedWidget->addWidget(m_pLookupassetwidget);
    ui->stackedWidget->addWidget(m_pAsignassetwidget);
    ui->stackedWidget->addWidget(m_pPermissionAsignwidget);
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    connect(m_pHomeselectwidget, SIGNAL(select_item1()), this, SLOT(goSelect_item1()));
    connect(m_pHomeselectwidget, SIGNAL(select_item2()), this, SLOT(goSelect_item2()));

    connect(m_pLookupassetwidget, SIGNAL(goToMain()), this, SLOT(goToMain()));
    connect(m_pAsignassetwidget, SIGNAL(goToMain()), this, SLOT(goToMain()));


    setWindowTitle(QString::fromLocal8Bit("AssetManage"));
}
MainWidget::~MainWidget()
{
    delete ui;
}


void MainWidget::screen_normal()
{
    //this->setGeometry(qApp->desktop()->availableGeometry());
    //this->layout()->setContentsMargins(1, 1, 1, 1);

}

void MainWidget::initTreeWidgetMenu(){

    //只写结点的实现
    QList<QTreeWidgetItem *> rootList;

    //添加第一个父节点
    QTreeWidgetItem *mainNode = new QTreeWidgetItem;
    mainNode->setText(0,"首页");
    rootList.append(mainNode);



    QTreeWidgetItem *assetEntryNode = new QTreeWidgetItem(mainNode,QStringList(QString("资产录入"))); //添加子节点

    QTreeWidgetItem * it_2_1 = new QTreeWidgetItem(assetEntryNode,QStringList(QString("批量录入"))); //添加子节点
    //it_2_1->setIcon(0,QIcon("xxx.png"));
    assetEntryNode->addChild(it_2_1);

    QTreeWidgetItem * it_2_2 = new QTreeWidgetItem(assetEntryNode,QStringList(QString("单次录入"))); //添加子节点
    assetEntryNode->addChild(it_2_2);

    mainNode->addChild(assetEntryNode);


    QTreeWidgetItem *asignPermissionNode = new QTreeWidgetItem(mainNode,QStringList(QString("权限分配"))); //添加子节点
    mainNode->addChild(asignPermissionNode);



    QTreeWidgetItem *asignAssetNode = new QTreeWidgetItem(mainNode,QStringList(QString("资产分配"))); //添加子节点
    mainNode->addChild(asignAssetNode);



    QTreeWidgetItem *lookUpAssetNode = new QTreeWidgetItem(mainNode,QStringList(QString("资产查看"))); //添加子节点
    mainNode->addChild(lookUpAssetNode);


    QTreeWidgetItem *pandianNode = new QTreeWidgetItem(mainNode,QStringList(QString("盘点"))); //添加子节点

    QTreeWidgetItem * pandianlist = new QTreeWidgetItem(pandianNode,QStringList(QString("盘点查看"))); //添加子节点

    pandianNode->addChild(pandianlist);

    QTreeWidgetItem * pandianhistory = new QTreeWidgetItem(pandianNode,QStringList(QString("盘点历史"))); //添加子节点
    pandianNode->addChild(pandianhistory);

    mainNode->addChild(pandianNode);



//    //添加第二个父节点
//    QTreeWidgetItem *imageItem2 = new QTreeWidgetItem;
//    imageItem2->setText(0,QString::fromLocal8Bit("asset entry"));
//    rootList.append(imageItem2);


//    QTreeWidgetItem *imageItem2_1 = new QTreeWidgetItem(imageItem2,QStringList(QString("sigan")));  //添加子节点
//    QTreeWidgetItem *imageItem2_2 = new QTreeWidgetItem(imageItem2,QStringList(QString("Band2")));
//    imageItem2->addChild(imageItem2_1);
//    imageItem2->addChild(imageItem2_2);

    //将结点插入部件中
    //ui->treeWidget->insertTopLevelItems(0,rootList);

    //全部展开
    //ui->treeWidget->expandAll();

    //connect(ui->treeWidget,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(showSelectedImage(QTreeWidgetItem*,int)));

}


void MainWidget::goToMain()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWidget::showSelectedImage(QTreeWidgetItem *item, int column)
{
    QTreeWidgetItem *parent = item->parent();
    if(NULL==parent) //注意：最顶端项是没有父节点的，双击这些项时注意(陷阱)
        return;
    int col = parent->indexOfChild(item); //item在父项中的节点行号(从0开始)


    if(0==col) //Band1
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    if(1==col) //Band2
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWidget::goSelect_item1()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWidget::goSelect_item2()
{
    ui->stackedWidget->setCurrentIndex(2);
}

