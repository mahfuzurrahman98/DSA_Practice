class Solution {
public:
  void dfs(string digits, map<char, string> letters, vector<string>& ans, string curStr, int curIndex) {
    if (curIndex == digits.size()) { // if current index get same size as digits
      ans.push_back(curStr); // we get the leaf nodes to insert into the ansewr
      return; // no more calls, just return
    }
    
    char curDigit = digits[curIndex]; // find the current digit
    string curLetters = letters[curDigit]; // find the current letters
            
    for (int i = 0; i < curLetters.size(); i++) { // loop through all the letters
      char letter = curLetters[i];
      dfs(digits, letters, ans, curStr + letter, curIndex + 1); // call next step with (adding current
                                                                // letter and next index of the digits)
    }
  }
  
  vector<string> letterCombinations(string digits) {
    map<char, string> letters;
    vector<string> ans;
    
    if (digits == "") {
      return ans;
    }
    
    letters['2'] = "abc", letters['3'] = "def";
    letters['4'] = "ghi", letters['5'] = "jkl";
    letters['6'] = "mno", letters['7'] = "pqrs";
    letters['8'] = "tuv", letters['9'] = "wxyz";
    
    dfs(digits, letters, ans, "", 0);
    
    return ans;
  }
};
