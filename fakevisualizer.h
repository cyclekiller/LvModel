#ifndef FAKEVISUALIZER_H
#define FAKEVISUALIZER_H

#include "interface/visualizer.h"
#include <QRectF>

class FakeVisualizer : Visualizer
{
public:
    FakeVisualizer(int width, int height);

    ~FakeVisualizer();

public:
    bool updateRanges(const QSet<Range *> addedRange,
                      const QSet<Range *> deletedRange,
                      const QSet<Range *> updatedRange,
                      void *labeler) override;

    bool changeRangeFocus(Range *focus) override;

    bool refresh() override;

    bool clear() override;

    friend class Widget;

private:
    float top, bottom;
    QList <QRectF> regions;
};

#endif // FAKEVISUALIZER_H
