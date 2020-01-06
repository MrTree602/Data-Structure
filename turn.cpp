/*题目描述
暑假来了， 你们一家打算坐飞机去旅游， 现在你们位于 S 号城市， 目标是 G 号城市，可是 S 号城市并没不一定有直达 G 号城市的航班， 爸爸已经给你收集了很多航班的信息，现在希望聪明的你找到一种乘坐方式， 使得转机的次数最少（终点不计算在内）。 如果不可达， 请输出-1
输入
第一行四个整数 n， k， s， g， 其中 n 表示城市总数， k 表示航线总数； s 表示起点城市编号， g 表示目标城市编号。
接下来的 k 行， 每行是两个用空格分隔开的整数 a， b， 表示城市 a 和城市 b 之间有航线,也就是城市 a 和城市 b 之间可以相互到达。
输出
1 个整数， 表示最少转机的次数。*/

//attempt1
//广度优先遍历
/*#include<iostream>
#define N 102
#define MAX 999999
using namespace std;
typedef struct Node {
    int x;
    int s;
}node;
int main() {
    node que[N];
    int i, j, k, l;
    int n, m;
    int begin_city, end_city;
    int map[N][N];
    int head=1, tail=1;
    bool book[N] = { 0 };
    bool flag = 0;

    //读入数据
    cin >> n >> m >> begin_city >> end_city;

    //map初始化
    for (i = 1;i <= n;++i) {
        for (j = 1;j <= n;++j) {
            if (i == j)
                map[i][j] = 0;
            else map[i][j] = MAX;
        }
    }
    for (i = 0;i < m;++i) {
        cin >> k >> l;
        map[k][l] = 1;
        map[l][k] = 1;
    }

    //广度优先遍历
    que[tail].x = begin_city;
    que[tail].s = 0;
    tail++;
    book[begin_city] = 1;
    while (head < tail) {
        k = que[head].x;
        for (i = 1;i <= n;++i) {
            //入队
            if (map[head][i] != MAX&&book[i] == 0) {
                que[tail].x = i;
                que[tail].s = que[head].s + 1;
                tail++;
                book[i] = 1;
            }
            //截止条件
            if (que[tail-1].x == end_city) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
        head++;
    }
    cout << que[tail - 1].s << endl;
    return 0;
}*/

//attempt2
//深度优先搜索
#include <iostream>
using namespace std;
//全局变量自动初始化为0
int startPosition,endPosition,visited[10],matrix[25][25],n,k;//n,k分别代表城市的数量和航线的数量。
int min_dis = 999999;
void Dfs(int v,int distance);
int main()
{
    cin >> n >> k >> startPosition >> endPosition;
    for(int m = 1; m <= k; m++)
    {
        int i,j;
        cin >> i >> j;
        matrix[i][j] = 1;
    }
    Dfs(startPosition,0);
    cout << min_dis-1;
    return 0;
}
void Dfs(int v,int distance)
{
    if(v == endPosition)
    {
        if(min_dis > distance)
        {
            min_dis = distance;
        }
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(matrix[v][i] == 1&&visited[i] == 0)
        {
            visited[i] = 1;
            Dfs(i,distance + 1);
            visited[i] = 0;
        }
    }
}