#ifndef LOCALDATAMANAGER_H
#define LOCALDATAMANAGER_H

#include <QHash>

#include "Note.h"

class LocalDataManager {
 public:
  LocalDataManager();
  ~LocalDataManager();

  QList<Note*> getNoteList() const;
  Note* getNoteById(QString noteId) const;
  void appendNewNote(Note* const note);
  void updateNote(QString nodeId);

 private:
  QHash<QString, Note*> mNoteMap;
};

#endif  // LOCALDATAMANAGER_H
