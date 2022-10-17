#include <iostream>
#include <string>

using namespace std;

const int MAX_CHAR = 256;

// palabra = HELO = 5
bool uniqueCharacters(string palabra) {
    if(palabra.length() > MAX_CHAR)
        return false;
    bool chars[MAX_CHAR] = { 0 };
    // chars = [0,0,0,0,1,0,0,1,1,0,1,0,.....0]
    for(int i = 0; i < palabra.length(); i++){
        // cout<<int('H');
        // 72
        if(chars[int(palabra[i])] == true)
            return false;
        chars[int(palabra[i])] = true;
    }
    return true;
}

int main(){
    string palabra = "hello";
    int contador = 0;
    bool valor;

    for(int i = 0; i < palabra.length(); i++){
        for(int j = 0; j < palabra.length(); j++){
            if(palabra[i] == palabra[j])
                contador++;
        }
        if(contador >= 2){
            cout<<"false";
            break;
        }
        else{
            contador = 0;
        }
    }

    if(contador == 0){
        cout<<"true";
    }
    
    bool result = uniqueCharacters(palabra);
    cout<<result;

    return 0;
}