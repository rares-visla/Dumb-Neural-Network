#include <stdio.h>
#include <stdlib.h>
#include "neuralnet.h"
#include "datasets.h"

#define NUM_INPUTS 2
#define NUM_LAYERS 1
#define NUM_NEURONS 1 //neurons per layer

void *safe_malloc(size_t size)
{
    void *pointer = malloc(size);
    if (pointer == NULL)
    {
        printf("ERROR MALLOC\n");
        exit(1);
    }
    return pointer;
    
}

//Return random float between 0 and 1
float rand_float()
{
    return (float)rand() / (float)RAND_MAX;
}

int main(int argc, char const *argv[])
{
    Neuralnet simple_nn;
    
    //allocate memory
    simple_nn.layers = safe_malloc(NUM_LAYERS * sizeof(Layer));
    simple_nn.num_layers = NUM_LAYERS;
    for (size_t i = 0; i < simple_nn.num_layers; i++)
    {
        simple_nn.layers[i].neurons = safe_malloc(NUM_NEURONS * sizeof(Neuron));
        simple_nn.layers[i].num_neurons = NUM_NEURONS;
        for (size_t j = 0; j < simple_nn.layers[i].num_neurons; j++)
        {
            simple_nn.layers[i].neurons[j].w = safe_malloc(NUM_INPUTS * sizeof(float));
            simple_nn.layers[i].neurons[j].num_weights = NUM_INPUTS;
        }
    }

    //initialize parameters to random floats
    for (size_t i = 0; i < simple_nn.num_layers; i++)
    {
        for (size_t j = 0; j < simple_nn.layers[i].num_neurons; j++)
        {
            Neuron *neuron = &simple_nn.layers[i].neurons[j];
            for (size_t k = 0; k < neuron->num_weights; k++)
            {
                neuron->w[k] = rand_float() * 10;
            }
            neuron->b = rand_float() * 10;
        } 
    }

    for (size_t i = 0; i < simple_nn.num_layers; i++)
    {
        printf("LAYER %ld\n", i);
        for (size_t j = 0; j < simple_nn.layers[i].num_neurons; j++)
        {
            printf("NEURON %ld\n", j);
            Neuron *neuron = &simple_nn.layers[i].neurons[j];
            for (size_t k = 0; k < neuron->num_weights; k++)
            {
                printf("w%ld = %f\n", k, neuron->w[k]);
            }
            printf("b = %f\n", neuron->b);
        } 
    }
    
    


    return 0;
}
