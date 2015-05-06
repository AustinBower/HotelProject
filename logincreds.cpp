#include "logincreds.h"

//parameterized constructor
LoginCreds::LoginCreds(QString name, QString pass)
{
    username = name;
    password = pass;
}

//default constructor
LoginCreds::LoginCreds()
{
    username = "";
    password = "";
}

//setters and getters for username and password variables
void LoginCreds::setUsername(QString name)
{
    username = name;
}

void LoginCreds::setPassword(QString pass)
{
    password = pass;
}

QString LoginCreds::getUsername()
{
    return username;
}

QString LoginCreds::getPassword()
{
    return password;
}


