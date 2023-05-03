#include <iostream>
#include "circular_buffer.h"

enum {
    INSERT_DEL_REAR = 1,
    INSERT_DEL_FRONT,
    INSERT_DEL_ITERATOR,
    ACCESS_FRONT_REAR,
    ACCESS_INDEX,
    CAPACITY,
    EXIT
};

int main() {
    int command;
    cout << "Let the size of our buffer be equal to 5" << endl;

    Circular_Buffer<int> circularBuffer(5);

    while (true) {
        cout << "What can we do:" << endl;
        cout << "1. Inserting and deleting at the end" << endl;
        cout << "2. Inserting and deleting at the beginning" << endl;
        cout << "3. Inserting and deleting to an arbitrary location by iterator" << endl;
        cout << "4. Access to the end, the beginning" << endl;
        cout << "5. Index Access" << endl;
        cout << "6. Changing the capacity" << endl;
        cout << "7. Exit" << endl;
        cout << "What you want?:" << endl;
        cin >> command;
        cout << endl;

        switch (command) {
            case INSERT_DEL_REAR: {
                Circular_Buffer<int> buf(5); // создание кольцевого буфера

                buf.push_back(1);
                buf.display();
                buf.push_back(2);
                buf.display();
                buf.push_back(3);
                buf.display();
                buf.push_back(4);
                buf.display();
                buf.push_back(5);
                buf.display();

                buf.pop_back();
                buf.display();
                cout << endl;
                break;
            }

            case INSERT_DEL_FRONT: {
                Circular_Buffer<int> buf(5); // создание кольцевого буфера

                buf.push_front(1);
                buf.push_front(2);
                buf.push_front(3);
                buf.push_front(4);
                buf.push_front(5);
                buf.display();

                buf.pop_front();
                buf.display();
                cout << endl;
                break;
            }

            case INSERT_DEL_ITERATOR: {
                break;
            }

            case ACCESS_FRONT_REAR: {
                break;
            }

            case ACCESS_INDEX: {
                break;
            }

            case CAPACITY: {
                cout << "Initial capacity: 5" << endl;
                Circular_Buffer<int> buf(5);
                buf.push_back(1);
                buf.push_back(2);
                buf.push_back(3);
                buf.push_back(4);
                buf.push_back(5);
                buf.display();
                cout << "New capacity: 7" << endl;
                buf.change_capacity(7);
                buf.display();
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
