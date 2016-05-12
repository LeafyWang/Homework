#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;

void maxSubarray(int data[], int count,int &max)
{
    int sum = 0;
    int begin=0;
    int end=0;

    max=-(1<<31);
    for(int i=0;i<count;i++)
    {
       sum +=data[i];
       if(sum>max)
       {
             max=sum;
             end=i;
       }
       else if(sum<0)
      {    begin=(i+1)%count;
           sum=0;
      }
   }
   return;
}

int main()
{
    string temp;

    int nums[10001];
    int count=0;
    cin >> temp;
    while(temp!="x")      //读入数组并存储
    {
        getchar();
        nums[count]=atoi(temp.c_str());
        count++;
        cin >> temp;
    }
    int max;
    maxSubarray(nums,count,max);
    cout << max << endl;
    return 0;
}
