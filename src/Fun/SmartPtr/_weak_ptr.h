#pragma once

template<typename T>
class _weak_ptr {
    bool is_empty() const {
        return pt == nullptr;
    }
    void clear() {
        if (pt == nullptr) {
            return;
        }
        pc->count_weak--;
        if (pc->count == 0 && pc->count_weak == 0) {
            delete pt;
            delete pc;
        }
        pc = nullptr;
        pt = nullptr;
    }
public:
    _weak_ptr() {
        pc = nullptr;
        pt = nullptr;
    }
    _weak_ptr(const _shared_ptr<T>& rhs) {
        pc = rhs.pc;
        pt = rhs.pt;
        if (rhs.is_empty()) {
            return;
        }
        pc->count_weak++;
    }
    _weak_ptr<T>& operator=(const _shared_ptr<T>& rhs) {
        clear();
        if (rhs.is_empty()) {
            return *this;
        }
        pc = rhs.pc;
        pt = rhs.pt;
        pc->count_weak++;
        return *this;
    }
    _counter* pc;
    T* pt;
    _shared_ptr<T> lock() {
        _shared_ptr<T> tmp;
        if (pc == nullptr || pc->count == 0) {
            return tmp;
        }
        tmp.pc = pc;
        tmp.pt = pt;
        tmp.pc->count_weak++;
        return tmp;
    }
};