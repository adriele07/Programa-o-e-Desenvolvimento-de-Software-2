//LoginAdministrador.cpp
#include "LoginAdministrador.hpp"

LoginAdministrador::LoginAdministrador(const std::vector<Administrador>& administradores) : administradores(administradores) {}

bool LoginAdministrador::autenticar(const std::string& nomeDeUsuario, const std::string& senha) {
    for (const auto& admin : administradores) {
        if (admin.nomeDeUsuario == nomeDeUsuario && admin.senha == senha) {
            return true;
        }
    }
    return false;
}