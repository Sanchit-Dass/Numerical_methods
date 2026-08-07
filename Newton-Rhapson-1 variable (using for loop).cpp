#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
    return x*x*x - 3*x - 5;
}

double df(double x)
{
    return 3*x*x - 3;
}

int main()
{
    double x0, x1;
    double epsilon = 1e-6;
    int maxIter = 100;

    cout << "Enter initial guess: ";
    cin >> x0;

    for (int i = 1; i <= maxIter; i++)
    {
        // Check if derivative is too close to zero
        if (fabs(df(x0)) < 1e-16)
        {
            cout << "Derivative is too small." << endl;
            return 0;
        }

        // Newton-Raphson formula
        x1 = x0 - f(x0) / df(x0);

        cout << "Iteration " << i<< ": x = " << x1 << endl;

        // Convergence check
        if (fabs(x1 - x0) < epsilon)
        {
            cout << "Root = " << x1 << endl;
            cout << "Number of iterations = " << i << endl;
            return 0;
        }

        x0 = x1;
    }

    cout << "Method did not converge within "
         << maxIter << " iterations." << endl;

    return 0;
}
