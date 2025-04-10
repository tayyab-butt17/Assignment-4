#include<iostream>
using namespace std;
void vowels(char A[50]);
int main()
{
	char A[50];
	cout << "Enter a String :";
	cin.getline(A, 50);
	vowels(A);
	return 0;
}
void vowels(char A[50])
{
	int vow = 0;
	for (int i = 0; A[i] != '\0'; i++)
	{
		if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
		{
			vow++;
		}
	}
	cout << "Vowels in String are : " << vow;
}