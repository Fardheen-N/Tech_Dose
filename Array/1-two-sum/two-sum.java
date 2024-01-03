class Solution {
    public int[] twoSum(int[] nums, int target) {
        int l=0,r=1;
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i=0;i<nums.length;i++){
            map.put(nums[i],i);
        }
        for(int i=0;i<nums.length;i++){
            int sum = target-nums[i];
            if(map.containsKey(sum)&&map.get(sum)!=i){
                return new int[]{i,map.get(sum)};
            }
        }
        return null;
    }
}