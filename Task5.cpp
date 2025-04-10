#include<iostream>
using namespace std;
void print(char A[50]);
int main()
{

	char A[50];
	cout << "Enter a String : ";
	cin.getline(A, 50);
	print(A);


	return 0;
}
void print(char A[50])
{
	
	for (int i = 0; A[i] != '\0'; i++)
	{
		cout << A[i] <<'\n';
	}
}

