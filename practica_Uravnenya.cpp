
#include <cmath>
#include <iostream>
using namespace std;

//    f(x) = 3 * sin(pow(x,0.5)) + 0.35 * x - 3.8
//    f'(x) = 3 * cos(pow(x,0.5)) + 0.35 
//    f''(x) = -(3 (cos(sqrt(x)) + sqrt(x) sin(sqrt(x))))/(4 x^(3/2))
//    [a, b]
//     a = 2, b = 3
//
//    f(a)*f''(a) > 0 => a = x0
//    f(b)*f''(b) > 0 => b = x0

void nuton()
{
    float x, xPrevious;
    double epsilon = 0.000001;
    x = 2;
    xPrevious = 0;

    while (abs(x - xPrevious) > epsilon)
    {
        xPrevious = x;
        x = xPrevious - ((3 * sin(pow(x,0.5)) + 0.35 * x - 3.8) * (3 * cos(pow(x, 0.5)) + 0.35));
    }
    cout << "There is a x = " << x << endl;
   
}

void hd()
{
    float a, b, c;
    float fA, fB, fC;
    double eps = 0.000001;
    a = 2;
    b = 3;
    while ((b - a) > eps)
    {
        c = (a + b) / 2;
        fA = 3 * sin(pow(a, 0.5)) + 0.35 * a - 3.8;
        fB = 3 * sin(pow(b, 0.5)) + 0.35 * b - 3.8;
        fC = 3 * sin(pow(c, 0.5)) + 0.35 * c - 3.8;
        if (fA * fC < 0) { b = c; }
        else if (fC * fB < 0) { a = c; }
        else { cout << "That's not good :c" << endl; }
    }
    cout << "There is x = " << a << " and " << b << endl;
}

//    f(x) = 3 * sin(pow(x,0.5)) + 0.35 * x - 3.8
//    f'(x) = 3 * cos(x^0.5) + 0.35 
//    f''(x) = -(3 (cos(sqrt(x)) + sqrt(x) sin(sqrt(x))))/(4 x^(3/2))
//    [2, 3]
//    f(x) = x + λ(3Sin(x^0.5)+0.35x - 3.8)
//    -1/r < λ < 0, если f'(x) > 0
//    0 < λ < 1/r, если f'(x) < 0
//    r = max(|f'(a)|, |f'(b)|) = 0.21
//    λ = -1/0.56 = -1.79

void implication()
{
    float x, xPrev;
    double lambda = -1.79; // -1/0.21
    x = 2; // можно выбрать любое x0 из [2, 3] — выбранного заранее промежутка
    xPrev = 0; //делаем заведомо сильно меньше x, чтобы цикл правильно сработал
    double eps = 0.000001;

    while (abs(x - xPrev) > eps)
    {
        xPrev = x;
        x = lambda * (3 * sin(pow(xPrev, 0.5)) + 0.35 * xPrev - 3.8) + xPrev;
    }
    cout << "X = " << x << endl;
}

int main()
{
    char option;
    cout << "Type tne number of resh uravnenue: NutonMetod, DelMetod, IterationMetod" << endl
        << "Valuable option N, D, I " << endl;
    cin >> option;
    switch (option)
    {
    case 'N': nuton(); break;
    case 'D': hd(); break;
    case 'I': implication(); break;
    }
}


