#include <iostream>
#include <string>

using namespace std;

int main () {

  string frase= " Mcto iien ncm hl! aeg !tu bai i!d";
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
  
return 0;
}