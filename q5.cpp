//
//  main.cpp
//  q5
//
//  Created by Shiny on 17/02/2017.
//  Copyright © 2017 Brendon. All rights reserved.
//
// 1 2 3 4 5
// 1 4 2 5 3

#include <stdio.h>

void shuffle(int *deck[]);
void print(int *deck[]);

int main()
{
    int card[10000];
    int *deck[10000];
    int index = 0;
    
    while (scanf("%d", &(card[index])) != EOF) {
        deck[index] = &(card[index]);
        index++;
    }
    deck[index] = NULL;
    shuffle(deck);
    print(deck);
    return 0;
}

void shuffle(int *deck[]){
    int buff[10000];
    int length=0, count=0;
    int mid;
    
    while (deck[length] != NULL){
        buff[length] = *deck[length];
        length++;
    }
    
    if (length %2 != 0)
        mid = length/2 + 1;
    else
        mid = length/2;

    for (int i=0; i<length; i++){
        if (i % 2 ==0)
            *deck[i] = buff[i/2];
        else{
            *deck[i] = buff[mid + count];
            count++;
        }
    }
        
}

void print(int *deck[]){
    int i = 0;
    while (deck[i]){
        printf("%d ", *deck[i]);
        i++;
    }
}
