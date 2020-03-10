#pragma once
#include "../BASE.h"

class V_point_in_triangle : public BASE {
public:
	virtual void main()
	{
        cout << judgePointInTriangle(vec(0, 0), vec(1, 0), vec(0, 1), vec(1, 1)) << endl; //false
        cout << judgePointInTriangle(vec(0, 0), vec(1, 0), vec(0, 1), vec(0.25, 0.25)) << endl; //true
	}
    struct vec //点或向量
    {
        float x;
        float y;
        vec(float _x, float _y) : x(_x), y(_y) {}
        vec operator - (const vec&  v) const {
            return vec(x - v.x, y - v.y);
        }
    };
    /*
    如果P在三角形ABC内部，则满足以下三个条件：P,A在BC的同侧、P,B在AC的同侧、PC在AB的同侧。某一个不满足则表示P不在三角形内部。
    是否同侧用二维向量的用叉积来判断
    */
    bool judgePointInTriangle(const vec& a, const vec& b, const vec& c, const vec& p) {
        return bothSide(a, b, c, p) && bothSide(a, c, b, p) && bothSide(b, c, a, p);
    }
    float v_cross(const vec& p, const vec& q) { return p.x * q.y - q.x * p.y; }
    float v_dot(const vec& p, const vec& q) { return p.x*q.x + p.y*q.y; }
    // 判断点cd是不是在直线ab的同一侧
    bool bothSide(const vec& a, const vec& b, const vec& c, const vec& d)
    {
        vec ab = b - a;
        vec ac = c - a;
        vec ad = d - a;
        return (v_cross(ab, ac) * v_cross(ab, ad)) > 0;
    }
};