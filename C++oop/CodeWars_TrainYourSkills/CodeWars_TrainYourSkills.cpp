#include <sstream>

class X {
	int m_a;
	int m_b;
public:
	X() {
		this->m_a = 1;
		this->m_b = 2;
	}
	X(int a, int b) {
		this->m_a = a;
		this->m_b = b;
	}
	X(int a) {
		this->m_a = a;
		this->m_b = 2;
	}
	X(const X& other) {
		this->m_a = other.m_a;
		this->m_b = other.m_b;
	}

	X& operator=(const X& other) {
		if (this != &other) {
			m_a = other.m_a;
			m_b = other.m_b;
		}
		return* this;
	}
	X& operator+=(const X& other) {
		this->m_a += other.m_a;
		this->m_b += other.m_b;
		return *this;
	}
	X& operator++() {
		++m_a;
		++m_b;
		return *this;
	}
	X operator++(int) {
		X temp = *this;
		++(*this);
		return temp;
	}
	X operator+(const X& other) const{
		return X(this->m_a + other.m_a, this->m_b + other.m_b);
	}
	friend std::ostream& operator<<(std::ostream& os, const X& other) {
		os << "[" << other.m_a << "," << other.m_b << "]";
		return os;
	}
	std::string print(); // used for testing
};

std::string X::print()
{
	std::stringstream s;
	s << "[" << m_a << "," << m_b << "]";
	return s.str();
}

/*  Expected:
 *  Use cases of the class that are expected to be working.
*/
/*
  { X{}                   } // see the logs, find out what happens with m_a and m_b
	{ X{1,2};				    	  }
  { X{1};				       	  } // see the logs, find out what happens with m_b
	{ X x{}, y{x};			  	}
	{ X x{}, y = x;				  } // as expected
	{ X x{}, y{}; y += x;		}
	{ X x{}; ++x;				    }  // ++m_a, ++m_b
	{ X x{}; x++;				    }  // m_a++, m_b++
	{ X x{}, y{}; x + y;		}  // as expected
	{ cout << X{1,2};				}  // shows "[1,2]"
*/
