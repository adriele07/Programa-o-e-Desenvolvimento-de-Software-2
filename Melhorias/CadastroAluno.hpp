#ifndef CADASTROALUNO_H
#define CADASTROALUNO_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

struct Aluno {
    std::string nomeDeUsuario;
    std::string senha;
    std::string numeroMatricula;

    const std::string& getNomeDeUsuario() const { return nomeDeUsuario; }
    const std::string& getSenha() const { return senha; }
    const std::string& getNumeroMatricula() const { return numeroMatricula; }
};

bool isAlunoRegistrado(const std::vector<Aluno>& alunos, const std::string& nomeDeUsuario);
void salvarAlunosEmArquivo(const std::vector<Aluno>& alunos);

#endif // CADASTROALUNO_H
