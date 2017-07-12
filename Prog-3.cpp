#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cstdlib>

using namespace std;
void Median(int nums[],int x,int y,int z)     //find the median of 3 samples and move it to nums[x]
{
    int temp ;
    if(nums[x]>nums[y])                      //sort 3 numbers and move the middle one to nums[b]
    {
        temp = nums[x];nums[x]= nums[y];nums[y] = temp;
    }

    if(nums[z]<nums[x]){return;}
    else if(nums[z]<nums[y]) { temp = nums[z];nums[z]= nums[x];nums[x] = temp; }
    else{ temp = nums[y];nums[y]= nums[x];nums[x] = temp; }
}

int FindPivot(int nums[],int bg,int ed)   //find the pivot and exchange it with the last element , then pivot will be the last number of this part of array
{
    int pos[9];                           //used to store the beginning index of nine evenly part of the array
    int pivot;
    for(int i=0;i<9;i++)
    {
        pos[i] = bg + i*(ed-bg)/9.0;      //pos[0] is nums[bg];
    }
    Median(nums,pos[0],pos[1],pos[2]);    //groups of 3, the(0,1,2)samples, the(3,4,5)samples, the(6,7,8)samples
    Median(nums,pos[3],pos[4],pos[5]);
    Median(nums,pos[6],pos[7],pos[8]);    // medians of three samples have been moved to pos[0],pos[3],pos[6]

    Median(nums,pos[0],pos[3],pos[6]);   //the ninther,the median of the median of 3 samples has been moved to pos[0]  (nums[bg])
    pivot = nums[bg];
    nums[bg] = nums[ed];nums[ed] = pivot; //exchange the pivot with the last element in order to make this pivot the last element(nums[ed])
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
    for(p=a;p<b;p++)        //simply Quicksort ,but the pivot is nums[b] and it is the ninther.
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
    Quicksort(nums,a,j-1);            //recursive
    Quicksort(nums,j+1,b);
}

int main()
{
    string temp;
    int nums[10001];
    int i=0;
    
    cin >> temp;
    while(temp!="x")                  //get input
    {
        getchar();
        nums[i]=atoi(temp.c_str());
        i++;
        cin >> temp;
    }
    
    Quicksort(nums,0,i-1);
    for(int j=0;j<i;j++)              //print the sorted array
    {
        cout << nums[j] << " ";
    }
    
    return 0;
}
