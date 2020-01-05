/*题目描述
小H和小W来到了一条街上，两人分开买菜，他们买菜的过程可以描述为，去店里买一些菜然后去旁边的一个广场把菜装上车，两人都要买n种菜，所以也都要装n次车。具体的，对于小H来说有n个不相交的时间段[a1,b1],[a2,b2]…[an,bn]在装车，对于小W来说有n个不相交的时间段[c1,d1],[c2,d2]…[cn,dn]在装车。其中，一个时间段[s, t]表示的是从时刻s到时刻t这段时间，时长为t-s。
由于他们是好朋友，他们都在广场上装车的时候会聊天，他们想知道他们可以聊多长时间。
输入	
输入的第一行包含一个正整数n，表示时间段的数量。接下来n行每行两个数ai，bi，描述小H的各个装车的时间段。接下来n行每行两个数ci，di，描述小W的各个装车的时间段。
输出
输出一行，一个正整数，表示两人可以聊多长时间。*/

//attempt1
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> a1,a2,b1,b2;
	int x,y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		a1.push_back(x);
		a2.push_back(y);
	}

	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		b1.push_back(x);
		b2.push_back(y);
	}

	int res=0;
	for(int i=0;i<n;i++)
	{
		if(a2[i] > b1[i] && a1[i] <= b1[i])
		{
			if(b2[i]>=a2[i])
				res += (a2[i]-b1[i]);
			else
				res += (b2[i]-b1[i]);
		}
	}
	cout<<res<<endl;

	return 0;
}