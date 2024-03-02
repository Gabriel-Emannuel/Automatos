#include "DFA.h"

#include <stdexcept>

bool isTransictionFuncionValid(
    unordered_map<string, unordered_map<char, string>> transictionFunction,
    unordered_set<string> states,
    unordered_set<char> alphabet) {
        
        char characterAt;
        string stateAt;
        
        unordered_map<char, string> transictionFunctionAt;

        bool isStateInvalid, isCharacterInvalid;

        for (const auto& statesAt: states) {
            isStateInvalid = transictionFunction.find(stateAt) == transictionFunction.end();
            if (isStateInvalid) return false;
        }

        for (const auto& pairStateTransiction: transictionFunction) {
            
            stateAt = pairStateTransiction.first;

            isStateInvalid = transictionFunction.find(stateAt) == transictionFunction.end();

            if (isStateInvalid) return false;

            transictionFunctionAt = pairStateTransiction.second;

            for (const auto& character : alphabet) {
                isCharacterInvalid = transictionFunctionAt.find(character) == transictionFunctionAt.end();
                if (isCharacterInvalid) return false; 
            }

            for (const auto& pairTransictionFunction: transictionFunctionAt) {
                
                characterAt = pairTransictionFunction.first;
                isCharacterInvalid = alphabet.find(characterAt) == alphabet.end();

                if (isCharacterInvalid) return false;

                stateAt = pairTransictionFunction.second;
                isStateInvalid = states.find(stateAt) == states.end();

                if (isStateInvalid) return false;
            }
        }

        return true;
};

DFA::DFA(unordered_set<string> states,
        unordered_set<char> alphabet,
        unordered_map<string, unordered_map<char, string>> transictionFunction,
        string initial_state,
        unordered_set<string> final_states) {
            if (!isTransictionFuncionValid(transictionFunction, states, alphabet)) {
                throw invalid_argument("Invalid Transiction Function!");
            }
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

bool DFA::isAcepted(string chain) {

    if (!isChainValid(chain, this->alphabet)) {
        return false;
    }

    char characterAt;
    string stateAt = this->initial_state;

    int size = chain.size();

    for (int i = 0; i < size; i++) {
        characterAt = chain.at(i);

        stateAt = this->transictionFunction.at(stateAt).at(characterAt);
    }

    bool isFinalState = this->final_states.find(stateAt) != this->final_states.end();

    return isFinalState;
}

bool DFA::isRegexAcepted(string regex) {
    unordered_set<char> valid_chars = {
        'a', 'b', 'c', 'd', 'e',
        'e', 'd', 'f', 'g', 'h',
        'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r',
        's', 't', 'u', 'v', 'w',
        'x', 'y', 'z', '*', '+',
        '(', ')', '|', '[', ']',
        '{', '}'
        };

    return true; //TODO fazer isso
}
