#include "MainController.h"

#include <QDebug>

MainController* MainController::mInstance = nullptr;

MainController::MainController() {
  mSettingsDialog = nullptr;
  mDataManager = LocalDataManager::getInstance();
}

MainController::~MainController() {
  if (mSettingsDialog) {
    delete mSettingsDialog;
  }

  qDeleteAll(mNoteWidgetMap);
  mNoteWidgetMap.clear();

  mDataManager->deleteInstance();

  if (MainController::mInstance) {
    delete mInstance;
  }
}

MainController* MainController::getInstance() {
  if (!mInstance) {
    mInstance = new MainController();
  }
  return mInstance;
}

void MainController::run() {
  QList<Note*> notes = mDataManager->getNotes();
  if (notes.empty()) {
    createNote();
  } else {
    foreach (Note* note, notes) { showNote(note); }
  }

  qDebug() << __PRETTY_FUNCTION__ << " is running...";
}

void MainController::createNote() {
  Note* note = new Note();
  mDataManager->insertNote(note);
  showNote(note);
}

void MainController::showNote(Note* note) {
  NoteWidget* noteWidget = new NoteWidget(note);
  mNoteWidgetMap[note->id()] = noteWidget;
  noteWidget->show();
}

void MainController::updateNote(Note* note) {
  mDataManager->updateNote(note);
}

void MainController::deleteNote(QString noteId) {
  delete mNoteWidgetMap.take(noteId);

  mDataManager->deleteNoteById(noteId);
}

void MainController::showAllNote() {
  qDebug() << __PRETTY_FUNCTION__;
}

void MainController::hideAllNote() {
  qDebug() << __PRETTY_FUNCTION__;
}

void MainController::showAboutDialog() {
  qDebug() << __PRETTY_FUNCTION__;
}

void MainController::showSettingsDialog() {
  if (!mSettingsDialog) {
    mSettingsDialog = new SettingsDialog();
    //    connect(mSettingsDialog, &SettingsDialog::finished, this,
    //            &MainController::settingsDialogIsFinished);
    mSettingsDialog->show();
  }
}

void MainController::settingsDialogIsFinished(int result) {
  qDebug() << __PRETTY_FUNCTION__;
  if (result == QDialog::Accepted) {
  }
  //  delete mSettingsDialog;
}
