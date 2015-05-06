#ifndef LOGINCREDS_H
#define LOGINCREDS_H
#include "QString"

class LoginCreds
{
public:
    LoginCreds(QString name, QString pass);
    LoginCreds();
    void setUsername(QString name);
    void setPassword(QString pass);
    QString getUsername();
    QString getPassword();
private:
    QString username;
    QString password;
};

#endif // LOGINCREDS_H
