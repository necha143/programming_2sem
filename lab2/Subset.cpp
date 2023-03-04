#include "Subset.h"

int Subset::am() const {
    return this->amount;
}

vector<int> Subset::mas() const {
    return this->array;
}


Subset Subset::operator+=(const int &numb) {
    array.push_back(numb);
    sort(array.begin(), array.end());
    return *this;
}

Subset Subset::operator-=(const int &numb) {
    for (int i = 0; i < amount; i++) {
        if (array[i] == numb) {
            swap(array[i], array[amount - 1]);
            break;
        }
    }
    array.pop_back();
    sort(array.begin(), array.end());
    array.resize(amount - 1);
    return *this;
}

bool Subset::operator==(const int &numb) {
    bool check = false;
    for (int i = 0; i < amount; i++) {
        if (array[i] == numb) {
            check = true;
            break;
        } else {
            check = false;
        }
    }
    return check;
}

Subset operator^(Subset &a, Subset &b) {
    vector<int> ans_arr;
    for (int i = 0; i < a.am(); i++) {
        for (int j = 0; j < b.am(); j++) {
            if (a.mas()[i] == b.mas()[j]) {
                ans_arr.push_back(a.mas()[i]);
            }
        }
    }
    return Subset(a.am(), ans_arr);
}

Subset operator<(Subset &a, Subset &b) {
    vector<int> ans_arr;
    for (int i = 0; i < a.am(); i++) {
        ans_arr.push_back(a.mas()[i]);
        ans_arr.push_back(b.mas()[i]);
    }

    auto end = ans_arr.end(); // https://www.techiedelight.com/ru/remove-duplicates-vector-cpp/
    for (auto it = ans_arr.begin(); it != end; ++it) {
        end = remove(it + 1, end, *it);
    }

    ans_arr.erase(end, ans_arr.end());
    sort(ans_arr.begin(), ans_arr.end());
    return Subset(ans_arr.size(), ans_arr);
}

Subset operator>(Subset &a, Subset &b) {
    vector<int> ans; // в данном векторе будут храниться элементы множества а
    vector<int> numb_to_del; // числа для удаления
    for (int i = 0; i < a.am(); i++) {
        for (int j = 0; j < b.am(); j++) {
            if (a.mas()[i] != b.mas()[j]) {
                ans.push_back(a.mas()[i]);
                ans.push_back(b.mas()[j]);
            } else {
                numb_to_del.push_back(a.mas()[i]);
            }
        }
    }

    auto end = ans.end(); // https://www.techiedelight.com/ru/remove-duplicates-vector-cpp/
    for (auto it = ans.begin(); it != end; ++it) {
        end = remove(it + 1, end, *it);
    }

    ans.erase(end, ans.end());
    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < numb_to_del.size(); j++) {
            if (ans[i] == numb_to_del[j]) {
                swap(ans[i], ans[ans.size() - 1]);
                ans.pop_back();
            }
        }
    }
    sort(ans.begin(), ans.end());

    return Subset(ans.size(), ans);
}