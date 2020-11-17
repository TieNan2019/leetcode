class KthLargest {
public:
        /* 堆 */
        vector<int> seq;
        /* 堆的大小 */
        int K;
        /* 指向堆尾 */
        int tail;
        KthLargest(int k, vector<int>& nums) {
                K = k;

                sort(nums.begin(), nums.end(), greater<int>());

                /* 哨兵 + k 个最大元素 + 1个空位用来插入新元素 */
                seq.resize(1 + K + 1);
                seq[0] = INT_MIN;
                
                /* 提取有效长度的最大值，只能是 K 或者 数组长度 的较小值 */
                int eff = K < nums.size() ? K : nums.size();

                /* 复制到小顶堆中 */
                for (int i = 0; i < eff; i++)
                        seq[i+1] = nums[i];

                /* 生成堆结构 */
                for (int node = eff / 2; node > 0; node--) {
                        int child;
                        for (int parent = node; parent * 2 <= eff; parent = child) {
                                child = parent * 2;

                                // 如果存在兄弟节点，则挑选出二者较小者
                                if (child + 1 <= eff && seq[child] > seq[child+1])
                                        child++;

                                if (seq[parent] >= seq[child]) {
                                        int tmp = seq[parent];
                                        seq[parent] = seq[child];
                                        seq[child] = tmp;
                                }
                        }
                }
                tail = eff;
        }


        int add(int val) {
                /* 如果堆已满，且新堆值小于堆顶，则直接返回堆顶 */
                if (tail == K && seq[1] >= val)
                        return seq[1];

                /* 如果元素大于堆顶，且堆已满，则将顶部元素移除 */
                if (tail == K) {
                        // 删除堆顶
                        seq[1] = seq[tail];
                        tail--;

                        int child;
                        for (int parent = 1; parent * 2 <= tail; parent = child) {
                                child = parent * 2;
                                if (child != tail && seq[child] > seq[child+1])
                                        child++;

                                if (seq[parent] > seq[child]) {
                                        int tmp = seq[child];
                                        seq[child] = seq[parent];
                                        seq[parent] = tmp;
                                }
                        }
                }

                /* 插入新值 */
                tail++;
                seq[tail] = val;
                for (int node = tail; seq[node] < seq[node/2]; node /= 2) {
                        int tmp = seq[node];
                        seq[node] = seq[node/2];
                        seq[node/2] = tmp;
                }
                           
                tail = tail <= K ? tail : K;
     
                return seq[1];
        }
};
