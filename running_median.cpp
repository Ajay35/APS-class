#include<bits/stdc++.h>
#include <iomanip>    
#define ll long long
using namespace std;
class max_heap
{
    std::vector<ll> arr;
public:
    bool isEmpty();
    ll extract_max();
    ll heap_top();
    void insert_element(ll);
    ll size();
    ll get_parent(ll);
    ll get_left_child(ll);
    ll get_right_child(ll);
    void bubble_up(std::vector<ll>&,ll);
    void bubble_down(std::vector<ll>&,ll);
};
class min_heap
{
    std::vector<ll> arr;
public:
    bool isEmpty();
    ll extract_min();
    ll heap_top();
    void insert_element(ll);
    ll size();
    ll get_parent(ll);
    ll get_left_child(ll);
    ll get_right_child(ll);
    void bubble_up(std::vector<ll>&,ll);
    void bubble_down(std::vector<ll>&,ll);
};
bool max_heap::isEmpty()
{
    if(arr.size()==0)
        return true;
    return false;
}
ll max_heap::heap_top()
{
    return arr[0];
}
ll max_heap::get_parent(ll i)
{
    ll parent=(i-1)/2;
    return parent;
}
ll max_heap::get_left_child(ll i)
{
    return (2*i+1);
}
ll max_heap::get_right_child(ll i)
{
    return (2*i+2);
}
ll max_heap::size()
{
    return arr.size();
}
void max_heap::insert_element(ll x)
{
    arr.push_back(x);
    /* call heapify here for each insertion */
    bubble_up(arr,arr.size()-1);
}
void max_heap::bubble_down(vector<ll>& arr,ll i)
{
    ll left=get_left_child(i);
    ll right=get_right_child(i);
    ll largest=i;
    if(left<arr.size() && arr[left]>arr[i])
        largest=left;
    else 
        largest=i;
    if(right<arr.size() && arr[right]>arr[largest])
        largest=right;
    if(largest!=i)
    {
        std::swap(arr[i],arr[largest]);
        bubble_down(arr,largest);
    }
}
void max_heap::bubble_up(vector<ll>& arr,ll i)
{
    ll parent=get_parent(i);
    if(i>0 && arr[i]>arr[parent])
    {
        std::swap(arr[i],arr[parent]);
        bubble_up(arr,parent);
    }
}
ll max_heap::extract_max()
{
    ll maxx=arr[0];
    arr[0]=arr[arr.size()-1];
    arr.pop_back();
    bubble_down(arr,0);
    return maxx;
}
bool min_heap::isEmpty()
{
    if(arr.size()==0)
        return true;
    return false;
}
ll min_heap::heap_top()
{
    return arr[0];
}
ll min_heap::get_parent(ll i)
{
    return ((i-1)/2);
}
ll min_heap::get_left_child(ll i)
{
    return (2*i+1);
}
ll min_heap::get_right_child(ll i)
{
    return (2*i+2);
}
ll min_heap::size()
{
    return arr.size();
}
void min_heap::insert_element(ll x)
{
    arr.push_back(x);
    /* call heapify here for each insertion */
    bubble_up(arr,arr.size()-1);
}
void min_heap::bubble_down(vector<ll>& arr,ll i)
{
    ll left=get_left_child(i);
    ll right=get_right_child(i);
    ll smallest=i;
    if(left<arr.size() && arr[left]<arr[i])
        smallest=left;
    else 
        smallest=i;
    if(right<arr.size() && arr[smallest]>arr[right])
        smallest=right;
    if(smallest!=i)
    {
        std::swap(arr[i],arr[smallest]);
        bubble_down(arr,smallest);
    }
}
void min_heap::bubble_up(vector<ll>&,ll i)
{
    ll parent=get_parent(i);
    if(i>0 && arr[i]<arr[parent])
    {
        std::swap(arr[i],arr[parent]);
        bubble_up(arr,parent);
    }
}
ll min_heap::extract_min()
{
    ll minn=arr[0];
    arr[0]=arr[arr.size()-1];
    arr.pop_back();
    bubble_down(arr,0);
    return minn;
}
int main()
{
    ll n,x;
    min_heap min_h;
    max_heap max_h;
    cin>>n;
    double median=0;
    while(n--)
    {
        cin>>x;
        if (x<=median)
        {
           max_h.insert_element(x);
        } 
        else
        {
            min_h.insert_element(x);
        }

        if (min_h.size() > max_h.size()+1) 
        {
                max_h.insert_element(min_h.heap_top());
                min_h.extract_min();
        }
        if (max_h.size() > min_h.size()+1) {
                min_h.insert_element(max_h.heap_top());
                max_h.extract_max();
        }

        if (min_h.size() == max_h.size()) 
        {
            median=(max_h.heap_top() + min_h.heap_top())/2.0;
        } 
        else if(min_h.size() > max_h.size()) 
        {
                median=(double)min_h.heap_top();
        } 
        else if (min_h.size() < max_h.size()) 
        {
                median=(double)max_h.heap_top();
        }
        cout<<fixed<<setprecision(1)<<median<<endl;
    }
    return 0;
}