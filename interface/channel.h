#ifndef CHANNEL_H
#define CHANNEL_H

#include "labeler.h"
#include "visualizer.h"

class Channel {
 public:
  Channel(QSet<Labeler *> labelers, QSet<Visualizer *> Visualizers);

  ~Channel();

 public:
  bool show();

 protected:
  QSet<Labeler *> labelers;
  QSet<Visualizer *> Visualizers;
};

#endif  // CHANNEL_H
