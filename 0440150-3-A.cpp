#include<iostream>
#include<math.h>
using namespace std;
void calculate(int a)
{
    int i,j,k;
    int sp;
    int b;

    for(i=0;i<=sqrt(a);i++)
    {
        sp = a;
        for(j=i;j<=sqrt(a);j++)
        {
            sp = a - i*i - j*j;
            k = sqrt(sp);
            {
                if(k*k == sp && k>=j)
                {
                    cout <<i <<" " << j << " " << k << endl;
                    return ;
                }
            }
        }
    }
    cout << "-1" <<endl;
    return;
    cout << "-1" <<endl;
    return;
}



int main()
{
    int N,a;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a;
        calculate(a);
    }
    return 0;
}
