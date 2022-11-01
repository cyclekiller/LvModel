# LvModel
A general model designed for labeling time-based data.
# Usage
1. Define a custom Labeler class and/or Visualizer class.
```
#include "interface/labeler.h"
class MyLabeler : public Labeler
```
```
#include "interface/visualizer.h"
class MyVisualizer : public Visualizer
```
2. Override some functions in the base class.
- If you want to customize labeler:
```
class MyLabeler: public Labeler
{
    ...
    bool changeRangeFocus(Range *range) override; // define behavior when changing the editing focus
    ... // do other things
}
```
- If you want to customize visualizer:
```
class MyVisualizer : public Visualizer
{
    ...
    bool updateRanges(const QSet<Range *> &addedRange, const QSet<Range *> &deletedRange,
                      const QSet<Range *> &updatedRange, void *labeler) override; // define behavior when updating the ranges
    ... // do other things
}
```
3. Initialize and link the labeler and visualizer.
```
myLabeler = MyLabeler(...);
myVisualizer = MyVisualizer(...);
myLabeler.link(&myVisualizer);
```
4. Create a channel including the labeler and visualizer.
```
Channel channel(QSet<Labeler *>{&myLabeler}, QSet<Visualizer *>{&myVisualizer});
channel.show();
```