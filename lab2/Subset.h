#pragma once

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Subset {
private:
    int amount = 0;
    int num = 0;
    vector<int> array;
public:
    Subset(int n, vector<int> arr) : amount(n), array(arr) {}

    Subset() {}

    Subset operator+=(const int &numb);//добавление элемента во множество
    Subset operator-=(const int &numb);//изъятие элемента из множества
    bool operator==(const int &numb);//проверка элемента во множестве



    void Display() {
        for (int i = 0; i < array.size(); i++) {
            cout << array[i] << " ";
        }
    }

    int am() const;

    vector<int> mas() const;
};

Subset operator^(Subset &a, Subset &b);//пересечение
Subset operator<(Subset &, Subset &);//объединение
Subset operator>(Subset &, Subset &); //добавление/изъятие всех эдементов, содержащихся в другом множестве