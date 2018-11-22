#include<bits/stdc++.h>
#define DEFAULT_SIZE 100
using namespace std;
class node
{
public:
  char *str;
  node *next;
};
class StringBuilder
{
  node *head,*tail;
  int str_len;
public:
  StringBuilder();
  void append(string);
  string getString();
  int getSize();
  int getCapacity();
  void showString();
  //bool resize_check(string);
  //void resize(string);
};
StringBuilder::StringBuilder()
{
  str_len=0;
  head=NULL;
  tail=NULL;
}
void StringBuilder::append(string str1)
{
  /* while(resize_check(str1))
  {
    resize(str1);
  }
  const char *temp=(const char *)str1.c_str();
  strcat(str,temp);
  str_len+=str1.size();
  size=size-(str1.size());
  cout<<"size after string append:"<<size<<endl;*/

   node* n=new node();
   n->str=(char *)malloc(str1.size()*sizeof(char));
   strcpy(n->str,str1.c_str());
    if(head==NULL)
    {
      cout<<"head empty:"<<endl;
      n->next=NULL;
      head=n;
      tail=n;
      this->str_len+=(str1.size());
    }
    else
    {
      cout<<"head not empty"<<endl;
      tail->next=n;
      tail=n;
      n->next=NULL;
      this->str_len+=(str1.size());
    }
}
/*void StringBuilder::resize(string str1)
{
  cout<<"new size:"<<size<<endl;
  char *new_str=(char *)realloc(str,(2*size)*sizeof(char));
  strcpy(new_str,str);
  str=new_str;  
  }*/
 /*void StringBuilder::showString()
{
  cout<<head->str<<endl;
  }*/
string StringBuilder::getString()
{
  node *tmp=head;
  string output="";
  while(tmp!=NULL)
  {
    string x(tmp->str);
    //cout<<tmp->str<<endl;
    output+=(x);
    tmp=tmp->next;
  }
  return output;
}
/*bool StringBuilder::resize_check(string str1)
{
  if(str1.size()>size)
    return true;
  return false;
  }*/
int StringBuilder::getSize()
{
  return str_len;
}
/*int StringBuilder::getCapacity()
{
  return size;
}*/
StringBuilder stringInitialize(string str1)
{
  StringBuilder temp;
  temp.append(str1);
  cout<<"initialize done"<<endl;
  return temp;
} 
StringBuilder stringAppend(StringBuilder sb1,StringBuilder sb2)
{
  StringBuilder temp=sb1;
  cout<<"first string:"<<temp.getString()<<":len1:"<<temp.getSize()<<endl;
  cout<<"second string:"<<sb2.getString()<<":len2:"<<sb2.getSize()<<endl;
  temp.append(sb2.getString());
  return temp;
}
void prefix_array(string sub, int m, int* last_prefix) 
{  
    int len=0; 
    last_prefix[0] = 0;  
    int i = 1; 
    while (i<m) 
    { 
        if (sub[i]==sub[len]) { 
            len++; 
            sub[i]=len; 
            i++; 
        } 
        else 
        { 
            if (len != 0)
	        len=last_prefix[len - 1];  
            else
            { 
                last_prefix[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

int findSubstring(StringBuilder sb,string sub) 
{
  int index=-1,i=0,j=0;
    int m=sub.size();
    string txt=sb.getString();
    int n=txt.size();
    int last_prefix[m];  
    prefix_array(sub,m,last_prefix); 
    
    while(i<n)
    { 
        if(sub[j]==txt[i])
	{ 
            j++; 
            i++; 
	} 
        if(j==m)
	{
	    index=i-j;
	    cout<<index<<endl;
            j=last_prefix[j-1]; 
        }  
        else if(i<n && sub[j]!=txt[i])
	{  
	    if(j!=0) 
	        j=last_prefix[j-1]; 
	    else
	        i++; 
                 
	}
    }
    if(index!=-1)
      index++;
    return index;
}

int main()
{
  string test="test";
   cout<<"string to initialize:"<<test.size()<<endl;
  StringBuilder sb1=stringInitialize(test);
  for(int i=0;i<10;i++)
  {
    sb1.append(test);
  }

  cout<<sb1.getString()<<":size is:"<<sb1.getSize()<<endl;
  StringBuilder sb2=stringInitialize("worldhhhh");
  cout<<sb2.getString()<<endl;
  StringBuilder sb3=stringAppend(sb1,sb2);
  cout<<sb3.getString()<<endl;;
  cout<<"appended string length:"<<sb3.getSize()<<endl;
  // cout<<"remaining capacity:"<<sb3.getCapacity()<<endl;
  cout<<"Index of substring:"<<findSubstring(sb1,"te")<<endl;
  cout<<"Index of substring:"<<findSubstring(sb1,"wor")<<endl;
  return 0;
}
