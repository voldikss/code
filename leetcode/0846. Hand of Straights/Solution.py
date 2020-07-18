# 使用模拟,没模拟出来...
class Solution:
    def isNStraightHand(self, hand, W):
        if len(hand) == 1:
            if W == 1:
                return True
            else:
                return False
        if len(hand) % W != 0:
            return False

        d = dict()
        for i in hand:
            d[i] = d.get(i, 0) + 1

        keys = sorted(list(d.keys()))

        first_not_zero_pos = 0
        tmp = []
        i = 0
        count = 0
        prev = keys[0]
        while i < len(keys):
            val = keys[i]
            d[val] -= 1
            if d[val] == 0 and first_not_zero_pos == i:
                first_not_zero_pos += 1
            tmp.append(val)

            if count != 0:
                if (prev + 1) != val:
                    print(prev, val)
                    return False
            prev = val

            count += 1
            i += 1
            if count % 3 == 0:
                i = first_not_zero_pos
                count = 0

            print(i, first_not_zero_pos, sorted(d.items()))

        if len(tmp) != len(hand):
            print(tmp)
            return False
        return True


s = Solution()
hand = [5,1]
W = 1
print(s.isNStraightHand(hand, W))
