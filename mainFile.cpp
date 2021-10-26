#include<iostream>
//#include<cstring>

#include <string>    /* printf */
#include <math.h> 
int Pow3Divider(int nn, int(&arr)[4]);
std::string  Pronouncedig(int dig, int pows);
int PowDivider(int nn, int(&arr)[3]);
std::string  PronounceUpTo1000(int n);
std::string  PronounceTotal(int n);

int main()
{
	long int n = 423245;
	static int arr[4];
	static int arr1[3];
	int m = 245;
	

	//std::cout << PronounceDig(m, 2).c_str();
	//std::cout << PronounceUpTo1000(245).c_str();
	std::cout<< PronounceTotal(n);
	
	/*Pow3Divider(n, arr);
	for(int i=3 ; i>=0;i--)
	{
		printf("\n%d\n",arr[i]);
	}
	std::cout << "\n" << n <<"\n";

	PowDivider(m, arr1);
	for (int i = 3; i >= 0;i--)
	{
		printf("\n%d\n", arr1[i]);
	}
	std::cout << "\n" << n << "\n";*/
	
	return 0;

}