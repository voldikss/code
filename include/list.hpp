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
std::ostream& operator<<(std::ostream& os, const std::list<T>& l) {
    for (auto& i : l) os << i << " ";
    return os;
}
