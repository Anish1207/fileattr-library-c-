#include <iostream>
#include "fileattr.h"
using namespace std;


int main()
{
	char path[100];
	cout<<"Enter a file path name : ";
	cin>>path;

	check_file(path);

	return 0;
}