#include <iostream>
#include<limits.h>
#define ull unsigned long
#define BIG_PRIME 100003
#define DEF_SIZE 10000
using namespace std;
template <class T1,class T2>
class node
{
public:
  T1 key;
  T2 val;
  node *next;
  node(T1,T2);
};
template <typename T1,typename T2>
class unordered_map
{
 node<T1,T2> **hash_table;
public:
  int a,b;
  unordered_map();
  void insert(T1,T2);
  T2 find(T1);
  void del(T1);
  ull get_hash(T1);
};

template<typename T1,typename T2>
node<T1,T2>::node(T1 k,T2 v)
{
  key=k;
  val=v;
  next=NULL;
}
template<typename T1,typename T2> unordered_map<T1,T2>::unordered_map()
{
  b=(rand()%BIG_PRIME);
  b=(rand()%(BIG_PRIME-1))+1;
  hash_table=new node<T1,T2> *[DEF_SIZE]();
}
template<typename T1,typename T2>
void unordered_map<T1,T2>::insert(T1 k,T2 v)
{
  ull hash=get_hash(k);
  node<T1,T2> *cur,*prev;
  cur=hash_table[hash];
  prev=NULL;
  while(cur!=NULL && cur->key!=k)
  {
     prev=cur;
     cur=cur->next;
  }
  if(cur==NULL) // reached last node in empty and non-empty linked list (key not found)
  {
    cur=new node<T1,T2>(k,v);
    if(prev==NULL)
       hash_table[hash]=cur;
    else 
       prev->next=cur;
  }
  else //existing key found
  {
    cur->val=v;
  }
}
template<typename T1,typename T2>
void unordered_map<T1,T2>::del(T1 k)
{
  cout<<"in delete fun:"<<endl;
  ull hash=get_hash(k);
  node<T1,T2> *cur,*prev;
  cur=hash_table[hash];
  prev=NULL;
  while(cur!=NULL && k!=cur->key)
  {
    prev=cur;
    cur=cur->next;
  }
  if(cur!=NULL)
  {
    if(prev==NULL)
    {
      hash_table[hash]=cur->next;
    }
    else
    {
      prev->next=cur->next;
    }
    delete cur;
    cout<<"deleted.."<<endl;
  }
  else
  {
    cout<<"Not found"<<endl;
  }
}
template<typename T1,typename T2>
T2 unordered_map<T1,T2>::find(T1 k)
{
  T2 v{};
    ull hash=get_hash(k);
    node<T1,T2> *cur;
    cur=hash_table[hash];
    while(cur!=NULL)
    {
       if(cur->key==k)
       {
           v=cur->val;
           return v;
       }
       cur=cur->next;
    }
    if(cur==NULL)
      cout<<"end is reached"<<endl;
return v;
}
template<typename T1,typename T2>
ull unordered_map<T1,T2>::get_hash(T1 k)
{
  ull hash;
  cout<<"received:"<<k<<endl;
  ull *temp=reinterpret_cast<ull*>(&k);
  hash=(((*temp)*a+b)%BIG_PRIME)%DEF_SIZE;
  cout<<"hash:"<<hash<<endl;
  return hash;
}
int main()
{ 
  unordered_map<int,string> m;
  unordered_map<string,int> m1;  
  m.insert(1,"ajay");
  m.insert(2,"pappa");
  m.insert(3,"mummy");
  m.insert(4,"dada");
  string t;
  t=m.find(4);
  if(t!="")
    cout<<t<<endl;
  else
    cout<<"not found"<<endl;
  m.del(4);
  t=m.find(4);
  if(t!="")
    cout<<t<<endl;
  else
    cout<<"not found"<<endl;

  m1.insert("ajayajayajayajayajayajay",1);
  m1.insert("pappadkjcbskbdcbskbcksdbckjbsdkjcbkjdsbcksbkcbksdjcbksb",2);
  m1.insert("mu",3);
  m1.insert("dascbdskjcbsckbsbcksbckjsbcdkjsbcdkjbcsckbsdkcbksjbcksbdcsbckjbscbksbdkcjsb",4);
  int f{};
  cout<<f<<endl;
  f=m1.find("pappa");
  if(f!=NULL)
    cout<<f<<endl;
  else
    cout<<"not found"<<endl;
  m1.del("pappa");
  f=m1.find("pappa");
  if(f!=NULL)
    cout<<f<<endl;
  else
    cout<<"not found"<<endl;
  return 0; 
} 


