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

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (auto x : vec) os << x << " ";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& vec) {
    for (auto& x : vec) os << x << std::endl;
    return os;
}
