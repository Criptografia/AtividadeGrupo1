#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


string descripto(string letter,string chave)
{
    int aux=23;
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        x= int(x-chave[i%chave.length()]-aux);
   
        letter.at(i)=x;
        aux=int(letter.at(i));
    }
    
       return letter;
}

int main()
{

    string chave, textoClaro, textoCripto;
    
    cout << "Digite o texto critografado: ";
    getline(cin, textoCripto);
    cout << "Digite a chave de criptografia: ";
    cin >> chave;

    textoClaro = descripto(textoCripto,chave);
    cout << textoClaro << endl;

    system("pause");
    return 0;
}
