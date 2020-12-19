#include <iostream>
#include <iomanip>
#include <cmath>

double fu(int x)
{
    double f = cos(x) * tanh(x);
    return f;
}

double fumin(int x)
{
    double fm = cos(x) * tanh(x) * sin(5 * x);
    return fm;
}

void print(const int i, const double t,
    const double co, const double f) {
    std::cout << "| " << std::setw(4) << i
        << "| " << std::setw(10) << t
        << "| " << std::setw(10) << co
        << "| " << std::setw(12) << f << "|" << std::endl;
}


int main()
{
    std::cout << "Ecstremum f(x) " << std::endl;
    std::cout  <<  "| " << std::setw(4) << "N"
        << "| " << std::setw(10) << "T"
        << "| " << std::setw(10) << "x"
        << "| " << std::setw(12) << "f(x)" << "|" << std::endl
        << std::string(50, '-') << std::endl;
    double tmin = 0.01;
    double tmax = 10000.0, xsch = 0.0, r = 0.0, a = 7, b = 11;
    int N = 1;
    double xn = 0, x = (double)(rand() % 2501) / 1000 + 1.5;
    r = fu(x);
    while (tmax > tmin)
    {
        xsch = (double)(rand() % 2501) / 1000 + 1.5;
        double d = fu(xsch) - fu(x);
        if (d <= 0)
        {
            xn = xsch;
            x = xsch;
            r = fu(xn);
        }
        else
        {
            double ver = (double)(a + rand() * 1. / RAND_MAX * (b - a));
            double P = exp(-d / tmax);
            if (ver < P)
            {
                xn = xsch;
                x = xsch;
                r = fu(xn);
            }
        }

        print(N, tmax, xn, fu(xn));
        tmax = tmax * 0.95;
        N++;

    }
    std::cout << std::endl << "Xmin = " << xn << "   Fmin = " << r << std::endl;



    std::cout << "\nEcstremum f(x)*sin(5x) " << std::endl;
    std::cout << "| " << std::setw(4) << "N"
        << "| " << std::setw(10) << "T"
        << "| " << std::setw(10) << "x"
        << "| " << std::setw(12) << "f(x)" << "|" << std::endl
        << std::string(50, '-') << std::endl;

    tmin = 0.01; tmax = 10000.0; xsch = 0.0; r = 0.0; a = 7; b = 11; N = 1; xn = 0;
    x = (double)(rand() % 2501) / 1000 + 1.5;
    r = fumin(x);
    while (tmax > tmin)
    {
        xsch = (double)(rand() % 2501) / 1000 + 1.5;
        double d = fumin(xsch) - fumin(x);
        if (d <= 0)
        {
            xn = xsch;
            x = xsch;
            r = fumin(xn);
        }
        else
        {
            double ver = (double)(a + rand() * 1. / RAND_MAX * (b - a));
            double P = exp(-d / tmax);
            if (ver < P)
            {
                xn = xsch;
                x = xsch;
                r = fumin(xn);
            }
        }

        print(N, tmax, xn, fumin(xn));
        tmax = tmax * 0.95;
        N++;

    }
    std::cout << std::endl << "Xmin = " << xn << "   Fmin = " << r << std::endl;


    return 0;
}