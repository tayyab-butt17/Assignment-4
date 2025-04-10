#include<iostream>
#include<fstream>
using namespace std;
void palindrome(char A[50]);
int main()
{
	char A[50];
	cout << "Enter a String to check Palindrome  : ";
	cin.getline(A, 50);
	palindrome(A);

	return 0;
}
void palindrome(char A[50])
{
	int len = 0;
	bool p = true;
	for (int i = 0; A[i] != '\0'; i++)
	{
		len++;
	}

	for (int i = 0; i<len/2; i++)
	{
		if (A[i] != A[len - i - 1])
		{
			p=false;
			break;
		}
		
	}
	if (p)
	{
		cout << "String is Palindrome .";
	}
	else
		cout << "String is not Palindrome .";


}