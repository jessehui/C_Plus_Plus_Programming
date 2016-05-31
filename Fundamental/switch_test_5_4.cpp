#include <iostream>
using namespace std;

void swap_func1(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}//利用指针实现

void swap_func2(int &n1, int &n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}//利用引用实现. 优点是不用再重新开辟空间.

int main()
{
	int n1 = 1;
	int n2 = 2;
	int *pn1 = &n1;
	int *pn2 = &n2;
	swap_func1(pn1, pn2);
	cout << "n1 = " << *pn1<<endl;
	cout << "n2 = " << *pn2 <<endl;

	system("pause");
}