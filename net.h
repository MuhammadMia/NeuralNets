#include <cstdint>
#include <cmath>

#include "node.h"

struct layer
{
    int numNode;
    activationFunction actFunc;
    node nodes[];

    void init(int numNodes, activationFunction actFunc, bool hasBias)
    {
        numNode = numNodes;
        if (hasBias)
        {
            for (int i = 0; i < numNodes; i++)
            {
                nodes[i] = {0, 0, rand() / float(RAND_MAX), actFunc};
            }
        }
        else
        {
            for (int i = 0; i < numNodes; i++)
            {
                nodes[i] = {0, 0, 0, actFunc};
            }
        }
    }

    void activateLayer()
    {
        for (int i = 0; i < numNode; i++)
        {
            nodes[i].activate();
        }
    }

    void calculateInputs(float prevOutputs[], float prevWeights[])
    {
        float sum = 0;

        for (int i = 0; i < numNode; i++)
        {
            for (int i = 0; i < sizeof(prevOutputs); i++)
            {
                sum += prevOutputs[i] * prevWeights[i];
            }

            sum += nodes[i].bias;

            nodes[i].input = sum;
        }
    }
};

struct network
{
    layer *layers;
    int numHiddenLayers;
    int numInputs;
    int numOutputs;

    void addLayer()
    {
    }

    void removeLayer()
    {
    }
};