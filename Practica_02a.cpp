/*
Arquitectura de Computadores 2022-01 (CCOMP3-1)
Universidad Católica San Pablo, Arequipa–Perú
Prof.: Yván Jesús Túpac Valdivia

Alumno: Alexander Carpio Mamani

División de enteros
*/

#include <iostream>
#include <bitset>
using namespace std;

int main(){
	const int n_bits = 4;
	int A=0, M=3, Q=7, Count=n_bits;
	bitset<n_bits> binary_Q (Q), binary_A (A);
	
	while(Count>0){
		binary_A <<= 1;
		binary_A[0] = binary_Q[3];
		A = binary_A.to_ulong();   // binario a psudo-entero
		
		binary_Q <<= 1;  // 101? => 0100
		
		A -= M;
		
		if (A >= 0){
			binary_Q[0] = 1;  // 0100 => 0101
		}
		else{
			A += M;
		}
		
		bitset<n_bits> aux(A);
		binary_A = aux;
		Q = binary_Q.to_ulong();
		Count--;
	}
	cout<<" Tipos\t\tBinario\t| Decimales"<<endl;
	cout<<" Cociente\t"<<binary_Q<<"\t\t"<<Q<<endl;
	cout<<" Residuo\t"<<binary_A<<"\t\t"<<A<<endl;
	
	system("pause");
    return 0;
}
