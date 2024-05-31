//Emprestimo.cpp
#include "Emprestimo.hpp"
#include <fstream>

void Emprestimo::realizarEmprestimo() {
    livro.emprestar();
    std::ofstream arquivo("emprestimos.csv", std::ios::app);
    arquivo << livro.getId() << ','
            << livro.getTitulo() << ','
            << livro.getAutor() << ','
            << livro.getAno() << ','
            << aluno.getNomeDeUsuario() << ','
            << aluno.getNumeroMatricula() << ','
            << dataEmprestimo << '\n';
}