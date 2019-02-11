#include "MainController.h"

MainController* MainController::mInstance = nullptr;

MainController::MainController() {}

MainController::~MainController() {
  if (MainController::mInstance) {
    delete mInstance;
  }
}

MainController* MainController::instance() {
  if (!mInstance) {
    mInstance = new MainController();
  }
  return mInstance;
}

void MainController::addNote() {
  Note* note = new Note();
  NoteWidget* noteWidget = new NoteWidget(note);
  mNoteWidgetList.append(noteWidget);
  noteWidget->show();
}

void MainController::deleteNote() {}
