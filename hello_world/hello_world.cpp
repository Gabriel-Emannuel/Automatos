#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Estado {
    unordered_map<char, Estado*> apontadores;
    bool ehestadoAceitacao; 
};

struct AutomatoFinitoDeterministico {
    unordered_map<string, Estado*> estados;
    unordered_set<char> alfabeto;
    Estado* estadoInicial;

    bool EhCadeiaAceita(Estado* estado, string &cadeia, int index) {
        bool EhFimCadeia = index == cadeia.length();
    
        if (EhFimCadeia) {
            return estado->ehestadoAceitacao;
        }

        char caractereVez = cadeia.at(index);

        bool EhCaractereValido = estado->apontadores.find(caractereVez) != estado->apontadores.end();

        if (!EhCaractereValido) {
            return false;
        }

        return EhCadeiaAceita(estado->apontadores.at(caractereVez), cadeia, index + 1);
    };

};

bool resetVariavelBooleana();

void adicionaAlfabeto(AutomatoFinitoDeterministico* AutomatoFinito);

void adicionaEstadoInicial(AutomatoFinitoDeterministico* AutomatoFinito);

void adicionaEstados(AutomatoFinitoDeterministico* AutomatoFinito);

void adicionaEstadosAceitacao(AutomatoFinitoDeterministico* AutomatoFinito);

void adicionaFuncaoTransicao(AutomatoFinitoDeterministico* AutomatoFinito);

int main() {
    
    AutomatoFinitoDeterministico* novoAutomato = new AutomatoFinitoDeterministico();
    
    adicionaEstados(novoAutomato);

    adicionaAlfabeto(novoAutomato);

    adicionaFuncaoTransicao(novoAutomato);

    adicionaEstadoInicial(novoAutomato);
    
    adicionaEstadosAceitacao(novoAutomato);

    bool EhCadeiaAceita, EhpararLoop;
    
    string cadeia;
    do {
        cout << "Insira a cadeia ou \"sair\" para encerrar a execução: ";
        cin >> cadeia;

        EhpararLoop = cadeia.compare("sair") == 0;

        if (EhpararLoop) {
            continue;
        }

        EhCadeiaAceita = novoAutomato->EhCadeiaAceita(novoAutomato->estadoInicial, cadeia, 0);

        if (EhCadeiaAceita) {
            cout << "Cadeia aceita!" << '\n';
        }
        else {
            cout << "Cadeia não aceita!" << '\n';
        }
    } while (!EhpararLoop);

    return 0;
}

bool resetVariavelBooleana() {
    return false;
}

void adicionaAlfabeto(AutomatoFinitoDeterministico* AutomatoFinito) {
    char caracterVez;

    bool ehCaractereRepetido, ehParaSairLoop; 

    cout << "Caso queira parar de inserir Caracteres, digite \".\" com o fim de parar de inserir caracteres." << '\n';

    do {
        cout << "Digite o novo Caractere: ";

        cin >> caracterVez;

        ehParaSairLoop = caracterVez == '.';

        if (ehParaSairLoop) {
            continue;
        }

        ehCaractereRepetido = AutomatoFinito->alfabeto.find(caracterVez) != AutomatoFinito->alfabeto.end();

        if (ehCaractereRepetido) {
            ehCaractereRepetido = resetVariavelBooleana();
            continue;            
        }

        AutomatoFinito->alfabeto.insert(caracterVez);

    } while (!ehParaSairLoop);   
}

void adicionaEstadoInicial(AutomatoFinitoDeterministico* AutomatoFinito) {
    string estadoApontado;

    cout << "Insira o Estado inicial: ";
    
    cin >> estadoApontado;

    AutomatoFinito->estadoInicial = AutomatoFinito->estados.at(estadoApontado);
}

void adicionaEstados(AutomatoFinitoDeterministico* AutomatoFinito) {
    string estadoVez;

    bool ehParaSairLoop;

    cout << "Caso queira parar de inserir Estados, digite \"sair\" com o fim de parar de inserir estados." << '\n';

    do {
        cout << "Digite o novo Estado: ";
        
        cin >> estadoVez;

        ehParaSairLoop = estadoVez.compare("sair") == 0;

        if (ehParaSairLoop) {
            continue;
        }

        AutomatoFinito->estados[estadoVez] = new Estado();
    } while (!ehParaSairLoop);
}

void adicionaEstadosAceitacao(AutomatoFinitoDeterministico* AutomatoFinito) {
    string estadoVez, resposta;

    bool ehEstadoAceitacao;

    for (const auto& estado: AutomatoFinito->estados) {
        estadoVez = estado.first;

        cout << "O estado " << estadoVez << " é de aceitação? (Apenas \"sim\" será considerado como resposta positiva!)";

        cin >> resposta;

        ehEstadoAceitacao = resposta.compare("sim") == 0;

        estado.second->ehestadoAceitacao = ehEstadoAceitacao;
    }
}

void adicionaFuncaoTransicao(AutomatoFinitoDeterministico* AutomatoFinito) {
    Estado* estadoInstanciado;

    string estadoApontado, estadoVez;

    cout << "Agora será definida a função de transição, siga o Template F(Estado, caractere) = Estado a ser apontado. " << '\n';

    for (const auto& estado: AutomatoFinito->estados) {
        estadoVez = estado.first;
        estadoInstanciado = estado.second;
        for (const auto& caractere: AutomatoFinito->alfabeto) {
            cout << "F(" << estadoVez << ',' << caractere << ") = ";
            cin >> estadoApontado;
            estadoInstanciado->apontadores[caractere] = AutomatoFinito->estados.at(estadoApontado);
        }
    }
}
