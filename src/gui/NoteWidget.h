#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <CustomSizeGrip.h>
#include <QWidget>

#include "Note.h"

namespace Ui {
class NoteWidget;
}

class NoteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NoteWidget(Note *note = new Note(), QWidget *parent = nullptr);
    ~NoteWidget();

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void createNoteWidget();
    void switchLockStatusNoteWidget();
    void deleteNoteWidget();

    void resizeNoteWidget();

    void expandMenuNoteWidget();
    void openSettingsDialog();

private:
    void lock();
    void unlock();
    void updateNoteContent();

    Ui::NoteWidget *ui;
    CustomSizeGrip *mSizeGrip;

    Note *mNote;
    QPoint mPosition;
    bool mDragging;
};

#endif // NOTEWIDGET_H
