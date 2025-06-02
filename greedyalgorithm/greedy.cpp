#include <iostream>
#include <vector>
#include <pair>
using namespace std;

// Activity Selection

int activityselection(vector<int> &start, vector<int> &end){

    int n = start.size();

    // step1 : store activities as pair of (end, start)
    vector<pair<int, int>> activities;
    for(int i = 0; i<n ; i++){
        activities.push_back({end[i], start[i]});
    }
    // we use pair to sort because we need to map the start and end array or club two different operations
    sort(activities.begin(), activities.end());

    int cnt = 1;
    int currend = activites[0].first;

    for(int i = 1; i<n ; i++){
        if(activities[i].second >= currend){
            cnt++;
            currend = activities[i].first;
        }
    }

    return cnt;

    

}

// Fractional Knapsack
int fractionalKnapsack(vector<int> &weight, vector<int> &value, int W){
    int n = weight.size();
    vector<pair<double, double>> pr;
    for(int i = 0; i<n ; i++){
        pr.push_back({(double)value[i]/weight[i], i});
    }

    double price = 0;
    sort(pr.begin(), pr.end());
    for(int i= n-1; i>=0; i++){
        if(W == 0) return price;

        if(W < weight[pr[i].second]){
            price += (W* pr[i].first);
            W = 0;
        }
        else{
            price += (weight[pr[i].second] * pr[i].first);
            W -= weight[pr[i].second];
        }

        
    }

    return price;
}

// Minimum absolute difference

int absdiff(vector<int> &a, vector<int> &b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int absDiff = 0;

    for(int i = 0 ; i<a.size(); i++){
        absDiff += abs(a[i] - b[i]);

    }

    return absDiff ;
}

// Maximum Length chain pairs
bool compare(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
    
}

int maxchainlen(vector<pair<int,int>> &b){

    sort(b.begin(), b.end(), compare); // note the comparing function should not have paranthesis
    int chainlen = 1;
    int currend = b[0].second;

    for(int i = 1; i<b.size(); i++){
        if(b[i].first >= currend){
            currend = b[i].second;
            chainlen++;

        }

    }

    return chainlen;
} 


// Indian coins - they are canonical
int Indiancoins(vector<int> &coins, int v){
    sort(coins.beign(), coins.end());
    int ans = 0;
    int n = coins.size();
    for(int i = n - 1; i>= 0 && v>0 ; i++){
        
        if(v >= coins[i]){
        ans += v/coins[i];
        v = v%coins[i];
        }
    }

    return ans;
}

// Job sequencing problem

bool compare2(pair<int, int> &a, pair<int, int> &b ){
    return a.second > b.second; // Sort by profit descending
}

int jobsequencing(vector<pair<int, int>> &jobs){
    sort(jobs.begin(), jobs.end(), compare2); // Step 1: sort by profit

    // Step 2: Find the maximum deadline
    int maxDeadline = 0;
    for(auto &job : jobs){
        maxDeadline = max(maxDeadline, job.first);
    }

    // Step 3: Create a slot array to mark occupied time slots
    vector<bool> slot(maxDeadline + 1, false); // index 1 to maxDeadline
    int profit = 0;

    // Step 4: Try to place each job in the latest available slot <= deadline
    for(auto &job : jobs){
        int deadline = job.first;
        int value = job.second;

        for(int t = deadline; t >= 1; t--){
            if(!slot[t]){ // if time slot is free
                slot[t] = true;
                profit += value;
                break;
            }
        }
    }

    return profit;
}




int main(){
    int n = 5;
    vector<pair<int, int>> pairs(n, make_pair(0,0));

    pairs[0] = make_pair(5, 24);
    pairs[1] = make_pair(39, 60)
} 