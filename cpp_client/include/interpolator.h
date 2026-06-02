#ifndef INTERPOLATOR_H
#define INTERPOLATOR_H

#include "json_reader.h"

Matrix bilinearInterpolation(
    const Matrix& input,
    int newRows,
    int newCols
);

#endif
