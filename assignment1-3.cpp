#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

double funa(double x)               //���¸���funx�Ǻ������ʽ
{
    return cos(x) - x*x*x + 1;
}
double diffa(double x)              //���¸���diffx�ǵ������ʽ
{
    return 0-sin(x)-3*x*x;
}

int main()
{
    int times;
    double x;

    cout << "f(x) = cos(x) and f(x) = x^3 - 1 ����x���ҽ��� cos(x) - x^3 + 1 = 0" <<endl;

    x = 1;
    times = 0;
    while(fabs(funa(x))>0.005*1)
    {
        x = x - funa(x)/diffa(x);
        times++;
    }
    printf("a:\t%.6f\t",x);
    cout << "��������Ϊ" << times << endl  ;

    return 0;
}
