#include<iostream>

using namespace std;

class Student{
	public:
		int rollno;
		string name;
};

int main()
{
	Student A;
	Student B;

	A.rollno = 1;
	A.name = "bhaskar";

	B.rollno = 2;
	B.name = "Nayana";

	cout << "Name and roll no of A is:" << A.name << "-" << A.rollno << endl;
	cout << "Name and roll no of A is:" << &A.name << "-" << &A.rollno << endl;
	cout << "Name and roll no of B is:" << B.name << "-" << B.rollno << endl;
	cout << "Name and roll no of B is:" << &B.name << "-" << &B.rollno << endl;

	return 0;
}
