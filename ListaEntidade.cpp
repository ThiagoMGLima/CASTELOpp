#include "ListaEntidade.h"

CASTELOpp::Listas::ListaEntidade::ListaEntidade() :
	objListaEntidade()
{

}

CASTELOpp::Listas::ListaEntidade::~ListaEntidade()
{
}

void CASTELOpp::Listas::ListaEntidade::pushEnt(CASTELOpp::Entidade::Entidade* entidade)
{
	objListaEntidade.push(entidade);

}


void CASTELOpp::Listas::ListaEntidade::popEnt(int pos)
{
	objListaEntidade.popPos(pos);
}

int CASTELOpp::Listas::ListaEntidade::lenEnt()
{
	return objListaEntidade.getLen();
}

CASTELOpp::Entidade::Entidade* CASTELOpp::Listas::ListaEntidade::operator[](int pos)
{
	return objListaEntidade.getItem(pos);
}


void CASTELOpp::Listas::ListaEntidade::executar(double t)
{
	CASTELOpp::Ente* aux = nullptr;

	for (unsigned int i = 0; i < objListaEntidade.getLen(); i++) {
		
		aux = objListaEntidade.getItem(i);
		aux->Atualizar(t);
	}
}

Lista<CASTELOpp::Entidade::Entidade>* CASTELOpp::Listas::ListaEntidade::getListaEntidade()
{
	return &objListaEntidade;
}
