#include <cstdint>
#include <cmath>

enum activationFunction
{
    linear,
    sigmoid,
    tanh,
    relu,
    leakyRelu
};

struct node
{
    float input;
    float output;
    float bias;
    activationFunction actFunc;

    void activate()
    {
        switch (actFunc)
        {
        case linear:
            output = linearActivation(input);
            break;

        case sigmoid:
            output = sigmoidActivation(input);
            break;

        case tanh:
            output = tanhActivation(input);
            break;

        case relu:
            output = reluActivation(input);
            break;

        case leakyRelu:
            output = leakyReluActivation(input);
            break;
        }
    }
};

float linearActivation(float x)
{
    float y;
    y = x;
    return y;
}

float sigmoidActivation(float x)
{
    float y;
    y = x;
    return y;
}

float tanhActivation(float x)
{
    float y;
    y = x;
    return y;
}

float reluActivation(float x)
{
    float y;
    y = 1 / (1 + pow(exp(1.0), (-1 * x)));
    return y;
}

float leakyReluActivation(float x)
{
    float y;
    y = x;
    return y;
}