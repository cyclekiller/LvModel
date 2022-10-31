#ifndef RANGE_H
#define RANGE_H

#include <QList>
#include <QMap>
#include <QSet>

enum RANGE_NEIGHBOR_POSSIBLE {
    POSSIBLE_NEIGHBOR,
    INVALID_NEIGHBOR_POSITION_UNMATCH,  // the position of two ranges is not
                                        // correct
    INVALID_NEIGHBOR_MULTIPLE_CONFLICT, // one of the ranges already assigned to
                                        // another neighbor
};

enum RANGE_PARENT_POSSIBLE {
    POSSIBLE_PARENT,
    INVALID_PARENT_POSITION_UNMATCH,  // the position of two ranges is not correct
    INVALID_PARENT_MULTIPLE_CONFLICT, // the child range already assigned to
                                      // another parent
};

/**
 * @brief The Range class represents a interval with start point <= end point. It also 
 * has a type identifier and some structure.
 * 
 * The type identifier has some pre-defined values corresponding to different use cases,
 * however custom type is also possible.
 * 
 * The range supports *neighboring* (see definitions below), either literally
 * or virtually. For example, interval [1, 2] and [2, 3] are literally
 * neighboring while [1, 2] and [4, 5] can only be virtually neighboring.
 * In principle, any two ranges can be virtually neighboring, however some operations rely
 * on the ranges being literally neighboring, such as Praat-style phoneme labeling.
 */
class Range {
public:
    /**
     * @brief Construct a new Range object.
     * 
     * @param begin the start point
     * @param end the end point
     * @param type the type identifier
     * @param hierarchy the hierarchy (optional)
     */
    Range(float begin, float end, int type, int hierarchy = -1);

    virtual ~Range();

public:
    /**
     * @brief Set another range as this range's left neighbor.
     * 
     * @param neighbor 
     * @return success or not
     */
    bool setLeftNeighbor(Range *neighbor);

    /**
     * @brief Set another range as this range's right neighbor.
     * 
     * @param neighbor 
     * @return success or not
     */
    bool setRightNeighbor(Range *neighbor);

    /**
     * @brief Set another range as this range's parent.
     * 
     * @param parent 
     * @return success or not
     */
    bool setParent(Range *parent);

    /**
     * @brief Check if any two ranges can be made as literal neighbors.
     * 
     * @param left the range supposed to be on the left
     * @param right the range supposed to be on the right
     * @return RANGE_NEIGHBOR_POSSIBLE 
     */
    static RANGE_NEIGHBOR_POSSIBLE neighborPossible(Range *left, Range *right);

    /**
     * @brief Check if any two ranges can be made as parent and child.
     * 
     * @param parent the range supposed to be on the parent
     * @param child the range supposed to be on the child
     * @return RANGE_PARENT_POSSIBLE 
     */
    static RANGE_PARENT_POSSIBLE parentPossible(Range *parent, Range *child);

    /**
     * @brief Merge a bunch of ranges into a parent range.
     * 
     * @param ranges 
     * @return Range* 
     */
    static Range *merge(const QList<Range *> &ranges);

    /**
     * @brief Split a range into a bunch of child & neighboring ranges.
     * 
     * @param innerBounds where to split the range
     * @return QList<Range *> 
     */
    QList<Range *> split(QList<float> innerBounds);

    float begin, end;

    int type, hierarchy;

    friend class Visualizer;

    friend class Labeler;

protected:
    Range *leftNeighbor = 0, *rightNeighbor = 0, *parent = 0;
};

#endif // RANGE_H
