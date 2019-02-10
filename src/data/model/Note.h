#ifndef NOTE_H
#define NOTE_H

#include <QString>

class Note {
 public:
  Note();

  QString getContent() const;
  void setContent(const QString& content);

  bool getLock() const;
  void setLock(bool lock);

 private:
  QString mContent;
  bool mLock;
};

#endif  // NOTE_H
