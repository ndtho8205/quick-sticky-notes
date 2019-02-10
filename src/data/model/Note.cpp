#include "Note.h"

Note::Note() {}

QString Note::getContent() const {
  return mContent;
}

void Note::setContent(const QString& content) {
  mContent = content;
}

bool Note::getLock() const {
  return mLock;
}

void Note::setLock(bool lock) {
  mLock = lock;
}
