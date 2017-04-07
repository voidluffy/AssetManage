#ifndef ASIGNASSETWIDGET_H
#define ASIGNASSETWIDGET_H

#include <QWidget>

namespace Ui {
class AsignAssetWidget;
}

class AsignAssetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AsignAssetWidget(QWidget *parent = 0);
    ~AsignAssetWidget();

private:
    Ui::AsignAssetWidget *ui;
signals:
    void goToMain();
};

#endif // ASIGNASSETWIDGET_H
