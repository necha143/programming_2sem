#pragma once

template<class T>
class MiniArray {
private:
    T fir;
    T sec;
    T thi;
    T four;
public:
    MiniArray() = default;
    virtual ~MiniArray() = default;

    MiniArray(T fir, T sec, T thi, T four) {
        this->fir = fir;
        this->sec = sec;
        this->thi = thi;
        this->four = four;
    }

    T get_ind(int i) {
        if (i == 0) {
            return this->fir;
        } else if (i == 1) {
            return this->sec;
        } else if (i == 2) {
            return this->thi;
        } else {
            return this->four; // здесь также можно кидать exception, если пользователь вводит индекс>4
        }
    }

    T get_beg() {
        return this->fir;
    }

    T get_end() {
        return this->four;
    }

    T get_size(){
        return 4;
    };
};