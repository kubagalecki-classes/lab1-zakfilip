#include <iostream>
#include <cmath>
using namespace std;

class Wektor2D
{
public:

	Wektor2D() : x(0), y(0) {}
	Wektor2D(Wektor2D& v) : x(v.x) , y(v.y) {}
	Wektor2D(const Wektor2D& v) : x(v.x), y(v.y) {}
	Wektor2D(double xx, double yy) : x(xx), y(yy) {}
	~Wektor2D() {}

	Wektor2D& operator=(Wektor2D& a)
	{
		if (this != &a)
		{
			this->x = a.x;
			this->y = a.y;
		}
		return *this;
	}
	friend Wektor2D operator+(Wektor2D& a,Wektor2D& b);
	friend double operator*(Wektor2D& a, Wektor2D& b);

	void print()
	{
		cout << "[" << x << "," << y << "]";
	}

	void setX(double xx) { x = xx; }
	void setY(double yy) { y = yy; }
	double getX() { return x; }
	double getX() const { return x; }
	double getY() { return y; }
	double getY() const { return y; }

private:
	double x, y;
};

Wektor2D operator+(Wektor2D& a,Wektor2D& b)
{
	Wektor2D tmp(a);
	tmp.x += b.x;
	tmp.y += b.y;
	return tmp;
}

double operator*(Wektor2D& a, Wektor2D& b)
{
	return a.x*b.x+a.y*b.y;
}
