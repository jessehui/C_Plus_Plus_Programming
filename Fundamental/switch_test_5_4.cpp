#include <iostream>
using namespace std;

void swap_func1(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}//����ָ��ʵ��

void swap_func2(int &n1, int &n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}//��������ʵ��. �ŵ��ǲ��������¿��ٿռ�.

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