#include<iostream>
#include<fstream>
using namespace std;
void copy(int A[10]);
int main()
{
	int A[10];
	cout << "Enter 10 Integers : ";
	for (int i = 0; i < 10; i++)
	{
		cin >> A[i];
	}
	copy(A);


	return 0;
}
void copy(int A[10])
{
	int B[10];
	for (int i = 0; i < 10; i++)
	{
		B[i] = A[i];
	}
	cout << "Copied integer Array :";
	for (int i = 0; i < 10; i++)
	{
		cout << B[i] << " ";
	}


}