class Solution {
public:
        vector<int> fraction(vector<int>& cont) {
                int parent = 1, child = 0;

                for (int i = cont.size() - 1; i >=0; i--) {
                        child = cont[i] * parent + child;
                        parent = parent;

                        if (i) {
                                int tmp = parent;
                                parent = child;
                                child = tmp;
                        }
                }

                return {child, parent};
        }
};
