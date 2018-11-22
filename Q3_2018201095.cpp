#include<bits/stdc++.h>
#include <stdlib.h>    
#define ll long long
using namespace std;
int randomize_partition(int *arr,int p,int r)
{
  //cout<<"in randomize partition"<<endl;
  srand(time(NULL));
  int x=p+rand() % (r-p+1);
  int pivot=arr[x];
  std::swap(arr[x],arr[r]);
  x=r;
  int i=p-1;
  for(ll j=p; j<=r-1;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
	    std::swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[x]);
    return i+1;
}
int randomize_select(int *arr,int p,int r,int k)
{
  //cout<<"in randomize select"<<endl;
  if(p==r)
    return arr[p];
  if(k==0) return -1;
  if(p<r)
  {
    int q=randomize_partition(arr,p,r);
    int x=q-p+1;
    if(k==x)
      return arr[q];
    else if(k<x)
       return randomize_select(arr,p,q-1,k);
    else
      return randomize_select(arr,q+1,r,k-x);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t,n,k;
  ifstream in;
  in.open("input.txt");
  
  
  /*while(t--)
  {*/
   cin>>k;
    int arr[1000000];
     clock_t start,end;
   double cpu_time_used;
    for(int i=0;i<1000000;i++)
      		in>>arr[i];
    cout<<randomize_select(arr,0,999999,k)<<endl;
  //}
	 end=clock();
     cpu_time_used=((double) (end - start))/CLOCKS_PER_SEC;
	 cout<<"CPU time:"<<cpu_time_used<<endl;	
	return 0;
}
