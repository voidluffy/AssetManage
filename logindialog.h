#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include "basewindow.h"

#include <QDialog>


// 登录状态;
typedef enum
{
    ONLINE = 1,     //在线;
    ACTIVE,			//活跃;
    AWAY,           //离开;
    BUSY,           //忙碌;
    NOT_DISTURB,	//请勿打扰;
    HIDE,           //隐身;
    OFFLINE			//离线;
}LoginState;


namespace Ui {
class LoginDialog;
}

class LoginDialog :  public BaseWindow
{
    Q_OBJECT

public:
    LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private:
    void initMyTitle() ;
    void initWindow();

private:
    Ui::LoginDialog *ui;
    // 密码框小键盘按钮;
    QPushButton* m_keyboardButton;

};
#endif // LOGINDIALOG_H
