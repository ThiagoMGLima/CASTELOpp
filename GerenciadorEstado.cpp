#include "GerenciadorEstado.h"

CASTELOpp::Gerenciador::GerenciadorEstado* CASTELOpp::Gerenciador::GerenciadorEstado::pGerenciadorEstado = nullptr;

CASTELOpp::Gerenciador::GerenciadorEstado::GerenciadorEstado() : 
    pilhaEstados(),construtorEstado()
{
  
}

CASTELOpp::Gerenciador::GerenciadorEstado::~GerenciadorEstado()
{
    while (!pilhaEstados.empty()) {
        delete(pilhaEstados.top());
        pilhaEstados.top() = nullptr;
        pilhaEstados.pop();
    }
    if (pGerenciadorEstado) {
        delete(pGerenciadorEstado);
        pGerenciadorEstado = nullptr;
    }
}

CASTELOpp::Gerenciador::GerenciadorEstado* CASTELOpp::Gerenciador::GerenciadorEstado::getGerenciadorEstado() {
    if (pGerenciadorEstado == nullptr) {
        pGerenciadorEstado = new GerenciadorEstado();
    }
    return pGerenciadorEstado;
}

void CASTELOpp::Gerenciador::GerenciadorEstado::Atualizar(double t)
{
    if (!pilhaEstados.empty()) {
        if (pilhaEstados.top()->getRemover()) //if id fase criar game over
            removerEstado();

        pilhaEstados.top()->Atualizar(t);

    }
    else {
        GerenciadorGrafico* pGrafico = nullptr;
        pGrafico = pGrafico->getGerGrafico();
        pGrafico->FechaJanela();
    }
}

void CASTELOpp::Gerenciador::GerenciadorEstado::addEstado(const ID Id,int num)
{
    Estado::Estado* estado = construtorEstado.criarEstado(Id,num);
    if (estado == nullptr) {
        std::cout << "ERROR::CASTELOpp::Gerenciador::GerenciadorEstado::estado adicionado eh nullptr" << std::endl;
        exit(1);
    }
    pilhaEstados.push(estado);
}

void CASTELOpp::Gerenciador::GerenciadorEstado::removerEstado()
{

    if (pilhaEstados.top() != nullptr) {
        delete(pilhaEstados.top());
        pilhaEstados.top() = nullptr;
        pilhaEstados.pop();
    }
    
    else {
        GerenciadorGrafico* pGrafico = nullptr;
        pGrafico = pGrafico->getGerGrafico();
        pGrafico->FechaJanela();
    }
}

CASTELOpp::Estado::Estado* CASTELOpp::Gerenciador::GerenciadorEstado::getEstadoAtual()
{
    return pilhaEstados.top();
    
}

