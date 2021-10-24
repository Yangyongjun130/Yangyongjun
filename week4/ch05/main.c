#include <stdio.h>
#include <stdlib.h>
//输入任意大小的数组
void display(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int getStandard(int array[], int i, int j) {
    // 基准数据
    int key = array[i];
    while (i < j) {       
        while (i < j && array[j] >= key) {
            j--;
        }       
        if (i < j) {
            array[i] = array[j];
        }    
        while (i < j && array[i] <= key) {
            i++;
        }   
        if (i < j) {
            array[j] = array[i];
        }
    }
    array[i] = key;
    return i;
}

void QuickSort(int array[], int low, int high) { 
    if (low < high) {       
        int standard = getStandard(array, low, high);    
        QuickSort(array, low, standard - 1);
        QuickSort(array, standard + 1, high);
    }
}
int main() {
    int array[] = { 49, 38, 65, 97, 76, 13, 27, 49, 10 };
    int size = sizeof(array);
    // 打印数据
    printf("%d \n", size);
    QuickSort(array, 0, size - 1);
    display(array, size);
    return 0;
}
