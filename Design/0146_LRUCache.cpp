#include <fmt/core.h>
#include <list>
#include <unordered_map>
#include <iostream>
// https://leetcode.com/problems/lru-cache/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days

// Cache replacement polices
// Ref: https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU

using namespace std;

class LRUCache
{
    const int capacity_;

    struct Cache
    {
        int key;
        int value;
    };

    // frequency, <key, value>
    // order by age bits in descending order
    std::list<Cache> caches_;
    std::unordered_map<int, std::list<Cache>::iterator> keyMap_;
    // key, cache loc (ranked by age bits)

public:
    LRUCache(const int capacity)
        : capacity_{capacity}
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        keyMap_.reserve(10001);
    }

    int get(const int key)
    {
        if (const auto itr = keyMap_.find(key); itr != keyMap_.end()) {
            // update the caches_ list
            caches_.splice(caches_.begin(), caches_, itr->second);
            return itr->second->value;
        }
        return -1;
    }

    void put(const int key, const int value)
    {
        if (const auto itr = keyMap_.find(key); itr != keyMap_.end()) {
            caches_.splice(caches_.begin(), caches_, itr->second);
            itr->second->value = value;
            return;
        }
        // cache miss, no such key
        // check the capacity
        if (caches_.size() == capacity_) {
            // overflown, remove the least used
            keyMap_.erase(caches_.back().key);
            caches_.pop_back();
        }
        // append the new key
        caches_.emplace_front(key, value);
        keyMap_.insert({key, caches_.begin()});
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    // ["LRUCache","put","put","get","put","get","put","get","get","get"]
    // [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
    LRUCache lru{2};
    lru.put(1, 1);
    lru.put(2, 2);
    lru.get(1);
    lru.put(3, 3);
    lru.get(2);
    lru.put(4, 4);
    lru.get(1);
    lru.get(3);
    lru.get(4);
}