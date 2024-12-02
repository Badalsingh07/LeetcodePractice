class Solution {
public:
    int isPrefixOfWord(string sentence, string search) {
        if(sentence.substr(0,search.length())==search)
        {
            return 1;
        }
        int count=0;
        for(int i=0;i<sentence.length();i++)
        {
            if(sentence[i]==' ')
            {
                count++;
                string str=sentence.substr(i+1,search.length());
                if(str==search)
                {
                    return count+1;
                }
            }
            
        }
        return -1;
    }
};