#include <iostream>
using namespace std;

int main()
{
	int i = 7;
	int *ipointer;
	int &ireference = i ;
	ipointer = &i;
	cout << "Using ipointer 		i=" << *ipoiter << endl;
	cout << "Using itreference	i=" << ireference << endl;
}