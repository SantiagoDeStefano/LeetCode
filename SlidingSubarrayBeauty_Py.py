from sortedcontainers import SortedList
class Solution:
    def getSubarrayBeauty(self, nums: list[int], k: int, x: int) -> list[int]:
        result = []
        sorted_list = SortedList()

        for i in range(len(nums)):
            sorted_list.add(nums[i])
            if(i - k >= 0):
                sorted_list.remove(nums[i - k])
            if(len(sorted_list) >= k):
                temp = sorted_list[x - 1]
                if temp >= 0:
                    result.append(0)
                else:
                    result.append(temp)
        return result

nums = [-1,-2,-3,-4,-5]

solution = Solution()
print(solution.getSubarrayBeauty(nums, 2, 2))