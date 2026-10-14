#include "op_amp.h"
#include <iostream>
#include <limits>

using namespace std;

OpAmpCatalog::OpAmpCatalog() {
    cout << "Викликано конструктор\n";
}

OpAmpCatalog::~OpAmpCatalog() {
    cout << "Викликано деструктор\n";
}

void OpAmpCatalog::addAmplifier(double gain, double voltage, int inputs) {
    if (gain <= 0.0) {
        cout << "Помилка: коефіцієнт підсилення має бути > 0!\n";
        return;
    }
    if (voltage <= 0.0 || voltage > 50.0) {
        cout << "Помилка: напруга живлення має бути від 0 (не включно) до 50 В!\n";
        return;
    }
    if (inputs < 1 || inputs > 16) {
        cout << "Помилка: кількість входів має бути від 1 до 16!\n";
        return;
    }

    op_amp_s_t item;
    item.gain = gain;
    item.supplyVoltage = voltage;
    item.inputCount = inputs;
    amplifiers.push_back(item);
}

void OpAmpCatalog::inputAmplifier() {
    double gain;
    double voltage;
    int inputs;

    while (true) {
        cout << "Коефіцієнт підсилення (> 0): ";
        if (cin >> gain && gain > 0.0) {
            break;
        }
        cout << "Помилка: коефіцієнт підсилення має бути > 0!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Напруга живлення (В, 0..50): ";
        if (cin >> voltage && voltage > 0.0 && voltage <= 50.0) {
            break;
        }
        cout << "Помилка: напруга живлення має бути від 0 (не включно) до 50 В!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Кількість входів (1..16): ";
        if (cin >> inputs && inputs >= 1 && inputs <= 16) {
            break;
        }
        cout << "Помилка: кількість входів має бути від 1 до 16!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    addAmplifier(gain, voltage, inputs);
}

void OpAmpCatalog::insertAmplifier(int index, double gain, double voltage, int inputs) {
    if (index < 0 || index > (int)amplifiers.size()) {
        cout << "Помилка: некоректний індекс для вставки!\n";
        return;
    }
    if (gain <= 0.0) {
        cout << "Помилка: коефіцієнт підсилення має бути > 0!\n";
        return;
    }
    if (voltage <= 0.0 || voltage > 50.0) {
        cout << "Помилка: напруга живлення має бути від 0 (не включно) до 50 В!\n";
        return;
    }
    if (inputs < 1 || inputs > 16) {
        cout << "Помилка: кількість входів має бути від 1 до 16!\n";
        return;
    }

    op_amp_s_t item;
    item.gain = gain;
    item.supplyVoltage = voltage;
    item.inputCount = inputs;
    amplifiers.insert(amplifiers.begin() + index, item);
}

void OpAmpCatalog::removeAmplifier(int index) {
    if (index < 0 || index >= (int)amplifiers.size()) {
        cout << "Помилка: некоректний індекс для видалення!\n";
        return;
    }
    amplifiers.erase(amplifiers.begin() + index);
}

void OpAmpCatalog::swapAmplifiers(int i, int j) {
    if (i < 0 || j < 0 || i >= (int)amplifiers.size() || j >= (int)amplifiers.size()) {
        cout << "Помилка: некоректні індекси для обміну!\n";
        return;
    }
    swap(amplifiers[i], amplifiers[j]);
}

void OpAmpCatalog::clearAll() {
    amplifiers.clear();
    cout << "Усі записи очищено.\n";
}

void OpAmpCatalog::setGain(int index, double gain) {
    if (index < 0 || index >= (int)amplifiers.size()) {
        cout << "Помилка: некоректний індекс!\n";
        return;
    }
    if (gain <= 0.0) {
        cout << "Помилка: коефіцієнт підсилення має бути > 0!\n";
        return;
    }
    amplifiers.at(index).gain = gain;
}

void OpAmpCatalog::setSupplyVoltage(int index, double voltage) {
    if (index < 0 || index >= (int)amplifiers.size()) {
        cout << "Помилка: некоректний індекс!\n";
        return;
    }
    if (voltage <= 0.0 || voltage > 50.0) {
        cout << "Помилка: напруга живлення має бути від 0 (не включно) до 50 В!\n";
        return;
    }
    amplifiers.at(index).supplyVoltage = voltage;
}

void OpAmpCatalog::setInputCount(int index, int inputs) {
    if (index < 0 || index >= (int)amplifiers.size()) {
        cout << "Помилка: некоректний індекс!\n";
        return;
    }
    if (inputs < 1 || inputs > 16) {
        cout << "Помилка: кількість входів має бути від 1 до 16!\n";
        return;
    }
    amplifiers.at(index).inputCount = inputs;
}

void OpAmpCatalog::displayAll() const {
    if (amplifiers.empty()) {
        cout << "Немає даних для виведення.\n";
        return;
    }
    for (size_t i = 0; i < amplifiers.size(); i++) {
        cout << "[" << i << "] K = " << amplifiers[i].gain
             << ", Uж = " << amplifiers[i].supplyVoltage << " В"
             << ", входів: " << amplifiers[i].inputCount << endl;
    }
}

void OpAmpCatalog::displayByInputs(int inputs) const {
    bool found = false;
    for (size_t i = 0; i < amplifiers.size(); i++) {
        if (amplifiers[i].inputCount == inputs) {
            cout << "[" << i << "] K = " << amplifiers[i].gain
                 << ", Uж = " << amplifiers[i].supplyVoltage << " В"
                 << ", входів: " << amplifiers[i].inputCount << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Підсилювачів з такою кількістю входів не знайдено.\n";
    }
}
