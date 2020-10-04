#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int* arr = new int[n];
	    for(int i = 0; i < n; i++)
	    cin >> arr[i];
	    int m;
	    cin >> m;
	    int cnt = 0,nextIndex = 0;
	    map<int,int> m1,m2;
	    for(int i = 0; i < n; i++)
	    {
	        if(cnt < m)
	        {
	            if(m1.find(arr[i]) == m1.end())
	            {
	                m1[arr[i]] = nextIndex;
	                nextIndex++;
	                cnt++;
	            }
	            else
	            {
	                m1.erase(arr[i]);
	                m1[arr[i]] = nextIndex;
	                nextIndex++;
	            }
	        }
	        else
	        {
	            if(m1.find(arr[i]) == m1.end())
	            {
	                int min = INT_MAX,min_ele;
	                for(auto i : m1)
	                {
	                    if(i.second < min)
	                   {
	                       min = i.second;
	                       min_ele = i.first;
	                   }
	                }
	                m1.erase(min_ele);
	                m1[arr[i]] = nextIndex;
	                nextIndex++;
	                cnt++;
	            }
	            else
	            {
	                m1.erase(arr[i]);
	                m1[arr[i]] = nextIndex;
	                nextIndex++;
	            }
	        }
	    }
	    cout << cnt << endl;
	}
	return 0;
}
