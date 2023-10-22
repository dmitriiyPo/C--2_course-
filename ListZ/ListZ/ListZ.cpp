#include "List.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    List list1;
    Iterator_Abstr* it1 = new List::Iterator(list1);
    
    int sl;
    cout << "1: стандартный тест\n2: создать свой список\n";
    cin >> sl;
    if (sl == 1) {
        it1->start();
        list1.push_I(it1, 1);
        list1.push_I(it1, 2);
        list1.push_I(it1, 3);
        list1.push_I(it1, 2);
        list1.push_I(it1, 1);

        cout << "list1: [\n";
        Iterator_Abstr* it2 = new List::Iterator(list1);
        it2->start();
        while(!it2->finish())
        {
            it2->next();
            cout << it2->get()->data;
            
        }
        cout << "]\n" << endl;
        /*
        cout << "list1: [\n";
        it1->next();
        cout << it1->get()->data << endl;
        it1->next();
        cout << it1->get()->data << endl;
        it1->next();
        cout << it1->get()->data << endl;
        it1->next();
        cout << it1->get()->data << endl;
        it1->next();
        cout << it1->get()->data << endl;
        cout << "]\n" << endl;
        */
        cout << "первый элемент list1: " << list1.first_I()->get()->data << endl << endl;

        List list2_1 = list1;
        Iterator_Abstr* it2_1 = new List::Iterator(list2_1);
        it2_1->start();
        cout << "list2_1(копия list1): [\n";
        while (!it2_1->finish()) {
            it2_1->next();
            cout << it2_1->get()->data << endl;
        }
        cout << "]\n" << endl;

        cout << "очистим list2_1 ";
        list2_1.clear();
        cout << list2_1.empty() << endl << endl;

        List list2_2(std::move(list1));
        Iterator_Abstr* it2_2 = new List::Iterator(list2_2);
        it2_2->start();
        cout << "list2_1(копия list1): [\n";
        while (!it2_2->finish()) {
            it2_2->next();
            cout << it2_2->get()->data << endl;
        }
        cout << "]\n" << endl;

        cout << list1.empty();
    }
    else if (sl == 2) {
        int n, e;
        cout << "сколько элементов будет в list1? ";
        cin >> n;

        it1->start();
        for (int i = 0; i < n; i++) {
            cin >> e;
            list1.push_I(it1, e);
        }

        cout << endl << "list1: [\n";
        for (int i = 0; i < n; i++) {
            it1->next();
            cout << it1->get()->data << endl;
        }
        cout << "]\n" << endl;
    }
}

