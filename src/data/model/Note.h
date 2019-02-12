#ifndef NOTE_H
#define NOTE_H

#include <QString>

class Note {
 public:
  Note();

  QString getId() const;

  QString getContent() const;
  void setContent(const QString& content);

  bool isLock() const;
  void setLockStatus(bool lock);

 private:
  QString mId;
  QString mContent;
  bool mLock;
};

#endif  // NOTE_H
