#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

double fun(double x)
{
    return sqrt(exp(x)/2);
}

double fun2(double x)     //question c : another rearrangement
{
    return 2*log(x)+log(2);
}

int main()
{
    double beg = 1.5;
    cout << "the root near 1.5:" <<endl;
    while(fabs(fun(beg)-beg)>0.00001)
    {
        beg = fun(beg);
        cout << beg <<endl;
    }

    cout <<"result" << beg << endl;

    cout << "the root near -0.5:" <<endl;
    beg = -0.5;
    while(fabs(-fun(beg)-beg)>0.00001)
    {
        beg = -fun(beg);
        cout << beg <<endl;
    }

    cout << "result" << beg << endl;

    cout << "the root near 2.6 positive/negative value is used:" <<endl;  //question b
    beg = 2.6;
    int times = 0;
    while(times<100)
    {
        beg = fun(beg);

        times ++ ;
    }cout << beg <<endl;
    beg = 2.6;
    times = 0;
    while(times<100)
    {
        beg = -fun(beg);

        times ++ ;
    }cout << beg <<endl;

    cout << "the root near 2.5 迭代100次 positive/negative value is used:" <<endl;
    beg = 2.5;
    times = 0;
    while(times<100)
    {
        beg = fun(beg);

        times ++ ;
    }cout << beg <<endl;
    beg = 2.5;
    times = 0;
    while(times<100)
    {
        beg = -fun(beg);

        times ++ ;
    }cout << beg <<endl;

    cout << "Try 2.7 迭代10次:" <<endl;
    beg = 2.7;
    times = 0;
    while(times<100)
    {
        beg = fun(beg);

        times ++ ;
    }cout << beg <<endl;



    cout << "Q(c): another rearrangement:" <<endl;
    beg = 2.6;      //another rearrangement
    times = 0;
    while(times<100)
    {
        beg = fun2(beg);

        times ++ ;
    }cout << beg <<endl;


    return 0;
}
