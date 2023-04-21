#pragma once
//Реализация обобщенного алгоритма не зависит от типа контейнера, поэтому одна основанная на шаблонах реализация может работать со всеми контейнерами,
// а равно и со встроенным типом массива.

namespace MyAlgo {

    template<typename iterator, typename Pred>
    bool all_of(const iterator &begin, const iterator &end, bool (&predicate)(Pred)) {
        for (iterator current = begin; current != end; current++) {
            if (!predicate(*current))
                return false;
        }
        return true;
    }

    template<typename iterator, typename Pred>
    bool is_partitioned(const iterator &begin, const iterator &end, bool (&predicate)(Pred)) {
        bool equal = true;
        iterator separator;
        for (iterator current = begin + 1; equal; current++) {
            if (predicate(*current) != predicate(*(current - 1))) {
                equal = false;
                separator = current;
            }
        }

        for (iterator current = separator; current != end - 1; current++) {
            if (predicate(*current) != predicate(*(current + 1))) {
                return false;
            }
        }
        return true;
    }

    template<typename iterator, typename element>
    iterator find_backward(const iterator &begin, const iterator &end, element el) {
        for (iterator current = end; current != begin; current--) {
            if (*current == el)
                return current;
        }

        if (*begin == el) {
            return begin;
        }
        return end;
    }

}