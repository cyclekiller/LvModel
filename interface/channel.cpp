#include "channel.h"

#include "labeler.h"
#include "visualizer.h"

Channel::Channel(QSet<Labeler *> labelers, QSet<Visualizer *> Visualizers) {
  this->labelers = labelers;
  this->visualizers = Visualizers;
}

Channel::~Channel() {}

bool Channel::show() {
  foreach (auto visualizer, visualizers) {
    visualizer->clear();
  }
  foreach (auto labeler, labelers) {
    auto rangeList = labeler->getRanges();
    auto rangeSet = QSet<Range *>(rangeList.constBegin(), rangeList.constEnd());
    foreach (auto visualizer, labeler->linkedVisualizers)
      if (visualizers.contains(visualizer)) {
        visualizer->updateRanges(rangeSet, QSet<Range *>(), QSet<Range *>(),
                                 labeler);
      }
  }
  return true;
}
