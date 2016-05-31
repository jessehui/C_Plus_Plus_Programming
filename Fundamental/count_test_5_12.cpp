
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

int count(string str_ask, string str_rec)
{
	int cnt = 0;
	int i;
	char *temp;
	string str_rec_join;
	for (i = 0; i < str_rec.size(); i++)
	{
		str_rec_join = str_rec.substr(i, 2);//substr(startpos,  length)
		cout << "str_rec_join " << i <<"\0"<< str_rec_join<<"\n";
		if (str_ask == str_rec_join)
			cnt++;
	}
	return cnt;
}


int main()
{
	string str_rec, str_ask;
	int count_num;
	cout << "Please Type the Raw String: \n";
	cin >> str_rec;
	cout << "What String Are You Counting?\n";
	cin >> str_ask;
	//cout << "test"<<str_rec.at(4)<<'\n';
	//cout << "是否是char型："<<(typeid(str_rec.at(4)) == typeid(char))<<'\n';
	//cout << "是否一样:" << (str_rec[4] == str_rec.at(4)) << '\n';
	//cout << "str_rec[4]=" << str_rec[4]<<'\n';
	count_num = count(str_ask, str_rec);
	cout << count_num<<"\n";
	system("pause");
}
