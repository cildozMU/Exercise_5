/************************************************************************************************
Programming Skills Challenge - Siemens
Exercise 5. The present program is an Unit Test for program developed in Exercise 4.
For validation purpose, please go to: https://www.onlinegdb.com/fZgerrnmS

Criado em 01/03/2024 - 07:48pm
Autora: Mariana Uzeda - mariana.uzeda@gmail.com
*************************************************************************************************/

#include <iostream>
#include <cassert>
#include <string>

/************************************************************************************************
Função implementada no Exercício 4 (ConcatRemove):
*************************************************************************************************/

// Função para verificar se é possível converter s em t usando k operações
std::string ConcatRemove(std::string s, std::string t, int k) {
    int LetrasIguais = 0;

    // Percorrendo s e t e contando o número de letras iguais
    for (int i = 0; i < std::min(s.length(), t.length()); ++i) {
        if (s[i] == t[i]) {
            LetrasIguais++;
        } else {
            break; // Ao percorrer, caso alguma letra não seja igual, interrompe-se o processo
        }
    }

    // Calcula o número de operações após as letras iguais iniciais.
    int NumOperacoes = s.length() - LetrasIguais + t.length() - LetrasIguais;
    
    // Verifica restrições de entrada de dados
    if (s.length() < 1 || s.length() > 100 || t.length() < 1 || t.length() > 100 || k < 1 || k > 100) {
        return "Erro: Restrições para s,t e k não foram atendidas.";
    } else 
    
    // Verifica se é possível transformar s em t usando k operações*
    if (NumOperacoes <= k || k >= s.length() + t.length()) {
        return "Sim";
    } else {
        return "Não";
    } 
}

/************************************************************************************************
Função para realizar os testes de validação:
*************************************************************************************************/

void Testes() {
    // Teste 1: Conversão válida
    assert(ConcatRemove("abc", "def", 6) == "Sim");

    // Teste 2: Conversão inválida
    assert(ConcatRemove("abc", "def", 5) == "Não");

    // Teste 3: Conversão com strings vazias
    assert(ConcatRemove("", "", 0) == "Erro: Restrições para s,t e k não foram atendidas.");

   // Teste 4: Conversão inválida com restrições
    assert(ConcatRemove("abc", "def", -1) == "Erro: Restrições para s,t e k não foram atendidas."); 
    
    // Teste 5: Conversão válida com mais movimentos disponíveis 
    assert(ConcatRemove("abc", "def", 8) == "Sim");
    
    // Teste 6: Conversão válida 
    assert(ConcatRemove("ava", "avo", 2) == "Sim");
    
    // Teste 7: Conversão válida com mais movimentos disponíveis 
    assert(ConcatRemove("ava", "ovo", 5) == "Não");
    
    // Teste 7: Conversão inválida 
    assert(ConcatRemove("ava", "ovo", 1) == "Não");
}

/************************************************************************************************
Programa Principal
*************************************************************************************************/

int main() {
    // Executar os testes
    Testes();

    std::cout << "Todos os testes passaram com sucesso!\n";

    return 0;
}



