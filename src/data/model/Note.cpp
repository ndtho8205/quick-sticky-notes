#include "Note.h"

#include <QUuid>

Note::Note() {
  mId = QUuid::createUuid().toString(QUuid::WithoutBraces);
  mContent = "";
}

Note::Note(const QJsonObject& json) {
  if (json.contains("id") && json["id"].isString())
    mId = json["id"].toString();
  if (json.contains("content") && json["content"].isString())
    mContent = json["content"].toString();

  mProperties = Properties(json["properties"].toObject());
}

QString Note::id() const {
  return mId;
}

QString Note::content() const {
  return mContent;
}

void Note::setContent(const QString& content) {
  mContent = content;
}

Properties* Note::properties() {
  return &mProperties;
}

void Note::write(QJsonObject& json) const {
  json["id"] = mId;
  json["content"] = mContent;

  QJsonObject propertiesObject;
  mProperties.write(propertiesObject);
  json["properties"] = propertiesObject;
}
