#ifndef LOOKUPASSETWIDGET_H
#define LOOKUPASSETWIDGET_H

#include <QWidget>

namespace Ui {
class LookupAssetWidget;
}

class LookupAssetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LookupAssetWidget(QWidget *parent = 0);
    ~LookupAssetWidget();

private:
    Ui::LookupAssetWidget *ui;
private slots:
    void sMain();
signals:
    void goToMain();
};

#endif // LOOKUPASSETWIDGET_H
