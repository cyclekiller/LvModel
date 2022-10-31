#include "visualizer.h"

Visualizer::Visualizer() {
}

Visualizer::~Visualizer() {
}

bool Visualizer::changeRangeFocus(Range *focus){
    this->focus = focus;
    return true;
};

bool Visualizer::rangeFocusNext(){
    if (focus->rightNeighbor) {
        return changeRangeFocus(focus->rightNeighbor);
    }
    return false;
};

bool Visualizer::rangeFocusPrev(){
    if (focus->leftNeighbor) {
        return changeRangeFocus(focus->leftNeighbor);
    }
    return false;
};

bool Visualizer::rangeFocusParent(){
    if (focus->parent) {
        return changeRangeFocus(focus->parent);
    }
    return false;
};
