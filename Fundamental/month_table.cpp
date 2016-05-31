
#include <iostream>

using namespace std;

struct Month_  {
	char *month_name;
	int num_days;
};

Month_ month[12] = {
	{"Jan",31},{"Feb",28},{"Mar",31},{"Apr",30},{"May",31},{"Jun",30},
	{"July",31},{"Aug",31},{"Sep",30},{"Oct",31},{"Nov",30},{"Dec",30}
};

int main()
{
	int i;
	for (i = 0; i < 12; i++)
	{
		cout << "Month " << month[i].month_name << " has " << month[i].num_days << " days\n";
	}
	system("pause");
}


