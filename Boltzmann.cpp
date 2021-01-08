// Size -> size:40, #particle:1000
// Head File
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
// Class Defination 
class particle{
    public:
        particle(float energy, int times);
        ~particle();
        void _changeEnergy(class particle *p1, class particle *p2);
        int times;
        float energy;
};
static long long count = 0;
// Defination of functions in class
// Constructor
inline particle::particle(float energy=5, int times=0):energy(energy),times(times){
    count++;
}
// Destructure
particle::~particle(){
    count--;
}
// Change the Energy
void particle::_changeEnergy(class particle *p1, class particle *p2){
    // std::cout << "Enter the _changeEnergy()"<< std::endl;
    //unsigned seed;
    int judgment = rand()%2;
    //std::cout << judgment<< std::endl;
    if(judgment && p2->energy>0){
        (p1->energy)++;
        (p2->energy)--;
    // count++;
    }
    else if (!judgment && p1->energy>0)
    {
        (p1->energy)--;
        (p2->energy)++;
        
    }
}
// Main Function
int main(){
    // Variable Defination
    particle Boltzmann[1000];
    for(int index=0; index< 1000; index++){
        int index01=0;
            unsigned seed;
            seed=time(0);
            srand(seed);
        while(index01<40){
            int other = rand()%1000;
            //std::cout << "The value of \'other\' is "<< other<< std::endl;
            if(index!=other){
                Boltzmann[index]._changeEnergy(&Boltzmann[index], &Boltzmann[other]);
                index01++;
                //std::cout << "The other particle is: "<< other<< " and their energy after exchangement is: "<< Boltzmann[index].energy<< " and "<< Boltzmann[other].energy<< std::endl;
            }else{
                continue;
            }
        }
    }
    int count[500]={0};
    for(int i=0; i<1000; i++){
        for(int j=0; j<500; j++){
            if(Boltzmann[i].energy==j){
                count[j]++;
                continue;
            }
        }
    }
    for(int k=0; k<500; k++){
        std::cout << "the number of paticles with energy:" << k<< " is "<< count[k]<< std::endl;
    }
    int sum=0;
    
    for(int l=0; l<500; l++){
        sum+=count[l];
    }
    /*
    for(int m=0; m<1000;m++){
        std::cout << "The energy of particle "<< m <<"is: "<< Boltzmann[m].energy<< std::endl;
    }
    */
    std::cout << sum<< std::endl;
    // std::cout << "The value of count is "<< count<< std::endl;
    FILE * fp;
    if((fp = fopen("text.txt","wb"))==NULL){
        printf("cant open the file");
        exit(0);
    }
    for(int o=0; o<500; o++){
        fprintf(fp,"%d \n",count[o]);
    }
    fclose(fp);
    return 0;
}
