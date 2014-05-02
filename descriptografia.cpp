#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int valorChar(char letra)
{
   string  caracteres="-uÇq=2[&a4io*sp/5;t3]y6.7,8_9+x>Gc0{¨OPk)jA?D:fFz1<H!J@K#vbL$w}Se%ZçrªXºC¹ghV²B³N£M¢Q¬W§E´Rln`T~Y^U|I(d";
   
    for (int i = 0; i < caracteres.length(); i++)
    {
        if(caracteres[i]==letra)
        {
           return i;
        }
    }
    
    return -1;
   
}

int valorChave(char letra)
{
   string  caracteres="asdfghjklzxcvbnmqwertyuiop1234 567890ASDFGHJKLZXCVBNMQWERTYUIOP";
   
    for (int i = 0; i < caracteres.length(); i++)
    {
        if(caracteres[i]==letra)
        {
           return i;
        }
    }
    
    return -1;
   
}

char charSub(int posicao)
{
    string  caractereSub="asdfghjklzxcvbnmqwertyuiop1234 567890ASDFGHJKLZXCVBNMQWERTYUIOP";
    
    return caractereSub[posicao];
}

string descripto(string letter,string chave)
{
    int incremento=23;
    for (int i = 0; i < letter.length(); i++)
    {
        int x = valorChar(letter[i]);
        if(x==-1)
        {
           return("texto invalido.");
        }
        int chaveAtual = valorChave(chave[i%chave.length()]);
        if(chaveAtual==-1)
        {
           return("Chave invalida.");
        }
        int incrementoTotal = (chaveAtual+incremento)%42;
        
        x-=incrementoTotal;
       
        incremento = x;
        
        
        letter[i]= charSub(x);

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
