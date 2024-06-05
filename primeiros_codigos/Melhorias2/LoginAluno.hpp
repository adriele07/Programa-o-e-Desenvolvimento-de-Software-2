#ifndef LOGINALUNO_HPP
#define LOGINALUNO_HPP

#include <string>
#include <vector>
#include "CadastroAluno.hpp"

class LoginAluno {
public:
    LoginAluno(const std::vector<Aluno>& alunos);
    bool autenticar(const std::string& nomeDeUsuario, const std::string& senha);
private:
    std::vector<Aluno> alunos;
};

#endif // LOGINALUNO_HPP
