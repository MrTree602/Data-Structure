/*
题目描述
牛群们开始了他们的第一场马拉松比赛。一共有N(1<=N<=5,000)条时间被以时(0<=Hours<=99)，分(0<=Minutes<=59)，秒(0<=Seconds<=59)的形式记录。贝茜必须要把他们按时，分，秒排序为升序，最少的时间最先。
考虑到如下的样例，这是牛群中用时最少的三头奶牛（题外话：牛跑26.2英里其实是很慢的）
11:20:20
11:15:12
14:20:14
正确的排序结果应该是这样的：
11:15:12
11:20:20
14:20:14

输入	
第1行，一个整数N
第2~n+1行，每行3个整数，表示时，分，秒

输出
共n行，每行3个整数，表示排序完后的结果

样例输入
3
11 20 20
11 15 12
14 20 14

样例输出
11 15 12
11 20 20
14 20 14

数据规模
对于 30% 的数据，有 1 ≤ n ≤ 50。
对于 100% 的数据，有 1 ≤ n≤ 5,000。
*/

/*attempt1
#include <iostream>
#define N 15000
#define M 5000
using namespace std;
int main() {
    int n, t;
    cin >> n;
    int a[N], b[M];
    for(int i=0; i < n*3; i++) {
        cin >> a[i];
    }
    
    int j=0;
    while(j<n*3) {
        b[j]=a[j]*3600+a[j+1]*60+a[j+2];
        j += 3;
    }
    
    for(int k=0; k < n-1; k++) {
        for(int m=0; m < n-1-k; m++) {
            if(b[m] > b[m+1]) {
                t = b[m];
                b[m] = b[m+1];
                b[m+1] = t;
            }
        }
    }
    
    int c[N], p;
    for(int i=0; i < n*3;) {
        for(int j=0; j < n; j++) {
            c[i] = b[j] / 3600;
            c[i+1] = (b[j]%3600)/60;
            c[i+2] = ((b[j]%3600)%60);
            i += 3;
        }
    }

    for(int b=0; b < n; b++) {
        cout << c[b] << " " << c[b+1] << " " << c[b+2]<< endl;
        b += 3;
    }

    return 0;
}*/

//attempt2
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
struct node
{
    int data;
    int data2;
    int data3;
    bool operator < (node nodeNew)
    {
        return data*10000+data2*100+data3<nodeNew.data*10000+nodeNew.data2*100+nodeNew.data3 ? 1:0;
    }
};
int main()
{
    unsigned int number;
    scanf("%d",&number);
    deque <node> myList;
    for(int i=0;i<number;i++)
    {
        node time;
        scanf("%d %d %d",&time.data,&time.data2,&time.data3);
        myList.push_back(time);
    }
    deque<node>::iterator i;
    sort(myList.begin(),myList.end());
    for(i=myList.begin();i!=myList.end();i++)
        cout<<(*i).data<<" "<<(*i).data2<<" "<<(*i).data3<<endl;
}