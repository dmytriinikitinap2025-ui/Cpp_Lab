#ifndef OP_AMP_H
#define OP_AMP_H

#include <string>
#include <vector>

struct op_amp_s_t {
    double gain;
    double supplyVoltage;
    int inputCount;
};

class OpAmpCatalog {
private:
    std::vector<op_amp_s_t> amplifiers;

public:
    OpAmpCatalog();
    ~OpAmpCatalog();

    void addAmplifier(double gain, double voltage, int inputs);
    void inputAmplifier();
    void insertAmplifier(int index, double gain, double voltage, int inputs);
    void removeAmplifier(int index);
    void swapAmplifiers(int i, int j);
    void clearAll();

    void setGain(int index, double gain);
    void setSupplyVoltage(int index, double voltage);
    void setInputCount(int index, int inputs);

    void displayAll() const;
    void displayByInputs(int inputs) const;
};

#endif
