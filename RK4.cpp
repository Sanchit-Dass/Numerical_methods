#include <bits/stdc++.h>
using namespace std;

// Example ODE: y' = x + y
double f(double x, double y) {
    return x + y;   // change this to your differential equation
}

int main() {
    double x0, y0, xn, h;
    cout << "Enter initial x0: ";
    cin >> x0;
    cout << "Enter initial y0: ";
    cin >> y0;
    cout << "Enter final x (xn): ";
    cin >> xn;
    cout << "Enter step size h: ";
    cin >> h;

    double x = x0;
    double y = y0;

    cout << fixed << setprecision(6);
    cout << "\nRK4 Method\n";
    cout << "x\t\t y\n";
    cout << x << "\t " << y << "\n";

    while (x < xn - 1e-9) {   // loop until x reaches xn
        double k1 = f(x, y);
        double k2 = f(x + h/2.0, y + h*k1/2.0);
        double k3 = f(x + h/2.0, y + h*k2/2.0);
        double k4 = f(x + h,     y + h*k3);

        y = y + (h/6.0)*(k1 + 2*k2 + 2*k3 + k4);
        x = x + h;

        cout << x << "\t " << y << "\n";
    }

    cout << "\nApproximate solution at x = " << xn << " is y = " << y << "\n";
    return 0;
}
