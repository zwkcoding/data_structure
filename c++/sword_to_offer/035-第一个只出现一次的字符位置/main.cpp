class Solution {
protected:
    int count[256];
public:
    int FirstNotRepeatingChar(string str) {
        memset(count, '\0', sizeof(count));
        if(str.size() == 0)  return  -1;
        for(int i = 0; i < str.size(); i++)  {
            count[(unsigned int)str[i]]++;
        }
        for(int i = 0 ; i < str.size() ; i++)  {
            if(count[(unsigned int)str[i]] == 1)  {
                return i;
            }
        }
        return -1;
        
    }
};
