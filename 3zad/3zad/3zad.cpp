#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "List list: " << endl;
    List list;

    AIterator* it = new List::Iterator(list);

    it->start();
    list.addI(it, 1);
    list.addI(it, 2);
    list.addI(it, 3);
    list.addI(it, 4);
    list.addI(it, 5);
    list.addI(it, 6);
    it->start();
    it->next();

    cout << it->get()->data << endl;
    it->next();
    cout << it->get()->data << endl;
    it->next();
    cout << it->get()->data << endl;
    it->next();
    cout << it->get()->data << endl;
    it->next();
    cout << it->get()->data << endl;
    it->next();
    cout << it->get()->data << endl;


    cout << "\nMake empty";
    list.makeEmpty();
    cout << "\nisEmpty " << list.isEmpty() << endl;
    it->start();
    cout << "\n после очистки буферный элемент: " << it->get()->data << endl;


    cout << "add" << endl;
    it->start();
    list.addI(it, 6);
    it->next();
    list.addI(it, 4);
    it->next();
    list.addI(it, 3);
    it->start();
    it->next();
    cout << it->get()->data << endl;
    it->next();
    cout << it->get()->data << endl;
    it->next();
    cout << it->get()->data << endl;
    it->next();


    cout << "search (4) " << endl;
    cout << list.searchFirst(4)->get()->data << endl;

    cout << "first" << endl;
    cout << list.first()->get()->data << endl;

    it->start();
    it->next();
    list.deleteI(it);
    cout << "list after deleting element" << endl;
    it->start();
    it->next();
    cout << it->get()->data << endl;
    it->next();
    cout << it->get()->data << endl;
    it->next();


    cout << "first" << endl;
    cout << list.first()->get()->data << endl;
    cout << "List list" << endl;

    it = new List::Iterator(list);
    it->start();
    while (!it->finish())
    {
        it->next();
        cout << it->get()->data << endl;
    }

    List l1 = list;
    List l2(list);


    AIterator* i = new List::Iterator(l1);
    i->start();

    cout << "List l1" << endl;
    while (!i->finish())
    {
        i->next();
        cout << i->get()->data << endl;
    }

    AIterator* iter = new List::Iterator(l2);
    iter->start();
    cout << "List l2" << endl;

    while (!iter->finish())
    {
        iter->next();
        cout << iter->get()->data << endl;
    }
    cout << "\nlist isEmpty " << list.isEmpty() << endl;



    cout << "end";
    return 0;
}