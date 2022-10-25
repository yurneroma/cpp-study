#include <cstdio>
using namespace std;  

int main() {
    int num, hour;
    double hour_pay;

    scanf("%d%d%lf", &num, &hour, &hour_pay);
    printf("NUMBER = %d\n", num); 
    printf("SALARY = U$ %.2lf\n", hour* hour_pay); 

    return 0;
}