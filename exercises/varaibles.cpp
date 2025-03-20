#include <iostream>
#include <typeinfo>
#include <vector>
#include <chrono>

using std::cout;
using std::endl;

int main()
{
	//Understanding pointers
	cout << "\n Understanding pointers : " << endl;
	int x = 5;
	int *x1 = &x;
	int x2 = *x1;
	cout << x << endl << x1 << endl << x2 << endl;

	//Allocating heap memory with 'new'
	cout << " \n Allocating heap memory with 'new' : " << endl;
	int *a = new int(5);
	int b = 5;
	cout << a << b << endl;

	//Introduction to vectors
	cout << "\n Introduction to vectors " << endl;
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	cout << &v[0] << ", " << &v[4] << endl;
	v.push_back(9);
	cout << &v[0] << ", " << &v[4] << endl;

	//Power of type 'auto'
	cout << "\n Power of type 'auto' : " << endl;
	auto y = 2;
	cout << " type of y : " << typeid(y).name() << endl;
	y = 5.5f;
	cout << y << endl;

	//Practical use of 'auto'
	cout << "Practical use of 'auto' : " << endl;
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	cout << now << endl;
	auto now2 = std::chrono::system_clock::now();
	cout << now2 << endl;

	/*
	** above code will thorw an error and will not get compile if use -std==c++17 flag
	** so below is the adjusted version

	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t time_n1 = std::chrono::system_clock::to_time_t(now);
	cout << ctime(&time_n1) << endl;

	auto now2 = std::chrono::system_clock::now();
	std::time_t time_n2 = std::chrono::system_clock::to_time_t(now2);
	cout << ctime(&time_n2) << endl;
	*/

	//Guess the output
	cout << "Guess the out put " << endl;
	int i = 0;
	cout << i++ << ", " << i << endl;
	cout << ++i << ", " << i << endl;

 return 0;
}
