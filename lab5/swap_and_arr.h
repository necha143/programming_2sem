#pragma once

#include <iostream>
#include "Exception.h"

using namespace std;

template<typename T>
void my_swap(T &t1, T &t2) {
    T temp(t1);
    t1 = t2;
    t2 = temp;
}


template<typename T>
class Array {
private:
    T *data;
    size_t size;

public:
    // Конструктор по умолчанию
    Array() : data(nullptr), size(0) {}

    // Конструктор с заданным размером массива
    Array(size_t size) : data(new T[size]), size(size) {}

    // Деструктор
    ~Array() {
        delete[] data;
    }

    // Оператор доступа к элементам массива по индексу
    T &operator[](size_t index) {
        if (index >= size) {
            throw Exception("ERROR. Index out of range.");
        }
        return data[index];
    }

    // Метод для получения размера массива
    size_t getSize() const {
        return size;
    }

    // Метод для сортировки массива
    void sort() {
        std::sort(data, data + size);
    }
};


template<typename T>
// Так же можно реализовать exception и здесь, ведь массив может быть пустой
T arrBegin(Array<T> &arr) {
    return arr[0];
}

template<typename T>
T arrEnd(Array<T> &arr) {
    return arr[arr.getSize() - 1];
}

template<typename T>
T max_elem(Array<T> &arr) {
    T max = arr[0];
    for (size_t i = 0; i < arr.getSize(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}