#ifndef FAKELABELER_H
#define FAKELABELER_H

#include "interface/labeler.h"
#include "interface/range.h"
#include <QRectF>

class FakeLabeler : Labeler {
 public:
  FakeLabeler(int width, int height);

  ~FakeLabeler();

 public:
  bool setRangeFocus(Range *focus) override;

  friend class Widget;

private:
  float top, bottom;
  QList <QRectF> splits;
};

#endif  // FAKELABELER_H
