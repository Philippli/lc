int rotateSearch(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
        int mid = ((r - l) >> 1) + l;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[l] <= nums[r]) {
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } else {
            if (nums[l] <= target) {
                if (nums[mid] <= nums[r]) {
                    r = mid - 1;
                } else if (nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (nums[mid] >= nums[l]) {
                    l = mid + 1;
                } else if (nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
    }

    return -1;
}
