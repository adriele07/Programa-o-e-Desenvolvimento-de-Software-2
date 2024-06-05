// ExcluirLivro.cpp
#include "ExcluirLivro.hpp"
#include <fstream>
#include <sstream>
#include "EditarLivro.hpp"

ExcluirLivro::ExcluirLivro(const std::string& nomeArquivo) : nomeArquivo(nomeArquivo) {}

std::vector<Livro> ExcluirLivro::lerLivros() {
    std::vector<Livro> livros;
    std::ifstream arquivo(nomeArquivo);
    std::string linha;
    while (std::getline(arquivo, linha)) {
        Livro livro;
        livro.id = std::stoi(linha);

        std::getline(arquivo, linha);
        livro.nome = linha;

        std::getline(arquivo, linha);
        livro.autor = linha;

        std::getline(arquivo, linha);
        livro.ano = std::stoi(linha);

        livros.push_back(livro);
    }
    return livros;
}

void ExcluirLivro::excluirLivro(int id) {
    std::vector<Livro> livros = lerLivros();
    livros.erase(std::remove_if(livros.begin(), livros.end(), [id](const Livro& livro) { return livro.id == id; }), livros.end());

    std::ofstream arquivo(nomeArquivo, std::ios::trunc);
    for (const Livro& livro : livros) {
        arquivo << livro.id << "\n";
        arquivo << livro.nome << "\n";
        arquivo << livro.autor << "\n";
        arquivo << livro.ano << "\n";
    }
}
