#include "neuralnet.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void *safe_malloc(size_t size);
float rand_float();

Neuralnet allocate_nn_memory(int num_layers, int num_neurons, int num_inputs)
{
    Neuralnet simple_nn;
    
    simple_nn.layers = safe_malloc(num_layers * sizeof(Layer));
    simple_nn.num_layers = num_layers;
    for (size_t i = 0; i < simple_nn.num_layers; i++)
    {
        simple_nn.layers[i].neurons = safe_malloc(num_neurons * sizeof(Neuron));
        simple_nn.layers[i].num_neurons = num_neurons;
        for (size_t j = 0; j < simple_nn.layers[i].num_neurons; j++)
        {
            simple_nn.layers[i].neurons[j].w = safe_malloc(num_inputs * sizeof(float));
            simple_nn.layers[i].neurons[j].num_weights = num_inputs;
        }
    }

    return simple_nn;
}

Neuralnet initialize_nn(int num_layers, int num_neurons, int num_inputs)
{
    Neuralnet nn = allocate_nn_memory(num_layers, num_neurons, num_inputs);

    for (size_t i = 0; i < nn.num_layers; i++)
    {
        for (size_t j = 0; j < nn.layers[i].num_neurons; j++)
        {
            Neuron *neuron = &nn.layers[i].neurons[j];
            for (size_t k = 0; k < neuron->num_weights; k++)
            {
                neuron->w[k] = rand_float() * 10;
            }
            neuron->b = rand_float() * 10;
        } 
    }

    return nn;
}

void print_nn(Neuralnet *nn)
{
    for (size_t i = 0; i < nn->num_layers; i++)
    {
        printf("LAYER %ld\n", i);
        for (size_t j = 0; j < nn->layers[i].num_neurons; j++)
        {
            printf("NEURON %ld\n", j);
            Neuron *neuron = &nn->layers[i].neurons[j];
            for (size_t k = 0; k < neuron->num_weights; k++)
            {
                printf("w%ld = %f\n", k, neuron->w[k]);
            }
            printf("b = %f\n", neuron->b);
        } 
    }
}

void free_nn(Neuralnet *nn)
{
    for (size_t i = 0; i < nn->num_layers; i++)
    {
        for (size_t j = 0; j < nn->layers[i].num_neurons; j++)
        {
            free(nn->layers[i].neurons[j].w);
        }
        free(nn->layers[i].neurons);
    }
    free(nn->layers);
}