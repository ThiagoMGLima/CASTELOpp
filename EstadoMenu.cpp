#include "EstadoMenu.h"

CASTELOpp::Estado::EstadoMenu::EstadoMenu():
	Estado(ID::Menu),Menu(new Menu::Menu())
{
}

CASTELOpp::Estado::EstadoMenu::~EstadoMenu()
{
}

void CASTELOpp::Estado::EstadoMenu::Atualizar(double t)
{
	Menu->Atualizar(t);
}

CASTELOpp::Menu::Menu* CASTELOpp::Estado::EstadoMenu::getMenu() const
{
	return Menu;
}
