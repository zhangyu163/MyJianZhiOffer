#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

enum Status {kValid = 0, kInvalid};
int g_nStatus = kValid;

long long StringToIntCore(const char* pCur, const bool minus);
int StringToInt(const char* str);
void Test(const string testName, const char* str, const int expected, const bool validStatus);
void Test1();
void Test2();
void Test3();

int main()
{
	Test1();
	Test2();
	Test3();
	return 0;
}

int StringToInt(const char* str)
{
	if(nullptr == str || '\0' == *str)
	{
		g_nStatus = kInvalid;
		return 0;
	}
	const char* pCur = str;
	bool minus = false;
	if('-' == *pCur)
	{
		minus = true;
		++pCur;
	}else if('+' == *pCur)
	{
		++pCur;
	}
	if('\0' == *pCur)
	{
		g_nStatus = kInvalid;
		return 0;
	}
	long long num = StringToIntCore(pCur, minus);
	return (int)num;
}

long long StringToIntCore(const char* pCur, const bool minus)
{
	long long num = 0;
	while(*pCur)
	{
		if(*pCur >= '0' && *pCur <= '9')
		{
			num = num * 10 + (*pCur - '0');
		}else{
			g_nStatus = kInvalid;
			num = 0;
			break;
		}
		++pCur;
	}
	if('\0' == *pCur)
	{
		if(minus)
		{
			num = 0 - num;
		}
		if(num < (int)0x80000000 || num > 0x7FFFFFFF)
		{
			num = 0;
			g_nStatus = kInvalid;
		}else{
			g_nStatus = kValid;
		}
	}
	return num;
}

void Test(const string testName, const char* str, const int expected, const bool validStatus)
{
	cout << "********" << testName << "*******" <<endl;
	int num = StringToInt(str);
	if(expected == num && validStatus == g_nStatus)
	{
		cout << "the number is: " << num << ", the g_nStatus is: " << g_nStatus << endl;
		cout << "passed!" << endl;
	}else{
		cout << "failed!" << endl;
	}
}

void Test1()
{
	const char* str = nullptr;
	Test("test1 for nullptr", str, 0, kInvalid);
	str = "";
	Test("test1 for nullptr", str, 0, kInvalid);
}

void Test2()
{
	const char* str = "--111";
	Test("test2 for -111", str, 0, kInvalid);
	str = "++3234";
	Test("test2 for ++3234", str, 0, kInvalid);
	str = "-0";
	Test("test2 for -0", str, 0, kValid);
	str = "+0";
	Test("test2 for +0", str, 0, kValid);
	str = "0";
	Test("test2 for 0", str, 0, kValid);
	str = "-2147483648";
	Test("test2 for 0x80000000", str, -2147483648, kValid);
	str = "2147483647";
	Test("test2 for 0x7FFFFFFF", str, 2147483647, kValid);
}

void Test3()
{
	const char* str = "-123";
	Test("test3 for -123", str, -123, kValid);
	str = "+3234";
	Test("test3 for +3234", str, 3234, kValid);
	str = "0345";
	Test("test2 for 0345", str, 345, kValid);
	str = "+0456";
	Test("test2 for +0456", str, 456, kValid);
	str = "9883";
	Test("test2 for 9883", str, 9883, kValid);
	str = "-21474836488";
	Test("test2 for 0x80000000", str, 0, kInvalid);
	str = "2147483648";
	Test("test2 for 0x7FFFFFFF", str, 0, kInvalid);

}
