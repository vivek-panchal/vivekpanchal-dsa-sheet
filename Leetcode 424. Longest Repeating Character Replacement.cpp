class Solution {
public:
    int characterReplacement(string s, int k) {
        // We maintain a map for counting the
        // occurance of the alphabet
        unordered_map<char, int> map;
        int left = 0;
        int right = 0;
        int result = 1;
        while(right < s.size()) {
            // Increase value for letter
            map[s[right]]++;
            
            // Length of our substring
            int length = right - left + 1;
            
            // Among all the letters find the most
            // frequent letter in our map
            int frequent;
            for(auto it = map.begin(); it != map.end(); it++)
                frequent = max(frequent, it->second);
            
            // If in our substring after subtracting the
            // most occuring alphabet from length we have a letter with
            // occurance less then K that means we can replace it
            if(length-frequent <= k) {
                result = max(result, length);
            }
            // else we increase our left pointer and remove
            // the count of pointer previously present at left
            else {
                map[s[left]]--;
                left++;
            }
			// Right pointer increases anyway
            right++;
        }
        return result;
    }
};
