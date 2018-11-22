#include<bits/stdc++.h>
using namespace std;
char l=(char)0,h=(char)255;
int sa_size;
void counting_sort(string arr[],int index)
{
  //cout<<"in counting sort:"<<sa_size<<endl;
    int t_size=256;
    string temp[sa_size];
    int count[t_size]={0};      

    for(int i=0;i<sa_size;i++)
    {
      int char_index;
      if(arr[i].size()-1<index)
	  char_index=0;
      else
	  char_index=(arr[i][index]-l)+1;
      count[char_index]++;
    }
    
    for(int i=1;i<t_size;i++)
    {
      count[i]+=count[i-1];
    }
    for(int i=sa_size-1;i>=0;i--)
    {
      int char_index;
      if(arr[i].size()-1<index)
	char_index=0;
      else
	char_index=(arr[i][index]-l)+1;
      temp[count[char_index]-1]=arr[i];
      count[char_index]--;
    }

    for(int i=0;i<sa_size;i++)
       arr[i]=temp[i];   
}
void radix_sort(string arr[])
{
  //cout<<"in radix sort"<<endl;
    int ind_max=0;
    for(int i=0;i<sa_size;i++)
    {
      if(arr[i].size()-1>ind_max)
            ind_max=arr[i].size()-1;
    }
    for(int i=ind_max;i>=0;i--)
    {
      counting_sort(arr,i);
    }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
    string str;
    map<string,int> suffix_index;
    cin >>str;
    int len=str.size();
    sa_size=2*str.size();
    
    str+=str;
    string suffix_array[sa_size];
    for(int i=0;i<sa_size;i++)
    {
      //cout<<"in loop"<<endl;
        suffix_index[str.substr(i,str.size()-i)]=i;
	//cout<<s.substr(i,s.size()-i)<<" "<<i<<endl;
        suffix_array[i]=str.substr(i,str.size()-i);
	//cout<<suffix_array[i]<<" "<<i<<endl;
    }
    //sort(v.begin(),v.end());
        radix_sort(suffix_array);
	/*for(int i=0;i<sa_size;i++)
	{
	  cout<<suffix_array[i]<<endl;
	  }*/
      for(int i=0;i<sa_size;i++)
      {
	int ind=suffix_index[suffix_array[i]];
	if(ind>=0 && ind<len)
	{
	  cout<<suffix_array[i].substr(0,len)<<endl;
	  break;
	}
    }
    return 0;
}
