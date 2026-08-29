class Solution {
    public int getNextIndex(int[] nums, int elem, int index) {
        for (int i = 0; i < nums.length && i!=index; i++)
            if (nums[i] == elem && i!=index) return i;
            else continue;
        return -1;
    }

    public int[] twoSum(int[] nums, int target) {
        String s = "";
        System.out.println(nums[0]);
        for (int i = 0; i < nums.length && s.equals(""); i++) {
            if (getNextIndex(nums, (target - nums[i]), i) != -1) 
                s += i+" "+getNextIndex(nums, (target - nums[i]), i);
            else
                continue;
        }
        String[] temp = s.split(" ");
        int[] ret = {Integer.parseInt(temp[0]), Integer.parseInt(temp[1])};
        return ret;
    }
}
