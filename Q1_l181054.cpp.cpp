// q1.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
#include "githubstruct.h"

//declarartion of prototypes of function
//to compare before input function
bool Comparison(gitHubUser, gitHubUser);
//to get input from user
void inputFromUser(gitHubUser* arr, int size);
//to check if already entered username is re-entered
bool exists(gitHubUser* arr, int size, string userName);
//to search for a username
gitHubUser* searchUser ( gitHubUser* users, int size, string userName);

int main()
{
gitHubUser a1;
//taking input to test comparison function
cout<<"Enter name:"<<endl;
cin>>a1.firstName;
cout<<"Enter username:"<<endl;
cin>>a1.userName;
cout<<"Enter email:"<<endl;
cin>>a1.email;
cout<<"Enter foldercount:"<<endl;
cin>>a1.folderCount;
cout<<"Enter password:"<<endl;
cin>>a1.password;

//getting input for second time
gitHubUser a2;
cout<<"Enter name:"<<endl;
cin>>a2.firstName;
cout<<"Enter username:"<<endl;
cin>>a2.userName;
cout<<"Enter email:"<<endl;
cin>>a2.email;
cout<<"Enter foldercount:"<<endl;
cin>>a2.folderCount;
cout<<"Enter password:"<<endl;
cin>>a2.password;
Comparison(a1,a2);

//input using array 
//PROBELM 1A
int size;
cout<<"Enter size of your dynamic array"<<endl;
cin>>size;
//dynamic array
gitHubUser* array = new gitHubUser[size];
//takinmg input
inputFromUser(array,size);
for(int i=0; i<size;i++)
{
	cout<<array[i].firstName<<endl;
	cout<<array[i].userName<<endl;
	cout<<array[i].email<<endl;
	cout<<array[i].password<<endl;
	cout<<array[i].folderCount<<endl;
	cout<<endl;

}

//PROBEM1B
string username;
cout<<"enter user name to be search in your array"<<endl;
cin>>username;
searchUser (array,size,username);
//deleting dynamic array
for(int j=0; j<size;j++)
{
	delete[]array;

}
return 0;
}

//definition of function
bool Comparison(gitHubUser, gitHubUser)
{

gitHubUser user1;
gitHubUser user2;

if(user1.firstName==user2.firstName && user1.userName==user2.userName && user1.email==user2.email && user1.password==user2.password && user1.folderCount==user2.folderCount)
{

	cout<<"BOTH ARE SAME";
	return true;
}
else
	return false;

}
void inputFromUser(gitHubUser* arr, int size)
{


for(int j=0; j<size; j++)
{
		
		cout<<"Enter username:"<<endl;
		cin>>arr[j].userName;
		while(exists(arr,j,arr[j].userName))
		{
			cout<<"Enter username:"<<endl;
			cin>>arr[j].userName;
		}

		cout<<"Enter name:"<<endl;
		cin>>arr[j].firstName;
		cout<<"Enter email:"<<endl;
		cin>>arr[j].email;
		cout<<"Enter foldercount:"<<endl;
		cin>>arr[j].folderCount;
		cout<<"Enter password:"<<endl;
		cin>>arr[j].password;

		
}
}

bool exists(gitHubUser* arr, int size, string userName)
{

for(int k=0; k<size; k++)
{
	if(arr[k].userName == userName)
	{
		cout<<"This name already exists!"<<endl;
		cout<<"Enter again"<<endl;
		/*inputFromUser(arr,size);*/
		return true;
	}

}
return false;

}

//1B
gitHubUser* searchUser ( gitHubUser* users, int size, string userName) 
{
for(int i=0; i<size; i++)
{
if(userName==users[i].userName)
{
	cout<<"username exists"<<endl;
	return &users[i];
}

}
return nullptr;
}