class Solution {
public:
        void depthFirstSearch(int src, set<int> &toDel, map<int, set<int>> &adjacency, bool *used) {
                for (int to : adjacency[src]) {
                        if (used[to])
                                continue;
                        
                        used[to] = true;
                        toDel.insert(to);
                        depthFirstSearch(to, toDel, adjacency, used);
                        // used[to] = false;
                }
        }

        int findCircleNum(vector<vector<int>>& isConnected) {
                bool *used = new bool[isConnected.size()];
                for (int i = 0; i < isConnected.size(); i++)
                        used[i] = false;

                set<int> nodes;
                for (int i = 0; i < isConnected.size(); i++)
                        nodes.insert(i);

                map<int, set<int>> adjacency;
                for (int i = 0; i < isConnected.size(); i++)
                        for (int j = 0; j < isConnected.size(); j++)
                                if (isConnected[i][j])
                                        adjacency[i].insert(j);

                int group = 0;
                while (!nodes.empty()) {
                        int src = *(nodes.begin());

                        used[src] = true;
                        set<int> toDel{ src };
                        depthFirstSearch(src, toDel, adjacency, used);

                        // used[src] = false;

                        for (int del : toDel)
                                nodes.erase(del);

                        group++;
                }


                delete[] used;

                return group;
        }
};
