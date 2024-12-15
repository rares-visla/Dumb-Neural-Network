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


//Allocate memory
static Neuralnet allocate_nn_memory(int num_layers, int num_neurons, int num_inputs);

//Allocate memory and initialize parameters to random floats
Neuralnet initialize_nn(int num_layers, int num_neurons, int num_inputs);

//Print neural network
void print_nn(Neuralnet *nn);

//Free memory
void free_nn(Neuralnet *nn);