class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        vector<int> result(N);
        bool skip = false;
        int indexInDeck = 0;
        int indexInResult = 0;

        sort(deck.begin(), deck.end());

        while (indexInDeck < N) {
            if (result[indexInResult] == 0) {
                if (!skip) {
                    result[indexInResult] = deck[indexInDeck];
                    indexInDeck++;
                }
                skip = !skip;
            }
            indexInResult = (indexInResult + 1) % N;
        }
        return result;
    }
};