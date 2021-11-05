#include "HexGeneticAlgo.h"

void HexGeneticAlgo::setTarget(string hexa) {
    this->target=hexa;
}

struct Member{
    string dna;
    int fitness;
};

struct Population{
    vector<Member> members = vector<Member>(20833);
};

Population population;

//Decimal ←→ Hex
string HexGeneticAlgo::decToHex(int dec, int ceros) {

    stringstream ss;
    ss<< hex << dec; // int decimal value
    string res ( ss.str() );

    if(res.size()%ceros!=0){
        int count = ceros-res.size();
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
string HexGeneticAlgo::hexToBin(string hexa) {
    int e = hexToDec(hexa);
    return decToBin(e);

}

string HexGeneticAlgo::binToHex(string bin) {
    return decToHex(binToDec( bin),2);
}
//Binary ←→ Hex

//Genetic Operations
string HexGeneticAlgo::invert(string hexa) {
    string result="" , tmp;
    int dec, complement;

    for(int i=1; i <= hexa.size() / 6; i++){
        tmp="";
        for(int j=0; j<6; j++){
            tmp+=(hexa.at(i * j));
        }
        dec =hexToDec(tmp);     //hexa to dec
        complement=16777215-dec;
        result.append(decToHex(complement,6));
    }
    return result;
}

string HexGeneticAlgo::mutate(string hexa) {

    cout << "Original " << hexa << endl;


    int mutBit= rand()%hexa.size();

    if(mutBit<0 || mutBit>=18){
        cout<<"NOT WORKING NOT WORKINGNOT WORKINGNOT WORKINGNOT WORKINGNOT WORKINGNOT WORKING"<<endl;
        cout<<" Mute bit" <<mutBit<<endl;
    }

    string toReplace;
    toReplace+=hexa[mutBit];

    int decToReplace = hexToDec( toReplace );

    int mutatedDec = 16- decToReplace;
    string mutatedHex = decToHex( mutatedDec  , 1 );
    hexa.replace(mutBit, 1, mutatedHex);

    cout << "Final " << hexa << endl;

    return hexa;
}

void HexGeneticAlgo::populateFromImage(){
    ImageManager imageManager;
    ReadWrite readWrite;
    vector<string> listHex = imageManager.getImageMatrix( readWrite.readFile("image/ti1.ppm") );

    for(int i=0; i<listHex.size();i++){
        population.members.at(i).dna=listHex.at(i);
    }
}

void HexGeneticAlgo::randomizePopulation() {
    ////Randomizes population
    for(int i =0; i< population.members.size();i++){
        //Resizes parents to be the same size
        population.members.at(i).dna.resize(target.size());

        population.members.at(i).dna = decToHex(rand()%16777215,6);

        for(int j=1; j<target.size()/6;j++){
            population.members.at(i).dna.append( decToHex(rand()%16777215,6));
        }
        population.members.at(i).fitness=0;
    }
}

void HexGeneticAlgo::startGeneticAlgo(){
    setTarget("659B982E504E0C3734");
    bool sequenceFound = false;
    int mutationRate = 25; //Mutation probability out of Population number of members
    int inversionRate = 10; //Inversion probability out of Population number of members.
    int generation =0; //Initial Generation

    populateFromImage();

    //Population pop = population;
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
                    j=population.members.at(i).dna.size();
                }
                else if(rand()%100==inversionRate){
                    population.members.at(i).dna = invert(population.members.at(i).dna);
                    j=population.members.at(i).dna.size();
                }
            }
        }
        cout<< "Generation : "<< generation<< " Highest Fitness : "<< Parents.at(0).fitness<< " with sequence : "<< Parents.at(0).dna.c_str()<< endl;
        sequenceFound=true;
    }

    cout<<"Generation "<<generation<<" Evolved to the full sequence"<<endl;
}

//Genetic Operations
HexGeneticAlgo::HexGeneticAlgo() {
    srand(time(nullptr));
}
