#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double ERROR_RATE = 0.02;

double f(double x)
{
    return (exp(-0.5*x)) - (x) - (0.2);
}

double df(double x)
{
    return (-(exp(-x/2) / 2) - 1);
}

void bisection(double a, double b);
void newton_raphson(double a);
void linear_interpolation(double a, double b);

int main()
{
    double a =0, b = 2;
    bisection(a, b);
    newton_raphson(b);
    linear_interpolation(a,b);

    return 0;
}

void bisection(double a, double b)
{
    if (f(a) * f(b) >= 0) {
        cout << "Hatali uc degerler.." << endl;
        return;
    }

    double c = a;
    for (int i = 0; i < 10; i++) {
        c = (a+b)/2;
        if (f(c)*f(a) < 0)
            b = c;
        else
            a = c;
        cout << "#" << i+1 << setw(22) << " The value of root is : " << c << "   " << setw(10) << (abs(b-a)/(2^i)) << endl;
    }
}

void newton_raphson(double a)
{
    double x1,x0;
    double df0;
    double f0;

    double h = f(a) / df(a);

    for (int i = 0; i < 10; i++) {

        df0 = df(a);
        f0 = f(a);
        if(df0 == 0.0) {
            cout << "Hatali deger.." << endl;
            return;
        }
        x1 = x0 - f0 / df0;
        cout << "#" << i+1 << setw(22) <<  " The value of the root is : " << x1 << "   " << setw(10) << abs(x1-x0) << endl;
        x0 = x1;

#if 0

        h = f(a)/df(a);
        a = a - h;
        cout << "The value of the root is : " << a << endl;
#endif
    }
}

void linear_interpolation(double a, double b)
{
    double x0 = a;
    double y0 = f(a);
    double x1 = b;
    double y1 = f(b);
    double x;

    for (int i = 1; i < 10; i++) {
        y0 + ((y1 - y0)/(x1-x0))*(x-x0);
    }

}
