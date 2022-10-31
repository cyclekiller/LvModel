#include "fakelabeler.h"

FakeLabeler::FakeLabeler(int width, int height) : Labeler() {
    top = height / 3 * 2 - height / 12;
    bottom = top + height / 6;
    this->width = width;
}

FakeLabeler::~FakeLabeler() {
    foreach (auto range, ranges) {
        delete range;
    }
}

void FakeLabeler::mock() {
    ranges.clear();
    splitLines.clear();
    int n = 4;
    float w = width / (n + 1);
    for (int i = 0; i < n - 1; i++) {
        float x = width / (n + 1) * (i + 1);
        auto range = new Range(x, x + w, 0);
        if (!ranges.empty()) {
            range->setLeftNeighbor(ranges.last());
            splitLines.append(QRectF(x - w / 10, top, w / 5, bottom - top));
        }
        ranges.append(range);
    }
    changeRangeFocus(ranges[0]);
}
