#include<iostream>
#include<fstream>
using namespace std;
void read(ifstream & out);
int main()
{
	ifstream output("output.txt");
	read(output);



	return 0;
}
void read(ifstream& out)
{
	string word;
	int w=0;
	while (out >> word)
	{
		w++;
	}
	cout << "Number of words in file are : " << w;

}
