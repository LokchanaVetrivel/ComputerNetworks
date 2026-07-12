int findMaximumXOR(int* nums, int numsSize) {
    int max = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int xor = nums[i] ^ nums[j];
            if (xor > max) {
                max = xor;
            }
        }
    }
    return max;
}
