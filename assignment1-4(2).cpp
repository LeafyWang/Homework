#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

double func(double x)       //function
{
    return pow((x-2),3)*pow((x-4),2);
}
int main()
{
    double a = 1,b = 5;
    double c = (a+b)/2.0;
    //double mis = (b-a);

    for (int i=0;i<10;i++)
    {
        printf("第%d次：a=%.8f\tb=%.8f\tc=%.8f\t\n",i+1,a,b,c);
        printf("f(x)分别为%.8f\t%.8f\t%.8f\n",func(a),func(b),func(c));
        //printf("最大估算误差为：%.8f 实际误差为：%.8f 实际误差绝对值为：%.8f\n\n",mis,c-answer,fabs(c-answer));
        if(func(a)*func(c)>0)      //Bisection
        {
            a = c;
            c = (a+b)/2.0;
        }
        else
        {
            b = c;
            c = (a+b)/2.0;
        }
    }
    return 0;
}
