//Emprestimo.cpp
#include "Emprestimo.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
Aluno& Emprestimo::getAluno() {
    return aluno;
}

Emprestimo::Emprestimo(Livro& livro, Aluno& aluno, const std::string& dataEmprestimo)
    : livro(livro), aluno(aluno), dataEmprestimo(dataEmprestimo) {}

bool Emprestimo::isLivroEmprestado() {
    std::ifstream arquivo("emprestimos.txt");
    if (!arquivo.is_open()) {
        std::cerr << "Erro: Não foi possível abrir o arquivo emprestimos.txt" << std::endl;
        return false;  // Retornar false pois não foi possível verificar o arquivo
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string campo;
        std::getline(ss, campo, ',');  // ID do livro
        try {
            if (std::stoi(campo) == livro.getId()) {  // Verifica se o livro está emprestado
                return true;
            }
        }
        catch (const std::invalid_argument&) {
            std::cerr << "Erro: ID do livro inválido no arquivo emprestimos.txt" << std::endl;
            continue;
        }
    }

    return false;
}

void Emprestimo::realizarEmprestimo() {
    std::cout << "Verificando se o livro já está emprestado..." << std::endl;
    if (isLivroEmprestado()) {
        std::cerr << "Erro: O livro já está emprestado." << std::endl;
        return;  // Interrompe a execução se o livro já estiver emprestado
    }

    std::cout << "Livro não está emprestado. Prosseguindo com o empréstimo..." << std::endl;
    livro.emprestar();

    std::ofstream arquivo("emprestimos.txt", std::ios::app);
    if (!arquivo.is_open()) {
        std::cerr << "Erro: Não foi possível abrir o arquivo emprestimos.txt" << std::endl;
        return;  // Interrompe a execução se o arquivo não puder ser aberto
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
Livro& Emprestimo::getLivro() {
    return livro;
}
