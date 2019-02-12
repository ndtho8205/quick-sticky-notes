#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QHash>
#include <QObject>

#include "LocalDataManager.h"
#include "Note.h"
#include "NoteWidget.h"

class MainController : public QObject {
  Q_OBJECT

 public:
  static MainController* instance();

 public slots:
  void addNewNote();
  void deleteNote();

  void showAllNote();
  void hideAllNote();

  void showAboutDialog();
  void showSettingsDialog();

 private:
  MainController();
  ~MainController();

 private:
  LocalDataManager* mDataManager;
  QHash<QString, NoteWidget*> mNoteWidgetMap;

  static MainController* mInstance;
};

#endif  // MAINCONTROLLER_H
