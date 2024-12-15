#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "neuralnet.h"
#include "datasets.h"

#define NUM_INPUTS 1
#define NUM_LAYERS 1
#define NUM_NEURONS 1 //neurons per layer

//Malloc with null check
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
    srand(time(0));

    //another idea is to make NUM_INPUTS equal to (sizeof(*train_doubling) / sizeof(float)) - 1 beforehand
    if (NUM_INPUTS != ((sizeof(*train_doubling) / sizeof(float)) - 1)) // -1 because 1 element is the output
    {
        fprintf(stderr,"NUMBER OF DECLARED INPUTS DIFFERS FROM NUMBER OF INPUTS IN THE DATASET");
        exit(1);
    }


    float (*dataset)[NUM_INPUTS + 1] = train_doubling; // +1 to accomodate the output
    int num_samples = sizeof(train_doubling) / sizeof(train_doubling[0]);

    Neuralnet simple_nn = initialize_nn(NUM_LAYERS, NUM_NEURONS, NUM_INPUTS);


    print_nn(&simple_nn);

    //forward propagation
    // float y = 0;
    // for (size_t i = 0; i < simple_nn.num_layers; i++)
    // {
    //     for (size_t j = 0; j < simple_nn.layers[i].num_neurons; j++)
    //     {
    //         Neuron *neuron = &simple_nn.layers[i].neurons[j];
    //         for (size_t k = 0; k < neuron->num_weights; k++)
    //         {
    //             y += neuron->w[k] * dataset[][]
    //         }
            
    //     }
        
    // }

    //mini forward prop with one neuron
    //actually more like cost function
    float cost = 0;
    for (size_t i = 0; i < num_samples; i++)
    {
        Neuron *neuron = &simple_nn.layers[0].neurons[0];
        float y = 0;
        y += neuron->w[0] * dataset[i][0];
        y += neuron->b;
        float distance = y - dataset[i][1];
        distance = distance * distance;
        cost += distance;
    }

    printf("COST: %f\n", cost);
    
    

    free_nn(&simple_nn);

    return 0;
}
