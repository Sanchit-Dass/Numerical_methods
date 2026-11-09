#include <iostream>
#include <iomanip> // Required for setprecision()
#include <cmath>

using namespace std;

// The problem is dy/dx = x + y, with y(0) = 1 and h = 0.1.
// Using Modified Euler's method, find y(0.5).

double f(double x, double y) // Defines f(x, y) = x + y
{
    return x + y;
}

int main()
{
    double x0, y0, h, xEnd;

    // Inputs
    cout << "x0 = ";
    cin >> x0;

    cout << "y0 = ";
    cin >> y0;

    cout << "h = ";
    cin >> h;

    cout << "xEnd = ";
    cin >> xEnd;

    // Number of steps required to reach xEnd
    int n = static_cast<int>(round((xEnd - x0) / h));
    cout<<"The Number of steps require to reach xEnd = "<<n<<endl;
	
	// Maximum number of iterations for the corrector step
    int maxCorrectorIterations;
    cout << "Maximum corrector iterations = ";
    cin >> maxCorrectorIterations;

    // Tolerance used to check convergence of the corrector iterations
    double tolerance;
	cout << "Tolerance = ";
	cin >> tolerance;

    // Display floating-point values with 8 digits
    // after the decimal point
    cout << fixed << setprecision(8);
    
    // Print table headings
    	cout << "n\t"<< "x\t\t" << "y_n\t\t" << "y_Predictor\t" <<endl;
        cout<<endl;

    // Start iterations
    for(int i = 0; i < n; i++)
    {
        // Calculate the next x value
        double xNew = x0 + h;

        // ---------------- PREDICTOR ----------------

        // Euler predictor:
        // y_(n+1)^0 = y_n + h*f(x_n, y_n)
        double y_predictor = y0 + h * f(x0, y0);

        // Use the Euler predictor as the initial approximation
		// for the corrector iteration
        double y_corrected = y_predictor;
        
        // Print the result of this step
        cout<<endl;
        cout << i << "\t" << x0 << "\t" << y0 << "\t"
            << y_corrected <<endl;
        cout<<endl;

        // ---------------- CORRECTOR ----------------

        for(int iter = 1; iter <= maxCorrectorIterations; iter++)
        {
            // Modified Euler corrector:
			// y_(n+1) = y_n + h/2 *[f(x_n,y_n) + f(x_(n+1),y_(n+1)^k)]
            double y_new_corrected = y0 + (h / 2.0) *
                (f(x0, y0) + f(xNew, y_corrected));

            // Error between two successive corrections
            double error;
            error = fabs(y_new_corrected - y_corrected);
            
            // Print the corrector iteration values
            cout << "\t" <<"y_corrector_"<<iter<<" = "<< y_new_corrected <<endl;
     
             // Use the latest corrected value for the next correction iteration
            y_corrected = y_new_corrected;
             
             // Check convergence
            if(error < tolerance)
            {
                break;
            }

            
        }
        // Update x and y for the next step
        x0 = xNew;
        y0 = y_corrected;
    }
    
    // Print the final last row values of the table.
    cout<<endl;
    cout << n << "\t" << x0 << "\t" << y0 <<endl;

    return 0;
}
