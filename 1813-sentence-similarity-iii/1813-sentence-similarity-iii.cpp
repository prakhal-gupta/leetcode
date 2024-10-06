class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        istringstream iss1(s1);
        vector<string> vec1((istream_iterator<string>{iss1}), istream_iterator<string>());
        istringstream iss2(s2);
        vector<string> vec2((istream_iterator<string>{iss2}), istream_iterator<string>());
        while (!vec1.empty() && !vec2.empty() && vec1.front() == vec2.front()) {
            vec1.erase(vec1.begin());
            vec2.erase(vec2.begin());
        }
        while (!vec1.empty() && !vec2.empty() && vec1.back() == vec2.back()) {
            vec1.pop_back();
            vec2.pop_back();
        }
        return vec1.empty() || vec2.empty();
    }
};