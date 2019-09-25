#ifndef VECTOR1_H
#define VECTOR1_H


#include "common.h"


class Map1;

class Vector1 : virtual public Common
{

public:

    Vector1();


    virtual ~Vector1() override;


    virtual Vector1& create ( const length_t number ) override;


    virtual void print() const override;


    virtual Vector1& remove() override;


    friend void synchronize ( Vector1 &vector1, Map1 &map1 );


private:

    std::vector< element_t >   m_vector;
    length_t                   m_length;
};

#endif // VECTOR1_H
