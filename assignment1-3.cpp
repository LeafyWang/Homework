#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

double funa(double x)               //以下各项funx是函数表达式
{
    return cos(x) - x*x*x + 1;
}
double diffa(double x)              //以下各个diffx是导数表达式
{
    return 0-sin(x)-3*x*x;
}

int main()
{
    int times;
    double x;

    cout << "f(x) = cos(x) and f(x) = x^3 - 1 交与x当且仅当 cos(x) - x^3 + 1 = 0" <<endl;

    x = 1;
    times = 0;
    while(fabs(funa(x))>0.005*1)
    {
        x = x - funa(x)/diffa(x);
        times++;
    }
    printf("a:\t%.6f\t",x);
    cout << "迭代次数为" << times << endl  ;

    return 0;
}
