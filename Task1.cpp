#include<iostream>
using namespace std;
void arr(int A[5]);
int main()
{
	int A[5];
	cout << "Enter 5 Numbers in Array :";
	for (int i = 0; i < 5; i++)
	{
		cin >> A[i];
	}
	arr(A);

	return 0;
}
void arr(int A[5])
{
	cout << "Array is : ";
	for (int i = 0; i < 5; i++)
	{
		cout << A[i] << " ";
	}
}