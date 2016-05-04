#include <iostream>
using namespace std;

int main()
{
	int i = 7;
	int *ipointer;
	int &ireference = i ;
	ipointer = &i;
	cout << "Using ipointer 		i=" << *ipointer << endl;
	cout << "Using ireference	i=" << ireference << endl;
}
