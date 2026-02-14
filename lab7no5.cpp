#include <stdio.h>

long convert(long h, long m, long s);

int main() {
    long hours, minutes, seconds;
    long total_seconds;
    
    scanf("%ld %ld %ld", &hours, &minutes, &seconds);
    
    total_seconds = convert(hours, minutes, seconds);
    
    printf("%ld\n", total_seconds);
    
    return 0;
}

long convert(long h, long m, long s) {
    return (h * 3600) + (m * 60) + s;
}

