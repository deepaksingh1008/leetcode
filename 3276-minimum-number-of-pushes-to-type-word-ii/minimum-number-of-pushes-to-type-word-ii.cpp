class Solution {
public:
    int minimumPushes(string word) {
      vector<int> map(26,0);
      for(int i=0;i<word.length();i++){
           map[word[i]-'a']++;
      }
        sort(map.begin(),map.end(),greater<int>());
        int ans = 0;
      for(int i=0;i<26;i++){
           int freq = map[i];
          int press = i/8 + 1;
          ans+= press*freq;
      }
        return ans;
    }
};