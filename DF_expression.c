#include <stdio.h>
#include <string.h>

char s[100];            //expression
int width, index, pos1 = 0, pos2 = 0;;

int dofunc(int w, int data[w][w]){     //202001010
    index++;                  //index position of expression
    printf("\n s[index] = %c , index = %d\n", s[index], index);     //print out current index and value of s[index]
    int temp = 0;
    temp = pos2;
    //------print out the square in current situation------//
    printf("\n");
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%d ",data[i][j]);
        }
        printf("%\n");
    }
    printf("%\n");
    //-----------------------------------------------------//
    if (s[index] == '0')
    {
        for (int i = 0; i < w; i++)
        {
            if (i!=0)
            {
                pos1++;
                pos2 = temp;
            }
            for (int j = 0; j < w; j++)
            {
                printf("\n pos1 = %d , pos2 = %d\n",pos1, pos2);
                data[pos1][pos2] = 0;
                pos2++;
            }
        }
        return 0;
    }
    else if (s[index] == '1')
    {
        for (int i = 0; i < w; i++)
        {
            if (i!=0)
            {
                pos1++;
                pos2 = temp;
            }
            for (int j = 0; j < w; j++)
            {
                data[pos1][pos2] = 1;
                pos2++;
            }
        }
        return w*w;
    }
    else
    {
        int total = 0;              //counting total number of '1'
        for (int i = 0; i < 4; i++)
            total += dofunc(w/2, data);
        return total;
    }
}

int main()
{
    int num = 0, i = 0, j = 0, l = 0;
    scanf("%s", &s);        //input expression
    getchar();
    l = strlen(s);
    scanf("%d", &width);        //input width*width size of square (must be 2^n)
    index = -1;
    int data[width][width];         //create width*width size array

    for (i = 0; i < width; i++)         //init array value
        for (j = 0; j < width; j++)
            data[i][j] = -1;

    num = dofunc(width, data);

    printf("\nNum of '1' = %d\n", num);
}
