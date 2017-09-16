#include <iostream>
#include<vector>
using namespace std;
int func(vector<int>& input,int value){
    int length=input.size();
    int left=0;
    int right=length-1;
    while(left <= right){
        int middle=left+((right-left)>>1);
        if(input[middle] > value){
            right=middle-1;
        }else if(input[middle] < value){
            left=middle+1;
        }else{
            return middle;
        }
    }
    return -1;
}
int main(int argc, char *argv[])
{
    std::vector<int> v1={11,12,13,14,15,16,17,18,19};
    std::vector<int> v2={12};
    std::vector<int> v3={11,14};
    cout<<func(v3,14)<<endl;
    return 0;
}
