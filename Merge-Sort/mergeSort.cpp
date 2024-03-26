#include<iostream>
#include<algorithm>       //merge sort using recursion
using namespace std;

void merge(int arr[],int l,int mid,int n)
{
    int len1=mid-l+1; //length of left side of the array
    int len2=n-mid;   //lenth of the right side of the array

    //create two temporary arrays to store elements from both sides.

    int arr1[len1];//array for storing left side elements
    int arr2[len2];//array for storing right side elements
    int k=l;      //##important
    for(int i=0;i<len1;i++)
    {
        arr1[i]=arr[k++];//copying values of the left side
    }
    k=mid+1;
    for(int i=0;i<len2;i++)
    {
        arr2[i]=arr[k];//copying values of the right side
        k++;
    }

    int index1=0; //index for left side
    int index2=0; //index for right sie
    int mainindex=l; //index for main array in which we will do merging and sorting
    while (index1 < len1 && index2 < len2)
    {
        if(arr1[index1]<arr2[index2])
        {
            arr[mainindex]=arr1[index1];      //merging and soting the arrays
            mainindex++;
            index1++;
        }
        else{
            arr[mainindex] = arr2[index2];
            mainindex++;
            index2++;
        }
    }

    while(index1<len1)
    {
        arr[mainindex]=arr1[index1]; // if there are more elements in the left side than merging of remaining elements
        mainindex++;
        index1++;
    }

    while(index2<len2)
    {
        arr[mainindex]=arr2[index2]; //if there are more elements in the rightside than merginng of remaining elements
        mainindex++;
        index2++;
    }

}

void mergeSort(int arr[],int l,int n)
{
    //Base condition
    if(l>=n)
    {
        return;
    }
    if(n>l)
    {

        int mid=(l+n)/2;   //diving the array into two

        // for left side
        mergeSort(arr,l,mid);
        //for right side
        mergeSort(arr,mid+1,n);
        //for merging and sorting two arrays
        merge(arr,l,mid,n);

    }

}

int main()
{
    int size;
    cout<<"enter the sizde of the array: ";
    cin>>size;
    int arr[size];

    cout<<"Enter the elements of the array: ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int l=0;

    mergeSort(arr,l,size-1);
// to print array
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";

    }
    return 0;
}