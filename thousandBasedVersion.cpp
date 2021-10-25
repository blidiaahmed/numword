#include<math.h>
#include<iostream>


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



int  Pow3Divider(int n, int(&arr)[3])
{
	float res = log(n) / log(1000);
	int thousand_Pow_Level_Of_n = 3;
	//if thousand_Pow_Level_Of_n > pow(1000.0, 5) { printf("out of limits");return 0; }
	int div;
	unsigned long long int p;

	while (thousand_Pow_Level_Of_n >= 0)
	{
		p = pow(1000, thousand_Pow_Level_Of_n);
		div = n / (p);


		//printf("\n thousand_Pow_Level_Of_n=%d,   pow = %15d, div =%d", thousand_Pow_Level_Of_n, p, div);
		n -= p * div;
		//printf(", n becaumes : %d ", n);
		arr[thousand_Pow_Level_Of_n] = div;
		thousand_Pow_Level_Of_n -= 1;
	}
	return 0;

}


int  PowDivider(int n, int(&arr)[2])
{
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
		if (dig != 1) concat = concat + "s";
		return concat;break;
	}
}

std::string  PronounceUpTo1000(int n)
{
	static int arr3[2];
	std::string strr;
	std::string strrt;
	PowDivider(n, arr3);
	int i = 3;
	//printf("\n n=%d",n);
	i = 2;
	while(i > 0)
	{
		if (i==1 && (arr3[0]!=0||arr3[1]!=0) && arr3[2]!=0)
		{
			printf("and ");
		}
		strr = PronounceDig( arr3[i],i);
		strrt = strrt + strr;
		std::cout <<strr.c_str()<< " ";
		i--;
	}
	strr = PronounceDig(arr3[i],i);

	std::cout <<strr.c_str()<< " ";
	return strrt;
}

std::string  PronounceTotal(int n)
{
	std::cout << "\n *----------*\n n=" << n << "\n *----------*\n";
	
	if (n==0)
	{
		return "zero";
	}
	static int arr[3];
	std::string strr="";
	Pow3Divider(n, arr);
	int i = 3;
	while (i > 0)
	{

		if (arr[i] != 0)
		{
			strr+=string(PronounceUpTo1000(arr[i]))+_powers[i];
		}

		i--;
	}
	
	return strr;
}