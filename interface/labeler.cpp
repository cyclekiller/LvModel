#include "labeler.h"

Labeler::Labeler() {}

Labeler::~Labeler() {}

bool Labeler::link(Visualizer *visualizer) {
    linkedVisualizers += visualizer;
    return true;
};

bool Labeler::unlink(Visualizer *visualizer) {
    if (linkedVisualizers.contains(visualizer)) {
        linkedVisualizers -= visualizer;
        return true;
    }
    return false;
};

// slow, only for demo
QList<Range *> Labeler::getRanges(int type, int hierarchy) const {
  QList<Range *> ranges;
  foreach (Range *range, this->ranges) {
    if (range->type == type || type == -1)
      if (range->hierarchy == hierarchy || hierarchy == -1) {
        ranges.append(range);
      }
  }
  return ranges;
};

LabelInfo Labeler::getLabelInfo(Range *range) const {
    return *labelInfos[range];
};
