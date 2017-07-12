#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cstdlib>

using namespace std;

int FindPivot(int nums[],int a,int b)      //find the middle value of begin/end/middle and move it to the end nums[b]
{
    int pivot; int temp ;
    int mid = (a+b)/2;
    if(nums[b]>nums[mid])
    {
        temp = nums[b];nums[b]= nums[mid];nums[mid] = temp;
    }
    if(nums[a]<nums[b])
    {
        pivot = nums[b];
    }
    else if(nums[a]<nums[mid])
    {
        temp = nums[a];nums[a]= nums[b];nums[b] = temp;
        pivot = nums[b];
    }
    else
    {
        temp = nums[mid];nums[mid]= nums[b];nums[b] = temp;
        pivot = nums[b];
    }
    return pivot;
}
void Quicksort(int nums[],int a,int b)
{
    int temp;
    if(b-a<=1)
    {
        if(nums[a]>nums[b])
        {
            temp = nums[b];nums[b]= nums[a];nums[a] = temp;
        }
        return ;
    }
    int pivot = FindPivot(nums,a,b);
    int j = a , p;
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
    nums[j] = pivot;    //the operations are same as Prog-1 after finding the pivot
    Quicksort(nums,a,j-1);
    Quicksort(nums,j+1,b);
}
int main()
{
    string temp;

    int nums[10001];
    int i=0;
    cin >> temp;
    while(temp!="x")
    {
        getchar();
        nums[i]=atoi(temp.c_str());
        i++;
        cin >> temp;
    }
    Quicksort(nums,0,i-1);
    for(int j=0;j<i;j++)
    {
        cout << nums[j] << " ";
    }
    return 0;
}
