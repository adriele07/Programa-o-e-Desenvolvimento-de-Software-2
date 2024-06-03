//Emprestimo.hpp
#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP

#include <string>
#include "Livro.hpp"
#include "CadastroAluno.hpp"

class Emprestimo {
public:
    Emprestimo(Livro& livro, Aluno& aluno, const std::string& dataEmprestimo);

    void realizarEmprestimo();

private:
    Livro& livro;
    Aluno& aluno;
    std::string dataEmprestimo;

    bool isLivroEmprestado();
};

#endif // EMPRESTIMO_HPP
