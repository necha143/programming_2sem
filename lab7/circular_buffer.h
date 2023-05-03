#pragma once

#include <iostream>
#include <iterator>

using namespace std;

template<typename T>
class Circular_Buffer {
    T *buffer;
    int start, final;
    int capacity;
    int size;

    bool empty() {
        return (size == 0);
    };

public:
    explicit Circular_Buffer(int capa_city) {
        this->buffer = new T[capa_city];
        this->capacity = capa_city;
        this->size = 0;
        this->start = this->final = 0;
        for (int i = 0; i < capa_city; i++) {
            buffer[i] = 0;
        }
    }

    ~Circular_Buffer() { delete[] buffer; }

    int getCapacity() {
        return this->capacity;
    }

    int getSize() {
        return this->size;
    }

    class Iterator : public iterator<random_access_iterator_tag, T> {
    private:
        T *currValue;
    public:
        /*using difference_type = typename iterator<random_access_iterator_tag, T>::difference_type;

        difference_type operator-(const Iterator &obj) const {
            return currValue - obj.currentValue;
        }*/

        explicit Iterator(T *currentValue_) {
            currValue = currentValue_;
        }

        Iterator(const Iterator &other) {
            currValue = other.currentValue;
        }

        Iterator operator+(int value) {
            return iterator(currValue + value);
            /*currValue += value;
            return *this;*/
        }

        Iterator operator-(int value) {
            return iterator(currValue - value);
            /*currValue -= value;
            return *this;*/
        }

        Iterator operator++() {
            currValue++;
            return *this;
        };

        Iterator operator--() {
            currValue--;
            return *this;
        }

        bool operator==(const Iterator *other) {
            return this->currentValue == other->currentValue;
        }

        bool operator!=(const Iterator *other) {
            return this->currentValue != other->currentValue;
        }

        bool operator>(const Iterator *other) {
            return this->currentValue > other->currentValue;
        }

        bool operator<(const Iterator *other) {
            return this->currentValue < other->currentValue;
        }

        bool operator>=(const Iterator *other) {
            return this->currentValue >= other->currentValue;
        }

        bool operator<=(const Iterator *other) {
            return this->currentValue <= other->currentValue;
        }

        T &operator*() const {
            return *currValue;
        };

        T *operator->() const {
            return currValue;
        }

        Iterator &operator=(T &other) const {
            currValue = *other;
            return *this;
        }
    };

    Iterator begin() {
        return Iterator(buffer);
    }

    Iterator end() {
        return Iterator(buffer + capacity);
    }

    /*T &operator[](const int &index) {
        int tmp = start + index;
        if (tmp > capacity) {
            tmp -= capacity + 1;
        }
        return buffer[tmp];
    }*/

    void push_back(const T &element) {
        if (start == final && size == 0) {
            buffer[final] = element;
            size++;
            return;
        }

        if (final == capacity - 1) {
            final = 0;
        } else {
            final++;
        }

        if (size == capacity) {
            if (start == capacity - 1) {
                start = 0;
            } else {
                start++;
            }
        } else {
            size++;
        }

        buffer[final] = element;
    }

    void pop_back() {
        if (empty()) {
            return;
        }

        buffer[final] = 0;
        if (final == 0) {
            capacity--;
        } else {
            final--;
        }
        size--;
    }

    void push_front(const T &element) {
        if (start == final && size == 0) {
            buffer[start] = element;
            size++;
            return;
        }

        if (start == 0) {
            start = capacity - 1;
        } else {
            start--;
        }

        if (size == capacity) {
            if (final == 0) {
                final = capacity - 1;
            } else {
                final--;
            }
        } else {
            size++;
        }

        buffer[start] = element;
    }

    void pop_front() {
        if (empty()) {
            return;
        }

        buffer[start] = 0;
        if (start == capacity - 1) {
            start = 0;
        } else {
            start++;
        }
        size--;
    }


    void change_capacity(int capa_city) {
        T *temp = new T[capa_city];
        for (int i = 0; i < this->capacity; i++) {
            temp[i] = buffer[i];
        }

        this->buffer = temp;
        this->capacity = capa_city;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << buffer[i] << " ";
        }
        cout << "\n";
    }
};