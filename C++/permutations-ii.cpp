// Time:  O(n * n!)
// Space: O(n)

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        vector<vector<int>> result;
        deque<bool> used(nums.size(), false);
        vector<int> ans;

        sort(nums.begin(), nums.end());
        permutations_unique_helper(nums, &used, &ans, &result);
        return result;
    }

    void permutations_unique_helper(const vector<int> &A, deque<bool> *used,
                                    vector<int> *ans, vector<vector<int> > *result) {
        if (ans->size() == A.size()) {
            result->emplace_back(*ans);
            return;
        }

        for (size_t i = 0; i < A.size(); ++i) {
            if ((*used)[i] || (i != 0 && A[i - 1] == A[i] && (*used)[i - 1])) {
                continue;
            }

            (*used)[i] = true;
            ans->emplace_back(A[i]);
            permutations_unique_helper(A, used, ans, result);
            ans->pop_back();
            (*used)[i] = false;
        }
    }
};
