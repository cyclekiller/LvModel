#include "range.h"

Range::Range(float begin, float end, int type, int hierarchy)
    : begin(begin), end(end), type(type), hierarchy(hierarchy) {
}

Range::~Range(){};

bool Range::setLeftNeighbor(Range *neighbor) {
    this->leftNeighbor = neighbor;
    neighbor->rightNeighbor = this;
    return true;
};

bool Range::setRightNeighbor(Range *neighbor) {
    neighbor->setLeftNeighbor(this);
    return true;
};

bool Range::setParent(Range *parent) {
    this->parent = parent;
    return true;
};

RANGE_NEIGHBOR_POSSIBLE Range::neighborPossible(Range *left, Range *right) {
    if (left->end != right->begin) {
        return INVALID_NEIGHBOR_POSITION_UNMATCH;
    }
    if ((left->rightNeighbor && left->rightNeighbor != right) ||
        (right->leftNeighbor && right->leftNeighbor != left)) {
        return INVALID_NEIGHBOR_MULTIPLE_CONFLICT;
    }
    return POSSIBLE_NEIGHBOR;
};

RANGE_PARENT_POSSIBLE Range::parentPossible(Range *parent, Range *child) {
    if (!(parent->begin <= child->begin && child->end <= parent->end)) {
        return INVALID_PARENT_POSITION_UNMATCH;
    }
    if (child->parent && child->parent != parent) {
        return INVALID_PARENT_MULTIPLE_CONFLICT;
    }
    return POSSIBLE_PARENT;
};

Range *Range::merge(const QList<Range *> &ranges) {
    auto parent = new Range(ranges.constFirst()->begin, ranges.constLast()->end, 0);
    foreach (auto range, ranges) {
        range->setParent(parent);
    }
    return parent;
};

QList<Range *> Range::split(QList<float> innerBounds) {
    QList<Range *> ranges;
    auto lastBegin = this->begin;
    innerBounds.append(this->end);
    foreach (auto innerBound, innerBounds) {
        auto range = new Range(lastBegin, innerBound, 0);
        range->setParent(this);
        ranges.append(range);
        lastBegin = innerBound;
    }
    return ranges;
};
