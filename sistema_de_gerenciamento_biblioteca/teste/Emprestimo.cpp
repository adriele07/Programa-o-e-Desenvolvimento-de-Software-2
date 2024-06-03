//Emprestimo.cpp
#include "Emprestimo.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>

Emprestimo::Emprestimo(Livro& livro, Aluno& aluno, const std::string& dataEmprestimo)
    : livro(livro), aluno(aluno), dataEmprestimo(dataEmprestimo) {}

bool Emprestimo::isLivroEmprestado() {
    std::ifstream arquivo("emprestimos.txt");
    if (!arquivo.is_open()) {
        std::cerr << "Erro: Não foi possível abrir o arquivo emprestimos.txt" << std::endl;
        return false;  // Retornar false pois não foi possível verificar o arquivo
    }

    std::set<int> livrosEmprestados;
    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string campo;
        std::getline(ss, campo, ',');  // ID do livro
        livrosEmprestados.insert(std::stoi(campo));
    }

    return livrosEmprestados.count(livro.getId()) > 0;  // Verifica se o livro está emprestado
}

void Emprestimo::realizarEmprestimo() {
    if (isLivroEmprestado()) {
        std::cerr << "Erro: O livro já está emprestado." << std::endl;
        return;  // Interrompe a execução se o livro já estiver emprestado
    }

    livro.emprestar();

    std::ofstream arquivo("emprestimos.txt", std::ios::app);
    if (!arquivo.is_open()) {
        std::cerr << "Erro: Não foi possível abrir o arquivo emprestimos.txt" << std::endl;
        return;
    }

    arquivo << livro.getId() << ','
            << livro.getTitulo() << ','
            << livro.getAutor() << ','
            << livro.getAno() << ','
            << aluno.getNomeDeUsuario() << ','
            << aluno.getNumeroMatricula() << ','
            << dataEmprestimo << '\n';

    std::cout << "Livro emprestado com sucesso." << std::endl;
}