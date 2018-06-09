#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using std::cout;
using std::endl;
using std::string;

void ReverseRange(char* pBegin, char* pEnd);
void ReverseString(char* str);

int main()
{
	char str[] = {"   "};
	char kk[] = {""};
	ReverseString(str);
	return 0;
}

void ReverseRange(char* pBegin, char* pEnd)
{
	if(nullptr == pBegin || nullptr == pEnd)
	{
		return;
	}
	while(pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		++pBegin;
		--pEnd;
	}
}

void ReverseString(char* str)
{
	if(nullptr == str)
	{
		return;
	}
	char *pBegin = str;
	char *pEnd = str;
	while(*pEnd)
	{
		++pEnd;
	}
	--pEnd;
	ReverseRange(pBegin, pEnd);
	pBegin = pEnd = str;
	while(*pBegin)
	{
		if(*pBegin == ' ')
		{
			++pBegin;
			++pEnd;
		}else if(*pEnd != ' ' && *pEnd)
		{
			++pEnd;
		}else if(*pEnd == '\0' || *pEnd == ' '){
			--pEnd;
			ReverseRange(pBegin, pEnd);
			++pEnd;
			pBegin = pEnd;
		}
	}
	cout << str << endl;
}
