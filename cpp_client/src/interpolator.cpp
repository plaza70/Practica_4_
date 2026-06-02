#include "../include/interpolator.h"

#include <cmath>

Matrix bilinearInterpolation(
    const Matrix& input,
    int newRows,
    int newCols
)
{
    int oldRows = input.size();
    int oldCols = input[0].size();

    Matrix output(
        newRows,
        std::vector<double>(newCols)
    );

    double rowScale =
        (double)(oldRows - 1) / (newRows - 1);

    double colScale =
        (double)(oldCols - 1) / (newCols - 1);

    for(int r = 0; r < newRows; r++)
    {
        for(int c = 0; c < newCols; c++)
        {
            double srcRow = r * rowScale;
            double srcCol = c * colScale;

            int r1 = floor(srcRow);
            int c1 = floor(srcCol);

            int r2 = std::min(r1 + 1, oldRows - 1);
            int c2 = std::min(c1 + 1, oldCols - 1);

            double dr = srcRow - r1;
            double dc = srcCol - c1;

            double q11 = input[r1][c1];
            double q21 = input[r1][c2];
            double q12 = input[r2][c1];
            double q22 = input[r2][c2];

            output[r][c] =
                q11 * (1 - dr) * (1 - dc) +
                q21 * (1 - dr) * dc +
                q12 * dr * (1 - dc) +
                q22 * dr * dc;
        }
    }

    return output;
}
