#include "loginscreen.h"
#include "ui_loginscreen.h"
#include "logincreds.h"
#include "mainwindow.h"
#include <QFile>
#include <QString>
#include <QTextStream>

/*
 * Although our initial intent was to have multiple levels of users with specific information being displayed for each,
 * we could not figure out quite how to do it right.
 */

LoginScreen::LoginScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginScreen)
{
    //set up the ui and set the error label text color to red
    ui->setupUi(this);
    ui->errorLabel->setStyleSheet("QLabel { color : red; }");

    //if possible, open up the file which stores the room information (i.e. room numbers, styles, and costs)
    QString fileName = ":/storedInfo/LoginInfo.txt";
    QFile mFile(fileName);
    if (!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        ui->errorLabel->setText("*FILE -LOGIN INFO- NOT FOUND/OPERABLE ERROR*");
        return;
    }
    /*similarly to in mainwindow, create new objects for each user in the text file. call the store function
     *to store the information into objects. close the file.
     */
    QTextStream in(&mFile);
    LoginCreds userOne;
    storeUser(userOne,in);
    allUsers.push_back(userOne);
    LoginCreds userTwo;
    storeUser(userTwo,in);
    allUsers.push_back(userTwo);
    LoginCreds userThree;
    storeUser(userThree,in);
    allUsers.push_back(userThree);
    LoginCreds userFour;
    storeUser(userFour,in);
    allUsers.push_back(userFour);
    LoginCreds userFive;
    storeUser(userFive,in);
    allUsers.push_back(userFive);
    mFile.close();
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::on_okButton_clicked()
{
    //initialize a for loop to iterate through each user in the system if necessary
    for (unsigned int i=0; i<allUsers.size(); i++)
    {
        //create qstrings to store username information. check to see if the entered username matches the current username in the system
        LoginCreds newUser = allUsers.at(i);
        QString creds = newUser.getUsername();
        QString input = ui->usernameLine->text();
        if (creds==input)
        {
            //alter qstring variables to store password information. check to see if the entered password matches the current password in the system
            creds = newUser.getPassword();
            input = ui->passwordLine->text();
            if (creds==input)
            {
                //if the username/password combo is valid, create a mainwindow and show it. close the login screen and break from the loop
                MainWindow *w = new MainWindow;
                w->show();
                this->close();
                break;
            }
            //both following else statememts are simply error display for the user
            else
            {
                ui->errorLabel->setText("USERNAME AND/OR PASSWORD INCORRECT");
            }
        }
        else
        {
            ui->errorLabel->setText("USERNAME AND/OR PASSWORD INCORRECT");
        }
    }
}

void LoginScreen::storeUser(LoginCreds& currentUser, QTextStream& in)
{
    //nearly identical to the store function used in mainwindow. iterate through the text file and store the user information into user objects
    QString line = in.readLine();
    QStringList list = line.split(",");
    for (int i = 0; i < list.size(); i++)
    {
        QString value = list.at(i);
        if (i == 0)
        {
            currentUser.setUsername(value);
        }
        else
        {
            currentUser.setPassword(value);
        }
    }
}
