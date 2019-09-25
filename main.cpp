#include <QCoreApplication>

#include "icontainer.h"
#include "vector1.h"
#include "map1.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Vector1 vector;
    Map1 map;


    std::cout << "Creating:\n";
    vector.create ( 15 ).print();
    map.create ( 25 ).print();


    std::cout << "\nElements got randomly removed:\n";
    vector.remove().print();
    map.remove().print();


    std::cout << "\nSynchronizing:\n";
    synchronize ( vector, map );
    vector.print();
    map.print();


    return a.exec();
}
