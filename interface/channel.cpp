#include "channel.h"

#include "labeler.h"
#include "visualizer.h"

Channel::Channel(QSet<Labeler *> labelers, QSet<Visualizer *> Visualizers) {
  this->labelers = labelers;
  this->Visualizers = Visualizers;
}
