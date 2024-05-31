//Emprestimo.hpp
#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP

#include <string>
#include "Livro.hpp"
#include "CadastroAluno.hpp"

class Emprestimo {
public:
    Emprestimo(Livro& livro, Aluno& aluno, const std::string& dataEmprestimo)
        : livro(livro), aluno(aluno), dataEmprestimo(dataEmprestimo) {}

    void realizarEmprestimo();

private:
    Livro& livro;
    Aluno& aluno;
    std::string dataEmprestimo;
};

#endif // EMPRESTIMO_HPP
