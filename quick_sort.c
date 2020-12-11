#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int *arr, int i, int j)
{
    if (i < j)
    {
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
        quick_sort(arr, i, right);
        quick_sort(arr, left, j);
    }
}

int main(int argv, char **argc){
    FILE *fp = fopen(argc[1], "r");

    int len;
    
    fscanf(fp, "%d", &len);
    
    int *arr = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
        fscanf(fp, "%d", &arr[i]);

    int left = 0, right = len-1;
    quick_sort(arr, left, right);

    fclose(fp);

    FILE *fout = fopen(argc[2], "w");
    for (int i = 0; i < len; i++)
        fprintf(fout, "%d ", arr[i]);
    fclose(fout);
    free(arr);
    return 0;
}