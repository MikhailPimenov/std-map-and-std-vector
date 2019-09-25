#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "typedefs.h"

class Constants
{
public:

    static element_t getMaxNumberOfRange()
    {
        return s_MaxNumberOfRange;
    }

    static element_t getMinNumberOfRange()
    {
        return s_MinNumberOfRange;
    }

    static length_t getMaxNumberToRemove()
    {
        return s_MaxNumberToRemove;
    }

private:

    static const element_t  s_MaxNumberOfRange    = 9;
    static const element_t  s_MinNumberOfRange    = 1;
    static const length_t   s_MaxNumberToRemove   = 15;

};

#endif // CONSTANTS_H
