#include <map>
#include <vector>

using namespace std;

class recursiveSolver
{
    public:
        recursiveSolver(map<int, int>& setsIn, int goalSizeIn);
        bool recursiveSolve();
        vector<int> getSetIDs();
    private:
        map<int, int> sets;
        map<int, int>::iterator iter;
        vector<int> setIDs;
        int runningSize;
        int goalSize;
};
