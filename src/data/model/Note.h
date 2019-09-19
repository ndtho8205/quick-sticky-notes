#ifndef NOTE_H
#define NOTE_H

#include <QJsonObject>
#include <QString>

#include "Properties.h"

class Note
{
public:
    explicit Note();
    explicit Note(const QJsonObject &json);

    QString id() const;

    QString content() const;
    void setContent(const QString &content);

    Properties *properties();

    void write(QJsonObject &json) const;

private:
    QString mId;
    QString mContent;

    Properties mProperties;
};

#endif // NOTE_H
