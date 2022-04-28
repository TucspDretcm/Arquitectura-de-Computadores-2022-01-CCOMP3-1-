/*

Arquitectura de Computadores 2022-01 (CCOMP3-1)
Universidad Católica San Pablo, Arequipa–Perú
Prof.: Yván Jesús Túpac Valdivia

Alumno: Alexander Carpio Mamani

Tema: Represencación en punto flotante

*/

#include <iostream>
#include <bitset>
using namespace std;

int get_n_exponent(string bstring, int n_exponent){
	for(int i=0; i<bstring.length();i++){
		if(bstring[i]=='1') return n_exponent;
		if(n_exponent>1) n_exponent--;
	}
	return 0;
}

template <class My_value>
string real_to_bin(My_value n, int conversor=0){
	
	/*
	Conversor:
		0: 32 bits
		1: 64 bits
		2: 128 bits
	*/
	
	if (sizeof(n)==4 || sizeof(n)==8){

		string output, bstring;
		int n_exponent, n_significand;
		
		if (n < 0){
			output = "1 ";
			n *= -1;
		}
		else output = "0 ";
		
		if (n<256.0 && conversor==0){
			bitset<8> binary_32(n);
			bstring = binary_32.to_string();
			n_significand = 23;
			n_exponent = get_n_exponent(bstring, 7);
			bstring = bstring.substr(8-n_exponent);
			
			if (n_exponent!=0) n_exponent += 127;
			
			binary_32 = n_exponent;
			output += binary_32.to_string();
		}
		else if ((n>255.0 && n<2048.0) || conversor==1){
			bitset<11> binary_64(n);
			bstring = binary_64.to_string();
			n_significand = 52;
			n_exponent = get_n_exponent(bstring, 10);
			bstring = bstring.substr(11-n_exponent);
			
			if (n_exponent!=0) n_exponent += 1023;

			binary_64 = n_exponent;
			output += binary_64.to_string();
		}
		else if((n>2047.0 && n<32768.0) || conversor==2){
			bitset<15> binary_128(n);
			bstring = binary_128.to_string();
			n_significand = 112;
			n_exponent = get_n_exponent(bstring, 14);
			bstring = bstring.substr(15-n_exponent);
			
			if (n_exponent!=0) n_exponent += 16383;

			binary_128 = n_exponent;
			output += binary_128.to_string();
		}
		
		output += ".";
		output += bstring;
		
		int int_n = n;
		My_value significand = n - int_n;
		n_significand -= bstring.length();
		
		for(int i = 0; i<n_significand; i++){
			significand *= 2.0;
			if (significand>=1.0){
				output += "1";
				significand -= 1.0;
			}
			else output += "0";
			
		}
		
		return output;
	}
	
	return "Ingreso de varible Erroneo.";
}

int main(){
	float A = 32.72, E=14300.15;
	double B = 256.41, BA = A;
	char C = '%';
	int D = 12;
	
	string binary_n = real_to_bin(A);
	cout<<" bin("<<A<<") = "<<binary_n<<endl<<endl;

	binary_n = real_to_bin(BA, 1);
	cout<<" bin("<<BA<<") = "<<binary_n<<endl<<endl;

	binary_n = real_to_bin(BA, 2);
	cout<<" bin("<<BA<<") = "<<binary_n<<endl<<endl;
	
	binary_n = real_to_bin(B);
	cout<<" bin("<<B<<") = "<<binary_n<<endl<<endl;
	
	binary_n = real_to_bin(C);
	cout<<" bin("<<C<<") = "<<binary_n<<endl<<endl;

	binary_n = real_to_bin(D);
	cout<<" bin("<<D<<") = "<<binary_n<<endl<<endl;


	binary_n = real_to_bin(E);
	cout<<" bin("<<E<<") = "<<binary_n<<endl<<endl;
	
	system("pause");
    return 0;
}
