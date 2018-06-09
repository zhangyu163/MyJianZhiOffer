#include<iostream>
#include<string>


using std::cout;
using std::endl;
using std::string;

bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str);
bool IsNumeric(const char* str);

void Test(const char* testName, const char* str, bool expected);
void Test1();

int main()
{
	Test1();
	return 0;
}

bool IsNumeric(const char* str)
{
	if(nullptr == str)
	{
		return false;
	}
	bool numeric = scanInteger(&str);
	if('.' == *str)
	{
		++str;
		numeric = scanUnsignedInteger(&str) || numeric;
	}
	if('e' == *str || 'E' == *str)
	{
		++str;
		numeric = scanInteger(&str) && numeric;
	}
	return numeric && '\0' == *str;
}

bool scanUnsignedInteger(const char** str)
{
	if(nullptr == str || nullptr == *str)
	{
		return false;
	}
	const char* before = *str;
	while(**str != '\0' && **str >= '0' && **str <= '9')
	{
		++(*str);
	}
	return *str > before;
}

bool scanInteger(const char** str)
{
	if(nullptr == str || nullptr == *str)
	{
		return false;
	}else if('\0' == *str)
	{
		return false;
	}
	if(**str == '+' || **str == '-')
	{
		++(*str);
	}
	bool numeric = scanUnsignedInteger(str);
	return numeric;
}

void Test(const char*  testName, const char* str, bool expected)
{
	cout << testName << endl;
	if(str)
	{
		cout << "the string is: " << str << endl;
	}
	bool numeric = IsNumeric(str);
	if(expected == numeric)
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << endl;
	}

}
void Test1()
{
	const char* str = "12.34";
	Test("test1 for ++23.34", "++23.34", false);
	Test("test1 for +500", "12e+5.4", false);
    Test("Test1 for +.1", "+.", false);
    Test("Test nullptr", nullptr, true);
}
