#include<stdio.h>

int main() {
    int i, r1, r2,total_find=0;
    scanf("%d %d", &r1, &r2);
    int array[r2-r1];
    for(int i=0;i<r2-r1;i++) array[i]=0;
    for (i = r1; i <= r2; i++) {
        int num = i;
        int count = 0, temp = num, sum = 0;
        
        // Calculate the number of digits in the current number
        while (temp != 0) {
            temp = temp / 10;
            count++;
        }
        
        int position = count;
        temp = num;
        
        // Calculate the sum of even-positioned digits
        while (temp != 0) {
            int digit = temp % 10;
            if (position % 2 == 0) {
                sum = sum + digit;
            }
            position--;
            temp = temp / 10;
        }
        
        // Check the conditions and print the number if they are satisfied
        if ((count >= 2 && count <= 6) && (sum > 8 && sum % 4 == 0)) {
           array[total_find]=num;
           total_find++;
        }
    }
    printf("%d:",total_find);
    for (int i = 0; i < total_find; i++)
    {
        printf("%d ",array[i]);
    }
    
    return 0;
}