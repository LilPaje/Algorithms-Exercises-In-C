#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int max);
void generateRandomList(int size, int list[], int max);
void sortList(int size, int list[]);

int main(){
    srand(time(0));
    int size = {100000};
    int max = {10};
    int listNumbers[size];

    generateRandomList(size, listNumbers, max);

    printf("Unsorted List:\n ");
    for(int i=0; i<size; i++){
        printf("->%d\n ", listNumbers[i]);
    }

    sortList(size, listNumbers);
    printf("Sorted List:\n ");
    for(int i=0; i<size; i++){
        printf("->%d\n ", listNumbers[i]);
    }

    return 0;
}

int generateRandomNumber(int max){
    return rand() % max + 1;
}

void generateRandomList(int size, int list[], int max){
    for(int i=0; i<size; i++){
        list[i] = generateRandomNumber(max);
    }
}

void sortList(int size, int list[]){
    for(int i = 1; i<size; i++){
        int key = list[i];
        int j = i-1;
        while(j >= 0 && list[j] > key){
            list[j+1] = list[j];
            j = j-1;
        }
        list[j+1] = key;
    }
}