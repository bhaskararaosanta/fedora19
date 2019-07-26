#include<iostream>

using namespace std;

int main()
{
	int y = 10, x = 20;
	int &r = y;	// r is a reference to int y
/*	int &r = NULL;	// cannot be assigned NULL unlike a pointer			      */
/*	int &r = x;	// cannot be reinitialized unlike a pointer and it will compile error */
	cout << r << endl;	// reference variable directly it can be dereference unlike '*' is used for pointer

	return 0;
}
