#include "swap_and_arr.h"

enum Commands {
    SWAP = 1,
    ARRAY,
    EXIT
};

enum TypeArrays {
    INT = 1,
    CHAR
};


int main() {
    int command, type;
    while (true) {
        cout << "1. Check swap work" << endl;
        cout << "2. Check array work" << endl;
        cout << "3. Exit" << endl;
        cout << "What you want?:" << endl;
        cin >> command;
        cout << endl;

        switch (command) {
            case SWAP:
                cout << "Enter two numbers to check swap" << endl;
                int a, b;
                cin >> a >> b;
                cout << endl << "Numbers before 'my_swap'" << endl;
                cout << "a: " << a << " " << "b: " << b << endl;
                my_swap(a, b);
                cout << "Numbers after 'my_swap'" << endl;
                cout << "a: " << a << " " << "b: " << b << endl << endl;
                break;

            case ARRAY: {
                cout << "What type of array do you want?: ";
                cout << "1)int, 2)char" << endl;
                cin >> type;

                switch (type) {
                    case INT: {
                        Array<int> intArr(5);
                        cout << "Enter 5 symbols for the array" << endl;
                        for (int i = 0; i < intArr.getSize(); i++) {
                            int numb;
                            cin >> numb;
                            intArr[i] = numb;
                        }

                        cout << "Array Size: " << intArr.getSize() << endl;
                        cout << "The initial element of the array: " << arrBegin(intArr) << endl;
                        cout << "The last element of the array: " << arrEnd(intArr) << endl;
                        cout << "Let's sort the array: " << endl;
                        intArr.sort();
                        for (int i = 0; i < intArr.getSize(); i++) {
                            cout << intArr[i] << " ";
                        }
                        cout << endl;

                        int numb, elem;
                        bool flag = true;
                        while (flag) {
                            try {
                                cout << "Enter the number of the array element to find out the number" << endl;
                                cin >> numb;
                                elem = intArr[numb - 1];
                                flag = false;
                            }
                            catch (Exception &ex) {
                                cout << "ERROR Message: " << ex.gerError() << endl;
                                flag = true;
                            }
                        }

                        cout << "The element of the array, that now standing under the " << numb << " number: " << elem
                             << endl;
                        cout << "Maximum element in the array: " << max_elem(intArr) << endl;

                        break;
                    }

                    case CHAR: {
                        Array<char> charArr(5);
                        cout << "Enter 5 elements for the array" << endl;
                        for (int i = 0; i < charArr.getSize(); i++) {
                            char elem;
                            cin >> elem;
                            charArr[i] = elem;
                        }

                        cout << "Array Size: " << charArr.getSize() << endl;
                        cout << "The initial element of the array: " << arrBegin(charArr) << endl;
                        cout << "The last element of the array: " << arrEnd(charArr) << endl;
                        cout << "Let's sort the array: " << endl;
                        charArr.sort();
                        for (int i = 0; i < charArr.getSize(); i++) {
                            cout << charArr[i] << " ";
                        }
                        cout << endl;

                        int numb;
                        char element;
                        try {
                            cout << "Enter the number of the array element to find out the number" << endl;
                            cin >> numb;
                            element = charArr[numb - 1];
                        }
                        catch (Exception &ex) {
                            cout << "ERROR Message: " << ex.gerError() << endl;
                            break;
                        }

                        cout << "The element of the array, that now standing under the " << numb << " number: "
                             << element << endl;
                        cout << "The highest letter in the array: " << max_elem(charArr) << endl;

                        break;
                    }

                    default:
                        cout << "There aren't such command... try again!" << endl << endl;
                        break;
                }

                cout << endl;
                break;
            }

            case EXIT:
                return 0;

            default:
                cout << "There aren't such command... try again!" << endl << endl;
                break;
        }
    }
}