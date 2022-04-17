/*
Arquitectura de Computadores 2022-01 (CCOMP3-1)
Universidad Católica San Pablo, Arequipa–Perú
Prof.: Yván Jesús Túpac Valdivia

Alumno: Alexander Carpio Mamani

División de enteros
*/

int main(){
	const int n_bits = 8;
	int A=0, M=5, Q=253, Count=n_bits;
	bitset<n_bits> binary_Q (Q), binary_A (A);
	
	while(Count>0){
		binary_A <<= 1;
		binary_A[0] = binary_Q[n_bits-1];
		A = binary_A.to_ulong();   // binario a psudo-entero
		
		binary_Q <<= 1;  // 1011 => 0110
		
		A -= M;
		
		if (A >= 0){
			binary_Q[0] = 1;  // 0110 => 0111
		}
		else{
			A += M;
		}
		
		bitset<n_bits> aux(A);
		binary_A = aux;
		Count--;
	}
	
	Q = binary_Q.to_ulong();
	
	cout<<" Tipos\t\tBinario\t| Decimales"<<endl;
	cout<<" Cociente\t"<<binary_Q<<"\t\t"<<Q<<endl;
	cout<<" Residuo\t"<<binary_A<<"\t\t"<<A<<endl;
	
	system("pause");
    return 0;
}