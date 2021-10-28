#include "GeneticAlgorithm.h"

struct Member{
    string dna;
    int fitness;
};

struct Population{
    vector<Member> members = vector<Member>(5000);
};

GeneticAlgorithm::GeneticAlgorithm() {
    string dna = "264e15264e15264e15264e15264e15264e15" ;
    bool sequenceFound = false;
    int mutationRate = 25;
    srand(time(nullptr));

    Population population;

    for(int i =0; i< population.members.size();i++){
        population.members.at(i).dna.resize(dna.size());
        for(int j=0; j<dna.size();j++){
            population.members.at(i).dna.at(j)=(unsigned char) rand() % 96+32;
        }
        population.members.at(i).fitness=0;
    }

    int generation =0;

    while(!sequenceFound){

        generation++;

        for (int i=0; i< population.members.size(); i++){
            population.members.at(i).fitness = 0;
            for(int j=0; j<population.members.at(i).dna.size(); j++){
                if (population.members.at(i).dna.at(j)==dna.at(j)){
                    population.members.at(i).fitness += 10;
                }
                if (population.members.at(i).fitness ==dna.size()*10){
                    sequenceFound= true;
                }
            }
        }

        sort(population.members.begin(), population.members.end(), [](Member const &a, Member &b){return a.fitness>b.fitness;});

        vector<Member> Parents{population.members.at(0),population.members.at(1)};

        for (int i=0; i<population.members.size();i++){
            for (int j=0; j<population.members.at(i).dna.size();j++){
                int tempSelection = rand() % Parents.size();
                population.members.at(i).dna.at(j) = Parents.at(tempSelection).dna.at(j);

                if(rand()%100<mutationRate){
                    population.members.at(i).dna.at(j) = (unsigned char) rand() % 96 +32;
                }
            }
        }

        cout<< "Generation : "<< generation<< " Highest Fitness : "<< Parents.at(0).fitness<< " with sequence : "<< Parents.at(0).dna.c_str()<< endl;
    }

    cout<<"Generation "<<generation<<" Evolved to the full sequence"<<endl;
    cout<<"Press enter to finalize the sesion"<<endl;
    cin >> dna;
    }
