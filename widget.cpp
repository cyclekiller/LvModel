#include "widget.h"

#include <QKeyEvent>
#include <QPainter>
#include <QPen>

#include "fakelabeler.h"
#include "fakevisualizer.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  int width = 800, height = 600;
  resize(width, height);

  fakeVis = new FakeVisualizer(width, height);
  fakeLab = new FakeLabeler(width, height);
}

Widget::~Widget() {
  delete ui;
  delete fakeVis;
  delete fakeLab;
}

void Widget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QPen pen;
  QBrush brush;

  pen.setColor(Qt::green);
  brush.setColor(Qt::blue);
  brush.setStyle(Qt::SolidPattern);
  painter.setPen(pen);
  painter.setBrush(brush);

  for (int i = 0; i < fakeVis->regions.length(); i++) {
    painter.drawRect(fakeVis->regions[i]);
  }

  pen.setColor(Qt::yellow);
  brush.setColor(Qt::red);
  brush.setStyle(Qt::SolidPattern);
  painter.setPen(pen);
  painter.setBrush(brush);
  for (int i = 0; i < fakeLab->splits.length(); i++) {
    painter.drawRect(fakeLab->splits[i]);
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
