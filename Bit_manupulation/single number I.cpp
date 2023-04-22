class Solution {
    public int singleNumber(int[] nums) {
        int carry = 0;
        for(int i:nums){
            carry^=i;
        }
        return carry;
    }
}
