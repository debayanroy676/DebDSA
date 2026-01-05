class Solution {
    public int[] twoSum(int[] nums, int target) {
        int i=0, j=1;
        int[] out={0,0};
        if(checkConstrains(nums, target)) {
            System.out.println("Constrains Unsatisfied");
            return out;
        }
        String ret = "";
        while(nums[i]+nums[j]!=target && j<nums.length && i<nums.length-1) 
            if(nums[i]+nums[j]>target) i++;
            else j++;
        ret = i+""+j;
        out = new int[ret.length()];
        for(i=0; i<ret.length(); i++) 
            out[i] = Integer.parseInt(ret.charAt(i)+"");
        return out;
    }
    public boolean checkConstrains(int[] nums, int target) {
        if(!(target>=-(int)Math.pow(10,9) && target>=(int)Math.pow(10,9)))
            return false;
        if(!(nums.length>=2 && nums.length<=10000))
            return false;
        for(int i=0; i<nums.length; i++) 
            if(!(nums[i]>=-(int)Math.pow(10,9) && nums[i]>=(int)Math.pow(10,9)))
                return false;
            else continue;
        return true;
    }
}