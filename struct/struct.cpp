// struct.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/* 工具：向量加 */
void vec_add(const float v1[3], const float v2[3], float out[3])
{
    out[0] = v1[0] + v2[0];
    out[1] = v1[1] + v2[1];
    out[2] = v1[2] + v2[2];
}

/* 工具：向量减 */
void vec_sub(const float v1[3], const float v2[3], float out[3])
{
    out[0] = v1[0] - v2[0];
    out[1] = v1[1] - v2[1];
    out[2] = v1[2] - v2[2];
}

/* 工具：点乘（返回标量） */
float vec_dot(const float v1[3], const float v2[3])
{
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

/* 工具：叉乘 */
void vec_cross(const float v1[3], const float v2[3], float out[3])
{
    out[0] = v1[1] * v2[2] - v1[2] * v2[1];
    out[1] = v1[2] * v2[0] - v1[0] * v2[2];
    out[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

/* 工具：求模 */
float vec_len(const float v[3])
{
    return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

/* 工具：单位化（原地修改） */
void vec_normalize(float v[3])
{
    float len = vec_len(v);
    if (len > 1e-6f) {
        v[0] /= len;
        v[1] /= len;
        v[2] /= len;
    }
}
int main(void)
{
    //由几何关系易知，B到AC1之间的距离为AC1模长的一半//
    float a[3] = { -1,1,-1 };
    float hB = vec_len(a);
    printf("B 到 AC1 的距离= %f\n", hB);
     
   //由几何关系易知，平面AEC1的法向量为（1，2，1），AF向量坐标为（0，0.5，0）, 距离 = | n·F| / |n |//                               */
    float n[3] = { 1 , 2 , 1 };
    float f[3] = { 0, 0.5f, 0 };
    float dist = vec_dot(n , f) / vec_len(n);
    printf("AF 到平面 AEC1 的距离= %f\n", dist);

    return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
