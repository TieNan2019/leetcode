/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
        int recursion(const vector<Employee*> &emps, map<int, int> &namelist, int id) {
                Employee *worker = emps[namelist[id]];

                if (worker->subordinates.empty())
                        return worker->importance;

                int sum = worker->importance;
                for (int x : worker->subordinates) {
                        sum += recursion(emps, namelist, x);
                }

                return sum;
        }

        int getImportance(vector<Employee*> employees, int id) {
                map<int, int> namelist;

                for (int index = 0; index < employees.size(); index++)
                        namelist[employees[index]->id] = index;

                return recursion(employees, namelist, id);
        }
};
