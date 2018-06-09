#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class CharacterStatistics
{
	public:

		CharacterStatistics()
		{
			for(int i = 0; i < 256; ++i)
			{
				occurrence.push_back(-1);
			}
		}

		~CharacterStatistics()
		{

		}

		void insert(char ch)
		{
			if(occurrence[int(ch)] >= 0)
			{
				occurrence[int(ch)] = -2;
			}else if(-1 == occurrence[int(ch)])
			{
				occurrence[ch] = index;
			}
			++index;
		}

		char getFirstChar()
		{
			char ch = '\0';
			int minIndex = 0x7fffffff;
			for(int i = 0; i < 256; ++i)
			{
				if(occurrence[i] >= 0 && occurrence[i] < minIndex)
				{
					ch = char(i);
					minIndex = occurrence[i];
				}
			}
			return ch;
		}
	private:
		
		int index = 0;
		vector<int> occurrence;
};

int main()
{
	CharacterStatistics charc;
	for(char ch: {'a', 'b', 'c', 'a', 'b', 'e', 'f'})
	{
		charc.insert(ch);
	}
	cout << charc.getFirstChar() << endl;
	return 0;
}
