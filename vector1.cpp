#include "vector1.h"


Vector1::Vector1()
{

}

Vector1::~Vector1()
{

}

Vector1& Vector1::create( const length_t number )
{
    initialize();

    m_vector.resize( number );

    std::vector< element_t >::iterator iterator;
    iterator = m_vector.begin();

    while ( iterator != m_vector.end() )
    {
        *iterator = getRandomElement();
        ++iterator;
    }

    m_length = number;

    return *this;
}

void Vector1::print() const
{
    std::cout << "Vector: ";


    std::vector< element_t >::const_iterator iterator;
    iterator = m_vector.begin();

    while ( iterator != m_vector.end() )
    {
        std::cout << *iterator << "  ";
        ++iterator;
    }


    std::cout << std::endl;
}

Vector1& Vector1::remove()
{
    m_length -= getNumberToRemove ( m_length );

    m_vector.resize( m_length );

    return *this;
}


