// ExcluirLivro.hpp
#ifndef EXCLUIRLIVRO_HPP
#define EXCLUIRLIVRO_HPP

#include <string>
#include <vector>

class Livro; // Forward declaration

class ExcluirLivro {
public:
    ExcluirLivro(const std::string& nomeArquivo);
    void excluirLivro(int id);

private:
    std::string nomeArquivo;
    std::vector<Livro> lerLivros();
};

#endif // EXCLUIRLIVRO_HPP
