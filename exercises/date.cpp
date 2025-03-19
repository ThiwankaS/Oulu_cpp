#include <iostream>

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov , dec
};

static int DEFAULT_DD = 1;
static Month DEFAULT_MM = Month::mar;
static int DEFAULT_YY = 1999;

class Date {

	private :
		int d = DEFAULT_DD;
		Month m = DEFAULT_MM;
		int y = DEFAULT_YY;
	public :
		Date () {};
		Date (const int dd, const Month mm, const int yy)
		:d{dd}, m{mm}, y{yy} {};
		std::string getDate () const {
			return std::to_string(d)
				+ "."
				+ std::to_string(static_cast<int>(m))
				+ "."
				+ std::to_string(y);
		}
};

//Opeartor overloading
std::ostream& operator<<(std::ostream& os, const Date& date) {
	return os << date.getDate();
}

int main (void)
{
	Date a;
	std::cout << a << std::endl;
	Date d {9, Month::mar, 1988};
	std::cout << d << std::endl;
	return (0);
}
