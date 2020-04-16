#include <QTimer>
#include <QDebug>
#include <stdlib.h>
#include <time.h>
#include "propertywrapper.h"

PropertyWrapper::PropertyWrapper(QObject *parent) : QObject(parent),
    m_lastname("LastName"),
    m_firstname("FirstName"),
    m_timer(new QTimer(this)),
    m_random_number(0)
{

    qDebug() << "1";
    //Initialize
    srand(time(NULL));

    qDebug() << "2";
    QStringList strList;

    strList << "Kowalska" << "Bździoch" << "Król" << "Buć";

    qDebug() << "3";
    connect(m_timer, &QTimer::timeout,[=](){
        qDebug() << "m_random_number: ";
        m_random_number = rand() % (strList.size());
        qDebug() << m_random_number;
        setLastname(strList[m_random_number]);
    });

    qDebug() << "4";
    m_timer->start(500);

}

QString PropertyWrapper::lastname() const
{
    return m_lastname;
}

QString PropertyWrapper::firstname() const
{
    return m_firstname;
}

void PropertyWrapper::setLastname(QString lastname)
{
    if (m_lastname == lastname)
        return;

    m_lastname = lastname;
    emit lastnameChanged(m_lastname);
}

void PropertyWrapper::setFirstname(QString firstname)
{
    if (m_firstname == firstname)
        return;

    m_firstname = firstname;
    emit firstnameChanged(m_firstname);
}
