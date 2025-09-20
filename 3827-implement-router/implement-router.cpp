#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class Key>
using ordered_set = tree<Key, null_type, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;

struct Packet { int s, d, t, uid; };

class Router {
    int cap = 0, uid = 0;
    deque<Packet> q;                                        // FIFO
    unordered_set<long long> seen;                          // (s,d,t) -> dedup
    unordered_map<int, ordered_set<pair<int,int>>> idx;     // dest -> (t, uid)

    static long long key(int s, int d, int t) {
        return ( (long long)s << 42 ) ^ ( (long long)d << 21 ) ^ (long long)t;
    }

    void evict_if_full() {
        if ((int)q.size() < cap) return;
        auto p = q.front(); q.pop_front();
        seen.erase(key(p.s, p.d, p.t));
        idx[p.d].erase({p.t, p.uid});
    }

public:
    Router(int memoryLimit): cap(memoryLimit) {}

    bool addPacket(int s, int d, int t) {
        if (cap == 0) return false;
        long long k = key(s, d, t);
        if (seen.count(k)) return false;        // duplicate
        evict_if_full();

        q.push_back({s, d, t, uid});
        seen.insert(k);
        idx[d].insert({t, uid});
        ++uid;
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto p = q.front(); q.pop_front();
        seen.erase(key(p.s, p.d, p.t));
        idx[p.d].erase({p.t, p.uid});
        return {p.s, p.d, p.t};
    }

    int getCount(int d, int L, int R) {
        auto it = idx.find(d);
        if (it == idx.end()) return 0;
        auto &os = it->second;
        int left  = os.order_of_key({L, INT_MIN});
        int right = os.order_of_key({R + 1, INT_MIN});
        return right - left;
    }
};


/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */