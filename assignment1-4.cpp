#include<math.h>
#include<iostream>
#include<stdio.h>

using namespace std;

float func(float x)
{
    return pow((x-2),3)*pow((x-4),2);
}
float point(float x1,float x2)
{
    return (x1*func(x2)-x2*func(x1))/(func(x2)-func(x1));
}
int main()
{
    //输入两个数x1,x2
    float x1,x2,x;
    x1=1;
    x2=5;
    int times=0;
    do{
        x=point(x1,x2);//得到交点的值
        if(func(x)*func(x1)>0)x1=x;//新的x1
        else x2=x;

        times++;
        printf("第%d次迭代，x值为%.6f\t",times,x);
        cout << func(x)<<endl;
        }while (fabs(func(x)) > 0.00001); //0.0001为取值精
    cout <<endl;
    printf("Secant method\t迭代次数为%d次\n",times);
    cout <<endl;

    return 0;
}
