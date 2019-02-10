#include "LocalDataManager.h"

LocalDataManager::LocalDataManager() {}

LocalDataManager::~LocalDataManager() {
  qDeleteAll(mNoteList);
  mNoteList.clear();
}

QList<Note*> LocalDataManager::noteList() const {
  return mNoteList;
}

void LocalDataManager::appendNote(Note* const note) {
  mNoteList.append(note);
}
