//#define skipsp
#define detnum

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

void skipspaces(ifstream *infp, char &curch, bool &eofile);
void getnumber(ifstream *infp, char &curch, bool &eofile, int &number);

int main(int argc, char **argv)
// If this program is put in a file called small.cc, it can
// be compiled with the command  g++ -g -o small small.cc
{
  ifstream inf; // input file
  char ch;      // current character
  bool eofile;  // true when end of file is reached
	
	
  if (argc != 2) {
    cout << "Usage:         " << argv[0] << " [filename]" << endl;
    exit(1);
  }

  inf.open(argv[1]);
  if (!inf) {
    cout << "Error: cannot open file " << argv[1] << " for reading" << endl;
    exit(1);
  }

  eofile = !inf.get(ch); // get first character
#ifdef skipsp
  while (!eofile) {
    if (isspace(ch))
		{
			skipspaces(&inf, ch, eofile);
			if (eofile) break;
		}
		cout << ch;
    eofile = !inf.get(ch); // get next character
  }
#ifdef detnum
// Execute this for exercise 3
	int number;
	
	 while (!eofile) {
		 if (isdigit(ch))
		 {
			 getnumber(&inf, ch, eofile, number);
			 cout<< number<< endl;
			 if (eofile) break;
		 }
    eofile = !inf.get(ch); // get next character
  }
	
#else
  while (!eofile) {
    if (isspace(ch)) cout << '.';
    else cout << ch;
    eofile = !inf.get(ch); // get next character
  }
#endif

  inf.close();
}

void skipspaces(ifstream *infp, char &curch, bool &eofile)
// infp - pointer to input file
// curch - current character
// eofile - bool enf-of-file flag. true if end of file is reached.
{
	eofile = !(*infp).get(curch);
	
	while (!eofile) {
		if (!isspace(curch)) return; // if the character is not space, break loop and return for
		else eofile = !(infp->get(curch)); //get next character
	}
	return;
}

void getnumber(ifstream *infp, char &curch, bool &eofile, int &number)
// Reads characters starting with curch,
// Reads as long as integer characters are encountered,
// Gets an int from the string
{
	string nstr = "";
	
	while (!eofile) {
		if (!isdigit(curch)) break; // 
		else {
			nstr+= curch;
			eofile = !(infp->get(curch)); //get next character
		}
	}
	number = stoi(nstr);
	return;
}