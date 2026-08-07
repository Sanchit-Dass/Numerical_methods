#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return x * x * x - 3 * x - 5;
}

double df(double x)
{
    return 3 * x * x - 3;
}

int main()
{
    double x0, x1;
    double error;
    const double epsilon = 1e-6;
    int iter = 0;

    cout << "Enter the initial guess: ";
    cin >> x0;

    do
    {
        // Check if the derivative is too small
        if (fabs(df(x0)) < 1e-12)
        {
            cout << "\nDerivative is too small." << endl;
            return 0;
        }

        // Newton-Raphson formula
        x1 = x0 - f(x0) / df(x0);

        // Compute the absolute error
        error = fabs(x1 - x0);

        iter++;

        cout << "Iteration " << iter
             << " : x = " << x1
             << "   Error = " << error << endl;

        // Update the current approximation
        x0 = x1;

    }
    while (error >= epsilon);

    if (error < epsilon)
    {
        cout << "Root               = " << x1 << endl;
        cout << "Function value     = " << f(x1) << endl;
        cout << "Absolute Error     = " << error << endl;
        cout << "Iterations         = " << iter << endl;
        cout << "----------------------------------------" << endl;
    }
   

    return 0;
}
