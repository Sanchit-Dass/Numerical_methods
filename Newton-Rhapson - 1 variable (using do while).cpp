#include <iostream>
#include <cmath>

using namespace std;

// Function f(x)
double f(double x)
{
    return x * x * x - 3 * x - 5;
}

// Derivative f'(x)
double df(double x)
{
    return 3 * x * x - 3;
}

int main()
{
    double x0, x1;
    double epsilon = 1e-6;
    int iter = 0;
    int maxIter = 100;

    cout << "Enter the initial guess: ";
    cin >> x0;

    do
    {
        // Check if derivative is too small
        if (fabs(df(x0)) < 1e-12)
        {
            cout << "\nDerivative is too small." << endl;
            return 0;
        }

        // Newton-Raphson formula
        x1 = x0 - f(x0) / df(x0);

        iter++;

        cout << "Iteration " << iter
             << ": x = " << x1 << endl;

        // Check convergence
        if (fabs(x1 - x0) < epsilon)
        {
            cout << "Root = " << x1 << endl;
            cout << "Iterations = " << iter << endl;
            return 0;
        }

        x0 = x1;

    } while (iter < maxIter);

    cout << "\nMethod did not converge within "
         << maxIter << " iterations." << endl;

    return 0;
}
