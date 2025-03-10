#include "Estado.h"

CASTELOpp::Estado::Estado::Estado(const ID Id):
	Ente(Id),remover(false),vtemposFase(new std::vector<float*>),nomes(new std::vector<std::string*>)
{

}

CASTELOpp::Estado::Estado::~Estado()
{
}

void CASTELOpp::Estado::Estado::setRemover(const bool remover)
{
	this->remover = remover;
}

const bool CASTELOpp::Estado::Estado::getRemover() const
{
	return remover;
}

void CASTELOpp::Estado::Estado::addpontuacao(float t)
{
	vtemposFase = new std::vector<float*>;
	vtemposFase->push_back(&t);
}



std::vector<float*>* CASTELOpp::Estado::Estado::getvtempos() const
{
	return vtemposFase;
}


