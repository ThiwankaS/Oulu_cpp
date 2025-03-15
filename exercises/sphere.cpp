#include <iostream>

class Sphere {

	private :
		double radius;
	public :
		Sphere();
		void setRadius(double const r);
		double getDiameter() const;
};

Sphere::Sphere() {
	radius = 1;
}

void Sphere::setRadius(double r) {
	radius = r;
}

double Sphere::getDiameter() const {
	return 2 * radius;
}

int main (void) {
	Sphere a;
	Sphere b;
	a.setRadius(7);
	std::cout << "Diameter of the sphere {a} is " << a.getDiameter() << std::endl;
	std::cout << "Diameter of the sphere {b} is " << b.getDiameter() << std::endl;
	return (0);
}
