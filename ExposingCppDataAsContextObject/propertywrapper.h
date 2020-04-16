#ifndef PROPERTYWRAPPER_H
#define PROPERTYWRAPPER_H

#include <QObject>
#include <QTimer>

class PropertyWrapper : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString  lastname READ lastname WRITE setLastname NOTIFY lastnameChanged)
    Q_PROPERTY(QString firstname READ firstname WRITE setFirstname NOTIFY firstnameChanged)


public:
    explicit PropertyWrapper(QObject *parent = nullptr);

    QString lastname() const;
    QString firstname() const;

signals:

    void lastnameChanged(QString lastname);
    void firstnameChanged(QString firstname);

public slots:
    void setLastname(QString lastname);
    void setFirstname(QString firstname);

private:
    QString m_lastname;
    QString m_firstname;

    QTimer * m_timer;
    int m_random_number;
};

#endif // PROPERTYWRAPPER_H
