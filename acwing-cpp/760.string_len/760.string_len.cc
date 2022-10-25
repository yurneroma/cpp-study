#include <string.h>
#include <cstdio>

using namespace std;

int main() {
    // string s1; 
    // getline(cin, s1);
    // cout << s1.size() << endl;
    char s[101];
    // fgets 遇到回车和结束符会停下, 或者是读到最大长度,会插入字符串结束符.  fgets 会包含回车字符, 需要过滤下.
    fgets(s, 101, stdin);
    int len = 0; 
    for (int i = 0; s[i] && s[i] != '\n'; i++) len++;
    printf("%d", len); 
}