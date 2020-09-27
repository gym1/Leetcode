
class solution
{
    public:
    int firstUniqChar(string s) 
    {
        // create a set for 26 letters
        int letter_count[26] = {0};
        for (int i = 0; s[i] != '\0'; i++)
        {
            // read all letter from that string into hash
            letter_count[s[i] - 'a']++;
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            // check the letter count
            if (letter_count[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
     }
};
        
