class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;  // To track the position to insert the compressed characters

        for (int i = 0; i < n; ) {
            char currentChar = chars[i];
            int count = 0;

            // Count the occurrences of the current character
            while (i < n && chars[i] == currentChar) {
                i++;
                count++;
            }

            // Place the character in the array
            chars[index++] = currentChar;

            // If the count is more than 1, add the digits to the array
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[index++] = c;
                }
            }
        }

        return index;  // The new length of the compressed array
    }
};
