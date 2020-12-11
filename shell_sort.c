#include <stdio.h>
#include <stdlib.h>

int power(int x,int y){
 if (y==1){
    return x;
 }
 else {
    return(x*power(x,y-1));
 }
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shell_sort(int *arr, int len, int c){
    int n = len;
    int inc, j;
    while (c != 0){
        if (c % 2 == 0){
            inc = power(9, c) - power(9, c/2);
        }
        else{
            inc = power(8, c) - power(6, (c+1)/2);
        }
        for (int i = inc; i<n; i++){
            int x = i;
            while (x>=inc && arr[x]<arr[x-inc]){
                swap(&arr[x], &arr[x-inc]);
                x -= inc;
            }
        }
        c--;
    }
    for (int j = 0; j<n; j++){
        int z = j;
        while(arr[z]<arr[z-1]&&z>0){
            swap(&arr[z], &arr[z-1]);
            z--;
        }
    }
}
    
    
int main(int argv, char **argc){
    FILE *fp = fopen(argc[1], "r");

    int len, counter = 0;
    
    fscanf(fp, "%d", &len);
    
    int *arr = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
        fscanf(fp, "%d", &arr[i]);

    int d = 0;
    while (3 * d < len){
        counter++;
        if (counter % 2 == 0){
            d = d + power(9, counter) - power(9, counter/2);
        }
        else{
            d = d + power(8, counter) - power(6, (counter+1)/2);
        }
    }
    shell_sort(arr, len, counter);

    fclose(fp);

    FILE *fout = fopen(argc[2], "w");
    for (int i = 0; i < len; i++)
        fprintf(fout, "%d ", arr[i]);
    fclose(fout);
    free(arr);
    return 0;
}