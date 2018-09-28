#ifndef CHROMOSOME_H_INCLUDED
#define CHROMOSOME_H_INCLUDED
#include <vector>

using namespace std;


struct chromosome{
    int genes[5];
    int generation;
};

vector<chromosome> crossover(chromosome c1, chromosome c2);
void mutate(chromosome c1);
void tes();

#endif // CHROMOSOME_H_INCLUDED
