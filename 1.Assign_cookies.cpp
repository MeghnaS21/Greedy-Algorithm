class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        int num_children = g.size(); // Number of children
        int num_cookies = s.size();  // Number of cookies

        int cookie_index = 0, child_index = 0; // Indices for cookies and children
        std::sort(g.begin(), g.end());  // Sort the greed factor of children
        std::sort(s.begin(), s.end());  // Sort the size of cookies

        // Iterate through cookies and children
        while (cookie_index < num_cookies && child_index < num_children) {
            if (s[cookie_index] >= g[child_index]) {
                // Cookie can satisfy the child's greed
                child_index++;  // Move to the next child
            }
            cookie_index++;  // Move to the next cookie
        }

        // Return the number of satisfied children
        return child_index;
    }
};

