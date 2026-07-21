class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalgas=0;
    int totalcost=0;
    int n=gas.size();
    int tank=0;
    int size=0;
    for(int i=0;i<n;i++){
      totalgas+=gas[i];
      totalcost+=cost[i];
      tank+=gas[i] -cost[i];

      if(tank<0){
        size=i+1;
        tank=0;
      }
    }
        if(totalgas<totalcost) return -1;

        return size;

    }
};