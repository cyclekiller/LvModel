#ifndef FAKELABELER_H
#define FAKELABELER_H

#include <QRectF>

#include "interface/labeler.h"
#include "interface/range.h"

class FakeLabeler : public Labeler {
public:
    FakeLabeler(int width, int height);

    ~FakeLabeler();

public:
    void mock();

    friend class Widget;

private:
    float top, bottom, width;
    QList<QRectF> splitLines;
};

#endif // FAKELABELER_H
