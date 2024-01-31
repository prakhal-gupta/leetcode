class Solution {
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
   {
    stack<pair<int,int>>st; 
    vector<int>ans(temperatures.size(),0);

          for(int i=temperatures.size()-1;i>=0;i--)
          {
       
           while(st.size()>0 && st.top().first<=temperatures[i]) 
            {   
                st.pop();
            }

            if(st.size()!=0) 
            ans[i] = (st.top().second-i); 
        
            st.push({temperatures[i],i}); 
            }
            return ans;
        }
  };