#include<iostream>
#include<fstream>
using namespace std;
void copy();
int main()
{
	
	copy();
	

	return 0;
}
void copy()
{
	char A[50];
	cout << "Enter a String :";
	cin.getline(A, 50);

	ofstream output("output.txt");
	if (output.is_open())
	{
		output << A;
		output.close();
		cout << "String copied in output.txt Successfully !";

	}
	else
	{
		cout << "File is'nt open !!! ";
	}

}
