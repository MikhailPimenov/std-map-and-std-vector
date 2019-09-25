#include "common.h"


#include "vector1.h"   // Для функции synchronize ( Vector1 &vector1, Map1 &map1 )
#include "map1.h"      // Для функции synchronize ( Vector1 &vector1, Map1 &map1 )



Common::Common()
{

}
Common::~Common()
{

}

void Common::initialize()
{
    static unsigned int s_difference = 0;

    srand ( static_cast< unsigned int > ( time( nullptr ) ) + s_difference );

    ++s_difference;
}

element_t Common::getRandomElement()
{
    return  static_cast< element_t > ( rand() %
                                       static_cast< int > ( Constants::getMaxNumberOfRange() )  +
                                       Constants::getMinNumberOfRange() );
}

bool Common::isEqual ( const std::vector< element_t >::const_iterator iteratorVector,
                       const std::map< key_t, element_t >::const_iterator iteratorMap )
{
    return *iteratorVector == iteratorMap->second;
}

length_t Common::getNumberToRemove ( const length_t length, const length_t max )
{
    return  static_cast< length_t >( rand() ) % max % length;                   // Результат будет не больше меньшего из max и length .
}

void synchronize ( Vector1 &vector1, Map1 &map1 )
{
    std::vector< element_t >::const_iterator iteratorVector;
    std::map< key_t, element_t >::const_iterator iteratorMap;


    iteratorMap = map1.m_map.begin();


    while ( iteratorMap != map1.m_map.end() )
    {
        iteratorVector = vector1.m_vector.begin();
        bool isElementFound = false;

        while ( iteratorVector != vector1.m_vector.end() )
        {
            if( Common::isEqual ( iteratorVector, iteratorMap ) )
            {
                isElementFound = true;
                break;
            }

            ++iteratorVector;
        }

        if ( isElementFound == false )
            iteratorMap = map1.m_map.erase ( iteratorMap );
        else
            ++iteratorMap;
    }



    iteratorVector = vector1.m_vector.begin();

    while ( iteratorVector != vector1.m_vector.end() )
    {
        iteratorMap = map1.m_map.begin();
        bool isElementFound = false;

        while ( iteratorMap != map1.m_map.end() )
        {
            if( Common::isEqual ( iteratorVector, iteratorMap ) )
            {
                isElementFound = true;
                break;
            }

            ++iteratorMap;
        }

        if ( isElementFound == false )
            iteratorVector = vector1.m_vector.erase ( iteratorVector );
        else
            ++iteratorVector;
    }
}
