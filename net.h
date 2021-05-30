#include <cstdint>
#include <cmath>

#include "node.h"

struct connection
{
    node *prev;
    node *next;
    float weight;
};

struct connectionLayer
{
    connection connections[1024];
};

struct layer
{
    int size;
    activationFunction actFunc;
    node nodes[32];

    void init(int numNodes, activationFunction actFunc, bool hasBias)
    {
        size = numNodes;

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
        for (int i = 0; i < size; i++)
        {
            nodes[i].activate();
        }
    }

    //! Needs fixing
    // void calculateInputs(float prevOutputs[], float prevWeights[])
    // {
    //     float sum = 0;

    //     for (int i = 0; i < size; i++)
    //     {
    //         for (int i = 0; i < (int)(sizeof(prevOutputs)); i++)
    //         {
    //             sum += prevOutputs[i] * prevWeights[i];
    //         }

    //         sum += nodes[i].bias;

    //         nodes[i].input = sum;
    //     }
    // }
};

struct network
{
    int numHiddenLayers;
    int numInputs;
    int numOutputs;

    layer input;
    layer output;

    layer hiddenLayers[32];

    connectionLayer connectionLayers[32 + 1];

    void addLayer()
    {
        //TODO
    }

    void removeLayer()
    {
        //TODO
    }

    void connectLayers()
    {
        //* Connecting Input Layer to HiddenLayer[0]
        int k = 0;
        for (int i = 0; i < input.size; i++)
        {
            for (int j = 0; j < hiddenLayers[0].size; j++)
            {
                connectionLayers[0].connections[k] = {&input.nodes[i], &hiddenLayers[0].nodes[j], rand() / float(RAND_MAX)};
                k++;
            }
        }

        //* Connecting all hidden layers
        for (int l = 1; l < numHiddenLayers - 1; l++)
        {
            int k = 0;
            for (int i = 0; i < hiddenLayers[l].size; i++)
            {
                for (int j = 0; j < hiddenLayers[l + 1].size; j++)
                {
                    connectionLayers[l].connections[k] = {&hiddenLayers[l].nodes[i], &hiddenLayers[l + 1].nodes[j], rand() / float(RAND_MAX)};
                    k++;
                }
            }
        }

        //* Connecting last hiddenLayer to output layer
        k = 0;
        for (int i = 0; i < hiddenLayers[numHiddenLayers - 1].size; i++)
        {
            for (int j = 0; j < output.size; j++)
            {
                connectionLayers[numHiddenLayers].connections[k] = {&hiddenLayers[numHiddenLayers - 1].nodes[i], &output.nodes[j], rand() / float(RAND_MAX)};
                k++;
            }
        }
    }

    void init(int numX, int numY, int numHidden, int hiddenLayerSizes[], activationFunction actFuncs[])
    {
        numInputs = numX;
        numOutputs = numY;
        numHiddenLayers = numHidden;

        input.init(numX, linear, false);
        output.init(numY, linear, false);

        for (int i = 0; i < numHiddenLayers; i++)
        {
            hiddenLayers[i].init(hiddenLayerSizes[i], actFuncs[i], true);
        }

        connectLayers();
    }
};