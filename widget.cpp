#include "widget.h"

#include <QKeyEvent>
#include <QPainter>
#include <QPen>

#include "fakelabeler.h"
#include "fakevisualizer.h"
#include "interface/channel.h"
#include "ui_widget.h"

#define USING(painter, pen, penColor, brush, brushColor)                                           \
    pen.setColor(Qt::penColor);                                                                    \
    brush.setColor(Qt::brushColor);                                                                \
    painter.setPen(pen);                                                                           \
    painter.setBrush(brush);

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    int width = 800, height = 600;
    resize(width, height);

    fakeLab.reset(new FakeLabeler(width, height));
    fakeVis.reset(new FakeVisualizer(width, height));
    fakeLab->link(fakeVis.data()); // link labeler and visualizer
    fakeLab->mock();               // mock user input

    // fakeVis->mock(); no need to call because fakeLab and fakeVis are linked
    Channel channel(QSet<Labeler *>{fakeLab.data()}, QSet<Visualizer *>{fakeVis.data()});
    channel.show();
}

Widget::~Widget() {
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pen;
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    USING(painter, pen, black, brush, gray)
    painter.drawRect(QRectF(0, fakeVis->top, this->width(), fakeVis->bottom - fakeVis->top));
    painter.drawRect(QRectF(0, fakeLab->top, this->width(), fakeLab->bottom - fakeLab->top));

    USING(painter, pen, blue, brush, green) foreach (auto region, fakeVis->regionToRange.keys()) {
        painter.drawRect(*region);
    }

    USING(painter, pen, yellow, brush, red) foreach (auto splitLine, fakeLab->splitLines) {
        painter.drawRect(splitLine);
    }

    if (fakeVis->focus != nullptr) {
        USING(painter, pen, blue, brush, blue)
        painter.drawRect(*fakeVis->rangeToRegion[fakeVis->focus]);
    }
}

void Widget::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Up:
            break;
        case Qt::Key_Down:
            break;
        case Qt::Key_Left:
            break;
        case Qt::Key_Right:
            break;
        case Qt::Key_Space:
            break;
        default:
            break;
    }
}
