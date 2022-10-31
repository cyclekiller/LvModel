#include "channel.h"

#include "labeler.h"
#include "visualizer.h"

Channel::Channel(const QSet<Labeler *> &labelers, const QSet<Visualizer *> &visualizers)
    : labelers(labelers), visualizers(visualizers) {
}

Channel::~Channel() {
}

bool Channel::show() {
    foreach (auto visualizer, visualizers) {
        visualizer->clear();
    }
    foreach (auto labeler, labelers) {
        auto rangeList = labeler->getRanges();
        auto rangeSet = QSet<Range *>(rangeList.constBegin(), rangeList.constEnd());
        foreach (auto visualizer, labeler->linkedVisualizers)
            if (visualizers.contains(visualizer)) {
                visualizer->updateRanges(rangeSet, QSet<Range *>(), QSet<Range *>(), labeler);
                visualizer->changeRangeFocus(labeler->focus);
            }
    }
    return true;
}
