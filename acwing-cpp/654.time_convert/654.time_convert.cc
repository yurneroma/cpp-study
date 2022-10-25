#include <cstdio>
using namespace std;

int main() {
    int n, arr[3] = {3600, 60, 1};
    scanf("%d", &n);
    for (int i = 0; i < 3; i++) {
        printf("%d",n/arr[i]); 
        if (i != 2 ) {
            printf(":");
        }
        n %= arr[i];
    }
    return 0;
}