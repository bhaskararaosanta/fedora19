#include<iostream>

using namespace std;

class Student{
	private:	// private data member
		int rollno;

	public:
		/* public member function to get value of rollno - getter */
		int getRollno()
		{
			return rollno;
		}
		/* public member function to set value for rollno - setter */
		void setRollno(int i)
		{
			rollno = i;
		}
};

int main()
{
	Student A;

	//A.rollno = 1;	// compile time error
	//cout << A.rollno;	// compile time error
	
	A.setRollno(1);	//rollno initialized to 1
	cout << A.getRollno() << "\n";	// output will be 1

	return 0;
}
