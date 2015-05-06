#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H
#include "logincreds.h"
#include <QDialog>
#include <vector>
#include <QTextStream>

namespace Ui {
class LoginScreen;
}

class LoginScreen : public QDialog
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = 0);
    ~LoginScreen();
    void storeUser(LoginCreds& currentCreds, QTextStream& in);
    std::vector <LoginCreds> allUsers;

private slots:
    void on_okButton_clicked();

private:
    Ui::LoginScreen *ui;
};

#endif // LOGINSCREEN_H
