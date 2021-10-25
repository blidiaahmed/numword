

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

