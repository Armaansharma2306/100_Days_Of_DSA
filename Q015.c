/*Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is 
a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int isIdentity = 1;   // assume true

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            int x;
            scanf("%d", &x);

            if(i == j) {
                if(x != 1)
                    isIdentity = 0;
            }
            else {
                if(x != 0)
                    isIdentity = 0;
            }
        }
    }

    if(isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}