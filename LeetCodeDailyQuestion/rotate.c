
/*

    189. 轮转数组
    给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数

*/
void reverse(int *nums, int left, int right)
{
    while(left < right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    k %= numsSize;
    //先反转整个数组
    reverse(nums, 0, numsSize-1);

    //在反转前K个元素
    reverse(nums, 0, k - 1);

    //最后反转后面于元素
    reverse(nums, k, numsSize - 1);
}