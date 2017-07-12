#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cstdlib>

using namespace std;
int FindPivot(int nums[],int b)      //used to find pivot
{
    return nums[b];
}
void Quicksort(int nums[],int a,int b)  //quicksort
{
    if (b<=a) return ;          //the end of recursion
    int pivot = FindPivot(nums,b);
    int j = a , p, temp;
    for(p=a;p<b;p++)
    {
        if(nums[p] < pivot)
        {
            temp = nums[p];
            nums[p] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
    nums[b] = nums[j];
    nums[j] = pivot;
    Quicksort(nums,a,j-1);    //recursion
    Quicksort(nums,j+1,b);
}

int main()
{
    string temp;

    int nums[10001];
    int i=0;
    cin >> temp;
    while(temp!="x")      //input
    {
        getchar();
        nums[i]=atoi(temp.c_str());
        i++;
        cin >> temp;
    }
    Quicksort(nums,0,i-1);
    for(int j=0;j<i;j++)    //output
    {
        cout << nums[j] << " ";
    }
    return 0;
}
