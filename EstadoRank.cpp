#include "EstadoRank.h"

CASTELOpp::Estado::EstadoRank::EstadoRank():
	Estado(ID::Rank),pMenuRank(new Menu::MenuRank(getvtempos()))
{

}

CASTELOpp::Estado::EstadoRank::~EstadoRank()
{
}

void CASTELOpp::Estado::EstadoRank::Atualizar(double t)
{
	pMenuRank->Atualizar(t);
}

CASTELOpp::Menu::MenuRank* CASTELOpp::Estado::EstadoRank::getRank() const
{
	return pMenuRank;
}
