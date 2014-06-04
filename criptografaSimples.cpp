#include <iostream>
#include <fstream.h> 
using namespace std;

int valorChar(char letra)
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
    string  caractereSub="-uÇq=2[&a4io*sp/5;t3]y6.7,8_9+x>Gc0{OPk)jA?D:fFz1<H!J@K#vbL$w}Se%ZçrªXºC¹ghV²B³N£M¢Q¬W§E´Rln`T~Y^U|I(d";
    
    return caractereSub[posicao];
}

string subtituicao(string letter,string chave)
{
    int incremento=23;
    int chaveAtual=0;
    for (int i = 0; i < letter.length(); i++)
    {
        int x = valorChar(letter[i]);
        if(x==-1)
        {
           return("Caracter invalido.");
        }
        chaveAtual = valorChar(chave[i%chave.length()]);
        if(chaveAtual==-1)
        {
           return("Chave invalida.");
        }
        int incrementoTotal = (chaveAtual+incremento)%41;
        
        x+=incrementoTotal;
       
        incremento = valorChar(letter[i]);
        
        
        letter[i]= charSub(x);

    }
    
       return letter;
}



string transposicao (string texto, string chave){

     int posicao[8];
     
     for(int i=0; i<8; i++){
             posicao[i]=-1;
     }
     
     int incremento=23;
     int chaveAtual=0;
     int incrementoTotal=0;     
     
     for(int i=0; i<8; i++){
             int teste=0;
             
             chaveAtual = valorChar(chave[i%chave.length()]);
             incrementoTotal = (chaveAtual+incremento)%8;
          
             
             do{
              
                 
                 if(posicao[incrementoTotal]== -1){
                      posicao[incrementoTotal]=i;
                      

                 }
                 else{
                      if(teste==1){
                           incrementoTotal++;
                      }
                      if(incrementoTotal>0 && teste==0){
                           incrementoTotal--;
                      }
                      else{
                           teste=1;       
                      }
                 }
                 
             }while( posicao[incrementoTotal]!= i );
             
             incremento=incrementoTotal;
     }
     
     int incrementoFinal=0;
     string textoFinal=texto;
     for (int i = 0; i < texto.length(); i++){
        int posicaoFinal=posicao[i%8],incrementoPosicao=i/8, diferenca=texto.length()%8;
      
        if (texto.length()-i>diferenca){
            textoFinal[posicaoFinal+incrementoPosicao*8]=texto[i];
        }
        else{
             posicaoFinal=posicao[(i+incrementoFinal)%8];
        
             while(true){

                 if (posicaoFinal>=diferenca){
                    incrementoFinal ++;
                 
                    posicaoFinal=posicao[(i+incrementoFinal)%8];
                 }
                 else{
                       textoFinal[posicaoFinal+incrementoPosicao*8]=texto[i];
                      break;
                 }
            
            } 
        }
    }
    return textoFinal;
}



int main(){

    string chave, textoClaro, textoCripto;
    
    ifstream inTexto ("textoClaro.txt", ios_base::in );
    
    ifstream inChave ("chave.txt", ios_base::in );
    
    ofstream outFile("textoCriptografado.txt",ios_base::out);
    
    getline(inTexto, textoClaro);
    getline(inChave, chave);
  
    int opcao=0;
    
    cout << "Escolha a opcao: "<< endl<<"1 - Substituicao "<< endl <<"2 - Transposicao "<< endl<<"3 - Substituicao e Transposicao "<<endl  ;
    cin >> opcao;
      
    switch(opcao){
                  case 1:
                  textoCripto = subtituicao(textoClaro,chave);
                  break;
                  case 3:
                  textoClaro = subtituicao(textoClaro,chave);
                  case 2:
                  textoCripto=transposicao(textoClaro,chave);
                  break;
    }
    
    outFile << textoCripto << endl;

    return 0;
}
