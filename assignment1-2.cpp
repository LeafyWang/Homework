#include<math.h>
#include<iostream>
#include<stdio.h>

using namespace std;

float func(float x)
{
    return 2*sin(x)-exp(x)/4 -1;
}
float point(float x1,float x2)
{
    return (x1*func(x2)-x2*func(x1))/(func(x2)-func(x1));
}
int main()
{
    //����������x1,x2
    float x1,x2,x;
    x1=-5;
    x2=-3;
    int times=0;
    do{
        x=point(x1,x2);//�õ������ֵ
        if(func(x)*func(x1)>0)x1=x;//�µ�x1
        else x2=x;

        times++;
        printf("��%d�ε�����xֵΪ%.6f\t",times,x);
        cout << func(x)<<endl;
        }while (fabs(func(x)) > 0.00001); //0.0001Ϊȡֵ��
    cout <<endl;
    printf("Secant method\t��������Ϊ%d��\n",times);
    cout <<endl;


    x1=-5;
    x2=-7;
    times=0;
    do{
        x=point(x1,x2);//�õ������ֵ
        if(func(x)*func(x1)>0)x1=x;//�µ�x1
        else x2=x;
        times++;

        printf("��%d�ε�����xֵΪ%.6f\t",times,x);
        cout << func(x)<<endl;
        }while (fabs(func(x)) > 0.00001);
    cout << endl;
    printf("��������Ϊ%d��\n",times);
    cout <<endl;

    cout << "�����趨Ϊ0.00001" <<endl;

    return 0;
}
