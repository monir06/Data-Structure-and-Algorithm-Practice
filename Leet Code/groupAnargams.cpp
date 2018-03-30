vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string , vector<string> > u;
    
    for(int i=0;i<strs.size();i++)
    {
        string a=strs[i];
        sort(a.begin(),a.end());
        u[a].push_back(strs[i]);
    }
    vector<vector<string> > v;
    unordered_map<string , vector<string> >:: iterator itr;
    
    for(itr=u.begin();itr!=u.end();itr++)
    {
        v.push_back((*itr).second);
    }
    return v;
        
    
}