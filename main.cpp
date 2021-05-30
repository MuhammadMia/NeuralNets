#include <iostream>
using namespace std;

#include "net.h"

int main()
{
    network net;

    int hiddenLayerSizes[5] = {28, 24, 16, 12, 8};
    activationFunction actFuncs[5] = {(activationFunction)1, (activationFunction)1, (activationFunction)1, (activationFunction)1, (activationFunction)1};

    net.init(32, 4, 5, hiddenLayerSizes, actFuncs);

    cout << "\nNetwork: ";
    cout << sizeof(net);

    return 0;
}
