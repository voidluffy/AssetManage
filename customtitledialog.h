#ifndef CUSTOMTITLEDIALOG_H
#define CUSTOMTITLEDIALOG_H

#include <QDialog>
#include <QMoveEvent>

namespace Ui {
class CustomTitleDialog;
}

class CustomTitleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomTitleDialog(QWidget *parent = 0);
    ~CustomTitleDialog();

    QWidget *getContentWidget();
    QDialog *getContentDialog();

    void setTitle(QString str);

    void showMaximized();

    void changeMax();

    virtual void doClose();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *e);

private slots:
    void on_btnMenu_Close_clicked();

    void on_btnMenu_Max_clicked();

    void on_btnMenu_Min_clicked();

private:
    Ui::CustomTitleDialog *ui;

    QPoint mousePoint;
    bool mousePressed;
    bool max;
    QRect location;

    QDialog *dialog;

    void InitStyle();

};

#endif // CUSTOMTITLE_H
