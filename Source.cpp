#include<iostream>
//#include<cstring>

#include <string>    /* printf */
#include <math.h> 

std::string digToname(int dig,int pows);
int main()
{
	long int n =423245;
	float res=log(n) / log(10);
	int nn = floor(res);
	std::cout <<"\n n="<<n<<"\n";	
	int p = 1;
	int div;
	while (nn >= 0)
	{

		p = pow(10, nn);
		div = n / (p);
		printf("\n nn=%d,   pow = %d: div =%d",nn, p,div);
		n -= p*div;
		
		printf(" %s ", digToname(div,nn).c_str());
		nn -= 1;
	}
	//printf("\n hello %d", (int)(2.0));

}