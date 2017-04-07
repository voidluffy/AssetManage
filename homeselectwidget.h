#ifndef HOMESELECTWIDGET_H
#define HOMESELECTWIDGET_H

#include <QWidget>

namespace Ui {
class HomeSelectWidget;
}

class HomeSelectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HomeSelectWidget(QWidget *parent = 0);
    ~HomeSelectWidget();

private:
    Ui::HomeSelectWidget *ui;


signals:
    void select_item1();
    void select_item2();
};

#endif // HOMESELECTWIDGET_H
