vector<int> Solution::solve(int people, int n, vector<int> &arr) {
    int max_ans=0,min_ans=0,temp,i;
    priority_queue<int,vector<int>,greater<int> > pmin;
    priority_queue<int> pmax;
    for(i=0;i<n;i++){
        pmin.push(arr[i]);
        pmax.push(arr[i]);
    }
    int k=people;
    while(k--){
        temp=pmin.top();
        min_ans+=temp;
        pmin.pop();
        if(temp>1)
            pmin.push(temp-1);
    }
    k=people;
    while(k--){
        temp=pmax.top();
        max_ans+=temp;
        pmax.pop();
        if(temp>1)
            pmax.push(temp-1);
    }
    vector<int> ans;
    ans.push_back(max_ans);
    ans.push_back(min_ans);
    return ans;
}
