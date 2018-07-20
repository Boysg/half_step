#include <stdio.h>
#include <stdlib.h>

/******************************************
*Name:Gomoku                              *
*Create date:2018/7/4                     *
*Author:Mr.Yin                            *
******************************************/

void refresh(int map[15][15]);
int judge_x(int map[15][15], int x, int y);  //判断竖排是否五连珠
int judge_y(int map[15][15], int x, int y);  //判断横排是否五连珠
int judge_xy(int map[15][15], int x, int y); //判断右下斜是否五连珠
int judge_yx(int map[15][15], int x, int y); //判断左下斜是否五连珠
int main(void)
{
    int board[15][15] = {0}; //定义棋盘大小
    int x, y;                //定义玩家每次输入的坐标
    int flag_player = 0;     //定义两名玩家编号
    int count_round = 0;     //定义回合数

    while (1)
    {
        //刷新棋盘
        refresh(board); 
        //判断游戏是否结束
        if (count_round != 0)
            if (judge_x(board, x, y) >= 4 ||
                judge_y(board, x, y) >= 4 ||
                judge_xy(board, x, y) >= 4 ||
                judge_yx(board, x, y) >= 4) 
                break;
        //玩家输入坐标
input:
        printf("Player%d please enter a location:\n", flag_player == 0 ? 1 : 2);
        scanf("%x,%x", &x, &y);
        //判断输入坐标是否合法
        if (x < 1 || y > 15 || board[x - 1][y - 1] != 0)
        {
            printf("Illegal input\n");
            goto input;
        }
        //读取玩家输入的坐标
        board[x - 1][y - 1] = flag_player == 0 ? 1 : 2;
        flag_player = !flag_player;
        count_round++;
    }
    printf("Game Over\nThe Winner is player%d\nYou used %d rounds\n", !flag_player + 1, count_round);

    return 0;
}

void refresh(int map[15][15])
{
    int i, j;
    system("clear");
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 15; j++)
        {
            if (map[i][j] == 0)
                printf("*  ");
            else if (map[i][j] == 1)
                printf("@  ");
            else if (map[i][j] == 2)
                printf("O  ");
        }
        printf("\b%x\n", i + 1);
    }
    for (i = 1; i <= 15; i++)
    {
        printf("%x  ", i);
    }
    printf("\n");
}

int judge_x(int map[15][15], int x, int y)
{
    int i, count_x = 0;
    for (i = x - 2; i >= 0; i--)
    {
        if (map[i][y - 1] == map[x - 1][y - 1])
            count_x++;
        else
            break;
    }
    for (i = x; i < 15; i++)
    {
        if (map[i][y - 1] == map[x - 1][y - 1])
            count_x++;
        else
            break;
    }
    return count_x;
}

int judge_y(int map[15][15], int x, int y)
{
    int i, count_y = 0;
    for (i = y - 2; i >= 0; i--)
    {
        if (map[x - 1][i] == map[x - 1][y - 1])
            count_y++;
        else
            break;
    }
    for (i = y; i < 15; i++)
    {
        if (map[x - 1][i] == map[x - 1][y - 1])
            count_y++;
        else
            break;
    }
    return count_y;
}

int judge_xy(int map[15][15], int x, int y)
{
    int i, j, count_xy = 0;
    for (i = x - 2, j = y - 2; i >= 0 || j >= 0; i--, j--)
    {
        if (map[i][j] == map[x - 1][y - 1])
            count_xy++;
        else
            break;
    }
    for (i = x, j = y; i < 15 || j < 15; i++, j++)
    {
        if (map[i][j] == map[x - 1][y - 1])
            count_xy++;
        else
            break;
    }
    return count_xy;
}

int judge_yx(int map[15][15], int x, int y)
{
    int i, j, count_yx = 0;
    for (i = x - 2, j = y; i >= 0 || j < 15; i--, j++)
    {
        if (map[i][j] == map[x - 1][y - 1])
            count_yx++;
        else
            break;
    }
    for (i = x, j = y - 2; i < 15 || j >= 0; i++, j--)
    {
        if (map[i][j] == map[x - 1][y - 1])
            count_yx++;
        else
            break;
    }
    return count_yx;
}