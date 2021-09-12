/*
给出一个三角形的三个点的坐标，该三个点构建一个三角形, 写一个函数
可以输出三角形内随机的一个点的位置。
more discussion : https://www.zhihu.com/question/31706710
*/

#include "../../../include/base.h"
#include <vector>
#include <cstdlib>
#include <ctime>

// ref: http://paulbourke.net/geometry/polygonmesh/
// return 1 for interior pt and 0 for exterior pt
int pnpoly(int npol, float *xp, float *yp, float x, float y)
{
    int i, j, c = 0;
    for (i = 0, j = npol-1; i < npol; j = i++) {
    if ((((yp[i] <= y) && (y < yp[j])) ||
            ((yp[j] <= y) && (y < yp[i]))) &&
        (x < (xp[j] - xp[i]) * (y - yp[i]) / (yp[j] - yp[i]) + xp[i]))
        c = !c;
    }
    return c;
}

float random_float()
{
    float tmp;
    tmp = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    if (0 == tmp) tmp = 0.1;
    else if (1.0 == tmp) tmp = 0.9;
    return tmp;
}

float get_pt_y_on_line(Point pt1, Point pt2, float x)
{
    float x_x2, x_x1;

    x_x2 = x - pt2.x;
    x_x1 = x - pt1.x;

    return (x_x2 * pt1.y - pt2.y * x_x1) / (pt1.x - pt2.x);
}

float get_pt_x_on_line(Point pt1, Point pt2, float y)
{
    float x_x2, x_x1;

    x_x2 = y - pt2.y;
    x_x1 = y - pt1.y;

    return (x_x1 * pt2.x - pt1.x * x_x2) / (pt2.y - pt1.y);
}

class Solution
{
public:

    int generateInnerPt(vector<Point>& triangle)
    {
        float min_x_12, max_x_12, randx_12, min_x_13, max_x_13, randx_13;
        float min_x_23, max_x_23, randx_23;
        Point pt1, pt2, pt3;
        Point pt_12, pt_13, pt_23;
        float x[3], y[3];

        assert(3 == triangle.size());
        pt1 = triangle[0];
        pt2 = triangle[1];
        pt3 = triangle[2];

        min_x_12 = min(pt1.x, pt2.x);
        max_x_12 = max(pt1.x, pt2.x);
        if (min_x_12 == max_x_12)
        {
            min_x_12 = min(pt1.y, pt2.y);
            max_x_12 = max(pt1.y, pt2.y);
            randx_12 = random_float() *
                (max_x_12 - min_x_12) + min_x_12;
            pt_12.y = randx_12;
            pt_12.x = get_pt_x_on_line(pt1, pt2, pt_12.y);
        }
        else
        {
            randx_12 = random_float() *
                (max_x_12 - min_x_12) + min_x_12;
            pt_12.x = randx_12;
            pt_12.y = get_pt_y_on_line(pt1, pt2, pt_12.x);
        }
        output(pt_12);

        min_x_13 = min(pt1.x, pt3.x);
        max_x_13 = max(pt1.x, pt3.x);
        if (min_x_13 == max_x_13)
        {
            min_x_13 = min(pt1.y, pt3.y);
            max_x_13 = max(pt1.y, pt3.y);
            randx_13 = random_float() * (max_x_13 - min_x_13) + min_x_13;
            pt_13.y = randx_13;
            pt_13.x = get_pt_x_on_line(pt1, pt3, pt_13.x);
        }
        else
        {
            randx_13 = random_float() * (max_x_13 - min_x_13) + min_x_13;
            pt_13.x = randx_13;
            pt_13.y = get_pt_y_on_line(pt1, pt3, pt_13.x);
        }
        output(pt_13);

        min_x_23 = min(pt_12.x, pt_13.x);
        max_x_23 = max(pt_12.x, pt_13.x);
        randx_23 = random_float() * (max_x_23 - min_x_23) + min_x_23;
        pt_23.x = randx_23;
        pt_23.y = get_pt_y_on_line(pt_12, pt_13, pt_23.x);
        output(pt_23);

        // test
        x[0] = pt1.x;
        x[1] = pt2.x;
        x[2] = pt3.x;
        y[0] = pt1.y;
        y[1] = pt2.y;
        y[2] = pt3.y;
        return pnpoly(3, x, y, pt_23.x, pt_23.y);
    }
};

int main()
{
    vector<Point> first;
    int expectAns;

    std:srand(std::time(nullptr)); // use current time as seed for random generotr

    first.clear();
    first.push_back({0, 0});
    first.push_back({1.0, 0});
    first.push_back({0, 2.0});
    expectAns = 1;
    TEST_SMP1(Solution, generateInnerPt, expectAns, first);

    first.clear();
    first.push_back({0, 0});
    first.push_back({2.0, 2.0});
    first.push_back({0, 4.0});
    expectAns = 1;
    TEST_SMP1(Solution, generateInnerPt, expectAns, first);

    first.clear();
    first.push_back({0, 0});
    first.push_back({2.0, 2.0});
    first.push_back({4.0, 0});
    expectAns = 1;
    TEST_SMP1(Solution, generateInnerPt, expectAns, first);

    first.clear();
    first.push_back({-2, 0});
    first.push_back({2.0, 0.1});
    first.push_back({4.0, 0});
    expectAns = 1;
    TEST_SMP1(Solution, generateInnerPt, expectAns, first);
}