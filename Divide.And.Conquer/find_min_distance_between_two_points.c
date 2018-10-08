/*
 * Copyright 2018 qiuyang Zhang. All rights reserved.
 * 
 * filename    : find_min_distance_between_two_points.c
 * author      : qiuyang Zhang
 * created     : 2018/10/08
 * description : 寻找最近点对
 * page        : P610
 *
 */
#include <limits.h>
#include <math.h>
#include <float.h>
#include "../Header/point.h"


inline double point_distance(struct point *a, struct point *b)
{
    return (sqrt(pow(a->x, 2) + pow(b->x, 2)));
}
/*
 * 函数名称：find_min_distance_between_two_points
 * 函数功能：寻找由左边区域的点和右边区域的点组成的最近点对
 * 函数输入：struct point *P[]  : 平面上的所有点集
 *           int num            : 平面上所有点的数量
 *           int x_sort_index[] : 按照x坐标升序排列的点在点集中的下标
 *           int y_sort_index[] : 按照y坐标降序排列的点在点集中的下标
 *           double line_x      : 划分中线的x坐标
 *           double min_left    : 左边区域中求出的最近点对的距离
 *           double min_right   : 右边区域中求出的最近点对的距离
 * 函数输出：struct point *a    : 在跨界区域找到的最近点对之一
 *           struct point *b    : 在跨界区域找到的最近点对之一
 *           double *distance   : 在跨界区域找到的最近点对的距离
 */
void find_min_cross_line(struct point *P[], int num, int x_sort_index[], int y_sort_index[],
                         double line_x, double min_left, double min_right,
                         struct point *a, struct point *b, double *distance)
{
    int cross_y_sort_index[200];    // 属于带状区域的点集的下标，按照y坐标降序排列
    int cross_num;                  // 带状区域点集的数量
    double known_min;                  // 已知的左区域和右区域中最近点对的最小距离

    known_min = (min_left <= min_right) ? min_left : min_right;
    cross_num = 0;

    // 按照y坐标降序排列寻找属于带状区域中的点
    int i;
    for (i = 0; i < num; ++i)
    {
        if (P[y_sort_index[i]]->x <= line_x + known_min
                && P[y_sort_index[i]]->x >= line_x - known_min)
            cross_y_sort_index[cross_num++] = y_sort_index[i];
    }

    double a_b_dis;                // 计算两点间距离的中间变量
    int j;
    *distance = DBL_MAX;
    for (i = 0; i < cross_num - 8; ++i)
    {
        for (j = 1; j <= 7; ++j)
        {
            a_b_dis = point_distance(P[cross_y_sort_index[i]],
                                     P[cross_y_sort_index[i + j]]);
            if (a_b_dis <= *distance)
            {
                a         = P[cross_y_sort_index[i]];
                b         = P[cross_y_sort_index[i + j]];
                *distance = a_b_dis;
            }
        }
    }
    for (; i < cross_num; ++i)
    {
        for (j = i + 1; j < cross_num; ++j)
        {
            a_b_dis = point_distance(P[cross_y_sort_index[i]],
                                     P[cross_y_sort_index[i + j]]);
            if (a_b_dis <= *distance)
            {
                a         = P[cross_y_sort_index[i]];
                b         = P[cross_y_sort_index[i + j]];
                *distance = a_b_dis;
            }
        }
    }
}
