#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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

void quick_sort(int *arr, int i, int j, int d, int n){
    if (d != 0){
        if (i < j){
            int left = i, right = j, bearing_element = arr[(i + j) / 2];
            while (left <= right){
                while (arr[left] < bearing_element) left++;
                while (arr[right] > bearing_element) right--;
                if (left <= right)
                {
                    swap(&arr[left], &arr[right]);
                    left++;
                    right--;
                }
            }
            quick_sort(arr, i, right, d - 1, n);
            quick_sort(arr, left, j, d - 1, n);
        }
    }
    else{
        heap_sort(arr, n);
    }
}


int main(int argv, char **argc){
    FILE *fp = fopen(argc[1], "r");

    int len, depth = 0;
    
    fscanf(fp, "%d", &len);
    
    int *arr = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
        fscanf(fp, "%d", &arr[i]);

    int left = 0, right = len-1;
    int max_rec = 2*log(len)/1;
    quick_sort(arr, left, right, max_rec, len);

    fclose(fp);

    FILE *fout = fopen(argc[2], "w");
    for (int i = 0; i < len; i++)
        fprintf(fout, "%d ", arr[i]);
    fclose(fout);
    free(arr);
    return 0;
}