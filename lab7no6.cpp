#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 20

int main() {
    int M, N;
    
    printf("Enter M (rows) and N (columns): ");
    scanf("%d %d", &M, &N);
    
    if (M < 2 || M > max || N < 2 || N > max) {
        printf("M and N must be between 2 and %d\n", max);
        return 1;
    }
    
    if (M * N < 100 || M * N > 200) {
        printf("Total elements (M*N) must be between 100 and 200\n");
        return 1;
    }
    
    int arr[max][max];
    int used[201] = {0};
    
    srand(time(NULL));
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            do {
                num = (rand() % 101) + 100;
            } while (used[num - 100] == 1);
            
            arr[i][j] = num;
            used[num - 100] = 1;
        }
    }
    
    printf("\nGenerated %dx%d array:\n", M, N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
