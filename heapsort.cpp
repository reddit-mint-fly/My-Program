#include<iostream>
using namespace std;
void heapdown(int v[],int len,int i)
{
    int root=i;
    int left=root*2+1;
    while(left < len)
    {
        if(left+1 < len && v[left+1]>v[left])
        {
            ++left;
        }
        if(v[left]>v[root])
        {
            std::swap(v[left],v[root]);
            root=left;
            left=root*2+1;
        }
        else
        {
            break;
        }
    }
}
void heapsort(int v[],int len)
{
    for (int i = (len-1)/2; i>=0; i--)
    {
        heapdown(v,len,i);
    }
    while(--len)
    {
        std::swap(v[0],v[len]);
        heapdown(v,len,0);
    }
}
int main(int argc, char *argv[])
{
    int v[]={34,53,2,6,12,76,45,98,443,23,8};
    heapsort(v,11);
    for (int i = 0; i < 11; i++) {
        cout<<v[i]<<"  ";
    }
    cout<<endl;
    return 0;
}
