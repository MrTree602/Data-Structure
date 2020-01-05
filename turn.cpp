/*题目描述
暑假来了， 你们一家打算坐飞机去旅游， 现在你们位于 S 号城市， 目标是 G 号城市，可是 S 号城市并没不一定有直达 G 号城市的航班， 爸爸已经给你收集了很多航班的信息，现在希望聪明的你找到一种乘坐方式， 使得转机的次数最少（终点不计算在内）。 如果不可达， 请输出-1
输入
第一行四个整数 n， k， s， g， 其中 n 表示城市总数， k 表示航线总数； s 表示起点城市编号， g 表示目标城市编号。
接下来的 k 行， 每行是两个用空格分隔开的整数 a， b， 表示城市 a 和城市 b 之间有航线,也就是城市 a 和城市 b 之间可以相互到达。
输出
1 个整数， 表示最少转机的次数。*/

//attempt1
//广度优先遍历
/*#include <iostream>
using namespace std;
struct node
{
    int x; //表示城市的编号
    int s; //表示运动的距离
};
//全局变量自动初始化为0
int startPosition,endPosition,visited[10],matrix[25][25],m,n;//m,n分别代表城市的数量和航线的数量。
struct node myQueue[20];
int main()
{
    int head = 1,tail = 1;
    cin >> m >> n >> startPosition >> endPosition;
    for(int k = 1;k <= n;k++)
    {
        int i,j;
        cin >> i >> j;
        matrix[i][j] = 1;
    }
    myQueue[tail].x = startPosition;
    myQueue[tail].s = 0;
    visited[tail++] = 1;
    while(head != tail)
    {
        int v = myQueue[head].x;
        if(v == endPosition)
        {
            break;
        }
        for(int i = 1;i <= n;i++)
        {
            if(matrix[v][i] == 1 && visited[i] == 0)
            {
                myQueue[tail].x = i;
                myQueue[tail].s = myQueue[head].s + 1;
                visited[tail++] = 1;
            }
        }
        head++;
    }
    for(int i = 1;i < tail - 1;i++)
    {
        cout << myQueue[i].x << " " << myQueue[i].s << endl;
    }
    return 0;
}*/

//attempt2
//深度优先搜索
#include <iostream>
using namespace std;
//全局变量自动初始化为0
int startPosition,endPosition,visited[10],matrix[25][25],m,n;//m,n分别代表城市的数量和航线的数量。
int min_dis = 999999;
void Dfs(int v,int distance);
int main()
{
    cin >> m >> n >> startPosition >> endPosition;
    for(int k = 1;k <= n;k++)
    {
        int i,j;
        cin >> i >> j;
        matrix[i][j] = 1;
    }
    Dfs(startPosition,0);
    cout << min_dis;
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
    for(int i = 1;i <= m;i++)
    {
        if(matrix[v][i] == 1&&visited[i] == 0)
        {
            visited[i] = 1;
            Dfs(i,distance + 1);
            visited[i] = 0;
        }
    }
}