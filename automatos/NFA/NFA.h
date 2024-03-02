#ifndef NFA_H
#define NFA_H

#include<unordered_set>
#include<unordered_map>
#include<string>

using namespace std;

class NFA {
    public:
    NFA(
        unordered_set<string> states,
        unordered_set<char> alphabet,
        unordered_map<string, unordered_map<char, unordered_set<string>>> transictionFunction,
        string initial_state,
        unordered_set<string> final_states
    );

    bool isAcepted(string chain);
    bool isRegexAcepted(string regex);

    unordered_set<string> states;
    unordered_set<char> alphabet;
    unordered_map<string, unordered_map<char, unordered_set<string>>> transictionFunction;
    string initial_state;
    unordered_set<string> final_states;
};

#endif