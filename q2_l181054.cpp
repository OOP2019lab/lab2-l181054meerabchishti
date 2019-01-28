// q2.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
#include "githubuser.h"
#include <fstream>
//to read data from file
void readDataFromFile( gitHubUser * users, string filepath);

int main()
{
	gitHubUser *users1; 
	//creating for a moment
	users1= new gitHubUser[5];
	readDataFromFile( users1,"fileinput.txt");
return 0;
}
void readDataFromFile( gitHubUser * users, string filepath)
{
ifstream infile;//to read file
infile.open("fileinput.txt");
if (!infile) {
cerr << "Unable to open file datafile.txt";
exit(1);   // call system to stop
}
gitHubUser *users1; 
int size;
infile>>size;
users1= new gitHubUser[size];
string Username;
while(!infile.eof())
{
infile>>Username;
cout<<Username;
}

}
