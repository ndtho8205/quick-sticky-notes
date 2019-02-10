#ifndef LOCALDATAMANAGER_H
#define LOCALDATAMANAGER_H

#include <QList>
#include "Note.h"

class LocalDataManager {
 public:
  LocalDataManager();
  ~LocalDataManager();

  QList<Note*> noteList() const;
  void appendNote(Note* const note);

 private:
  QList<Note*> mNoteList;
};

#endif  // LOCALDATAMANAGER_H
