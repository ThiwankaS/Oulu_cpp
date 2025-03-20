#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

int main (void)
{
	/*
	** this will initialize a vector with 5 elements and zero as the default value
	*/
	std::vector<int> zeros(5);
	cout << "vector zeros : " << endl;
	for(int i : zeros)
		cout << i << endl;
	/*
	** this will initialize a vector with 5 elements and 2 as the default value
	*/
	std::vector<int> twos(5, 2);
	cout << "vector twos : " << endl;
	for(int i : twos)
		cout << i << endl;

	/*
	** this will initialize a vector with 8 elements and assing the value provided inside {}
	*/
	std::vector<int> v = {1, 6, 7, 2, 5, 4, 3, 8};
	cout << "vector v : { before } " << endl;
	for(int i : v)
		cout << i << endl;
	//below line will add 9 at the end of the vector 'v'
	v.push_back(9);
	cout << "vector v : { after add 9 } " << endl;
	for(int i : v)
		cout << i << endl;
	/*
	** below two lines will make the program crashed and but v.at(10) will add an nice execption
	** at the end of the program wich is very helpfull for debugging
	*/
	//cout << v[10] << endl;
	//cout << v.at(10) << endl;

	/*
	** traversing a vector using an iterator after sorting.
	*/
	sort(v.begin(), v.end());
	cout << "after sorting the vector : " << endl;
	for(auto it = v.begin(); it != v.end(); ++it)
		cout << *it << endl;

	return (0);
}
