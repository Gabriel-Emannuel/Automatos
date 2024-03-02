#include "NFA.h"

#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

NFA::NFA(unordered_set<string> states,
        unordered_set<char> alphabet,
        unordered_map<string, unordered_map<char, unordered_set<string>>> transictionFunction,
        string initial_state,
        unordered_set<string> final_states) {
            this->states = states;
            this->alphabet = alphabet;
            this->transictionFunction = transictionFunction;
            this->initial_state = initial_state;
            this->final_states = final_states;
};

bool isChainValid(string chain, unordered_set<char> alphabet) {
    int size = chain.size();
    
    for (int i = 0; i < size; i++) {
        if (alphabet.find(chain.at(i)) == alphabet.end()) {
            return false;
        }
    }
    return true;
};

bool NFA::isAcepted(string chain) {
    bool isChainInvalid = isChainValid(chain, this->alphabet);

    
}