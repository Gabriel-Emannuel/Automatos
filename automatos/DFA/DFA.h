#ifndef DFA_H
#define DFA_h

#include<unordered_set>
#include<unordered_map>
#include<string>

using namespace std;

class DFA {
    public:
    DFA(
        unordered_set<string> states,
        unordered_set<char> alphabet,
        unordered_map<string, unordered_map<char, string>> transictionFunction,
        string initial_state,
        unordered_set<string> final_states
    );

    bool isAcepted(string chain);
    bool isRegexAcepted(string regex);

    unordered_set<string> states;
    unordered_set<char> alphabet;
    unordered_map<string, unordered_map<char, string>> transictionFunction;
    string initial_state;
    unordered_set<string> final_states;
};

#endif