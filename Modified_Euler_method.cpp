#include <bits/stdc++.h>
using namespace std;

// Example: y' = x + y
double f(double x, double y) {
    return x + y;
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
    cout << "\nModified Euler Method (Trapezoidal Rule)\n";
    cout << "x\t\t y\n";
    cout << x << "\t " << y << "\n";

    while (x < xn - 1e-9) {   // loop until x reaches xn (with small tolerance)
        double k1 = f(x, y);                 // slope at (x_n, y_n)
        double y_pred = y + h * k1;          // predictor (Euler)
        double k2 = f(x + h, y_pred);        // slope at (x_{n+1}, y_pred)

        // Corrector (trapezoidal update)
        y = y + (h / 2.0) * (k1 + k2);
        x = x + h;

        cout << x << "\t " << y << "\n";
    }

    cout << "\nApproximate solution at x = " << xn << " is y = " << y << "\n";
    return 0;
}
