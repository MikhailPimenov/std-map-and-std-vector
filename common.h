#ifndef COMMON_H
#define COMMON_H

#include "icontainer.h"


class Map1;                                         // Для функции synchronize ( Vector1 &vector, Map1 &map ) .
class Vector1;                                      // Для функции synchronize ( Vector1 &vector, Map1 &map ) .


class Common : public IContainer
{

public:


    Common();


    virtual ~Common() override;


protected:

    /**
     * @brief initialize инициализирует функцию srand() для
     * дальнейшего получения случайных значений через rand().
     */
    static void initialize();


    /**
     * @brief isEqual возвращает true, если элементы контейнеров, на которые указывают
     * соответствующие итераторы, равны. Не работает с числами с плавающей запятой.
     * @param iteratorVector константный итератор для контейнера std::vector
     * класса Vector1.
     * @param iteratorMap константный итератор для контейнера std::map
     * класса Map1.
     * @return true, если элемент контейнера vector
     * равен второму члену пары элемента map.
     */
    static bool isEqual( const std::vector< element_t >::const_iterator iteratorVector,
                         const std::map< key_t, element_t >::const_iterator iteratorMap );


    /**
     * @brief getRandomElement возвращает случайный элемент.
     * @return возврат (по значению) случайного элемента.
     */
    static element_t getRandomElement();


    /**
     * @brief getNumberToRemove возвращает случайное число элементов, которые потом можно будет уничтожить.
     * Метод создаёт случайное число, которое не больше длины массива
     * и не больше устанвленного ограничения.
     * @param length длина массива, из которого будут удалены элементы.
     * @param max ограничение на максимальное число элементов, которые можно уничтожить.
     * @return возврат (по значению) числа элементов, которые можно уничтожить.
     */
    static length_t getNumberToRemove(const length_t length,
                                      const length_t max = Constants::getMaxNumberToRemove() );


    /** КОПИЯ ОПИСАНИЯ
     * @brief synchronize синхронизирует контейнеры классов Vector1 и Map1.
     * После синхронизации в обоих контейнерах остаются только
     * те элементы, которые присутствуют в обоих контейнерах.
     * @param vector ссылка на класс с контейнером типа std::vector.
     * @param map ссылка на класс с контейнером типа std::map.
     */
    friend void synchronize ( Vector1 &vector1, Map1 &map );


};




/** КОПИЯ ОПИСАНИЯ
 * @brief synchronize синхронизирует контейнеры классов Vector1 и Map1.
 * После синхронизации в обоих контейнерах остаются только
 * те элементы, которые присутствуют в обоих контейнерах.
 * @param vector ссылка на класс с контейнером типа std::vector.
 * @param map ссылка на класс с контейнером типа std::map.
 */
void synchronize ( Vector1 &vector, Map1 &map );



#endif // COMMON_H
