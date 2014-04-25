#include <iostream>
#include <string>
using namespace std;

string subtituicao(string letter,string chave)
{
    int aux=23;
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        x= int(x+chave[i%chave.length()]+aux);
        while(int(x)>=255 ){
                      x-=255;}
        
        aux=int(letter.at(i));
        letter.at(i)=x;
    }
    
       return letter;
}


string descripto(string letter,string chave)
{
    int aux=23;
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        x= int(x-chave[i%chave.length()]-aux);
         while(int(x)<=0 ){
                      x+=255;
         }
   
        letter.at(i)=x;
        aux=int(letter.at(i));
    }
    
       return letter;
}

int main()
{

    string chave, textoClaro, textoCripto;
    
    cout << "Digite o texto para ser criptografado: ";
    getline(cin, textoClaro);
    cout << "Digite a chave de criptografia: ";
    cin >> chave;

    textoCripto = subtituicao(textoClaro,chave);
    cout << textoCripto << endl;
    textoClaro = descripto(textoCripto,chave);
    cout << textoClaro << endl;
    cin >>chave ;
    return 0;
}
