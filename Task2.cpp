#include<iostream>
using namespace std;
int sum(int A[5]);
int main()
{
	int A[5];
	cout << "Enter 5 Numbers in Array :";
	for (int i = 0; i < 5; i++)
	{
		cin >> A[i];
	}

	cout<<"Sum of Array is : "<<sum(A);

	return 0;
}
int sum(int A[5])
{
	int s = 0;
	for (int i = 0; i < 5; i++)
	{
		s+=A[i];
	}
	return s;
}