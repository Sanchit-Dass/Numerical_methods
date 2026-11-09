
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a[5][5] = {0}, b[5][5] = {0}, tol;
    int i, j, k = 1, iteration = 0;

    cout << "Enter the tolerance error: " << endl;
    cin >> tol;

    if (cin.fail() || !isfinite(tol) || tol <= 0)
    {
        cout << "Invalid tolerance!" << endl;
        return 1;
    }

    // Boundary conditions
    for (i = 0; i <= 4; i++)
    {
        a[i][0] = 0.0;
        a[i][4] = 12 + (4 - i);
    }

    for (j = 0; j <= 4; j++)
    {
        a[4][j] = 3*j;
        a[0][j] = j*j;
    }

    // Jacobi iterations
    while (k != 0 && iteration < 10000)
    {
        k = 0;

        // Calculate new values
        for (i = 1; i <= 3; i++)
        {
            for (j = 1; j <= 3; j++)
            {
                b[i][j] = 0.25 * (a[i-1][j] + a[i+1][j]+ a[i][j-1] + a[i][j+1]);

                if (fabs(b[i][j] - a[i][j]) > tol)
                {
                    k = 1;
                }
            }
        }

        // Update all values after one complete iteration
        for (i = 1; i <= 3; i++)
        {
            for (j = 1; j <= 3; j++)
            {
                a[i][j] = b[i][j];
            }
        }

        iteration++;
    }

    if (k != 0)
    {
        cout << "Method did not converge!" << endl;
        return 1;
    }

    cout << "Number of iterations = " << iteration << endl;
    cout << "Solution of Laplace equation (Jacobi method):" << endl;

    cout << fixed << setprecision(6);

    for (i = 0; i <= 4; i++)
    {
        for (j = 0; j <= 4; j++)
        {
            cout << setw(12) << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
