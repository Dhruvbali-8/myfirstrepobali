 #include <iostream>
#include <cmath>

using namespace std;

// Function for which we want to find the root
double f(double x) {
    return (x *x* x - 3*x-5); // Change this to your desired function
}

// Bisection method
double bisection(double a, double b, double tolerance) {
    if (f(a) * f(b) >= 0) {
        cout << "Bisection method cannot guarantee convergence in this interval." << endl;
        return NAN; // Not-a-Number to indicate failure
    }

    double c;
    int iteration = 0;

    while ((b - a) >= tolerance) {
        c = (a + b) / 2.0;
        
        if (f(c) == 0.0) {
            break; // Found the root exactly
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        iteration++;
    }

    cout << "Number of iterations: " << iteration << endl;

    return c;
}

int main() {
    double a, b, tolerance;
    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter the tolerance (e.g., 0.001): ";
    cin >> tolerance;

    double root = bisection(a, b, tolerance);

    if (!isnan(root)) {
        cout << "Approximate root: " << root << endl;
    } else {
        cout << "Failed to find a root within the given interval." << endl;
    }

    return 0;
}
