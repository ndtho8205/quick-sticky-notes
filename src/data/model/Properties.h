#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QJsonObject>
#include <QPoint>
#include <QSize>
#include <QString>

class Properties
{
public:
    explicit Properties();
    explicit Properties(const QJsonObject &json);

    bool locked() const;
    void lock();
    void unlock();

    QPoint position() const;
    void setPosition(const QPoint &position);

    QSize size() const;
    void setSize(const QSize &size);

    QString lastModified() const;

    void setLastModified(const QString &lastModified);

    void write(QJsonObject &json) const;

private:
    bool mLocked;
    QString mLastModified;
    QPoint mPosition;
    QSize mSize;
};

#endif // PROPERTIES_H
