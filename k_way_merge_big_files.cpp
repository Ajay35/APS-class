#include<bits/stdc++.h>
#include<fstream>
/*   
	100MB txt file : ~18 seconds (using STL priority_queue)
	2GB txt file: ~ CPU time:450.738 seconds (using STL priority_queue)
	100MB txt file : ~13 seconds  (min-heap using vectors)
	2GB	txt file CPU time: 293.168 seconds (min-heap using vectors)
*/
#define ll long long
using namespace std;
struct node
{
public:
	int file_no;
	ll val;
		node(int _file_no,ll _val)
		{
			file_no=_file_no;
			val=_val;
		}	
};
class min_heap
{
    std::vector<node> arr;
public:
    bool isEmpty();
    void pop();
    node heap_top();
    void insert_element(node);
    int size();
    int get_parent(int);
    int get_left_child(int);
    int get_right_child(int);
    void bubble_up(std::vector<node>&,int);
    void bubble_down(std::vector<node>&,int);
};
bool min_heap::isEmpty()
{
    if(arr.size()==0)
        return true;
    return false;
}
node min_heap::heap_top()
{
    return arr[0];
}
int min_heap::get_parent(int i)
{
    return ((i-1)/2);
}
int min_heap::get_left_child(int i)
{
    return (2*i+1);
}
int min_heap::get_right_child(int i)
{
    return (2*i+2);
}
int min_heap::size()
{
    return arr.size();
}
void min_heap::insert_element(node x)
{
    arr.push_back(x);
    /* call heapify here for each insertion */
    bubble_up(arr,arr.size()-1);
}
void min_heap::bubble_down(vector<node>& arr,int i)
{
    int left=get_left_child(i);
    int right=get_right_child(i);
    int smallest=i;
    if(left<arr.size() && arr[left].val<arr[i].val)
        smallest=left;
    else 
        smallest=i;
    if(right<arr.size() && arr[smallest].val>arr[right].val)
        smallest=right;
    if(smallest!=i)
    {
        std::swap(arr[i],arr[smallest]);
        bubble_down(arr,smallest);
    }
}
void min_heap::bubble_up(vector<node>&,int i)
{
    int parent=get_parent(i);
    if(i>0 && arr[i].val<arr[parent].val)
    {
        std::swap(arr[i],arr[parent]);
        bubble_up(arr,parent);
    }
}
void min_heap::pop()
{
    node minn=arr[0];
    arr[0]=arr[arr.size()-1];
    arr.pop_back();
    bubble_down(arr,0);
}





 /*class compare  
 {  
public:
   bool operator()(const node &l, const node &r)  
   {  
	   return l.val>r.val;
   }  
 };*/  
int main(int argc,char** argv)
{
   if(argc!=3)
   {
		cout<<"enter input output file names"<<endl;
		exit(0);
   }
   clock_t start,end;
   double cpu_time_used;
   int chunk_size=1000000,k=0;
   std::vector<ll> buf;
   ll x;
   start=clock();
   ifstream in(argv[1],std::ios_base::in);
   ofstream output;
   //cout<<"no of files:"<<k<<endl;
   /*for(int i=0;i<k;i++)
   {
   		char file_name[256]; 
		snprintf(file_name,sizeof(file_name),"%d.txt",i);
		outout_files[i].open(file_name,std::ios_base::out);
		input_files[i].open(file_name,std::ios_base::in);
   }*/
   //int out_put_file_no=0;
   ll cnt=0;

   while(in>>x)
   {
	  // cout<<"in while:"<<x<<endl;
	   cnt++;
	   buf.push_back(x);
	   if(cnt==chunk_size)
	   {
		   
		   //cout<<buf.size()<<endl;
		   sort(buf.begin(),buf.end());
		   char file_name[256]; 
		   snprintf(file_name,sizeof(file_name),"%d.txt",k);
		   output.open(file_name,std::ios_base::out);
		   for(int i=0;i<buf.size();i++)
		   {
			   output<<buf[i]<<"\n";
		   }
		   output.close();
		   k++;
		   cnt=0;
		   buf.clear();
	   }
   }
   // cout<<buf.size()<<endl;
	//cout<<"iterations"<<k<<endl;
	if(!buf.empty())
	{
		//cout<<"buf not empty:"<<k<<endl;
		//cout<<"buf is not empty with size being:"<<buf.size()<<endl;
		char file_name[256]; 
		snprintf(file_name,sizeof(file_name),"%d.txt",k);
		output.open(file_name,std::ios_base::out);
		for(int i=0;i<buf.size();i++)
		{
			cout<<buf[i]<<endl;
			output<<buf[i]<<"\n";
		}
		//cout<<"nos written:"<<p<<endl;
		output.close();
		k++;
	}
   	cout<<"file read complete"<<endl;
	//cout<<"file count:"<<k<<endl;

	cout<<"making output file as output.txt"<<endl;
	ofstream final_output;
	final_output.open(argv[2],std::ios_base::out);

	ifstream input_files[k];
	for(int i=0;i<k;i++)
   	{
   		char file_name[256]; 
		snprintf(file_name,sizeof(file_name),"%d.txt",i);
		input_files[i].open(file_name,std::ios_base::in);
  	}
	//priority_queue<node,vector<node>,compare> heap;
	min_heap heap;
	// make priority queue of first elements of k files
	for(int i=0;i<k;i++)
	{
		ll val;
		input_files[i]>>val;
		//cout<<"value:"<<val<<endl;
		//cout<<"file no:"<<i<<endl;
		heap.insert_element(node(i,val));
		//cout<<"heap top is:"<<heap.top().val<<endl;
	}
	cout<<"pushing first element of all files :done:"<<endl;

	int count=0;
	ll tmp;
    while(count!=k)
    {
		//cout<<"heap size is:"<<heap.size()<<endl;
   		node n=heap.heap_top();
		  // cout<<"heap top is:"<<n.val<<endl;
		  // cout<<"file number of heap top element is:"<<n.file_no<<endl;
		   //cout<<"write output value:"<<n.val<<endl;
       final_output<<n.val<<"\n";
	   
       if(input_files[n.file_no]>>tmp)
        {
			//cout<<"in if"<<endl;
            n.val=tmp;
        }
		else
		{
			//cout<<"finished element in one file"<<endl;
			n.val=INT_MAX;
			count++;
		}
		heap.pop();
		heap.insert_element(n);
		//getchar();
    }
 
    for(int i=0;i<k;i++)
	{
		input_files[i].close();
		char file_name[256]; 
		snprintf(file_name,sizeof(file_name),"%d.txt",i);
		std::remove(file_name);
	}
	final_output.close();
	end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"CPU time:"<<cpu_time_used<<endl;
	return 0;
}

