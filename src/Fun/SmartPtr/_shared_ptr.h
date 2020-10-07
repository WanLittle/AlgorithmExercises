#pragma once

template<typename T>
class _shared_ptr {
    void clear() {
        if (pt == nullptr) {
            return;
        }
        pc->count--;
        if (pc->count == 0) {
            delete pt;
        }
        if (pc->count == 0 && pc->count_weak == 0) {
            delete pc;
        }
        pc = nullptr;
        pt = nullptr;
    }
public:
    bool is_empty() const {
        return pt == nullptr;
    }
    _shared_ptr() {
        pc = nullptr;
        pt = nullptr;
    }
    _shared_ptr(T *t) {
        if (t == nullptr) {
            pc = nullptr;
            pt = nullptr;
            return;
        }
        pc = new _counter(1, 0);
        pt = t;
    }
    _shared_ptr(const _shared_ptr<T>& rhs) {
        pc = rhs.pc;
        pt = rhs.pt;
        if (rhs.is_empty()) {
            return;
        }
        pc->count++;
    }
    _shared_ptr<T>& operator=(const _shared_ptr<T>& rhs) {
        if (&rhs == this) {
            cout << "the same" << endl;
            return *this;
        }
        clear();
        if (rhs.is_empty()) {
            return *this;
        }
        pc = rhs.pc;
        pt = rhs.pt;
        pc->count++;
        return *this;
    }
    ~_shared_ptr() {
        clear();
    }
    _counter* pc;
    T* pt;
    T* operator->() {
        return pt;
    }
};
