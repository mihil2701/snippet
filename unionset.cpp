<snippet>
	<content><![CDATA[
bool compareInterval(pair<ll int,ll int> i1, pair<ll int,ll int> i2) 
{ 
    return (i1.first < i2.first); 
}
vector <pair<ll int,ll int>> umerg(vector <pair<ll int,ll int>> s2,vector <pair<ll int,ll int>> s3)
{
	vector <pair<ll int,ll int>> merged;
	ll int i=0;
	ll int j=0;
	while(i<s2.size() and j<s3.size())
	{
		if (compareInterval(s2[i],s3[j]))
			{merged.push_back({s2[i].first,s2[i].second});i++;continue;}
		else
			{merged.push_back({s3[j].first,s3[j].second});j++;continue;}
	}
	while(i<s2.size())
	{
		merged.push_back({s2[i].first,s2[i].second});i++;continue;
	}
	while(j<s3.size())
	{
		merged.push_back({s3[j].first,s3[j].second});j++;continue;
	}
    stack <pair<ll int,ll int>> s; 
    s.push(merged[0]);
    ll int n=merged.size(); 
    for (ll int i = 1 ; i < n; i++) 
    { 
        pair <ll int,ll int> top = s.top(); 
        if (top.second < merged[i].first) 
            s.push(merged[i]);  
        else if (top.second < merged[i].second) 
        { 
            top.second= merged[i].second; 
            s.pop(); 
            s.push(top); 
        } 
    } 
    vector <pair<ll int,ll int>> ans;   
    while (!s.empty()) 
    { 
    	pair <ll int,ll int> top = s.top();
        ans.push_back({top.first,top.second});
        s.pop(); 
    }
    sort (ans.begin(),ans.end());
    return ans;
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>unionset</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>
