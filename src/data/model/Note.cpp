#include "Note.h"

#include <QUuid>

Note::Note() {
  mId = QUuid::createUuid().toString();
  mContent = "";
  mLock = false;
}

QString Note::getId() const {
  return mId;
}

QString Note::getContent() const {
  return mContent;
}

void Note::setContent(const QString& content) {
  mContent = content;
}

bool Note::isLock() const {
  return mLock;
}

void Note::setLockStatus(bool lock) {
  mLock = lock;
}
