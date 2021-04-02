#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>


template <typename U, typename V>
std::ostream& operator<<(std::ostream& os, const std::pair<U, V>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
