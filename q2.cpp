//
//  main.cpp
//  q2
//
//  Created by Shiny on 03/02/2017.
//  Copyright © 2017 Brendon. All rights reserved.
//

//Answers
// 5 -1 -2 5 -2 1 6
// 4 -2 1 -2 1 -2 2 -2
// -1 3 2 -2 -1 2
// -1 0 3 3 6 -1 -2
// 2 -1 0 -2 4 0 6 1 6 0

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    int normal[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                    // 31 28 31	30	31	30	31	31	30	31	30	31
    int year, day, num;
    int flag = 0;
    int count = 0;
    printf("Enter the first date of the year \n");
    scanf("%d %d", &year, &day);
    printf("How many guess ? \n");
    scanf("%d", &num);
    
    int *answer = new int[num];
    
    if (year % 400 == 0 || (year % 4 ==0 && year %100 !=0))
        flag = 1;
    
    while(count < num){
        int mon, date;
        int sum=0;
        printf("The %d time, enter the mon and date \n", count+1);
        scanf("%d %d", &mon, &date);
        
        //check
        if (mon<1 || mon > 12){
            answer[count] = -1;
            count ++;
            continue;
        }
        
        if (flag==0){
            if(date<1 || date > normal[mon-1]){
                answer[count] = -2;
                count ++;
                continue;
            }
        }
        else{
            if(date<1 || date > leap[mon-1]){
                answer[count] = -2;
                count ++;
                continue;
            }
        }
        
        //typical
        if (flag == 0){ //normal
            for (int j=0; j<(mon-1); j++)
                sum += normal[j];
            sum += date;
        }
        //leap
        else{
            for (int j=0; j<(mon-1); j++)
                sum += leap[j];
            sum += date;
        }
    
        //printf("%d", sum);
        answer[count] = (day + sum-1) % 7;
        count ++;
    }
    for(int i; i<num; i++)
        printf("%d ", answer[i]);
    
    //cout<<"enter the first date of the year"
    delete[] answer;
    return 0;
}
