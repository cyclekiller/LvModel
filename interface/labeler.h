#ifndef LABELER_H
#define LABELER_H

#include "labelinfo.h"
#include "range.h"
#include "visualizer.h"

/**
 * @brief The Labeler class holds same labeling data, edits the data and sends the data to its linked visualizers
 * for displaying the data in context. (see also visualizer.h)
 * 
 * The labeler can have all sorts of data, but it can only send Range classes (see range.h)
 * to its linked visualizers. This is to prevent labelers from entangling with visualizers.
 */
class Labeler {
public:
    Labeler();

    virtual ~Labeler();

public:
    /**
     * @brief Links a visualizer.
     * 
     * One labeler can link to multiple visualizers at the same time. Although
     * the labeler cannot choose to send different data to different visualizers,
     * flexible control is provided by the callback functions (i.e. the visualizer
     * can call the labeler's functions defined in the interface such as getLabelInfo).
     */
    bool link(Visualizer *visualizer);

    /**
     * @brief Unlinks a visualizer.
     */
    bool unlink(Visualizer *visualizer);

    /**
     * @brief Get the Ranges object stored in the labeler.
     * 
     * @param type filter by type (default all types)
     * @param hierarchy filter by hierarchy (default all hierarchies)
     * @return QList<Range *> 
     */
    QList<Range *> getRanges(int type = -1, int hierarchy = -1) const;

    /**
     * @brief Get the LabelInfo object associated with a particular range.
     * 
     * @param range 
     * @return LabelInfo 
     */
    LabelInfo getLabelInfo(Range *range) const;

    /**
     * @brief Change the editing focus to a particular range.
     * 
     * @param focus 
     * @return success or not
     */
    virtual bool changeRangeFocus(Range *focus) = 0;

    friend class Channel;

protected:
    QSet<Visualizer *> linkedVisualizers;
    QList<Range *> ranges;
    QMap<Range *, LabelInfo *> labelInfos;
    Range *focus = 0;
};

#endif // LABELER_H
