#ifndef LABELER_H
#define LABELER_H

#include "labelinfo.h"
#include "range.h"
#include "visualizer.h"

class Labeler {
public:
    Labeler();

    virtual ~Labeler();

public:
    bool link(Visualizer *visualizer);

    bool unlink(Visualizer *visualizer);

    QList<Range *> getRanges(int type = -1, int hierarchy = -1) const;

    LabelInfo getLabelInfo(Range *range) const;

    virtual bool changeRangeFocus(Range *focus);

    friend class Channel;

protected:
    QSet<Visualizer *> linkedVisualizers;
    QList<Range *> ranges;
    QMap<Range *, LabelInfo *> labelInfos;
    Range *focus = 0;
};

#endif // LABELER_H
