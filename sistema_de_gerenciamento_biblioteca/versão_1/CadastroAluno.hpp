//CadastroAluno.hpp
#include <string>
#include <vector>

struct Aluno {
    std::string nomeDeUsuario;
    std::string senha;
    std::string numeroMatricula;
};

bool isAlunoRegistrado(const std::vector<Aluno>& alunos, const std::string& nomeDeUsuario);
void salvarAlunosEmArquivo(const std::vector<Aluno>& alunos);