/*题目描述
Dave最近学习了字符串的字典序， 他现在在思考这样一个问题， 对于一个由小写字母组成的字符串s， 最多可以去掉其中一个字符， 如何使得得到的字符串的字典序最小。
字典序， 顾名思义就是字典中的顺序， 比较的方法是从前往后依次比较， 直到第一个不同的字符来确定字典序， 如果没有则长度较短的字典序小。
例如对于字符串s1 = "abc", s2="abdc"， 先比较第一个字符， 相同， 继续比较第二个字符， 也相同，而第三个字符'c'<'d', 所以字典序s1<s2。
而对于s1 = "abc", s2="abcd", s1<s2
输入	
一个字符串s
输出
一个字符串t, 为s中最多去掉一个字符后得到的字典序最小字符串*/

//attempt1
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    string a;
    char b;
    int i;
    bool c = 0;
    cin >> a;
    for(i = 0;i < a.length();i++)
    {
        b=a[i+1];
        if(c == 0 && (b < a[i]||i == a.length()))
        {
            c = 1;
            continue;
        }
        else
        {
            cout << a[i];
        }
    }
}

