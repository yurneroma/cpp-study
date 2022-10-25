#include <cstdio>
using namespace std;


int main() {
    int dis; 
    double gas;
    scanf("%d%lf", &dis, &gas);
    printf("%.3f km/l", dis/gas); 
}