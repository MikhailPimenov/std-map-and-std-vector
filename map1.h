#ifndef MAP1_H
#define MAP1_H

#include "common.h"

class Vector1;

class Map1 : virtual public Common
{

public:

    Map1();
    virtual ~Map1() override;


    virtual Map1& create ( const length_t number ) override;


    virtual void print() const override;


    virtual Map1& remove() override;


    friend void synchronize ( Vector1 &vector1, Map1 &map1 );


private:

    std::map<key_t, element_t>   m_map;
    length_t                     m_length;
};
#endif // MAP1_H
