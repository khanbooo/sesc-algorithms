#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int *arr, int i, int n){
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;
    int max = i;

    if (leftchild < n && arr[leftchild] > arr[max])
        max = leftchild;

    if (rightchild < n && arr[rightchild] > arr[max])
        max = rightchild;

    if (max != i){
        swap(&arr[i], &arr[max]);
        heapify(arr, max, n);
    }

}

void heap_sort(int *arr, int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, i, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, 0, i);
    }
}


int main(int argv, char **argc){
    FILE *fp = fopen(argc[1], "r");

    int len;
    
    fscanf(fp, "%d", &len);
    
    int *arr = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
        fscanf(fp, "%d", &arr[i]);

    heap_sort(arr, len);

    fclose(fp);

    FILE *fout = fopen(argc[2], "w");
    for (int i = 0; i < len; i++)
        fprintf(fout, "%d ", arr[i]);
    fclose(fout);
    free(arr);
    return 0;
}
