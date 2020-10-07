#pragma once

class _counter {
public:
    _counter(int u, int v) :count(u), count_weak(v) {}
    ~_counter() {}
    int count;
    int count_weak;
};
