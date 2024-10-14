#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

// Classe abstrata Operacao
class Operacao {
public:
    virtual int calcular(int operador1, int operador2) const = 0; // Método abstrato
    virtual ~Operacao() = default;  // Destrutor virtual
};

// Classe Soma que implementa Operacao
class Soma : public Operacao {
public:
    int calcular(int operador1, int operador2) const override {
        return operador1 + operador2;
    }
};

// Classe Subtracao que implementa Operacao
class Subtracao : public Operacao {
public:
    int calcular(int operador1, int operador2) const override {
        return operador1 - operador2;
    }
};

// Classe Multiplicacao que implementa Operacao
class Multiplicacao : public Operacao {
public:
    int calcular(int operador1, int operador2) const override {
        return operador1 * operador2;
    }
};

// Classe Divisao que implementa Operacao
class Divisao : public Operacao {
public:
    int calcular(int operador1, int operador2) const override {
        if (operador2 == 0) {
            std::cerr << "Erro: Divisao por zero!" << std::endl;
            return 0;
        }
        return operador1 / operador2;
    }
};

// Função principal
int main() {
    // Inicializar gerador de números aleatórios
    srand(static_cast<unsigned int>(time(0)));

    // Criar um mapa associando os operadores a instâncias das classes
    std::unordered_map<char, std::shared_ptr<Operacao>> operacoes;
    operacoes['+'] = std::make_shared<Soma>();
    operacoes['-'] = std::make_shared<Subtracao>();
    operacoes['*'] = std::make_shared<Multiplicacao>();
    operacoes['/'] = std::make_shared<Divisao>();

    // Criar um array com 20 operações aleatórias
    std::vector<std::pair<int, char>> operacoesArray;
    char operadores[] = {'+', '-', '*', '/'};

    for (int i = 0; i < 20; ++i) {
        int num1 = rand() % 100;  // Gera um número aleatório entre 0 e 99
        char operador = operadores[rand() % 4];  // Escolhe aleatoriamente entre +, -, *, /
        operacoesArray.push_back({num1, operador});
    }

    // Executar as operações
    for (int i = 0; i < operacoesArray.size(); ++i) {
        int num1 = operacoesArray[i].first;
        int num2 = rand() % 100;  // Gera um número aleatório entre 0 e 99 para o segundo operador
        char operador = operacoesArray[i].second;

        if (operacoes.find(operador) != operacoes.end()) {
            // Chamar o método calcular da operação correspondente
            int resultado = operacoes[operador]->calcular(num1, num2);
            std::cout << "Operacao: " << num1 << " " << operador << " " << num2 << " = " << resultado << std::endl;
        } else {
            std::cerr << "Operacao invalida!" << std::endl;
        }
    }

    return 0;
}
