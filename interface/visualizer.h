#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "range.h"

class Visualizer {
public:
    Visualizer();

    virtual ~Visualizer();

public:
    virtual bool updateRanges(const QSet<Range *> &added, const QSet<Range *> &deleted,
                              const QSet<Range *> &updated, void *labeler) = 0;

    virtual bool changeRangeFocus(Range *focus) = 0;

    virtual bool refresh() = 0;

    virtual bool clear() = 0;

protected:
    QMap<void *, QSet<Range *>> allLabelerRanges;
    Range *focus = 0;
};

#endif // VISUALIZER_H
