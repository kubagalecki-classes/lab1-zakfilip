#include <cmath>
#include <iostream>
using namespace std;

class Informer
{
    Informer() { cout << "Informer created" << endl; }
    ~Informer() { cout << "Informer destroyed" << endl; };
};
class Wektor2d
{
public:
    Wektor2d() : x(0), y(0)
    {
        //Informer I();
        ++num_wek;
        cout << "Empty vector created" << endl;
    }
    Wektor2d(const Wektor2d& v) : x(v.x), y(v.y)
    {
        //Informer I();
        ++num_wek;
        cout << "Vector copied" << endl;
    }
    Wektor2d(double xx, double yy) : x(xx), y(yy)
    {
        //Informer I();
        ++num_wek;
        cout << "Vector "
            << "[ " << x << " " << y << " ]"
            << " created" << endl;
    }
    /*
       static Wektor2d kart(double xx, double yy)
       {
           Informer I();
           ++num_wek;
           x = xx;
           y = yy;
           cout << "Vector "
                << "[ " << x << " " << y << " ]"
                << " created" << endl;
       }
       static Wektor2d bieg(double r, double a)
       {
           Informer I();
           ++num_wek;
           x = r * cos(a);
           y = r * sin(a);
           cout << "Vector "
                << "[ " << x << " " << y << " ]"
                << " created" << endl;
       }
   */
    ~Wektor2d()
    {
        --num_wek;
        cout << "Vector "
            << "[ " << x << " " << y << " ]"
            << " destroyed" << endl;
    }

    friend Wektor2d operator+(const Wektor2d& a, const Wektor2d& b);
    // Rozumiem że skalarnie
    friend double operator*(const Wektor2d& a, const Wektor2d& b);
    // Std dla formalności
    friend std::ostream& operator<<(std::ostream& os, const Wektor2d& a);

    double norm() { return sqrt(x * x + y * y); }
    void   print() { cout << "[ " << x << " " << y << " ]" << endl; }
    int    populacja() { return num_wek; }

    double getX() { return x; }
    double getX() const { return x; }
    double getY() { return y; }
    double getY() const { return y; }
    void   setX(double xx) { x = xx; }
    void   setY(double yy) { y = yy; }

    static int num_wek;

private:
    double     x, y;
};

Wektor2d operator+(const Wektor2d& a, const Wektor2d& b)
{
    Wektor2d tmp = a;
    tmp.x += b.x;
    tmp.y += b.y;
    return tmp;
}
double operator*(const Wektor2d& a, const Wektor2d& b)
{
    return (a.x * b.x + a.y * b.y);
}
std::ostream& operator<<(std::ostream& os, const Wektor2d& a)
{
    os << "[ " << a.x << " " << a.y << " ]";
    return os;
}

int Wektor2d::num_wek = 0;

int main()
{
    Wektor2d v(3, 4);
    cout << v.populacja() << endl;
    // cout << "Norm of v " << v.norm() << endl;
    // v.print();
    return 0;
}

/*
Ja czasami do visuala przeskakuje także bede updatować
*/
