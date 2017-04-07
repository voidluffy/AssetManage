#ifndef LoginWindow_H
#define LoginWindow_H

#include "basewindow.h"

namespace Ui {
	class LoginWindow;
}


class LoginWindow : public BaseWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_LoginpushButton_clicked();

private:
    void initMyTitle() ;
	void initWindow();

private:
	Ui::LoginWindow *ui;
	// ÃÜÂë¿òÐ¡¼üÅÌ°´Å¥;
	QPushButton* m_keyboardButton;

};

#endif // LoginWindow_H
