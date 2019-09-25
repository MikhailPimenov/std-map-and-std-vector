#include "map1.h"


Map1::Map1()
{

}

Map1::~Map1()
{

}

Map1& Map1::create ( const length_t number )
{
    initialize();


    for ( length_t index = 0; index < number; ++index )
          m_map[index] = getRandomElement();


    m_length = number;


    return *this;
}

void Map1::print() const
{
    std::cout << "Map:    ";


    std::map< key_t, element_t >::const_iterator iterator;
    iterator = m_map.begin();


    while ( iterator != m_map.end() )
    {
        std::cout << iterator->second << "  ";
        ++iterator;
    }

    std::cout << '\n';
}

Map1& Map1::remove()
{
    length_t numberToRemove = getNumberToRemove ( m_length );
    m_length -= numberToRemove;


    std::map< key_t, element_t >::const_iterator iterator;
    iterator = m_map.begin();

    while ( iterator != m_map.end() )
    {
        if ( numberToRemove == 0 )
            return *this;

        iterator = m_map.erase ( iterator );
        --numberToRemove;
    }

    return *this;
}
