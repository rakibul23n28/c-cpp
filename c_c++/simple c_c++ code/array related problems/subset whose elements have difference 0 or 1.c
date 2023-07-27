#include <stdio.h>
int main()
{
    //a is the length of array and b is the name of array.
    int a, t, i, j, count, k;
    count = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &a);

    int b[a], d[101];

    printf("Enter array elements: ");
    for (i = 0; i < a; i++) {
        scanf("%d", &b[i]);
    }

    for (i = 0; i <= 100; i++) {
        for (j = 0; j < a; j++) {
            if (i == b[j]) {
                count = count + 1;
            }
        }
        d[i] = count;
        count = 0;
    }
      for (i = 0; i < 100; i++) {
        printf("%d ", d[i]);
    }

    t = d[0] + d[1];

    for (i = 0; i < 100; i++) {
        k = d[i] + d[i + 1];
        if (k > t) {
            t = k;
        }
    }
    printf("Number of subset: %d", t);

    return 0;
}
