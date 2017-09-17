#include<iostream>
using namespace std;
class Test{
    public:
        void show(){
            std::cout << "test struct" << std::endl;
        }
};
class Ptr{
    private:
        int count;
        Test* t;
        Ptr(Test* src){
            t=src;
            count=1;
        }
        ~Ptr(){
            delete t;
        }
        friend class SmartPoint;
};
class SmartPoint{
    private:
        Ptr* ptr;
    public:
        SmartPoint(Test* t){
            ptr=new Ptr(t);
        }
        SmartPoint(const SmartPoint& s):ptr(s.ptr){
            ++ptr->count;
        }
        SmartPoint& operator=(const SmartPoint& s){
            ++s.ptr->count;
            if(ptr->count==0){
                delete ptr;
            }
            ptr=s.ptr;
            return *this;
        }
        ~SmartPoint(){
            if(--ptr->count==0){
                delete ptr;
            }else{
                cout<<"shengyu "<<ptr->count<<endl;
            }
        }
};
