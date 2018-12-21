class Solution {
public:
    
        size_t findlastpos(char c,string S)
    {
        int pos = 0;
        for(int i = 0 ; i < S.length();i++)
        {
            if(S[i] == c)
            {
                pos = i;
            }
        }
        return pos;
    }
    
    vector<int> partitionLabels(string S)
    {
        vector<int> ans;
        for(int i=0;i<S.length();)
        {
            char t = S[i];
            size_t anchor_first = findlastpos(t,S);
            int num = 1;
            for(int j = i+1;j<=anchor_first;j++)
            {
                size_t anchor_next = findlastpos(S[j],S);
                if(anchor_next > anchor_first)
                {
                    anchor_first = anchor_next;
                }
                num++;
            }
            ans.push_back(num);
            
            i=anchor_first + 1;
        }
        
        return ans;
    }
    
};