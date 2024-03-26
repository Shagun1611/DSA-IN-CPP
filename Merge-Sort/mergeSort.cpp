// MERGE SORT USING RECURSSION!!!

#include<iostream>
#include<algorithm>
using namespace std;

void merging(int arr[], int l, int mid, int h)
{
    int len1=mid-l+1;
    int len2=h-mid;

    int arr1[len1] ,arr2[len2];
    int k=l;
    for(int i=0;i<len1;i++)
    {
        arr1[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++)
    {
        arr2[i]=arr[k++];
    }
    int index1=0;
    int index2=0;
    int main=l;

    while(len1>index1 && len2>index2)
    {
        if(arr1[index1]>arr2[index2])
        {
            arr[main++]=arr2[index2++];
        }
        else
        {
            arr[main++]=arr1[index1++];
        }
    }
    while(len1>index1)
    {
        arr[main++]=arr1[index1++];
    }
    while(len2>index2)
    {
        arr[main++]=arr2[index2++];
    }
}

void mergeSort(int arr[], int l, int h)
{
    if(l>=h)
    {
        return;
    }
    if(h>l)
    {
        int mid=(l+h)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr,mid+1,h);
        merging(arr,l,mid,h);
    }
}
void Print(int arr[],int size)
{
    cout<<"Array after merging and Sorting is: ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    
    int arr[size];
    cout<<"Enter the elements of the array: ";
    cout<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter the "<<(i+1)<<" of the array: ";
        cin>>arr[i];
    }

    mergeSort(arr, 0, size-1);

    Print(arr, size);


}
