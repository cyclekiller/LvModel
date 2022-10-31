#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "range.h"

/**
 * @brief The Visualizer class displays labeling data sent by its linked labelers,
 * usually in a context of some other data. (See also labeler.h)
 *
 * The visualizer is usually (not always) some interactive plot which already displays
 * some well-known time-based data format such as waveform, spectrogram and midi.
 * Extra visual objects are layered upon the plot, providing necessary hint for labeling.
 *
 * Sometimes the visualizer also modifies the labeling data, however it should only
 * modify the range, not the label info (see labelinfo.h).
 */
class Visualizer {
public:
    Visualizer();

    virtual ~Visualizer();

public:
    /**
     * @brief Update data sent by a labeler.
     *
     * @param added new ranges added
     * @param deleted old ranges deleted
     * @param updated existing ranges updated
     * @param labeler the sender
     * @return success or not
     */
    virtual bool updateRanges(const QSet<Range *> &added, const QSet<Range *> &deleted,
                              const QSet<Range *> &updated, void *labeler) = 0;

    /**
     * @brief Change the displaying focus to a particular range.
     *
     * @param focus
     * @return success or not
     */
    virtual bool changeRangeFocus(Range *focus) = 0;

    /**
     * @brief Change the displaying focus to next range.
     *
     * @return success or not
     */
    bool rangeFocusNext();

    /**
     * @brief Change the displaying focus to prev range.
     *
     * @return success or not
     */
    bool rangeFocusPrev();

    /**
     * @brief Change the displaying focus to parent range.
     *
     * @return success or not
     */
    bool rangeFocusParent();

    /**
     * @brief Update label-related visualizations.
     *
     * In normal cases, use updateRanges instead.
     *
     * @return success or not
     */
    virtual bool update() = 0;

    /**
     * @brief Clear label-related visualizations.
     *
     * @return success or not
     */
    virtual bool clear() = 0;

protected:
    QMap<void *, QSet<Range *> *> allLabelerRanges;
    Range *focus = 0;
};

#endif // VISUALIZER_H
