#ifndef ICONTAINER_H
#define ICONTAINER_H

#include <iostream>
#include <vector>
#include <map>
#include <ctime>

#include "constants.h"
#include "typedefs.h"

/**
 * @brief The IContainer class класс-интерфейс
 */
class IContainer
{
public:

    IContainer();


    virtual ~IContainer();


    virtual IContainer& create ( const length_t number ) = 0;


    virtual IContainer& remove() = 0;


    virtual void print() const = 0;
};

#endif // ICONTAINER_H
