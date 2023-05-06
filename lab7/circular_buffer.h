#pragma once

#include <iostream>

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
    explicit Circular_Buffer(int capa_city) { //ключевое слово explicit перед конструктором служит для того,
        this->buffer = new T[capa_city]{}; // чтобы конструктор не вызывался автоматически при неявном преобразовании
        this->capacity = capa_city;
        this->size = 0;
        this->start = this->final = 0;
    }

    ~Circular_Buffer() { delete[] buffer; } //деструктор

    int getCapacity() {
        return this->capacity;
    }

    int getSize() {
        return this->size;
    }

    //////////класс итератор с переопредленными методами///////////
    class Iterator : public iterator<random_access_iterator_tag, T> {
        /*Класс итератор наследуется от типа итератора, который поддерживает произвольный доступ к элементам контейнера, в котором итератор используется.
        Он обеспечивает быстрый доступ к элементам за константное время, позволяет перемещаться на заданное
        количество шагов вперед и назад и поддерживает арифметику указателей.*/
        T *iterator_;
    public:
        using difference_type = typename iterator<random_access_iterator_tag, T>::difference_type;

        // difference_type является типом, который используется для представления разницы между двумя итераторами в контейнере.
        difference_type operator-(const Iterator &obj) const {
            return iterator_ - obj.iterator_;
        }

        explicit Iterator(T *curr_Value) {
            iterator_ = curr_Value;
        }

        Iterator(const Iterator &other) {
            iterator_ = other.iterator_;
        }

        Iterator operator+(int value) {
            iterator_ = iterator_ + value;
            return *this;
        }

        Iterator operator-(int value) {
            iterator_ = iterator_ - value;
            return *this;
        }

        Iterator operator++() {
            iterator_++;
            return *this;
        };

        Iterator operator--() {
            iterator_--;
            return *this;
        }

        Iterator operator+=(const int val) {
            iterator_ = iterator_ + val;
            return *this;
        };

        Iterator operator-=(const int val) {
            iterator_ = iterator_ - val;
            return *this;
        };

        bool operator==(const Iterator *other) {
            return this->iterator_ == other->iterator_;
        }

        bool operator!=(const Iterator *other) {
            return this->iterator_ != other->iterator_;
        }

        bool operator>(const Iterator *other) {
            return this->iterator_ > other->iterator_;
        }

        bool operator<(const Iterator *other) {
            return this->iterator_ < other->iterator_;
        }

        bool operator>=(const Iterator *other) {
            return this->iterator_ >= other->iterator_;
        }

        bool operator<=(const Iterator *other) {
            return this->iterator_ <= other->iterator_;
        }

        T &operator*() const { //оператор разыменования, благодаря ему, мы можем вернуть объект на который указывает итератор
            return *iterator_;
        };
    };

    //////////вставка и удаление в конец///////////
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
        final--;
        size--;
    }

    //////////вставка и удаление в начало///////////
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
        start++;
        size--;
    }

    //////////Вставка и удаление в произвольное место по итератору//////////
    void add(Iterator iterator, int value) {
        int index = (iterator - begin()) % capacity;
        buffer[index] = value;

        size++;
        if (final == capacity - 1) {
            final = 0;
        } else {
            final++;
        }
    }

    void del(Iterator iterator) {
        int index = (iterator - begin()) % capacity;
        int IndexLast = final;

        while (index != final) {
            buffer[index % capacity] = buffer[(index + 1) % capacity];
            if (index == capacity - 1) {
                index = 0;
            } else {
                index++;
            }
        }

        if (final == 0) {
            final = capacity - 1;
        } else {
            final--;
        }
        buffer[IndexLast] = 0;
        size--;
    }

    //////////доступ в конец, начало//////////
    T &first() {
        int real_index = (start) % capacity;
        return buffer[real_index];
    }

    T &last() {
        int real_index = (final) % capacity;
        return buffer[real_index];
    }

    Iterator begin() {
        return Iterator(buffer);
    }

    Iterator end() {
        return Iterator(buffer + capacity);
    }

    //////////доступ по индексу (переопределение метода [])///////////
    T &operator[](int index) {
        int real_index = (start + index) % capacity;
        return buffer[real_index];
    }

    //////////изменение капасити///////////
    void change_capacity(int capa_city) {
        T *temp = new T[capa_city] {};
        for (int i = 0; i < this->capacity; i++) {
            temp[i] = buffer[i];
        }
        delete[] this->buffer;
        this->buffer = temp;
        this->capacity = capa_city;
    }

    //////////вывод буфера на экран///////////
    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << buffer[i] << " ";
        }
        cout << "\n";
    }
};