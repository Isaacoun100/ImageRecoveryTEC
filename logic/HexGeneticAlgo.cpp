#include "HexGeneticAlgo.h"

void HexGeneticAlgo::setTarget(string hex) {
    this->target=hex;
}

struct Member{
    string dna;
    int fitness;
};

struct Population{
    vector<Member> members = vector<Member>(500000);
};

Population population;

//Decimal ←→ Hex
string HexGeneticAlgo::decToHex(int dec) {
    stringstream ss;
    ss<< hex << dec; // int decimal value
    string res ( ss.str() );

    if(res.size()%6!=0){
        int count = 6-res.size()%6;
        string fix;
        while (0<count){
            fix.append("0");
            count--;
        }
        res=fix+res;
    }

    return res;
}

int HexGeneticAlgo::hexToDec(string hex) {
    int dec;
    std::stringstream ss;
    ss  << hex ;
    ss >> std::hex >> dec ; //int decimal value
    return dec;
}
//Decimal ←→ Hex

//Decimal ←→ Bin
string decToBinAux(int dec, string result) {
    if(dec != 0) result.append(decToBinAux(dec / 2, result));
    if(dec != 0) result.append(to_string(dec % 2));
    return result;
}

string HexGeneticAlgo::decToBin(int dec) {
    return decToBinAux(dec,"");
}

int HexGeneticAlgo::binToDec(string bin) {
    int val = 0, temp = 1,len = bin.length();
    for (int i = len - 1; i >= 0; i--) {
        if (bin[i] == '1')val += temp;
        temp = temp * 2;
    }
    return val;
}
//Decimal ←→ Bin

//Binary ←→ Hex
string HexGeneticAlgo::hexToBin(string hex) {
    return decToBin(hexToDec(hex) );
}

string HexGeneticAlgo::binToHex(string bin) {
    return decToHex(binToDec( bin ));
}
//Binary ←→ Hex

//Genetic Operations
string HexGeneticAlgo::invert(string hex) {
    string result="" , tmp;
    int dec, complement;

    for(int i=1; i<=hex.size()/6;i++){
        tmp="";
        for(int j=0; j<6; j++){
            tmp+=(hex.at(i*j));
        }
        dec =hexToDec(tmp);     //hex to dec
        complement=16777215-dec;
        result.append(decToHex(complement));
    }

    return result;
}

string HexGeneticAlgo::mutate(string hex) {
    string result = hexToBin(hex);
    srand(time(nullptr));
    int mutBit=rand()%result.size();

    if(result.at(mutBit)=='0') result.replace(mutBit,1,"1");
    else if (result.at(mutBit)=='1') result.replace(mutBit,1,"0");

    return binToHex(result);
}

void HexGeneticAlgo::randomizePopulation() {
    ////Randomizes population
    for(int i =0; i< population.members.size();i++){
        //Resizes parents to be the same size
        population.members.at(i).dna.resize(target.size());

        population.members.at(i).dna = decToHex(rand()%16777215);

        for(int j=1; j<target.size()/6;j++){
            population.members.at(i).dna.append( decToHex(rand()%16777215));
        }
        population.members.at(i).fitness=0;
    }
}

//Genetic Operations
HexGeneticAlgo::HexGeneticAlgo() {
    setTarget("659B982E504E0C3734");
    bool sequenceFound = false;
    int mutationRate = 250; //Mutation probability out of Population number of members
    int inversionRate = 10; //Inversion probability out of Population number of members.
    int generation =0; //Initial Generation
    srand(time(nullptr));

    randomizePopulation();

    Population pop = population;
    while (!sequenceFound){
        generation++;
        for (int i=0; i< population.members.size(); i++){
            population.members.at(i).fitness = 0;
            for(int j=0; j<population.members.at(i).dna.size(); j++){
                if (population.members.at(i).dna.at(j)==target.at(j)){
                    population.members.at(i).fitness += 10;
                }
                if (population.members.at(i).fitness ==target.size()*10){
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
                    population.members.at(i).dna= mutate(population.members.at(i).dna);
                    j=population.members.size();
                }
                else if(rand()%100==inversionRate){
                    population.members.at(i).dna = invert(population.members.at(i).dna);
                    j=population.members.size();
                }
            }
        }
        cout<< "Generation : "<< generation<< " Highest Fitness : "<< Parents.at(0).fitness<< " with sequence : "<< Parents.at(0).dna.c_str()<< endl;
    }

    cout<<"Generation "<<generation<<" Evolved to the full sequence"<<endl;
}
