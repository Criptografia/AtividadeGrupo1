#include <iostream>
#include <string>

using namespace std;

void transposicao (string key, string texto){
	cout << "Entrou na Funcao\n";
	cout << "A chave e: "<<key <<endl;
	cout << "O texto antes da transposicao: " <<texto <<endl;	
	
	
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
	
	
	//ALOCAR CADA LETRA EM SEU ESPACO
	
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
	int change = key.length();
	char aux[num_col];
		
	cout << "Texto depois da transposicao:"; 
	for (int i=0;i<8;i++){
		for (int j=0;j<num_col;j++){
			cout << transp[i][j];
		}
		cout <<" ";	
	}
	
	

}


int main () {
	
	string chave = "motoneta";
	string texto = "Minha bicicleta tem guidon";
	
	
	transposicao(chave,texto);
	
	return 0;
}
