#include "Base.h"
#include "Segment.h"
#include "Trapezoid.h"


int main() {
    vector<IFigure *> figures_arr; // вектор для хранения фигур
    int command;
    int memory;
    double sum_area, sum_per;
    CVector2D centerMass;

    while (true) {
        cout << "1. Add figure " << endl;
        cout << "2. Show all figures" << endl;
        cout << "3. Sum all areas" << endl;
        cout << "4. Sum all perimeters" << endl;
        cout << "5. System weight center" << endl;
        cout << "6. Show using memory" << endl;
        cout << "7. Sort" << endl;
        cout << "8. Exit" << endl;
        cout << "What you want?: ";
        cin >> command;
        cout << endl;

        switch (command) {
            case ADD:
                cout << "1. Segment" << endl;
                cout << "2. Trapezoid" << endl;
                cout << "What you want to add?: ";
                cin >> command;
                cout << endl;
                switch (command) {
                    case SEGMENT:
                        figures_arr.push_back(new Segment());
                        break;
                    case TRAPEZOID:
                        figures_arr.push_back(new Trapezoid());
                        break;
                    default:
                        cout << "There aren't such figure..." << endl;
                        break;
                }
                break;

            case SHOW:
                for (auto &figure: figures_arr) { //auto сам определяет тип переменной
                    figure->draw();
                }
                break;

            case SUM_AREAS:
                sum_area = 0;
                for (auto &figure: figures_arr) {
                    sum_area += figure->square();
                }
                cout << "Sum of areas: " << sum_area << endl;
                cout << endl;
                break;

            case SUM_PERIMETERS:
                sum_per = 0;
                for (auto &figure: figures_arr) {
                    sum_per += figure->perimeter();
                }
                cout << "Sum of perimeters: " << sum_per << endl;
                cout << endl;
                break;

            case CENTRE_MASS: // геометрическая точка, положение которой определяется распределением массы в теле
                for (auto &figure: figures_arr) {
                    centerMass.x += figure->position().x * figure->mass();
                    centerMass.y += figure->position().y * figure->mass();
                }
                cout << "Center of mass: " << centerMass << endl;
                cout << endl;
                break;

            case MEMORY:
                memory = 0;
                for (auto &figure: figures_arr) {
                    memory += figure->size();
                }
                cout << "Memory involved: " << memory << endl;
                cout << endl;
                break;

            case SORT:
                sort(figures_arr.begin(), figures_arr.end(), [](IFigure *x, IFigure *y) { return *x < *y; });
                cout
                        << "Figures weight: ";                         // Компаратор — это функция, которая как бы учит сортировать sort
                for (auto &figure: figures_arr) {
                    cout << figure->className() << "=" << figure->mass() << " ";
                }
                cout << endl;
                cout << endl;
                break;

            case EXIT:
                return 0;

            default:
                cout << "There aren't such command... try again!" << endl;
                cout << endl;
                break;
        }
    }
}