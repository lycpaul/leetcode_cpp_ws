#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool areSentencesSimilar(vector<string> &sentence1,
                             vector<string> &sentence2,
                             vector<vector<string>> &similarPairs)
    {
        // not the same size
        if (sentence1.size() != sentence2.size())
            return false;

        // build the hashmap for storing similar pairs
        std::unordered_map<string, set<string>> hash;
        hash.reserve(similarPairs.size());
        for (const auto &p : similarPairs) {
            hash[p[0]].emplace(p[1]);
        }

        for (int i = 0; i < sentence1.size(); ++i) {
            if (sentence1[i] == sentence2[i])
                continue;
            // normalize strings
            std::transform(sentence1[i].begin(),
                           sentence1[i].end(),
                           sentence1[i].begin(),
                           ::tolower);
            std::transform(sentence2[i].begin(),
                           sentence2[i].end(),
                           sentence2[i].begin(),
                           ::tolower);

            const auto itr1 = hash.find(sentence1[i]);
            const auto itr2 = hash.find(sentence2[i]);
            const bool matchedPair = (itr1 != hash.end() and itr1->second.contains(sentence2[i]))
                                     or (itr2 != hash.end() and itr2->second.contains(sentence1[i]));
            if (!matchedPair or itr1 == hash.end() and itr2 == hash.end())
                return false;
        }
        return true;
    }
};

int main()
{
    vector<string> s1{"this",      "summer", "thomas",  "get",    "actually", "actually",
                      "rich",      "and",    "possess", "the",    "actually", "great",
                      "and",       "fine",   "vehicle", "every",  "morning",  "he",
                      "drives",    "one",    "nice",    "car",    "around",   "one",
                      "great",     "city",   "to",      "have",   "single",   "super",
                      "excellent", "super",  "as",      "his",    "brunch",   "but",
                      "he",        "only",   "eat",     "single", "few",      "fine",
                      "food",      "as",     "some",    "fruits", "he",       "wants",
                      "to",        "eat",    "an",      "unique", "and",      "actually",
                      "healthy",   "life"};
    vector<string> s2{"this",      "summer", "thomas",  "get",   "very",      "very",
                      "rich",      "and",    "possess", "the",   "very",      "fine",
                      "and",       "well",   "car",     "every", "morning",   "he",
                      "drives",    "a",      "fine",    "car",   "around",    "unique",
                      "great",     "city",   "to",      "take",  "any",       "really",
                      "wonderful", "fruits", "as",      "his",   "breakfast", "but",
                      "he",        "only",   "drink",   "an",    "few",       "excellent",
                      "breakfast", "as",     "a",       "super", "he",        "wants",
                      "to",        "drink",  "the",     "some",  "and",       "extremely",
                      "healthy",   "life"};
    vector<vector<string>> sp{{"good", "nice"},
                              {"good", "excellent"},
                              {"good", "well"},
                              {"good", "great"},
                              {"fine", "nice"},
                              {"fine", "excellent"},
                              {"fine", "well"},
                              {"fine", "great"},
                              {"wonderful", "nice"},
                              {"wonderful", "excellent"},
                              {"wonderful", "well"},
                              {"wonderful", "great"},
                              {"extraordinary", "nice"},
                              {"extraordinary", "excellent"},
                              {"extraordinary", "well"},
                              {"extraordinary", "great"},
                              {"one", "a"},
                              {"one", "an"},
                              {"one", "unique"},
                              {"one", "any"},
                              {"single", "a"},
                              {"single", "an"},
                              {"single", "unique"},
                              {"single", "any"},
                              {"the", "a"},
                              {"the", "an"},
                              {"the", "unique"},
                              {"the", "any"},
                              {"some", "a"},
                              {"some", "an"},
                              {"some", "unique"},
                              {"some", "any"},
                              {"car", "vehicle"},
                              {"car", "automobile"},
                              {"car", "truck"},
                              {"auto", "vehicle"},
                              {"auto", "automobile"},
                              {"auto", "truck"},
                              {"wagon", "vehicle"},
                              {"wagon", "automobile"},
                              {"wagon", "truck"},
                              {"have", "take"},
                              {"have", "drink"},
                              {"eat", "take"},
                              {"eat", "drink"},
                              {"entertain", "take"},
                              {"entertain", "drink"},
                              {"meal", "lunch"},
                              {"meal", "dinner"},
                              {"meal", "breakfast"},
                              {"meal", "fruits"},
                              {"super", "lunch"},
                              {"super", "dinner"},
                              {"super", "breakfast"},
                              {"super", "fruits"},
                              {"food", "lunch"},
                              {"food", "dinner"},
                              {"food", "breakfast"},
                              {"food", "fruits"},
                              {"brunch", "lunch"},
                              {"brunch", "dinner"},
                              {"brunch", "breakfast"},
                              {"brunch", "fruits"},
                              {"own", "have"},
                              {"own", "possess"},
                              {"keep", "have"},
                              {"keep", "possess"},
                              {"very", "super"},
                              {"very", "actually"},
                              {"really", "super"},
                              {"really", "actually"},
                              {"extremely", "super"},
                              {"extremely", "actually"}};

    Solution sol;
    cout << sol.areSentencesSimilar(s1, s2, sp) << endl;
}