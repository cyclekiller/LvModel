#ifndef WIDGET_H
#define WIDGET_H

#include <QScopedPointer>
#include <QWidget>

#include "fakelabeler.h"
#include "fakevisualizer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *event);

    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Widget *ui;

    QScopedPointer<FakeVisualizer> fakeVis;
    QScopedPointer<FakeLabeler> fakeLab;
};
#endif // WIDGET_H
