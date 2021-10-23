#include <string>    /* printf */
#include <math.h> 

using namespace std;
static const char* errnum = "error";
static const char* _singles[] = {
		"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

static const char* _teens[] = {
	errnum,"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

static const char* _tens[] = {
	errnum, errnum, "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty",
};

static const char* _hundred = "hundred";

static const char* _powers[] = {
	errnum,errnum,errnum, "thousand","ten thousands","hundred thousands", "million", "billion", "trillion", "quadrillion"
};

std::string digToname(int dig,int pows)
{
	string single, hund,concat;
	switch (pows)
	{
	case 0: return _singles[dig];break;
	case 1: return _tens[dig];break;
	case 2:
		single = string(_singles[dig]);
		hund = string(_hundred);
		concat = single + "  " + hund;
		return concat;break;
	default:

		single = string(_singles[dig]);

		//printf("\nhello\n   %s%d", single.c_str(),pows);
		hund = string(_powers[pows]);

		//printf("\nhello\n %s  %s", single.c_str(), hund.c_str());
		concat = single + "  " + hund;

		return concat;break;
		break;
	}
}
