
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a[5][5] = {0}, tol, oldValue;
    int i, j, k = 1, iteration = 0;

    cout << "Enter the tolerance error: " << endl;
    cin >> tol;


    // Boundary conditions
    for (i = 0; i <= 4; i++)
    {
        a[i][0] = 0;
        a[i][4] = 12 + (4 - i);
    }

    for (j = 0; j <= 4; j++)
    {
        a[4][j] = 3 * j;
        a[0][j] = j * j;
    }

    // Gauss-Seidel iterations
    while (k != 0 && iteration < 10000)
    {
        k = 0;

        for (i = 1; i <= 3; i++)
        {
            for (j = 1; j <= 3; j++)
            {
                oldValue = a[i][j];

                a[i][j] = 0.25 * (a[i-1][j] + a[i+1][j]+ a[i][j-1] + a[i][j+1]);

                if (fabs(a[i][j] - oldValue) > tol)
                {
                    k = 1;
                }
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
    cout << "Solution of Laplace equation:" << endl;
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
