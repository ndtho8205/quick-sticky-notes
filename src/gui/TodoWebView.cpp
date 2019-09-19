#include "TodoWebView.h"

TodoWebView::TodoWebView(QWidget *parent) : QWebEngineView(parent) {}

void TodoWebView::run()
{
    load(QUrl("http://localhost:8080/"));
    show();
}
