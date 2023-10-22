#include <iostream>
#include "Queue.h"
#include "Iterator.h"
#include <locale.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");

    // тест очереди
    Queue q1(3);
    q1.push(1);
    q1.push(2);
    q1.push(3);

    cout << endl;
    cout << "(" << q1.getHead() << "  " << q1.getTail() << ")3" << endl;
    cout << endl;

    

    cout << "size(" << q1.size_() << ")3" << endl;
    cout << "Первый эл-т очереди: " << q1.front() << endl;

    q1.pop();
    q1.push(4);

    cout << "size(" << q1.size_() << ")3" << endl;

    cout << "Первый эл-т очереди: " << q1.front() << endl;

    q1.pop();

    q1.push(5); //3 4 5
    cout << "size(" << q1.size_() << ")3" << endl;
    cout << "Первый эл-т очереди: " << q1.front() << endl;

    q1.pop();//4 5
    cout << "size(" << q1.size_() << ")2" << endl;
    cout << "Первый эл-т очереди: " << q1.front() << endl;

    q1.pop();//5
    cout << "size(" << q1.size_() << ")1" << endl;
    cout << "Первый эл-т очереди: " << q1.front() << endl;

    q1.pop();//пуст
    cout << "size(" << q1.size_() << ")0" << endl;

    // тест итератора
    cout << endl;
    q1.clear();
    q1.push(3);
    q1.push(2);
    q1.push(1);
    //3 2 1


    Iterator itr(q1);
    itr.start();

    while (!itr.finish())
    {
        cout << "Числа: " << itr.getValue() << endl;
        itr.next();
    }

}
