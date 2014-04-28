#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string subtituicao(string letter,string chave)
{
    int aux=23;
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        x= int(x+chave[i%chave.length()]+aux);
        
        aux=int(letter.at(i));
        letter.at(i)=x;
    }
    
       return letter;
}



int main()
{

    string chave, textoClaro, textoCripto;
    
    cout << "Digite o texto a ser critografado: ";
    getline(cin, textoClaro);
    cout << "Digite a chave de criptografia: ";
    cin >> chave;

    textoCripto = subtituicao(textoClaro,chave);
    cout << textoCripto << endl;
    
    system("pause");
    return 0;
}
