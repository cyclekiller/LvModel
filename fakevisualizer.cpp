#include "fakevisualizer.h"
#include "interface/labeler.h"

FakeVisualizer::FakeVisualizer(int width, int height) : Visualizer() {
    top = height / 3 - height / 12;
    bottom = top + height / 6;
    this->width = width;
}

FakeVisualizer::~FakeVisualizer() {
    foreach (auto region, rangeToRegion) {
        delete region;
    }
    foreach (auto ranges, allLabelerRanges) {
        delete ranges;
    }
}

bool FakeVisualizer::updateRanges(const QSet<Range *> &addedRange,
                                  const QSet<Range *> &deletedRange,
                                  const QSet<Range *> &updatedRange, void *labeler) {
    if (!allLabelerRanges.contains(labeler))
        allLabelerRanges.insert(labeler, new QSet<Range *>());
    auto ranges = allLabelerRanges[labeler];
    if (!addedRange.isEmpty()) {
        *ranges += addedRange;
        foreach (auto range, addedRange) {
            auto region = new QRectF(QPointF(range->begin, top), QPointF(range->end, bottom));
            rangeToRegion.insert(range, region);
            regionToRange.insert(region, range);
        }
    }
    if (!deletedRange.isEmpty()) {
        *ranges -= deletedRange;
        foreach (auto region, rangeToRegion) {
            auto range = regionToRange[region];
            if (deletedRange.contains(range)) {
                regionToRange.remove(region);
                rangeToRegion.remove(range);
            }
        }
    }
    if (!updatedRange.isEmpty()) {
        foreach (auto range, updatedRange) {
            auto region = rangeToRegion[range];
            *region = QRectF(QPointF(range->begin, top), QPointF(range->end, bottom));
        }
    }
    return true;
}

bool FakeVisualizer::changeRangeFocus(Range *focus) {
    this->focus = focus;
    return true;
};

bool FakeVisualizer::update() {
    rangeToRegion.clear();
    regionToRange.clear();
    foreach (auto labeler, allLabelerRanges.keys()) {
        auto ranges = allLabelerRanges[labeler];
        foreach (auto range, *ranges) {
            auto region = new QRectF(QPointF(range->begin, top), QPointF(range->end, bottom));
            rangeToRegion.insert(range, region);
            regionToRange.insert(region, range);
        }
    }
    return true;
}

bool FakeVisualizer::clear() {
    foreach (auto region, rangeToRegion) {
        delete region;
    }
    foreach (auto ranges, allLabelerRanges) {
        delete ranges;
    }
    allLabelerRanges.clear();
    rangeToRegion.clear();
    regionToRange.clear();
    focus = nullptr;
    return true;
}

void FakeVisualizer::mock() { // temporary
    clear();
    int n = 4;
    float w = width / (n + 1);
    for (int i = 0; i < n - 1; i++) {
        float x = width / (n + 1) * (i + 1);
        auto range = new Range(x, x + w, 0);
        if (i == 0)
            changeRangeFocus(range);
        updateRanges(QSet<Range *>{range}, QSet<Range *>{}, QSet<Range *>{}, nullptr);
    }
}
