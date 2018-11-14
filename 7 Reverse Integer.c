#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char *argv[]) {
    char max[12] = "+2147483647";
    char min[12] = "-2147483648";
    int a, count=0, i;
    printf("Enter an integer: ");
    scanf("%d", &a);
    char b[13]; 
    if (a<0) {
        b[count++] = '-';
    } else {
        b[count++] = '+';
    }
    a = abs(a);
    while (a>0) {
        b[count++] = a%10 + '0';
        a = (a - a%10)/10;
    }
    if (count<=13) {
        b[count] = '\0';
    }
    printf("Flipped: ");
    if ((b[0]=='+' && strcmp(b+1, max+1) > 0) || (b[0]=='-' && strcmp(b+1, min+1) > 0)) {
        printf("0\n");
    } else {
        for (i = 0; i < strlen(b); i++) {
            if (i == 0 && b[i] == '-') {
                printf("%c", b[i]);
                continue;
            } else if (b[i] == '+') {
                continue;
            }
            if (b[i] != '0') {
                break;
            }
        }
        while (i < strlen(b)) {
            printf("%c", b[i]);
            i++;
        }
        printf("\n");
    }
    return 0;
}
