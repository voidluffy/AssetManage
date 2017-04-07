#include "homewidget.h"


#include <QVBoxLayout>


HomeWidget::HomeWidget(QWidget *parent) :
    QWidget(parent), m_isFirst(true)
{
    this->initUI();
}

void HomeWidget::initUI()
{

    m_scanBottomWidget = new HomeCenterItem;

    QVBoxLayout *vLayout = new QVBoxLayout;
    //vLayout->addWidget(m_topBackWidget);
    vLayout->addWidget(m_scanBottomWidget);
   // vLayout->setSpacing(0);
    vLayout->setContentsMargins(0,0,0,0);

    this->setLayout(vLayout);
}

void HomeWidget::startFirst()
{
    if(m_isFirst)
    {
        m_scanBottomWidget->startFirstAnim();
        m_isFirst = !m_isFirst;
    }
}
