/*
 * =====================================================================================
 *
 *       Filename:  q4.cpp
 *
 *    Description:  q3
 *
 *        Version:  1.0
 *        Created:  02/15/2017 17:44:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MIN(a,b) ((a) < (b) ? a:b )

int value(int type, int width, int height, int length);
int GCD(int a, int b);

int main ()
{
    int type, width, height, length;
    scanf ( "%d%d%d%d", &type, &width, &height, &length );
    printf ( "%d\n", value ( type, width, height, length ) );
    return 0;
}

int value(int type, int width, int height, int length){
    int price;

    switch(type){
        case 79:
            price = 30;
            break;
        case 47:
            price = 10;
            break;
        case 29:
            price = 4;
            break;
        case 82:          
            price = 5;
            break;
        case 26:          
            price = 3;
            break;
        case 22:
            price = 9;
            break;
        default:
           return -1;
    }
    if ( width < 1 || length < 1 || height <1)
        return -2;

    int gcd, total=0;
    //min = MIN(width, height);
    //min = MIN(min, length);
    gcd = GCD(length, GCD(height, width));
    printf("%d\n", GCD(height, width));
    printf("GCD = %d \n", gcd);
    total = (length/gcd) * (width/gcd) * (height/gcd);
    total = total * pow( gcd, 6) * price;   
    //printf("Total = %d \n", total);
    return total;
}

int GCD(int a, int b){
    int t;
    while (b>0){
        t = a%b;
        a = b;
        b = t;
    }
    return a;
}

/*
 int GCD (int a, int b){
    while (b!=0)
        return (GCD(b,a%b)); 
 }
 */
