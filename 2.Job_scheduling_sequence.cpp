//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    private:
    bool static comparison(Job a, Job b){
        return (a.profit > b.profit);
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        //sort the array according to profit
        sort(arr, arr+n, comparison);
        //get the max-deadline
        int maxi=arr[0].dead;
        for(int i=0;i<n;i++){
            maxi = max(maxi, arr[i].dead);
        }
        //create an raay of slots[deadline+1]
        int slots[maxi+1];
        
        //initial all with -1
        for(int i=0;i<=maxi;i++){
            slots[i]=-1;
        }
        //create count_jobs & job_profit variable
        int count_jobs = 0, job_profit = 0;
        //traverse and check for the slots[deadline]
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead ; j>0 ;j--){
                if(slots[j]==-1){
                    slots[j]=i;
                    count_jobs++;
                    job_profit += arr[i].profit;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(count_jobs);
        ans.push_back(job_profit);
        return ans;
        //if found then, place it in the slot.
        //count the jobs
        //increase the job profit
        //return the pairs
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
