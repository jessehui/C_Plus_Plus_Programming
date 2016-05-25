#include <iostream>

using namespace std;

int main()
{
	int array_a[10];
	int array_b[10];

	cout << &array_a[0] << '\0' << &array_a[1]<< '\n';
	cout << &array_b[0] << '\0' << &array_b[1] << '\n';
	cin.get();
}