#include <iostream>
#include "op_amp.h"

using namespace std;

int main() {
    cout << "=== Лаб. №8, варіант 10: Операційний підсилювач (vector) ===\n\n";

    OpAmpCatalog catalog;

    cout << "1. Додавання (push_back):\n";
    catalog.addAmplifier(100.0, 15.0, 2);
    catalog.addAmplifier(50.0, 12.0, 1);
    catalog.addAmplifier(200.0, 9.0, 2);
    catalog.displayAll();

    cout << "\n1a. Введення одного об'єкта з клавіатури (метод inputAmplifier):\n";
    catalog.inputAmplifier();
    catalog.displayAll();

    cout << "\n2. Вставка на позицію 1:\n";
    catalog.insertAmplifier(1, 80.0, 5.0, 4);
    catalog.displayAll();

    cout << "\n3. Обмін елементів [0] і [2]:\n";
    catalog.swapAmplifiers(0, 2);
    catalog.displayAll();

    cout << "\n4. Видалення елемента [1]:\n";
    catalog.removeAmplifier(1);
    catalog.displayAll();

    cout << "\n5. Зміна полів і валідація:\n";
    catalog.setGain(0, 150.0);
    catalog.setGain(0, -5.0);
    catalog.addAmplifier(0.0, 12.0, 2);
    catalog.displayAll();

    cout << "\n6. Підсилювачі з 2 входами:\n";
    catalog.displayByInputs(2);

    cout << "\n7. Очищення:\n";
    catalog.clearAll();
    catalog.displayAll();

    return 0;
}
