#ifndef LOCALDATAMANAGER_H
#define LOCALDATAMANAGER_H

#include <QDir>
#include <QHash>

#include "Note.h"

class LocalDataManager
{
public:
    static LocalDataManager *getInstance();
    static void deleteInstance();

    QList<Note *> getNotes() const;
    Note *getNoteById(QString noteId) const;

    void insertNote(Note *const note);

    void updateNote(Note *const note);

    void deleteNoteById(QString noteId);

private:
    LocalDataManager();
    ~LocalDataManager();

    QDir notesDir() const;
    Note *readNoteByFilename(QString noteFilename) const;
    Note *readNoteById(QString noteId) const;
    bool writeNote(Note *const note);

    static LocalDataManager *mInstance;
};

#endif // LOCALDATAMANAGER_H
