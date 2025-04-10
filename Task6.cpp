#include<iostream>
using namespace std;
int maximum(int A[10]);
int main()
{

	int A[10];
	cout << "Enter 10 integers : ";
	for (int i = 0; i < 10; i++)
	{
		cin >> A[i];
	}
	cout<<"Maximum Number of Array is : "<<maximum(A);


	return 0;
}
int maximum(int A[10])
{
	int max = A[0];
	for (int i = 0; i < 10; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

