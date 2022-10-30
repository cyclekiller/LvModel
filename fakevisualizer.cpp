#include "fakevisualizer.h"

FakeVisualizer::FakeVisualizer(int width, int height) : Visualizer() {
  top = height / 3 - height / 12;
  bottom = top + height / 6;

  // temporary: mock regions
  int n = 4;
  float w = width / (n + 1);
  for (int i = 0; i < n - 1; i++) {
    float x = width / (n + 1) * (i + 1);
    Range range(x, x + w, 0);
    updateRanges(QSet<Range *>{&range}, QSet<Range *>{}, QSet<Range *>{},
                 this);
  }
}

FakeVisualizer::~FakeVisualizer() {}

bool FakeVisualizer::updateRanges(const QSet<Range *> addedRange,
                                  const QSet<Range *> deletedRange,
                                  const QSet<Range *> updatedRange,
                                  void *labeler) {
  if (!addedRange.empty()) {
    foreach (const Range *range, addedRange)
      regions.append(
          QRectF(QPointF(range->begin, top), QPointF(range->end, bottom)));
  }
  if (!updatedRange.empty()) {
  }
  return true;
}

bool FakeVisualizer::changeRangeFocus(Range *focus) { return true; }

bool FakeVisualizer::refresh() { return true; }

bool FakeVisualizer::clear() { return true; }

