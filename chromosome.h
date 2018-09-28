#ifndef CHROMOSOME_H_INCLUDED
#define CHROMOSOME_H_INCLUDED
#include <vector>

using namespace std;


struct chromosome{
    int genes[5];
    int generation;
    double fitness;
};

chromosome crossover(chromosome c1, chromosome c2);
chromosome mutate(chromosome c1, double chance);
double f_fitness(chromosome c);

#endif // CHROMOSOME_H_INCLUDED
