#ifndef TODOWEBVIEW_H
#define TODOWEBVIEW_H

#include <QtWebEngineWidgets/QWebEngineView>

class TodoWebView : public QWebEngineView {
  Q_OBJECT
 public:
  explicit TodoWebView(QWidget* parent = nullptr);

  void run();
 signals:

 public slots:
};

#endif  // TODOWEBVIEW_H
