#include<iostream>
//#include<cstring>

#include <string>    /* printf */
#include <math.h> 
int Pow3Divider(int n, int(&arr)[3]);
std::string  Pronouncedig(int dig, int pows);
int PowDivider(int n, int(&arr)[2]);
std::string  PronounceUpTo1000(int n);
std::string  PronounceTotal(int n);

int main()
{
	long int n = 423245;
	/*int m = 2;
	int l = 245;
	static int arr[3];

	static int arr2[2];*/
	
	//Pow3Divider( n,arr);
	//PowDivider(l, arr2);

	//std::cout << PronounceDig(m, 2).c_str();
	//PronounceUpTo1000(l).c_str();
	PronounceTotal(n);

	/*
	int cmp = 3;
	while (cmp >= 0)
	{
		
		cmp--;
	}
	*/
	return 0;

}