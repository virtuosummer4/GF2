// define for skip spaces in ex2
//#define skipsp
// define for numbers in ex3
//#define dnum
// define for ex4
#define strex4

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;

const int maxlength = 8; // maximum number of characters in a name string
typedef string namestring;

void skipspaces(ifstream *infp, char &curch, bool &eofile);
void getnumber(ifstream *infp, char &curch, bool &eofile, int &number);
void getname(ifstream *infp, char &curch, bool &eofile, namestring &str);

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
#endif

#ifdef dnum
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
#endif

#ifdef strex4
// Execute this for exercise 4
	namestring str = "";
	 while (!eofile) {
		 if (isalpha(ch))
		 {
			 getname(&inf, ch, eofile, str);
			 cout<< str<< endl;
			 if (eofile) break;
		 }
    eofile = !inf.get(ch); // get next character
  }
#endif
  
	/*
#else
  while (!eofile) {
    if (isspace(ch)) cout << '.';
    else cout << ch;
    eofile = !inf.get(ch); // get next character
  }
#endif*/

  inf.close();
}

void skipspaces(ifstream *infp, char &curch, bool &eofile)
// infp - pointer to input file
// curch - current character
// eofile - bool enf-of-file flag. true if end of file is reached.
{
	//eofile = !(*infp).get(curch);
	
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

void getname(ifstream *infp, char &curch, bool &eofile, namestring &str)
// Reads name from text file, starting with curch
// str = reference parameter for result
// 
{
	str = "";
	int i = 0;
	bool e = false;
	
	while (!eofile) {
		if (!isalpha(curch)) break; // 
		else {
			if (i < maxlength) str+= curch;
			else e = true;
			i++;
			eofile = !(infp->get(curch)); //get next character
		}
	}
	if (e) cout<< "Warning: name exceeds "<< maxlength <<" characters" << endl;
	
	return;
}
