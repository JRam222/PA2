#include <iostream>
#include <string>

using namespace std;
std::string f = "-f";
std::string d = "-d";
std::string b = "-b";
string lines[3]; //array to hold stdin
int k=0;	 //counter for while loop
//
int main(int arg, char* input[]){
	string lineInput;
	// retrieve the lines from stdin and store them in array
	while(getline(cin,lineInput)){
		lines[k] = lineInput;
		k++;
	}
	
	//displays correct output
	if(input[1] == d){
		cout << "\n" << lines[0]<< "\n";
	}
	if(input[1] == f){
		cout<< "\n" << lines[1]<< "\n";
	}
	if(input[1] == b){
		cout<< "\n" << lines[2] << "\n";
	}
}
