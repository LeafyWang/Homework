#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

double func(double num)       //function
{
    return 2*sin(num)- exp(num)/4 - 1;
}
int main()
{
    double a = -7,b = -5;
    double c = (a+b)/2.0;
    //double mis = (b-a);

    for (int i=0;i<5;i++)
    {
        printf("��%d�Σ�a=%.8f\tb=%.8f\tc=%.8f\t\n",i+1,a,b,c);
        printf("f(x)�ֱ�Ϊ%.8f\t%.8f\t%.8f\n",func(a),func(b),func(c));
        //printf("���������Ϊ��%.8f ʵ�����Ϊ��%.8f ʵ��������ֵΪ��%.8f\n\n",mis,c-answer,fabs(c-answer));
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

    a = -3;
    b = -5;
    c = (a+b)/2.0;
    //double mis = (b-a);

    cout << endl << endl ;

    for (int i=0;i<5;i++)
    {
        printf("��%d�Σ�a=%.8f\tb=%.8f\tc=%.8f\t\n",i+1,a,b,c);
        printf("f(x)�ֱ�Ϊ%.8f\t%.8f\t%.8f\n",func(a),func(b),func(c));
        //printf("���������Ϊ��%.8f ʵ�����Ϊ��%.8f ʵ��������ֵΪ��%.8f\n\n",mis,c-answer,fabs(c-answer));
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
