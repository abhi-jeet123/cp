 //Find the town judge problem

//  In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.


//Approach: we can simply find the incoming and out going edge of the nodes,since graph
// given is directed,and will check if there exit a node with indegree equals to 
// n-1 then we can say that this is the town judge and every person except him 
//trust him.else return -1.

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> indegree;
        for(auto edge:trust){
            indegree[edge[0]]--;
            indegree[edge[1]]++;
        }
        for(int i=1;i<=n;++i){
            if(indegree[i]==n-1)return i;
        }
        return -1;

        
    }
};