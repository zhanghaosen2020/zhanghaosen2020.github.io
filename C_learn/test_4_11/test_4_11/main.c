#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//for循环

//do..while循环
int main() 
{
/*    int i = 0;
    for (i = 1; i <= 10; i++)
    {
        //if (i == 5)
        //    break;//终止循环
        if (i == 5)
            continue;//跳过continue后边的代码(打印语句)，但会执行i++，代码不会进入死循环，会跳出来

        printf("%d ", i);
    }
*/
 /*   int x, y;
    for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)
    {
        printf("hehe\n");
    }//打印两次呵呵
*/

//演示do..while打印1~10
    int i = 1;
    do
    {   
        if (i == 5)
            //break;//打印1~4
            continue;

        printf("%d ", i);
        i++;
    }
    while (i <= 10);

    return 0;
}