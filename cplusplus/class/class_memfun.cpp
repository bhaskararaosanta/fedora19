#include<iostream>

using namespace std;

/*class Cube{
	public:
		int side;
		int getVolume()
		{
			return side*side*side;	// return volume of cube
		}
}; */

/* other alternative to define member function outside of class and same can be accessed through scope resolution operator :: as below */
class Cube{
	public:
		int side;
		int getVolume();
};

// member function defined outside class definition

int Cube::getVolume()
{
	return side*side*side;	// return volume of cube
}


int main()
{
	Cube C1;
	C1.side = 4;
	cout << "Volume of cube C1 = " << C1.getVolume() << endl;
}
