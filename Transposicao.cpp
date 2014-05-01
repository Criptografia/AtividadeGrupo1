#import <iostream>
#import <string>

using namespace std;

void descriptografia (string key, string texto){
	cout << "Entrou na Funcao\n";
	cout << "A chave e: "<<key <<endl;
	cout << "O texto antes da transposicao: " <<texto <<endl;	
	
	
	//TRANSPOSICAO
	
	int tam = texto.length();
	cout << tam;
	
	char transp[4][12];
	
	for (int i=0; i<tam;i++){
		if (i<4){
		
		transp[i][0] = texto[i]; 
		}
	}

}


int main () {
	
	string chave = "motocicleta";
	string texto = "minhabicletaedemetal";
	
	
	descriptografia(chave,texto);
	
	return 0;
}
