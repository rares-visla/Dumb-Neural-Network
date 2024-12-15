#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "neuralnet.h"
#include "datasets.h"

#define NUM_INPUTS 2
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
    Neuralnet simple_nn = initialize_nn(NUM_LAYERS, NUM_NEURONS, NUM_INPUTS);

    print_nn(&simple_nn);

    free_nn(&simple_nn);

    return 0;
}
