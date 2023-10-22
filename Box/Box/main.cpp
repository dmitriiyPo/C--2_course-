#include<iostream>
#include"Box.h"
#include"Container.h"
using namespace std;
using namespace BoxClass;
using namespace ContainerClass;

int main()
{
   
    int n = 4;
    Box* arr = new Box[n];
    arr[0] = Box(1, 2, 3, 7, 5);
    arr[1] = Box(4, 5, 6, 1, 5);
    arr[2] = Box(7, 8, 9, 2, 10);
    arr[3] = Box(1, 1, 1, 5, 1);
    cout << arr[1] << endl;
    cout << endl;

    
    
    ContainerClass::Container container (10,10,10,15.0);

    container.addBox(BoxClass::Box (1, 1, 1, 1, 1));
    container.addBox(BoxClass::Box(2, 2, 2, 2, 1));
    container.addBox(BoxClass::Box(3, 3, 3, 3, 1));
    container.addBox(BoxClass::Box(2, 2, 2, 2, 3));

    BoxClass::Box box(3, 3, 3, 1, 1);
    container[0] = box;

    container.deleteBox(2);
    
    std::cout << "Box 1:" << " " << container.getBox(0) << endl;
    std::cout << "Box 2:" << " " << container.getBox(1) << endl;
    std::cout << "Box 3:" << " " << container.getBox(2) << endl;

    std::cout << "Number of boxes in the container:" << " " << container.getSize() << endl;
    
    std::cout << "Weights:" << " " << container.getSumOfWeights() << endl;
    std::cout << "Values:" << " " << container.getSumOfValues() << endl;

    std::cout << container[0];


    return 0;
}
