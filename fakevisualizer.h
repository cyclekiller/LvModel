#ifndef FAKEVISUALIZER_H
#define FAKEVISUALIZER_H

#include <QRectF>

#include "interface/visualizer.h"

class FakeVisualizer : public Visualizer {
public:
    FakeVisualizer(int width, int height);

    ~FakeVisualizer();

public:
    bool updateRanges(const QSet<Range *> &addedRange, const QSet<Range *> &deletedRange,
                      const QSet<Range *> &updatedRange, void *labeler) override;

    bool changeRangeFocus(Range *focus) override;

    bool refresh() override;

    bool clear() override;

    void mock();

    friend class Widget;

private:
    float top, bottom, width;
    QMap<Range *, QRectF *> rangeToRegion;
    QMap<QRectF *, Range *> regionToRange;
};

#endif // FAKEVISUALIZER_H
