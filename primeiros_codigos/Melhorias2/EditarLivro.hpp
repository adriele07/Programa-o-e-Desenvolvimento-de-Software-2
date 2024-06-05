// EditarLivro.hpp
#ifndef EDITARLIVRO_H
#define EDITARLIVRO_H

#include <string>
#include <vector>

struct Livro {
    int id;
    std::string nome;
    std::string autor;
    int ano;
};

class EditarLivro {
public:
    EditarLivro(const std::string& nomeArquivo);
    std::vector<Livro> lerLivros();
    void editarLivro(int id, const Livro& livro);
    void salvarLivros(const std::vector<Livro>& livros);

private:
    std::string nomeArquivo;
};

#endif // EDITARLIVRO_H
