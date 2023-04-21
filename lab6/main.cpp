#include <iostream>
#include <vector>
#include "algorothms.h"
#include "4-numbers.type.h"

using namespace std;

enum Commands {
    ALL_OF = 1,
    IS_PARTITIONED,
    FIND_BACKWARD,
    EXIT
};

template<typename T>
bool positive_val(T value) {
    return value > 0;
}

template<typename T>
bool even_val(T value) {
    return value % 2;
}

bool all_even(MiniArray<int> numb) {
    bool check = true;
    for (int i = 0; i < 4; i++) {
        check = even_val(numb.get_ind(i));
        if (!check) {
            return false;
        }
    }
    return check;
}

bool check_first_last(MiniArray<int> numb) {
    return numb.get_beg() < numb.get_end();
}

int main() {
    int command;
    while (true) {
        cout << "1. Check all_of work" << endl;
        cout << "2. Check is_partitioned work" << endl;
        cout << "3. Check find_backward work" << endl;
        cout << "4. Exit" << endl;
        cout << "What you want?:" << endl;
        cin >> command;
        cout << endl;

        switch (command) {
            case ALL_OF: {
                vector<int> arr_1 = {1, 2, 3, 4, 5};
                cout << "First array with numbers (1,2,3,4,5) and predicate (numb>0):" << endl;
                cout << ((MyAlgo::all_of(arr_1.begin(), arr_1.end(), positive_val<int>)) ? "\tTRUE" : "\tFALSE")<< endl;

                vector<int> arr_2 = {-1, -2, -3, -4, -5};
                cout << "Second array with numbers (-1,-2,-3,-4,-5) and predicate (numb>0):" << endl;
                cout << ((MyAlgo::all_of(arr_2.begin(), arr_2.end(), positive_val<int>)) ? "\tTRUE" : "\tFALSE") << endl;

                vector<MiniArray<int>> arr_3 = {MiniArray(1, 3, 6, 8),
                                                MiniArray(7, 9, 6, 4)};
                cout << "My own 'array' with <MiniArray(2, 4, 6, 8), MiniArray(-1, 4, 6, -3)> and predicate (all number %2==0):" << endl;
                cout << ((MyAlgo::all_of(arr_3.begin(), arr_3.end(), all_even)) ? "\tTRUE" : "\tFALSE") << endl << endl;
                break;
            }

            case IS_PARTITIONED: {
                vector<int> arr_1 = {-2, -1, -3, 1, 2};
                cout << "First array with numbers (-2, -1, -3, 1, 2) and predicate (numb>0):" << endl;
                cout << ((MyAlgo::is_partitioned(arr_1.begin(), arr_1.end(), positive_val<int>)) ? "\tTRUE" : "\tFALSE")<< endl;

                vector<int> arr_2 = {-1, -2, -3, -4, -5};
                cout << "Second array with numbers (-1,-2,-3,-4,-5) and predicate (numb>0):" << endl;
                cout << ((MyAlgo::is_partitioned(arr_2.begin(), arr_2.end(), positive_val<int>)) ? "\tTRUE" : "\tFALSE") << endl;

                vector<MiniArray<int>> arr_3 = {MiniArray(1, 33, 2, 4),
                                                MiniArray(99, 77, 6, 8)};
                cout << "My own 'array' with <MiniArray(1, 33, 2, 4), MiniArray(99, 77, 6, 8)> and predicate (numb1 < numb2):" << endl;
                cout << ((MyAlgo::is_partitioned(arr_3.begin(), arr_3.end(), check_first_last)) ? "\tTRUE" : "\tFALSE") << endl << endl;
                break;
            }

            case FIND_BACKWARD: {
                bool check = false;
                vector<int> arr_1 = {1, 2, 3, 4, 5};
                cout << "The first element <4> in array with numbers (1, 2, 3, 4, 5) stands in: ";
                auto find = MyAlgo::find_backward(arr_1.begin(), arr_1.end(), 4);
                for (int i = 0; i < arr_1.size(); i++){
                    if (find == arr_1.end() - i){
                        cout << i << "th place from the end" << endl;
                        check = false;
                        break;
                    } else {
                        check = true;
                    }
                }
                if (check){
                    cout << "...ooPs...there aren't such number" << endl;
                }

                vector<char> arr_2 = {'a', 'b', 'c', 'd'};
                cout << "The first element <d> in array with chars (a, b, c, d) stands in: ";
                auto find_1 = MyAlgo::find_backward(arr_2.begin(), arr_2.end(), 'd');
                for (int i = 0; i < arr_1.size(); i++){
                    if (find_1 == arr_2.end() - i){
                        cout << i << "th place from the end" << endl;
                        //check = false;
                        break;
                    } else {
                        //check = true;
                    }
                }
                cout << endl;
                break;
            }

            case EXIT:
                return 0;

            default:
                cout << "There aren't such command...try again!" << endl << endl;
                break;
        }
    }
}