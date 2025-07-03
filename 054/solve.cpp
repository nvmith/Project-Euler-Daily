#include <bits/stdc++.h>

using namespace std;

map<char, int> rankMap = 
{
    {'2', 2}, 
    {'3', 3}, 
    {'4', 4}, 
    {'5', 5},
    {'6', 6}, 
    {'7', 7}, 
    {'8', 8}, 
    {'9', 9},
    {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}
};

struct Hand
{
    vector<int> ranks;
    vector<char> suits;
    map<int, int> count;

    void parse(vector<string> cards)
    {
        ranks.clear();
        suits.clear();
        count.clear();

        for (int i = 0; i < cards.size(); i++)
        {
            string card = cards[i];
            int r = rankMap[card[0]];
            char s = card[1];
            ranks.push_back(r);
            suits.push_back(s);
            count[r]++;
        }

        sort(ranks.rbegin(), ranks.rend());
    }

    bool isFlush()
    {
        for (int i = 1; i < suits.size(); i++)
            if (suits[i] != suits[0]) return false;
        return true;
    }

    bool isStraight()
    {
        vector<int> r = ranks;
        sort(r.begin(), r.end());
        if (r == vector<int>{2, 3, 4, 5, 14}) return true;

        for (int i = 1; i < 5; i++)
            if (r[i] != r[i - 1] + 1) return false;
        return true;
    }

    pair<int, vector<int> > getRank()
    {
        bool flush = isFlush();
        bool straight = isStraight();
        
        //Royal Flush
        if (straight && flush && find(ranks.begin(), ranks.end(), 14) != ranks.end() && find(ranks.begin(), ranks.end(), 10) != ranks.end())
            return make_pair(10, vector<int>());
            
        //Straight Flush
        if (straight && flush)
            return make_pair(9, vector<int>(1, ranks[0]));

        //Four of a Kind
        map<int, int>::iterator it;
        for (it = count.begin(); it != count.end(); it++)
        {
            int val = it->first;
            int cnt = it->second;
            if (cnt == 4)
            {
                vector<int> kicker;
                for (int i = 0; i < ranks.size(); i++)
                    if (ranks[i] != val) kicker.push_back(ranks[i]);
                return make_pair(8, vector<int>{val, kicker[0]});
            }
        }
        
        //Full House
        int three = -1;
        vector<int> pairs;

        for (it = count.begin(); it != count.end(); ++it)
        {
            int val = it->first;
            int cnt = it->second;
            if (cnt == 3) three = val;
            else if (cnt == 2) pairs.push_back(val);
        }

        if (three != -1 && pairs.size() > 0)
        {
            int bestPair = pairs[0];
            for (int i = 1; i < pairs.size(); i++)
                if (pairs[i] > bestPair) bestPair = pairs[i];
            return make_pair(7, vector<int>{three, bestPair});
        }
        
        //Flush
        if (flush) return make_pair(6, ranks);
        //Straight
        if (straight) return make_pair(5, vector<int>{ranks[0]});
        //Three of a Kind
        if (three != -1) return make_pair(4, vector<int>{three});
        
        //Two Pairs
        if (pairs.size() == 2)
        {
            sort(pairs.begin(), pairs.end());
            reverse(pairs.begin(), pairs.end());
            vector<int> result = pairs;
            for (int i = 0; i < ranks.size(); i++)
            {
                if (ranks[i] != pairs[0] && ranks[i] != pairs[1])
                {
                    result.push_back(ranks[i]);
                    break;
                }
            }
            return make_pair(3, result);
        }
        
        //One Pair
        if (pairs.size() == 1)
        {
            int p = pairs[0];
            vector<int> kicker;
            for (int i = 0; i < ranks.size(); i++)
                if (ranks[i] != p) kicker.push_back(ranks[i]);
            return make_pair(2, vector<int>{p, kicker[0], kicker[1], kicker[2]});
        }
        
        //High Card
        return make_pair(1, ranks);
    }
};

bool player1Wins(vector<string> cards)
{
    vector<string> p1(cards.begin(), cards.begin() + 5);
    vector<string> p2(cards.begin() + 5, cards.end());

    Hand h1, h2;
    h1.parse(p1);
    h2.parse(p2);

    auto r1 = h1.getRank();
    auto r2 = h2.getRank();

    if (r1.first != r2.first)
        return r1.first > r2.first;
    return r1.second > r2.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int winCount = 0;
    string card;
    vector<string> cards;

    while (cin >> card)
    {
        cards.push_back(card);
        if (cards.size() == 10)
        {
            if (player1Wins(cards)) winCount++;
            cards.clear();
        }
    }

    cout << winCount;
}
