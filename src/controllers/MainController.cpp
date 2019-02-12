#include "MainController.h"

#include <QDebug>

MainController* MainController::mInstance = nullptr;

MainController::MainController() {}

MainController::~MainController() {
  if (MainController::mInstance) {
    delete mInstance;
  }
  qDeleteAll(mNoteWidgetMap);
  mNoteWidgetMap.clear();
  delete mDataManager;
}

MainController* MainController::instance() {
  if (!mInstance) {
    mInstance = new MainController();
  }
  return mInstance;
}

void MainController::addNewNote() {
  qDebug() << __func__;

  Note* note = new Note();
  NoteWidget* noteWidget = new NoteWidget(note);
  mNoteWidgetMap[note->getId()] = noteWidget;
  noteWidget->show();
}

void MainController::deleteNote() {
  qDebug() << __func__;
}

void MainController::showAllNote() {
  qDebug() << __func__;
}

void MainController::hideAllNote() {
  qDebug() << __func__;
}

void MainController::showAboutDialog() {
  qDebug() << __func__;
}

void MainController::showSettingsDialog() {
  qDebug() << __func__;
}
