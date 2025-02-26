#include <iostream>
#include <math.h>
using namespace std;
double F(double x) {
    return x * x - log10(x + 2);
}
double Fproiz(double x) {
    return 2 * x - 1 / ((x + 2) * log(10));
}
double newton(double x0, double epsilon, int& iterations) {
    double x = x0;
    iterations = 0;
    while (abs(F(x)) > epsilon) {
        x = x - F(x) / Fproiz(x);
        iterations++;
    }
    return x;
}
double g(double x) {
    return sqrt(log10(x + 2));
}
double iteration(double x0, double epsilon, int& iterations) {
    double x_prev = x0;
    double x = g(x_prev);
    iterations = 0;
    while (abs(x - x_prev) > epsilon) {
        x_prev = x;
        x = g(x_prev);
        iterations++;
    }
    return x;
}
int main() {
    setlocale(0, "");
    double epsilon = 0.0001;
    double x0 = 1.0;
    int iterations;
    double korennewton = newton(x0, epsilon, iterations);
    cout << "Метод касательных (Ньютона): корень = " << korennewton << ", итераций = " << iterations << endl;
    double koreniteration = iteration(x0, epsilon, iterations);
    cout << "Метод простой итерации: корень = " << koreniteration << ", итераций = " << iterations << endl;
    return 0;
}



/*double F(double x) {
    return x * x - log10(x + 2);
}
void anal(double a, double b, double h) {
    double x0 = a;
    double x1 = x0 + h;
    double F_x0 = F(x0);
    double F_x1 = F(x1);
    cout << "Поиск интервалов, где функция меняет знак:" << endl;
    while (x0 <= b) {
        if (F_x0 * F_x1 < 0) {
            cout << "Корень находится в интервале [" << x0 << ", " << x1 << "]" << endl;
        }
        x0 = x1;
        x1 = x0 + h;
        F_x0 = F(x0);
        F_x1 = F(x1);
        if (x1 > b) break;
    }
}
int main() {
    setlocale(0, "");
    double a = -2.0;
    double b = 2.0;
    double h = 0.1;
    anal(a, b, h);
    return 0;
}*/
