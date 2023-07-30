// 7
//       $
//      1$7
//     23$65
//    456$432
//   7654$1234
//  32123$56765
// 456765$432123



#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int x = 1, y = n, state = 1,state_next=1;
    for (int row = 1; row <= n; row++)
    {
        for (int space = 1; space <= n - row; space++)
        {
            printf(" ");
        }

        for (int lh = row; lh >= 1; lh--)
        {
            if (lh == 1)
            {
                printf("$");
            }
            else
            {
                printf("%d", x);
                if (state == 1)
                {
                    x++;
                    if (x > n)
                    {
                        x = x - 2;
                        state = 0;
                    }
                }
                else
                {
                    x--;
                    if (x < 1)
                    {
                        x = x + 2;
                        state = 1;
                    }
                }
            }
        }

        for (int rh = 2; rh <= row; rh++)
        {
            printf("%d", y);
            if (state_next== 1)
            {
                y--;
                if (y < 1)
                {
                    y = y + 2;
                    state_next = 0;
                }
            }
            else
            {
                y++;
                if (y > n)
                {
                    y = y - 2;
                    state_next = 1;
                }
            }
            
        }
        printf("\n");
    }

    return 0;
}