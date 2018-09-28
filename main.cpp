#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include "chromosome.h"

using namespace std;


void init_population(int a);
void print_population();
void genetic_algorithm_driver();

vector<chromosome> population;
const int INIT_POP = 2;
const double FITNESS_MIN = 0.2001;
const double MUTATE_RATE = 0.1;

int main()
{
    cout<<"INIT of Genetic Algorithm"<<endl;
    cout<<"initial population = "<<INIT_POP<<endl;
    cout<<"minimum fitness value = "<<FITNESS_MIN<<endl;
    cout<<"mutation rate = "<<MUTATE_RATE<<endl;
    cout<<endl;
    srand(time(NULL)); //randomize seed initialization
    genetic_algorithm_driver();


    return 0;
}

void init_population(int pop_num){
    population.clear();
    for(int i=0; i<pop_num; i++){
        int temp_chrom[5];
        for(int j=0; j<sizeof temp_chrom/sizeof temp_chrom[0]; j++){
            //randomize the geness
            int gene = rand() % 2; // generate a random number between 0 and n-1
            temp_chrom[j] = gene;
        }
        chromosome c;
        c.generation=0;
        copy(begin(temp_chrom), end(temp_chrom), begin(c.genes));
        population.push_back(c);
    }
}

void print_population(){
    cout<<"Generation : "<<population[0].generation<<endl;
    for(int i=0; i<population.size(); i++){
        cout<<"Genes : ";
        for(int j=0; j<sizeof population[i].genes/sizeof population[i].genes[0]; j++){
            cout<<population[i].genes[j];
        }
        cout<<endl;
    }
}

void genetic_algorithm_driver(){
    init_population(INIT_POP);
    //get the minimum fitness from current generation
    chromosome c_fit;
    double fit_current;
    fit_current=f_fitness(population[0]);
    for(int i=0; i<population.size(); i++){
        double fitness = f_fitness(population[i]);
        if(fitness<fit_current){
            fit_current = fitness;
            c_fit = population[i];
        }
    }
    print_population();
    //print fittest
    cout<<"Fittest chromosome = ";
    for(int i=0; i<sizeof c_fit.genes/sizeof c_fit.genes[0]; i++){
        cout<<c_fit.genes[i];
    }
    cout<<", with fitness value = "<<fit_current<<endl<<endl;
    while(fit_current>FITNESS_MIN){
        vector<chromosome> v_pop_generation;
        //do crossovers & mutations
        int pop_size = population.size();
        for(int i=0; i<pop_size; i++){
            for(int j=0; j<pop_size; j++){
                if(i!=j){
                    chromosome c_next = crossover(population[i], population[j]);
                    c_next = mutate(c_next, MUTATE_RATE);
                    v_pop_generation.push_back(c_next);
                }
            }
        }
        //calculate the minimum fitness
        fit_current = f_fitness(v_pop_generation[0]);
        for(int i=0; i<v_pop_generation.size(); i++){
            double fitness = f_fitness(v_pop_generation[i]);
            if(fitness<fit_current){
                fit_current = fitness;
                c_fit = v_pop_generation[i];
            }
        }

        //move current generation to population vector
        population.clear();
        copy(v_pop_generation.begin(), v_pop_generation.end(), back_inserter(population));
        print_population();

        //print fittest
        cout<<"Fittest chromosome = ";
        for(int i=0; i<sizeof c_fit.genes/sizeof c_fit.genes[0]; i++){
            cout<<c_fit.genes[i];
        }
        cout<<", with fitness value = "<<fit_current<<endl<<endl;
    }
}

