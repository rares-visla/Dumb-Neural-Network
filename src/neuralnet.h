#pragma once

typedef struct Neuron
{
    float *w;
    int num_weights;
    float b;
}Neuron;

typedef struct Layer
{
    Neuron *neurons;
    int num_neurons;
}Layer;

typedef struct Neuralnet
{
    Layer *layers;
    int num_layers;
}Neuralnet;
