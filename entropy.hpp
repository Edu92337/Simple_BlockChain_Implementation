#include<iostream>
#include<random>
#include<vector>
#include<string>
using namespace std;
const unsigned char N[32] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
    0xBA, 0xAE, 0xDC, 0xE6, 0xAF, 0x48, 0xA0, 0x3B,
    0xBF, 0xD2, 0x5E, 0x8C, 0xD0, 0x36, 0x41, 0x41
};

bool is_valid_entropy(const vector<unsigned char>& entropy){
    //verificar se o tamanho é 32 bytes
    bool at_least_one_non_zero = false;
    bool less_than_N = true;
    if(entropy.size()!=32){
        return false;
    }
    //verificar se não é todo zeros
    for(auto byte: entropy){
        if(byte!=0){
            at_least_one_non_zero = true;
            break;
        }
    }
    //varificar se é menor que N
    for(size_t i=0;i<32;i++){
        if(entropy[i]>N[i]){
            less_than_N = false;
            break;
        }
    }
    if(at_least_one_non_zero && less_than_N){
        return true;
    }
    
    return false;
}
vector<unsigned char>generate_entropy(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 255);
    size_t size_key = 32;
    vector<unsigned char>entropy(size_key);
    do{
        for(int i = 0;i<size_key;i++){
            entropy[i] = (unsigned char)dis(gen);
        }
    }while(is_valid_entropy(entropy)==false);
    
    return entropy;
}

