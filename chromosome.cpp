#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "chromosome.h"

using namespace std;


//for now it's only single point crossover
chromosome crossover(chromosome c1, chromosome c2){
    chromosome c_next = c1;
    c_next.generation+=1;
    int gene_length = sizeof c1.genes/sizeof c1.genes[0];
    int cross_point = rand() % 5;
    //crossover until cross_point
    for(int i=0; i<=cross_point; i++){
        c_next.genes[i]=c1.genes[i];
    }
    for(int i=cross_point+1; i<gene_length; i++){
        c_next.genes[i]=c2.genes[i];
    }

    return c_next;
}


chromosome mutate(chromosome c, double chance){
    int gene_length = sizeof c.genes/sizeof c.genes[0];
    for(int i=0; i<gene_length; i++){
        double rand2 = (double)(rand()%100)/100;
        if(rand2<=chance){
            if(c.genes[i]==0){
                c.genes[i]=1;
            }
            else{
                c.genes[i]=0;
            }
        }
    }
    return c;
}

double f_fitness(chromosome c){
    double fitness = 0;
    double bias = 0.000001;
    for(int i=0; i<sizeof c.genes/sizeof c.genes[0]; i++){
        if(c.genes[i]==1){
            fitness++;
        }
    }
    return 1/(fitness+bias);
}

