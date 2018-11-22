#include<bits/stdc++.h>
using namespace std;
char l=(char)0,h=(char)255;
int sa_size;
vector<int> kasai(string txt, vector<int> suffix_arr,int x) 
{ 
    int n = suffix_arr.size();
     
    vector<int> lcp(n,0); 
    vector<int> inv_suff(n,0);  
    for (int i=0; i < n; i++) 
        inv_suff[suffix_arr[i]] = i; 
    int k=0; 
    for (int i=0;i<n;i++) 
    { 
        if(inv_suff[i]==n-1) 
        {
            k=0; 
            continue; 
        }
        int j=suffix_arr[inv_suff[i]+1]; 
  
        while(i+k<n && j+k<n && txt[i+k]==txt[j+k])
	{
            k++;
	}
	
        lcp[inv_suff[i]] = k; 
  
        // Deleting the starting character from the string. 
        if (k>0) 
            k--; 
    } 
    cout<<"......"<<endl;
    // return the constructed lcp array 
    return lcp; 
}
vector<int> kasai(string s, vector<int> sa)
{
    int n=s.size(),k=0;
    vector<int> lcp(n,0);
    vector<int> rank(n,0);

    for(int i=0; i<n; i++)
         rank[sa[i]]=i;

    for(int i=0;i<n;i++, k?k--:0)
    {
        if(rank[i]==n-1)
	  {
	    k=0;
	    continue;
	  }
        int j=sa[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k])
	{
	  k++;
	}
        lcp[rank[i]]=k;
    }
    return lcp;
}

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
    {
       arr[i]=temp[i];
    }
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
  string rev_str;
  int k;
    map<string,int> suffix_index;
   
    getline(cin,str);
    string temp=str;
    int len=str.size();
    
    reverse(temp.begin(),temp.end());
    str=str+'#'+temp;
   
    sa_size=str.size();
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
    vector<int> suffix_arr;
 
        radix_sort(suffix_array);

	for(int i=0;i<sa_size;i++)
	{
	  suffix_arr.push_back(suffix_index[suffix_array[i]]);
	}
	/*for(int i=0;i<sa_size;i++)
      {
	cout<<suffix_array[i]<<" "<<suffix_arr[i]<<endl; 
      }*/
      
      vector<int> lcp=kasai(str,suffix_arr);
      
      
     int tmp=lcp[lcp.size()-1];
   
      for(int i=lcp.size()-1;i>=1;i--)
      {
	lcp[i]=lcp[i-1];
      }
      lcp[0]=tmp;
      for(int i=0;i<lcp.size();i++)
      {
	cout<<suffix_array[i]<<":"<<lcp[i]<<endl;
      }
      int palin_len=0,pos=0;
      for(int i=1;i<sa_size;++i)
      {
        if((lcp[i]>palin_len))
        {
            if((suffix_arr[i-1]<len && suffix_arr[i]>len)||(suffix_arr[i]<len && suffix_arr[i-1]>len))
            {
                palin_len=lcp[i];
                pos=suffix_arr[i];
            }
        }
    }
      cout<<"length of longest palindromic substring:"<<palin_len<<endl;
      cout<<str.substr(pos,palin_len)<<endl;
      return 0;
}
