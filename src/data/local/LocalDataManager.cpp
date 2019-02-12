#include "LocalDataManager.h"

#include <QDebug>

LocalDataManager::LocalDataManager() {}

LocalDataManager::~LocalDataManager() {
  qDeleteAll(mNoteMap);
  mNoteMap.clear();
}

QList<Note*> LocalDataManager::getNoteList() const {
  return mNoteMap.values();
}

Note* LocalDataManager::getNoteById(QString noteId) const {
  return mNoteMap.value(noteId, nullptr);
}

void LocalDataManager::appendNewNote(Note* const note) {
  mNoteMap[note->getId()] = note;
}

void LocalDataManager::updateNote(QString nodeId) {
  qDebug() << __func__;
}
