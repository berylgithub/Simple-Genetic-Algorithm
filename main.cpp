#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
#include "chromosome.h"

using namespace std;


void init_population(int a);
void print_population();

vector<chromosome> population;

int main()
{
    chromosome c1, c2;
    crossover(c1, c2);
    int A[5]={1,2,3421,54,6};
    int b[5];
    copy(begin(A), end(A), begin(b));
    init_population(5);
    print_population();
    return 0;
}

void init_population(int pop_num){
    srand(time(NULL)); //randomize seed initialization
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

