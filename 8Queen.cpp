#include<bits/stdc++.h>
using namespace std;
#define MAX 50
int coun = 0;

bool canPlace(int q,int c,int ans[])
{
	for(int i=1;i<q;i++)
	{
		int j=ans[i];
		if(j==c || abs(j-c)==abs(i-q))
		   return false;
	}
	return true;
}
void eightQueenProblem(int q,int c,int ans[])
{
//	for(int i=q;i<=8;i++)
//	   ans[i] = 0;
	if(q>8)
	{
		for(int i=1;i<q;i++)
		   cout<<ans[i];
		cout<<"\n";
		coun++;
		return;
	}
	if(c>8)
	{
	   return;		
	}
	if(canPlace(q,c,ans))
	{
		ans[q]=c;
		eightQueenProblem(q+1,1,ans);
	}
    eightQueenProblem(q,c+1,ans);
}

int main()
{
	int ans[100];
	for(int i=1;i<=100;i++)
	   ans[i] = 0;
	eightQueenProblem(1,1,ans);
	cout << "count = " << coun;
	return 0;
}
