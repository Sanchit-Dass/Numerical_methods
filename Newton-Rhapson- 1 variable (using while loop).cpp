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
    int iteration = 0;
    int maxIter = 100;

    cout << "Enter initial guess: ";
    cin >> x0;

    while (true)
    {
        if (fabs(df(x0)) < 1e-12)
        {
            cout << "Derivative is too small." << endl;
            break;
        }

        x1 = x0 - f(x0) / df(x0);

        iteration++;

        cout << "Iteration " << iteration
             << ": x = " << x1 << endl;

        if (fabs(x1 - x0) < epsilon)
        {
            cout << "Root = " << x1 << endl;
            cout << "Iterations = " << iteration << endl;
            break;
        }

        if (iteration >= maxIter)
        {
            cout << "Method did not converge within "<< maxIter << " iterations." << endl;
            break;
        }

        x0 = x1;
    }

    return 0;
}
