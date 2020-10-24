#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;


class Dict {
public:
        int len()
        {
                return _keys.size();
        }

        string & operator[] (string key)
        {
                auto it = find (_keys.begin(), _keys.end(), key);

                if (it != _keys.end())
                        return _values[it-_keys.begin()];
                else {
                        _keys.push_back(key);
                        _values.push_back("");
                        return _values.back();
                }
        }

        vector<string> keys() {
                return _keys;
        }

        vector<string> values() {
                return _values;
        }

        vector<vector<string>> items() {
                vector<vector<string>> res;
                for (int i = 0; i < _keys.size(); i++) {
                        res.push_back(vector<string>({_keys[i], _values[i]}));
                }

                return res;
        }

private:
        vector<string> _keys;
        vector<string> _values;
};


int main(void)
{
        Dict d;
        d["Hello"] = "World";
        d["han"] = "xiao";

        cout << d["Hello"] << endl;
        cout << d["han"] << endl;

        double x = 3.14159;
        x++;
        cout << x << endl;

        return 0;
}
