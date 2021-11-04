#include "GeneticAlgorithm.h"
/*
struct Member{
    string dna;
    int fitness;
};

struct Population{
    vector<Member> members = vector<Member>(5000);
};

Population population;

void setPopulation(Population pop){
    population = pop;
}

string GeneticAlgorithm::stringToBin(string text) {
    string result;
    for (std::size_t i = 0; i < text.size(); ++i)
    {
        result.append(bitset<8>(text.c_str()[i]).to_string());
    }

    return result;
}

char GeneticAlgorithm::binToChar(string str) {
    char parsed = 0;
    for (int i = 0; i < 8; i++) {
        if (str[i] == '1') {
            parsed |= 1 << (7 - i);
        }
    }
    return parsed;
}

string GeneticAlgorithm::binToString(string bin){

    string result,tmp;
    int i=0;

    while(i<=bin.size()){
        if(i%8!=0 || i==0){
            tmp+=bin[i];
        }
        else{
            result+= binToChar(tmp);
            tmp="";
            tmp+=bin[i];
        }
        i++;
    }
    return result;

}

string GeneticAlgorithm::invert(string text) {
    string binText=stringToBin(text);
    srand(time(nullptr));
    bool greater;

    int second, first=rand()% binText.size()+0 ;
    while(!greater){
        second=rand()% binText.size()+0;
        if(first<second){greater= true;}
    }

    while(first<second){
        if(binText[first]=='0') binText.replace(first,1,"1");
        else binText.replace(first,1,"0");
        first++;
    }
    return binToString(binText);
}

GeneticAlgorithm::GeneticAlgorithm() {
    string dna = "aldfjkl" ; //String we're looking for
    bool sequenceFound = false; //Whether or not the string was found

    int mutationRate = 25; //Mutation probability out of Population number of members
    int inversionRate = 1; //Inversion probability out of Population number of members.
    srand(time(nullptr));
    int generation =0; //Initial Generation

    //Randomizes population
    for(int i =0; i< population.members.size();i++){
        //Resizes parents to be the same size
        population.members.at(i).dna.resize(dna.size());
        for(int j=0; j<dna.size();j++){
            //Randominzes characters for the parents
            population.members.at(i).dna.at(j)=(unsigned char) rand() % 96+32;
        }
        population.members.at(i).fitness=0;
    }


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
                else if(rand()%100==inversionRate){
                    //population.members.at(i).dna.at(j) = invert( population.members.at(i).dna.at(j) ); // Change the char not the string
                }
            }
        }

        cout<< "Generation : "<< generation<< " Highest Fitness : "<< Parents.at(0).fitness<< " with sequence : "<< Parents.at(0).dna.c_str()<< endl;
    }

    cout<<"Generation "<<generation<<" Evolved to the full sequence"<<endl;
    }
    */