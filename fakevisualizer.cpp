#include "fakevisualizer.h"

FakeVisualizer::FakeVisualizer(int width, int height) : Visualizer() {
  top = height / 3 - height / 12;
  bottom = top + height / 6;
  this->width = width;
}

FakeVisualizer::~FakeVisualizer() {
    foreach(auto range, regionToRange){
        delete range;
    }
    foreach(auto region, rangeToRegion){
        delete region;
    }
}

bool FakeVisualizer::updateRanges(const QSet<Range *> addedRange,
                                  const QSet<Range *> deletedRange,
                                  const QSet<Range *> updatedRange,
                                  void *labeler) {
  if (!addedRange.empty()) {
    foreach (auto range, addedRange) {
      auto region =
          new QRectF(QPointF(range->begin, top), QPointF(range->end, bottom));
      rangeToRegion.insert(range, region);
      regionToRange.insert(region, range);
    }
  }
  if (!updatedRange.empty()) {
    foreach (auto range, updatedRange) {
      auto region = rangeToRegion[range];
      *region = QRectF(QPointF(range->begin, top), QPointF(range->end, bottom));
    }
  }
  if (!deletedRange.empty()) {
    foreach (auto region, rangeToRegion) {
      auto range = regionToRange[region];
      if (deletedRange.contains(range)) {
        regionToRange.remove(region);
        rangeToRegion.remove(range);
      }
    }
  }
  return true;
}

bool FakeVisualizer::changeRangeFocus(Range *focus) {
  this->focus = focus;
  return true;
}

bool FakeVisualizer::refresh() { return true; }

bool FakeVisualizer::clear() {
    rangeToRegion.clear();
    regionToRange.clear();
    focus = nullptr;
    return true;
}

void FakeVisualizer::mock() {
    clear();
    int n = 4;
    float w = width / (n + 1);
    for (int i = 0; i < n - 1; i++) {
      float x = width / (n + 1) * (i + 1);
      auto range = new Range(x, x + w, 0);
      updateRanges(QSet<Range *>{range}, QSet<Range *>{}, QSet<Range *>{}, this);
    }
}
