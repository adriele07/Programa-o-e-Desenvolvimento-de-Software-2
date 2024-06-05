// LoginAdministrador.hpp
#ifndef LOGINADMINISTRADOR_HPP
#define LOGINADMINISTRADOR_HPP

#include <string>
#include <vector>
#include "CadastroAdministrador.hpp"

class LoginAdministrador {
public:
    LoginAdministrador(const std::vector<Administrador>& administradores);
    bool autenticar(const std::string& nomeDeUsuario, const std::string& senha);

private:
    std::vector<Administrador> administradores;
};

#endif // LOGINADMINISTRADOR_HPP