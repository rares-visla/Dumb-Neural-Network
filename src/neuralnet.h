#pragma once

typedef struct Neuralnet
{
    Layer *layers;
}Neuralnet;

typedef struct Layer
{
    float *Neuron;
}Layer;

typedef struct Neuron
{
    float *w;
    float b;
}Neuron;
