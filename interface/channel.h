#ifndef CHANNEL_H
#define CHANNEL_H

#include "labeler.h"
#include "visualizer.h"

/**
 * @brief The Channel class is a viewport that doesn't modify anything but only
 * choose what can be seen through it.
 * 
 * For example, there are two labelers: one for pitch curve editing, another for phoneme alignment editing,
 * and there are two visualizers: one is wav plot, another is the original song's midi pianoroll.
 * The pitch labeler is linked to the midi piano roll, the phoneme labeler is linked
 * to the wav plot. Then we can construct two channels, one for displaying and editing the pitch curve
 * along with the midi pianoroll, another for displaying and editing the phoneme alignment along with
 * the wav plot.
 * 
 * The channel will not open or close any window, or affect other labelers or visualizers it
 * doesn't control.
 */
class Channel {
public:
    /**
     * @brief Construct a new Channel object.
     * 
     * @param labelers the labelers whose data can be seen through this channel
     * @param visualizers the visualizers that can be seen through this channel
     */
    Channel(const QSet<Labeler *> &labelers, const QSet<Visualizer *> &visualizers);

    virtual ~Channel();

public:
    /**
     * @brief Show the channel by letting all visualizers in this channel only
     * display the data from only the labelers in this channel.
     */
    bool show();

protected:
    QSet<Labeler *> labelers;
    QSet<Visualizer *> visualizers;
};

#endif // CHANNEL_H
