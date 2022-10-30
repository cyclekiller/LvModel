#include "fakelabeler.h"

FakeLabeler::FakeLabeler(int width, int height) : Labeler() {
    top = height / 3 * 2 - height / 12;
    bottom = top + height / 6;

    // temporary: add splits
    int n = 4;
    float w = width / (n + 1) / 10;
    for (int i = 1; i < n - 1; i++) {
      float x = width / (n + 1) * (i + 1) - w / 2;
      splits.append(QRectF(QPointF(x, top), QPoint(x + w, bottom)));
    }
}

FakeLabeler::~FakeLabeler() {}

bool FakeLabeler::setRangeFocus(Range *focus) {
    this->focus = focus;
    return true;
}
