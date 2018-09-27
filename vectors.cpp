#include <iostream>
#include <assert.h>
using namespace std;
class vector
{
    int s;
    int c;
    int *arr;
public:
    vector();
    vector(int,int);
    int size();
    int resize(int);
    void push_back(int);
    void pop_back();
    void insert(int,int);
    void erase(int);
    int front();
    int back();
    int geti(int);
    int getCapacity();
    bool empty();
    void printVector(int,int);
    int& operator[](int);
};
vector::vector()
{
    s=0;
    c=10;
    arr=(int *)malloc(10*sizeof(int));
}
vector::vector(int n,int x)
{
    s=n;
    c=n;
    arr=(int *)malloc((2*n)*sizeof(int));
    for(int i=0;i<n;i++)
    {
        arr[i]=x;
    }
}
int vector::geti(int i)
{
    return arr[i];
}
int vector::size()
{
    return s;
}
void vector::erase(int i)
{
    assert(i>=0 && i<s);
    for(int j=i;j<s-1;j++)
    {
        arr[j]=arr[j+1];
    }
    --s;
    c++;
}
void vector::insert(int i,int x)
{
    assert(i>=0 && i<=s);
        if(c==0)
        {
            int *new_ptr=(int *)realloc(arr,(2*s)*sizeof(int));
            ++s;
            for(int j=s-1;j>i;j--)
            {
                arr[j]=arr[j-1];
            }
            new_ptr[i]=x;
            c=(2*s)-s;
            c--;
            arr=new_ptr;
        }
        else
        {
            s++;
            for(int j=s-1;j>i;j--)
            {
                arr[j]=arr[j-1];
            }
            arr[i]=x;
            c--;
        }
}
void vector::push_back(int a)
{
    if(c==0)
    {
        int *new_ptr=(int *)realloc(arr,(2*s)*sizeof(int));
        new_ptr[s]=a;
        c=(2*s)-s;
        s++;
        c--;
        arr=new_ptr;
    }
    else
    {
        arr[s]=a;
        s++;
        c--;
    }
}
int vector::getCapacity()
{
    return c;
}
void vector::pop_back()
{
    if(s>0)
    {
        s--;
        c++;
    }
    else
    {
        cout<<"error"<<endl;
    }
}
int vector::front()
{
    return arr[0];
}
int vector::back()
{
    return arr[s-1];
}
bool vector::empty()
{
    if(s>0)
        return true;
    return false;
}
void vector::printVector(int i,int j)
{
    if(i>=0 && j<s)
    {
        for(int i=0;i<j;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
}
int& vector::operator[](int i)
{
    assert(i>=0 && i<s);
    return arr[i];
}
int main(int argc, char const *argv[])
{
    vector v;
	cout<<v.getCapacity()<<endl;
	for(int i=0;i<20;i++)
	{
		v.push_back(i);
	}
	cout<<v.getCapacity()<<endl;
	v.push_back(2);
	v.pop_back();
		cout<<v.getCapacity()<<endl;
    /*for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    cout<<"size:"<<v.size()<<endl;
    cout<<"capacity:"<<v.getCapacity()<<endl;
    for(int i=0;i<20;i++)
    {
        v.push_back(i);
    }
    cout<<"after pushback:"<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    cout<<"size:"<<v.size()<<endl;
    cout<<"capacity:"<<v.getCapacity()<<endl;
    //v.push_back(75);
    
    cout<<"front:"<<v.front()<<endl;
    cout<<"back:"<<v.back()<<endl;
    for(int i=0;i<20;i++)
    {
        v.pop_back();
    }
   cout<<"size after pop_back:"<<v.size()<<endl;
    cout<<"capacity:"<<v.getCapacity()<<endl;
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;

    for(int i=0;i<7;i++)
    {
        v.insert(i,i+100);
    }    
       for(int i=0;i<v.size();i++)
            cout<<v[i]<<endl;
        cout<<"front:"<<v.front()<<endl;
        cout<<"back:"<<v.back()<<endl;
        cout<<"size:"<<v.size()<<endl;
        cout<<"capacity:"<<v.getCapacity()<<endl;
        v.insert(v.size(),1000);
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<endl;
        cout<<"inserting at end size"<<v.size()<<endl;*/
    return 0;
}
