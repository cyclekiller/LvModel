#ifndef LABELINFO_H
#define LABELINFO_H

#include <QString>

/**
 * @brief The LabelInfo class stores the actual label information.
 * 
 * By now, LabelInfo only contains a string.
 */
class LabelInfo {
public:

    /**
     * @brief Construct a new LabelInfo object.
     * 
     * @param label the label string
     */
    LabelInfo(const QString &label);

    virtual ~LabelInfo();

public:
    QString label;
};

#endif // LABELINFO_H
