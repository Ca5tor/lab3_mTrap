#include <iostream>
#include <iomanip> // для setprecision и setw

double f(double x) {
    return (2 * (1 + x) * std::exp(-x) - 2 * cos(x));
}

double trap(double a, double b, double E) {
    int n = 1;
    double h = (b - a);
    double s = (f(a) + f(b)) * (h / 2);
    double s1;

    do {
        n = 2 * n;
        h = (b - a) / n;
        s1 = s;
        s = f(a) + f(b);
        for (int i = 1; i != n - 1; i++)
            s = s + 2 * f(a + i * h);
        s = s * h / 2;

        std::cout << std::setprecision(6) << std::setw(11) << h <<
            std::setw(10) << n << std::setw(10) << s << std::endl;

    } while ((abs(s - s1) / 3) > E);

    return s;
}

void main() {
    double a = 1, b = 4, E = 0.0001;
    double result = trap(a, b, E);

    std::cout << "\n\tResult:" << result << std::endl;
    system("pause");
}
