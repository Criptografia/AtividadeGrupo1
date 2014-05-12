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
    for (int i = 0; i < letter.length(); i++)
    {
        int x = valorChar(letter[i]);
        if(x==-1)
        {
           return("Caracter invalido.");
        }
        int chaveAtual = valorChar(chave[i%chave.length()]);
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
void transposicao (string texto, string key){
//	cout << "Entrou na Funcao\n";
//	cout << "A chave e: "<<key <<endl;
//	cout << "O texto antes da transposicao: " <<texto <<endl;	


	//TRANSPOSICAO

	int tam = texto.length();



	//DEFINIR O NUMERO DE COLUNAS
	int num_col;

	if (tam%8==0){
		num_col = tam/8;
	}
	else  {
		num_col = (tam/8)+1;
	}

	char transp[8][num_col];
//

	for (int i=0; i<tam;i++){
		if (isspace(texto[i])){
		texto[i]+=1;
		}
		for (int k=1;k<num_col;k++){
			if (i<k*8){
				transp[i%8][0] = texto[i];
				break;
			}
			else if (i>=k*8 && i<(k+1)*8){
				transp[i%8][k] = texto[i];
				break;
			}

		}		


	}

//	EXIBIR A MATRIZ
//	for (int i=0;i<8;i++){
//		for (int j=0;j<num_col;j++){
//		
//		if (j == (num_col-1)){
//		cout << transp[i][j] <<endl;	
//		}
//		else
//		cout << transp[i][j] <<" ";
//		}
//	}


	//APLICAR A CHAVE
//	int change = key.length();
//	char aux[num_col];

//	cout << "Texto depois da transposicao:"; 
	for (int i=0;i<8;i++){
		for (int j=0;j<num_col;j++){
			cout << transp[i][j];
		}
		cout <<" ";	
	}



}



int main(){

    string chave, textoClaro, textoCripto;
    
    ofstream outFile("textoCriptografado.txt",ios_base::out);
    
    ifstream inTexto ("textoClaro.txt", ios_base::in );
    
    ifstream inChave ("chave.txt", ios_base::in );
    
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
                  transposicao(textoClaro,chave);
                  break;
    }

    outFile << textoCripto << endl;


    return 0;
}
