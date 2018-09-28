#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "chromosome.h"

using namespace std;



vector<chromosome> crossover(chromosome c1, chromosome c2){
    chromosome c1_next, c2_next;
    c1_next.generation=c1.generation+1;
    c2_next.generation=c2.generation+1;


}
void mutate(){
    cout<<"mutate"<<endl;
}
