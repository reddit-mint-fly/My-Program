#include<iostream>
using namespace std;
void swap(int&a,int&b)
{
    int tmp=a;
    a=b;
    b=tmp;
}
void show(int arr[])
{
    for(int i=0;i<10;i++){
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}
void maopao(int arr[])
{
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    show(arr);
}
void insertsort(int arr[])
{
    for(int j=1;j<10;j++){
        int value=arr[j];
        int i=j-1;
        while(arr[i]>value && i>=0){
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=value;
    }
    show(arr);
}
//-------------------------------------------------------------------------------------
void mergearray(int a[],int b[],int first,int middle,int last)
{
    int k=0;
    int i=first;
    int j=middle+1;
    int m=last;
    while(i<=middle && j<=last){
        if(a[i] <= a[j]){
            b[k++]=a[i++];
        }else{
            b[k++]=a[j++];
        }
    }
    while(i<=middle){
        b[k++]=a[i++];
    }
    while(j<=last){
        b[k++]=a[j++];
    }
    for(int i=0;i<k;i++){
        a[first+i]=b[i];
    }
}
void mergesort(int a[],int first,int last,int b[])
{
    if(first<last)
    {
        int middle=(first+last)/2;
        mergesort(a,first,middle,b);
        mergesort(a,middle+1,last,b);
        mergearray(a,b,first,middle,last);
    }
}
int main()
{
    int arr[10]={23,11,33,12,4,6,15,57,88,90};
    int a[]={1,3,5,7,9,2,4,6,8,10};
    int *b=new int[10];


    //maopao(arr);
    //insertsort(arr);
    mergesort(a,0,9,b);
    show(a);
    delete[] b;
}
