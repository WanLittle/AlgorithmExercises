#pragma once
#include "../BASE.h"

class V_point_in_triangle : public BASE {
public:
	virtual void main()
	{
        cout << judgePointInTriangle(vec(0, 0), vec(1, 0), vec(0, 1), vec(1, 1)) << endl; //false
        cout << judgePointInTriangle(vec(0, 0), vec(1, 0), vec(0, 1), vec(0.25, 0.25)) << endl; //true
	}
    struct vec //�������
    {
        float x;
        float y;
        vec(float _x, float _y) : x(_x), y(_y) {}
        vec operator - (const vec&  v) const {
            return vec(x - v.x, y - v.y);
        }
    };
    /*
    ���P��������ABC�ڲ�����������������������P,A��BC��ͬ�ࡢP,B��AC��ͬ�ࡢPC��AB��ͬ�ࡣĳһ�����������ʾP�����������ڲ���
    �Ƿ�ͬ���ö�ά�������ò�����ж�
    */
    bool judgePointInTriangle(const vec& a, const vec& b, const vec& c, const vec& p) {
        return bothSide(a, b, c, p) && bothSide(a, c, b, p) && bothSide(b, c, a, p);
    }
    float v_cross(const vec& p, const vec& q) { return p.x * q.y - q.x * p.y; }
    float v_dot(const vec& p, const vec& q) { return p.x*q.x + p.y*q.y; }
    // �жϵ�cd�ǲ�����ֱ��ab��ͬһ��
    bool bothSide(const vec& a, const vec& b, const vec& c, const vec& d)
    {
        vec ab = b - a;
        vec ac = c - a;
        vec ad = d - a;
        return (v_cross(ab, ac) * v_cross(ab, ad)) > 0;
    }
};