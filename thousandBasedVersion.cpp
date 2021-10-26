#include<math.h>
#include<iostream>

#include <typeinfo>
using namespace std;
static const char* errnum = "error";
static const char* _singles[] = {
		"zero", "one", "two", "three",
		"four", "five", "six", "seven", "eight", "nine"
};

static const char* _teens[] = {
	errnum,"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

static const char* _tens[] = {
	errnum, errnum, "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty",
};

static const char* _hundred = "hundred";

static const char* _powers[] = {
	"", "thousand", "million", "billion", "trillion", "quadrillion"
};



int  Pow3Divider(int nn, int(&arr)[4])
{
	int n = nn;
	float res = log(n) / log(1000);

	int thousand_Pow_Level_Of_n = 3;
	int div;
	unsigned long long int p;
	//printf("\npow3div for n=%d*****\n", n);
	while (thousand_Pow_Level_Of_n >= 0)
	{
		p = pow(1000, thousand_Pow_Level_Of_n);
		div = n / (p);

		
		printf("\n thousand_Pow_Level_Of_n=%d,   pow = %15d", thousand_Pow_Level_Of_n, p);
		
		n -= p * div;
		
		arr[thousand_Pow_Level_Of_n] = div;
		std::cout << ",  div=" << div<<endl;
		//cout << typeid(div).name() << endl;
		//printf(", n becomes : %d\n ", n);
		thousand_Pow_Level_Of_n -= 1;
	}
	return 0;

}


int  PowDivider(int nn, int(&arr)[3])
{
	int n = nn;
	float res = log(n) / log(10);
	
	int Pow_Level_Of_n = 2;
	int div;
	unsigned long long int p;
	
	while (Pow_Level_Of_n >= 0)
	{
		p = pow(10, Pow_Level_Of_n);
		div = n / (p);

		//printf("%d", div);
		//printf("\n Pow_Level_Of_n=%d,   pow = %d, div =%d",Pow_Level_Of_n, p, div);
		n -= p * div;
		//printf(", n became : %d ", n);
		arr[Pow_Level_Of_n] = div;
		Pow_Level_Of_n -= 1;
	}
	return 0;

}

std::string  PronounceDig(int dig, int pows)
{
	string single, hund, concat;


	//printf("\npows=%d", pows);
	switch (pows)
	{
	case 0: ;
		if (dig!=0)
		{
			return _singles[dig];
		}
		else
		{
			return "";
		}
	case 1: 
		if (dig != 0)
		{
			return _tens[dig];
		}
		else
		{
			return "";
		}
	case 2:
		single = string(_singles[dig]);
		hund = string(_hundred);
		concat = single + "  " + hund;
		if (dig != 1) concat = concat + "s ";
		return concat;break;
	}
}

std::string  PronounceUpTo1000(int n)
{
	static int arr3[3];
	std::string strr;
	std::string strrt="";
	PowDivider(n, arr3);
	int i = 3;
	//printf("\n n=%d",n);
	i = 2;
	while(i > 0)
	{
		if (i==1 && (arr3[0]!=0||arr3[1]!=0) && arr3[2]!=0)
		{
			strrt += "and ";
		}
		if (arr3[i] != 0) 
		{
			strr = PronounceDig(arr3[i], i);
			strrt = strrt + strr + " ";
		}
		//std::cout <<strr.c_str()<< " ";
		i--;
	}
	strr = PronounceDig(arr3[i],i);
	strrt = strrt + strr;
	//std::cout <<strr.c_str()<< " ";

	//printf("\nutt=%s\n ",strrt.c_str());
	return strrt;
}

std::string  PronounceTotal(int n)
{
	std::cout << "\n *----------*\n n=" << n << "\n *----------*\n";
	
	if (n==0)
	{
		return "zero";
	}
	static int arr[4];
	std::string strr="";
	//std::cout << n;
	Pow3Divider(n, arr);
	int i = 3;
	while (i >= 0)
	{
		//printf("\n i=%d, arr=%d\n",i,arr[i]);
		//std:cout << "arr i="<<arr[i];

		if (arr[i] != 0)
		{
			
			strr+=string(PronounceUpTo1000(arr[i])) + " " + _powers[i]+" ";
			//std::cout<< string(PronounceUpTo1000(arr[i])) + " " + _powers[i];
			if (i - 1 != -1) { if (arr[i - 1] != 0) strr += "and ";  }
		}
		

		i--;
	}
	
	return strr;
}