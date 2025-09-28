#include <iostream>
#include <list>
#include <stdexcept>
#include <unordered_map>

using namespace std;

// LRU cache
// int int

class LRU {
public:
    LRU(size_t capacity) : capacity_(capacity) {}

    void Put(int key, int val) {
        auto it = key_to_vals_.find(key);
        if (it != key_to_vals_.end()) {
            // 已存在，更新值
            it->second->second = val;
            vals_.splice(vals_.begin(), vals_, it->second);
            return;
        }
        if (vals_.size() == capacity_) {
            // 元素已满
            auto tar = vals_.back();
            vals_.pop_back();
            key_to_vals_.erase(tar.first);
        }
        vals_.emplace_front(key, val);
        key_to_vals_.emplace(key, vals_.begin());
    }

    int Get(int key) {
        auto it = key_to_vals_.find(key);
        if (it == key_to_vals_.end()) {
            throw runtime_error("can not find the key: " + to_string(key));
        }
        auto res = it->second->second;
        vals_.splice(vals_.begin(), vals_, it->second);
        return res;
    }

private:
    unordered_map<int, list<pair<int, int>>::iterator> key_to_vals_;
    list<pair<int, int>> vals_;
    size_t capacity_;
};


int main() {
    LRU lru(3);
    lru.Put(3, 0);
    lru.Put(4, 1);
    lru.Put(5, 2);
    lru.Put(6, 3);
    try {
        auto res = lru.Get(3);
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
    auto res = lru.Get(4);
    cout << res << endl;

    return 0;
}
