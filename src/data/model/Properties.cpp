#include "Properties.h"

#include <QJsonArray>

Properties::Properties()
{
    mLocked = false;
    mPosition = QPoint(0, 0);
    mSize = QSize(300, 300);
}

Properties::Properties(const QJsonObject &json)
{
    if (json.contains("locked") && json["locked"].isBool())
        mLocked = json["locked"].toBool();

    if (json.contains("last_modified") && json["last_modified"].isString())
        mLastModified = json["last_modified"].toString();

    if (json.contains("position") && json["position"].isArray()) {
        QJsonArray positionArray = json["position"].toArray();
        mPosition = QPoint(positionArray[0].toInt(), positionArray[1].toInt());
    }

    if (json.contains("size") && json["size"].isArray()) {
        QJsonArray sizeArray = json["size"].toArray();
        mSize = QSize(sizeArray[0].toInt(), sizeArray[1].toInt());
    }
}

bool Properties::locked() const
{
    return mLocked;
}

void Properties::lock()
{
    mLocked = true;
}

void Properties::unlock()
{
    mLocked = false;
}

QPoint Properties::position() const
{
    return mPosition;
}

void Properties::setPosition(const QPoint &position)
{
    mPosition = position;
}

QSize Properties::size() const
{
    return mSize;
}

void Properties::setSize(const QSize &size)
{
    mSize = size;
}

QString Properties::lastModified() const
{
    return mLastModified;
}

void Properties::setLastModified(const QString &lastModified)
{
    mLastModified = lastModified;
}

void Properties::write(QJsonObject &json) const
{
    json["locked"] = mLocked;
    json["last_modified"] = mLastModified;
    json["position"] = QJsonArray({ mPosition.x(), mPosition.y() });
    json["size"] = QJsonArray({ mSize.width(), mSize.height() });
}
