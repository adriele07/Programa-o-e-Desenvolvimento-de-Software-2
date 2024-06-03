// CadastroAluno.cpp
#include "CadastroAluno.hpp"
#include <fstream>

bool isAlunoRegistrado(const std::vector<Aluno>& alunos, const std::string& nomeDeUsuario) {
    for (const auto& aluno : alunos) {
        if (aluno.nomeDeUsuario == nomeDeUsuario) {
            return true;
        }
    }
    return false;
}

void salvarAlunosEmArquivo(const std::vector<Aluno>& alunos) {
    std::ofstream arquivo("alunos.txt");

    for (const auto& aluno : alunos) {
        arquivo << aluno.nomeDeUsuario << "\n" << aluno.senha << "\n" << aluno.numeroMatricula << "\n";
    }
    arquivo.close(); // Fechar o arquivo após escrever os dados
}