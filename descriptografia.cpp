#include <iostream>
#include <fstream.h> 
using namespace std;
int valorChar(char letra)
{
   string  caracteres="-uÇq=2[&a4io*sp/5;t3]y6.7,8_9+x>Gc0{OPk)jA?D:fFz1<H!J@K#vbL$w}Se%ZçrªXºC¹ghV²B³N£M¢Q¬W§E´Rln`T~Y^U|I(d";
   
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

string desSubstituicao(string letter,string chave)
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
        int incrementoTotal = (chaveAtual+incremento)%41;
        
        x-=incrementoTotal;
       
        incremento = x;
        
        
        letter[i]= charSub(x);

    }
    
       return letter;
}
void desTransposicao(string frase){

    int palavras=0,j=0;
    
      //cout << frase<<endl;
      
      for (int i=1;i<100;i++){
        if (frase[i] == ' '){
          j=i-1;
         // cout <<j <<endl;
          break;
        }
      }
    
      for (int d=1;d<=j;d++){
        for (int i=0; i<1000;i++){
          if (frase[i] == ' '){
            palavras++;	
          cout << frase[i+=d] << " ";
        }
       }
      }
    cout <<endl;

}

int main()
{

    string chave, textoClaro, textoCripto;
    
    ifstream inTexto("textoCriptografado.txt",ios_base::in);
    
    ifstream inChave ("chave.txt", ios_base::in );
    
    ofstream outFile ("textoDescriptografado.txt", ios_base::out );
    
    getline(inTexto, textoCripto);
    getline(inChave, chave);
    
    
    int opcao;

     cout << "Escolha a opcao: "<< endl<<"1 - Substituicao "<< endl <<"2 - Transposicao "<< endl<<"3 - Substituicao e Transposicao "<<endl  ;
    cin >> opcao;
      
    switch(opcao){
                  case 1:
                  textoClaro = desSubstituicao(textoCripto,chave);
                  break;
                  case 3:
                  case 2:
                  desTransposicao(textoCripto);
                  break;
    }

    outFile << textoClaro << endl;


    return 0;
}
