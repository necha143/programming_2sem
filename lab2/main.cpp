#include "Subset.h"

class menu {
private:
    int command;
public:
    void our_menu() {
        cout << "1. Checking for the content of an element in the set" << endl;
        cout << "2. Adding an element to a set" << endl;
        cout << "3. Removing an element from a set" << endl;
        cout << "4. Finding intersections of sets" << endl;
        cout << "5. Finding unions of sets" << endl;
        cout << "6. Changes sets" << endl;
        cout << "7. Exit" << endl;
        cout << "What you want to do?" << endl;
        cin >> command;

        if (command == 1) {
            cout << endl;
            first_func();
        } else if (command == 2) {
            cout << endl;
            second_func();
        } else if (command == 3) {
            cout << endl;
            third_func();
        } else if (command == 4) {
            cout << endl;
            fourth_func();
        } else if (command == 5) {
            cout << endl;
            fifth_func();
        } else if (command == 6) {
            cout << endl;
            sixth_func();
        } else if (command == 7) {
            cout << endl;
            ::exit(0);
        } else {
            cout << endl;
            cout << "There are no such comand" << endl;
            cout << endl;
            our_menu();
        }
    }


    void first_func() {
        cout << "Enter the size of the set" << endl;

        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            arr.push_back(i);
        }
        Subset a(n, arr);

        cout << "Enter a number to check" << endl;
        int numb;
        cin >> numb;

        if (numb == a) {
            cout << "Such number exists";
        } else {
            cout << "There is no such number";
        }
    }

    void second_func() {
        cout << "Enter the size of the set" << endl;

        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            arr.push_back(i);
        }

        cout << "Enter a number to add" << endl;
        int numb;
        cin >> numb;
        n++;

        Subset a(n, arr);
        a += numb;
        cout << "New set: ";
        a.Display();
    }

    void third_func() {
        cout << "Enter the size of the set" << endl;

        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            arr.push_back(i);
        }

        cout << "Enter a number to remove from the set" << endl;
        int numb;
        cin >> numb;
        Subset a(n, arr);
        n--;

        a -= numb;
        cout << "New set: ";
        a.Display();
    }

    void fourth_func() {
        cout << "Enter the size of the sets" << endl;

        int n;
        cin >> n;
        vector<int> x;
        vector<int> y;
        for (int i = 1; i <= n; i++) {
            x.push_back(i);
            y.push_back(i + 2);
        }

        Subset a(n, x);
        Subset b(n, y);
        Subset c = a ^ b;

        cout << "The set with the intersection of a and b: ";
        c.Display();
    }

    void fifth_func() {
        cout << "Enter the size of the sets" << endl;

        int n;
        cin >> n;
        vector<int> x;
        vector<int> y;
        for (int i = 1; i <= n; i++) {
            x.push_back(i);
            y.push_back(i + 2);
        }

        Subset a(n, x);
        Subset b(n, y);
        Subset c = a < b;

        cout << "The set with the unions of a and b: ";
        c.Display();
    }

    void sixth_func() {
        cout << "Enter the size of the sets" << endl;

        int n;
        cin >> n;
        vector<int> x;
        vector<int> y;
        for (int i = 1; i <= n; i++) {
            x.push_back(i);
            y.push_back(i + 3);
        }

        Subset a(n, x);
        Subset b(n, y);
        Subset c = a > b;
        
        cout << "A set consisting of elements 'a' and 'b', but not two at the same time: ";
        c.Display();
    }

} Menu;

int main() {
    Menu.our_menu();
    return 0;
}