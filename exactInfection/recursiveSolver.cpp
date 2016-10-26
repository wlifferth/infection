#include <map>
#include <vector>
#include <cstdio>


#include "recursiveSolver.h"
        
recursiveSolver::recursiveSolver(map<int, int>& setsIn, int goalSizeIn)
{
    sets = setsIn;
    runningSize = 0;
    goalSize = goalSizeIn;
    iter = sets.begin();
    return;
}

bool recursiveSolver::recursiveSolve()
{
    // If this is the end, we return one way or another
    if(iter == sets.end()) return false;
    // Lets say this thing IS included
    setIDs.push_back(iter->first);
    runningSize += iter->second;
    if(runningSize == goalSize) return true;
    
    // On the next go around we want to evaluate the next entry
    iter++;
    // If there is a solution that includes this set, return true (preserving it's place in the stack)
    if(recursiveSolve()) return true;
    // Otherwise, no solution set exists with this set in it so we can remove it from the stack an running total
    iter--;
    setIDs.pop_back();
    runningSize -= iter->second;
    // BUT there might be a solution that does not include this one
    iter++;
    if(recursiveSolve()) return true;
    iter--;
    return false;
}

vector<int> recursiveSolver::getSetIDs()
{
    return setIDs;
}
