#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QList>
#include <QObject>
#include "LocalDataManager.h"
#include "Note.h"
#include "NoteWidget.h"

class MainController : public QObject {
  Q_OBJECT

 public:
  static MainController* instance();

  void addNote();
  void deleteNote();

 private:
  MainController();
  ~MainController();

 private:
  LocalDataManager* mDataManager;
  QList<NoteWidget*> mNoteWidgetList;

  static MainController* mInstance;
};

#endif  // MAINCONTROLLER_H
