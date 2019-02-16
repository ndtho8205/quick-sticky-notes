#include "LocalDataManager.h"

#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

LocalDataManager* LocalDataManager::mInstance = nullptr;

LocalDataManager::LocalDataManager() {}

LocalDataManager::~LocalDataManager() {}

QDir LocalDataManager::notesDir() const {
  QDir dir("./notes");
  if (!dir.exists()) {
    QDir().mkdir("./notes");
  }
  return dir;
}

Note* LocalDataManager::readNoteByFilename(QString noteFilename) const {
  QFile noteFile(notesDir().filePath(noteFilename));
  if (!noteFile.open(QIODevice::ReadOnly)) {
    qWarning() << "Couldn't open file: " << noteFile.fileName();
    return nullptr;
  }

  QJsonDocument loadDoc = QJsonDocument::fromJson(noteFile.readAll());
  Note* note = new Note(loadDoc.object());

  return note;
}

Note* LocalDataManager::readNoteById(QString noteId) const {
  return readNoteByFilename(QString("%1.json").arg(noteId));
}

bool LocalDataManager::writeNote(Note* const note) {
  QFile noteFile(notesDir().filePath(QString("%1.json").arg(note->id())));
  if (!noteFile.open(QIODevice::WriteOnly)) {
    qWarning() << "Couldn't open file to write: " << noteFile.fileName();
    return false;
  }

  QJsonObject noteObject;
  note->write(noteObject);
  QJsonDocument saveDoc(noteObject);

  noteFile.write(saveDoc.toJson());
  return true;
}

//
//
//

LocalDataManager* LocalDataManager::getInstance() {
  if (!mInstance) {
    mInstance = new LocalDataManager();
  }
  return mInstance;
}

void LocalDataManager::deleteInstance() {
  delete mInstance;
  mInstance = nullptr;
}

QList<Note*> LocalDataManager::getNotes() const {
  QList<Note*> notes;

  QStringList noteFiles = notesDir().entryList(QStringList() << "*.json"
                                                             << "*.JSON",
                                               QDir::Files);
  foreach (QString noteFilename, noteFiles) {
    Note* note = readNoteByFilename(noteFilename);
    if (note)
      notes.append(note);
  }

  return notes;
}

Note* LocalDataManager::getNoteById(QString noteId) const {
  return readNoteById(noteId);
}

void LocalDataManager::insertNote(Note* const note) {
  writeNote(note);
}

void LocalDataManager::updateNote(Note* const note) {
  writeNote(note);
}

void LocalDataManager::deleteNoteById(QString noteId) {
  QFile deleteFile(QString("./notes/%1.json").arg(noteId));
  deleteFile.remove();
}
