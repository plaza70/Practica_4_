#include "../include/validator.h"

bool validateMatrix(const Matrix& matrix)
{
    if(matrix.size() != 16)
    {
        return false;
    }

    for(const auto& row : matrix)
    {
        if(row.size() != 16)
        {
            return false;
        }
    }

    return true;
}
