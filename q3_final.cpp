//
//  main.cpp
//  q3
//
//  Created by Shiny on 07/02/2017.
//  Copyright © 2017 Brendon. All rights reserved.
//

/* Example
 2 3
 1 2 3
 4 5 6
 7 8 9
 1 2 3
 4 5 6
 7 8 9
 1 2 4 8 6 3 9 5 7
 Ans 3 0 1
 */

//#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
int board[10][256][256];
int n,m;

int test_row(int i,int j,int k){
    int bingo = 1;
    for (int a=0; a<m; a++){
        if (board[i][j][a]!=0){
            bingo = 0;
            break;}
    }
    if (bingo == 0)
        return 0;
    else
        return 1;
}


int test_col(int i,int j,int k){
    int bingo = 1;
    for (int a=0; a<m; a++){
        if (board[i][a][k]!=0)
        {
            bingo = 0;
            break;}
    }
    if (bingo == 0) return 0;
    else return 1;
}


int test_dia(int i,int j,int k){
    
    
    if (j==k || (j+k+1)==m){
        int bingo = 1;
        //case 1
        for (int a=0; a<m; a++){
            if (board[i][a][a] != 0)
                bingo = 0;
        }
        if (bingo == 1)
            return 1;
        
        
        //case 2
        bingo = 1;
        for (int b=0; b<m; b++){
            if (board[i][b][m-b-1] != 0)
                bingo = 0;
        }
        if (bingo == 1)
            return 1;
        
        return 0;
    }
    else
        return 0;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    bool flag = false;
    
    //FILE *fp;
    
    //printf("Enter the number of the players(<=10) & size of the chessboard(<=256) \n");
    scanf("%d %d", &n, &m);
    //printf("n = %d, m = %d \n",n ,m);
    
    //int board[n][m][m];
    
    /*fp = fopen("/Users/Mac/Dropbox/[Coursera] programming/q3/q3/input.txt", "r");
    if (fp == NULL){
        printf("Cannot Find File \n");
        exit(-1);
    }*/
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<m; k++){
                scanf("%d", &board[i][j][k]);
            }
        }
        
    }
    //fclose(fp);
    
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<m; k++){
                printf("%d ", board[i][j][k]);
            }
            printf("\n");
        }
    }*/
    
    //int num[256];

    while(!flag){
        int num;
        //bool r1, r2, r3;
        //for (int l=0; l<m*m; l++){ //BINGO Numbers
        scanf("%d", &num);
        //printf("Bingo Number = %d \n", num);
        for (int i=0; i<n; i++){ //Player
            for (int j=0; j<m; j++){
                for(int k=0; k<m; k++){
                    if (num == board[i][j][k]){
                        board[i][j][k] = 0; //cross it
                        //check if bingo
                        if(test_row(i,j,k) || test_col(i,j,k) || test_dia(i,j,k)){
                            if (flag == false) printf("%d ",num);
                            flag = true;
                            printf("%d ", i);
                        }
                    }
                }
            }
        }
        
        if (flag == true)
            break;
        }

    return 0;
}
