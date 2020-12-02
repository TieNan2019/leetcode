class Solution {
public:
        bool lemonadeChange(vector<int>& bills) {
                int keep[21] = { 0 };

                for (int cash : bills) {
                        // cout << cash << endl;
                        keep[cash]++;

                        switch (cash) {
                                case 20:
                                        if (keep[10] > 0 && keep[5] > 0) {
                                                keep[10]--, keep[5]--;
                                        }
                                        else if (keep[5] >= 3) {
                                                keep[5] -= 3;
                                        }
                                        else {
                                                // cout << keep[10] << " : " << keep[5] << endl;
                                                return false;
                                        }
                                        break;

                                case 10:
                                        if (keep[5] > 0) {
                                                keep[5]--;
                                        }
                                        else {
                                                return false;
                                        }
                                        break;

                                case 5:
                                        break;
                                default:
                                        break;
                        }


                }

                return true;
        }
};
