#include<iostream>
using namespace std;
void reverse(char A[50]);
int main()
{

	char A[50];
	cout << "Enter a String : ";
	cin.getline(A, 50);
	reverse(A);


	return 0;
}
void reverse(char A[50])
{
	int len = 0;
	for (int i = 0; A[i] != '\0'; i++)
	{
		len++;
	}
	cout << "Reverse Array : ";
	for (int i = len-1; i>=0; i--)
	{
		cout << A[i];
	}

}

