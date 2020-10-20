#include<bits/stdc++.h>
using namespace std;

struct  node
{
	char ch;
	int freq;
	node *left,*right;
};
class Heap
{
	node *arr[100];
	int n;
	public:
	Heap(node *a[],int no)
	{
		n = no;
		for(int i=1;i<=n;i++)
		{
			arr[i] = a[i];			
		}
	}
	void minHeapify(int i)
	{
		int left = 2*i;
		int right = 2*i+1;
		int smallest = i;
		if(left<=n && arr[smallest]->freq>arr[left]->freq)
		    smallest = left;
		if(right<=n && arr[smallest]->freq>arr[right]->freq)
		    smallest = right;
		if(smallest!=i)
		{
			//swap(arr[smallest],arr[i]);
			node* temp = arr[smallest];
			arr[smallest] = arr[i];
			arr[i] = temp;
			minHeapify(smallest);
		}
	}
	void buildMinHeap()
	{
		int i;
		for(i=n/2;i>0;i--)
		   minHeapify(i);
	}
	void insert(node *ab)
	{
		n = n+1;
		arr[n] = ab;
		int x = n;
		int parent = x/2;
		while(parent>=1 && arr[parent]->freq>arr[x]->freq)
		{
		//	swap(arr[parent],arr[x]);
			node* temp = arr[parent];
			arr[parent] = arr[x];
			arr[x] = temp;
			x = parent;
			parent = x/2;
		}
	}
	node* extractMin()
	{
		node *store;
		store = arr[1];
		arr[1] = arr[n];
		n--;
		minHeapify(1);
		return store;
	}
	node* huffman()
	{
		int size = n;
		for(int i=1;i<size;i++)
		{
			node *x = extractMin();
			node *y = extractMin();
			node *z = (node *)malloc(sizeof(node));
			z->ch = '$';
			z->freq = x->freq+y->freq;
			z->left = x;
			z->right = y;
			insert(z);
		}
		node *result = extractMin();
		return result;
	}
};

void print(node* root,int ans[],int n)
{
	if(root->left==NULL && root->right==NULL)
	{
		cout<<root->ch<<": ";
		for(int i=0;i<n;i++)
		      cout<<ans[i];
	    cout <<endl;
	}
	if(root->left!=NULL)
	{
		ans[n] = 0;
		print(root->left,ans,n+1);
	}
	if(root->right!=NULL)
	{
		ans[n] = 1;
		print(root->right,ans,n+1);
	}
}

int main()
{
    int i,n;
    cout<<"enter the no of distinct chars (n)";
    cin>>n;
    node *arr[n+1];
    cout<<"enter the characters and their frequencies"<<"\n";
    for(i=1;i<=n;i++)
    {
     	arr[i] = (node*)malloc(sizeof(node));
     	cin>>(arr[i]->ch)>>(arr[i]->freq);
     	arr[i]->left = NULL;
     	arr[i]->right = NULL;
	}   
    Heap h(arr,n);
    h.buildMinHeap();
    node *result = h.huffman();
    int ans[100];
    print(result,ans,0);
	return 0;
}

