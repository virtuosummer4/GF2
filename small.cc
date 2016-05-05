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
  int number;	// integer to store number acquired from getnumber function.
  namestring str = "";
  
  
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
  
  while (!eofile) {
	  if (isspace(ch))
		{
			skipspaces(&inf, ch, eofile);
			if (eofile) break;
		}
	  else if (isdigit(ch))
		 {
			 getnumber(&inf, ch, eofile, number);
			 cout<< number<< endl;
			 if (eofile) break;
		 }
	  else if (isalpha(ch))
		 {
			 getname(&inf, ch, eofile, str);
			 cout<< str<< endl;
			 if (eofile) break;
		 }
  }
  

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
	
	while (!eofile) {
		if (!isalpha(curch)) break; // 
		else {
			str+= curch;
			eofile = !(infp->get(curch)); //get next character
		}
	}
	if (str.size() > maxlength){
		cout<< "Warning: name '" << str << "' was truncated" <<endl;
		str.resize(maxlength);
	}
	return;
}
