#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//forѭ��

//do..whileѭ��
int main() 
{
/*    int i = 0;
    for (i = 1; i <= 10; i++)
    {
        //if (i == 5)
        //    break;//��ֹѭ��
        if (i == 5)
            continue;//����continue��ߵĴ���(��ӡ���)������ִ��i++�����벻�������ѭ������������

        printf("%d ", i);
    }
*/
 /*   int x, y;
    for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)
    {
        printf("hehe\n");
    }//��ӡ���κǺ�
*/

//��ʾdo..while��ӡ1~10
    int i = 1;
    do
    {   
        if (i == 5)
            //break;//��ӡ1~4
            continue;

        printf("%d ", i);
        i++;
    }
    while (i <= 10);

    return 0;
}