// EditarLivro.cpp
#include "EditarLivro.hpp"
#include <fstream>
#include <sstream>

EditarLivro::EditarLivro(const std::string& nomeArquivo) : nomeArquivo(nomeArquivo) {}

std::vector<Livro> EditarLivro::lerLivros() {
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

void EditarLivro::editarLivro(int id, const Livro& livro) {
    std::vector<Livro> livros = lerLivros();
    for (Livro& l : livros) {
        if (l.id == id) {
            l = livro;
            break;
        }
    }
    salvarLivros(livros);
}

void EditarLivro::salvarLivros(const std::vector<Livro>& livros) {
    std::ofstream arquivo(nomeArquivo);
    for (const Livro& livro : livros) {
        arquivo << livro.id << '\n' << livro.nome << '\n' << livro.autor << '\n' << livro.ano << '\n';
    }
}
