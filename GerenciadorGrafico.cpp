#include "GerenciadorGrafico.h"

CASTELOpp::Gerenciador::GerenciadorGrafico* CASTELOpp::Gerenciador::GerenciadorGrafico::pGerGrafico = nullptr;

CASTELOpp::Gerenciador::GerenciadorGrafico::GerenciadorGrafico():
	pWindow(new sf::RenderWindow(sf::VideoMode(1000,800),"CASTELOpp")),camera(sf::Vector2f(500.0f,400.0f),sf::Vector2f(1000.0f,800.0f)) {

}

CASTELOpp::Gerenciador::GerenciadorGrafico::~GerenciadorGrafico()
{
	if (pWindow) {
		delete(pWindow);
		pWindow = nullptr;
	}
}

CASTELOpp::Gerenciador::GerenciadorGrafico* CASTELOpp::Gerenciador::GerenciadorGrafico::getGerGrafico()
{
	if (pGerGrafico == nullptr)
		pGerGrafico = new CASTELOpp::Gerenciador::GerenciadorGrafico();
	
	return pGerGrafico;
}

sf::RenderWindow* CASTELOpp::Gerenciador::GerenciadorGrafico::getWindow()
{
	return pWindow;
}

void CASTELOpp::Gerenciador::GerenciadorGrafico::printElemento(sf::RectangleShape Elemento)
{
	pWindow->draw(Elemento);
}

void CASTELOpp::Gerenciador::GerenciadorGrafico::LimpaTela()
{
	pWindow->clear();
}

void CASTELOpp::Gerenciador::GerenciadorGrafico::MostraTela()
{
	pWindow->display();
}

void CASTELOpp::Gerenciador::GerenciadorGrafico::FechaJanela()
{
	pWindow->close();
}

bool CASTELOpp::Gerenciador::GerenciadorGrafico::VerificaJanela() {
	if (pWindow->isOpen())
		return true;
	return false;
}

void CASTELOpp::Gerenciador::GerenciadorGrafico::atualizaCamera(const sf::Vector2f pos)
{
	camera.setCenter(pos);
	pWindow->setView(camera);
}

sf::View CASTELOpp::Gerenciador::GerenciadorGrafico::getCamera() const
{
	return camera;
}

const sf::Texture CASTELOpp::Gerenciador::GerenciadorGrafico::CarregarTextura(const char* caminhoTextura) {
	
	sf::Texture textura;

	//carrega a textura ja verificando se carregou corretamente
	if (!textura.loadFromFile(caminhoTextura)) {
		std::cout << "ERRO::CASTELOpp::Gerenciador::GerenciadorGrafico::nao foi possivel encontrar o caminho da textura - " << caminhoTextura << std::endl;
		exit(1);
	}

	return textura;
}
