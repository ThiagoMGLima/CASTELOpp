#include "Ente.h"

CASTELOpp::Gerenciador::GerenciadorGrafico* CASTELOpp::Ente::pGerGrafico = pGerGrafico->getGerGrafico();

CASTELOpp::Ente::Ente(ID id):
	id(id)
{

}

CASTELOpp::Ente::~Ente()
{

}

void CASTELOpp::Ente::Atualizar(double t)
{
}

CASTELOpp::ID CASTELOpp::Ente::getId()
{
	return id;
}


