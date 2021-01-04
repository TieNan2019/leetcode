/* 每个议员投票的最优解为 : ban 掉对方即将投票议员的投票权，这样就可以保证己方的议员可以尽可能多的保留自己的权力 */

class Solution {
public:
        string predictPartyVictory(string senate) {
		/* 分别为两个对立阵营维护队列，顺序即为投票顺序 */
                queue<int> rCnt, dCnt;

                for (int i = 0; i < senate.size(); i++)
                        switch (senate[i]) {
                                case 'R':
                                        rCnt.push(i);
                                        break;
                                case 'D':
                                        dCnt.push(i);
                                        break;
                                default:
                                        break;
                        }


                int len = senate.size();
		
		/* 理论上应该投票的人 */
                int voter = 0;
                while (!rCnt.empty() && !dCnt.empty()) {
			/* 轮到 Radiant 投票 */
                        if (rCnt.front() == voter) {
                                // cout << voter << " --  Radiant votes : ban -- " << dCnt.front() << endl;

				/* 投票结束后重新进入队尾 */
                                rCnt.pop();
                                rCnt.push(voter);

				/* ban 掉即将投票的对方议员 */
                                dCnt.pop();
                        }
			/* 轮到 Dire 投票 */
                        else if (dCnt.front() == voter) {
                                // cout << voter << " --  Dire votes : ban -- " << rCnt.front() << endl;

				/* 投票结束后重新进入队尾 */
                                dCnt.pop();
                                dCnt.push(voter);

				/* ban 掉即将投票的对方议员 */
                                rCnt.pop();
                        }

                        voter++;
			/* 模拟，可能要持续多轮 */
                        if (voter >= len)
                                voter = 0;
                }

                // cout << "Dire Left : " << dCnt.size() << endl;
                // cout << "Radiant Left : " << rCnt.size() << endl;

		/* 全部失去权力的一方失败 */
                return rCnt.empty() ? "Dire" : "Radiant";
        }
};
