#include <stdio.h>
#include <stdlib.h>

void combinations(int arr[], int data[], int start, int end, int index, int r) {
    if (index == r) {
        for (int i = 0; i < r; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        combinations(arr, data, i + 1, end, index + 1, r);
    }
}

void printCombinations(int arr[], int n, int r) {
    int *data = (int *)malloc(r * sizeof(int));
    combinations(arr, data, 0, n - 1, 0, r);
    free(data);
}

int main() {
    int n, k;

    printf("Digite n e k nessa ordem \n");
    scanf("%d %d", &n, &k);

    int *vetor = malloc(n * sizeof(int));
    printf("Digite cada digito \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &vetor[i]);

    printCombinations(vetor, n, k);

    free(vetor);
    
    return 0;
}