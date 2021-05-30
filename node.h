#include <cstdint>
#include <cmath>

enum activationFunction
{
    linear = 0,
    sigmoid = 1,
    tan_h = 2,
    relu = 3,
    leakyRelu = 4
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
        case 0:
            output = linearActivation(input);
            break;

        case 1:
            output = sigmoidActivation(input);
            break;

        case 2:
            output = tanhActivation(input);
            break;

        case 3:
            output = reluActivation(input);
            break;

        case 4:
            output = leakyReluActivation(input);
            break;
        }
    }
};
