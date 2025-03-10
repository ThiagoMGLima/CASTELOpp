#include "MenuRank.h"

CASTELOpp::Menu::MenuRank::MenuRank(std::vector<float*>* vpontuacao):
	Ente(ID::Rank),fonte(),vtexto(),fundo(ID::Castelo)
{
	criarFundo();

	if (!fonte.loadFromFile("./Fonte/Bradley_Gratis.ttf")) {
		std::cout << "ERROR CASTELOpp::Menu::Botao::Botao, Nao foi possivel carregar Fonte" << std::endl;
		exit(1);
	}
	

	if (vpontuacao->size() > 0) {
		while (!vpontuacao->empty()) {
			addPontuacao(vpontuacao->operator[](vpontuacao->size() - 1));
			vpontuacao->operator[](vpontuacao->size() - 1) = NULL;
			vpontuacao->pop_back();
		}
	}
}

CASTELOpp::Menu::MenuRank::~MenuRank()
{
}

void CASTELOpp::Menu::MenuRank::addPontuacao(float pontuacao, std::string nome)
{
	
	if (posicaoRank(pontuacao)) {
		std::string string = nome + ": ";
		string.push_back(pontuacao);
		sf::Text* pText = new sf::Text();
		pText->setFont(fonte);
		pText->setPosition(sf::Vector2f(500.0f,100.0f*posicaoRank(pontuacao)));
		pText->setString(string);
		
	}
	
}

void CASTELOpp::Menu::MenuRank::addPontuacao(float* pontuacao)
{
	if (posicaoRank(*pontuacao) >= 0) {
		std::string string = ": ";
		string.push_back(*pontuacao);
		sf::Text* pText = new sf::Text();
		pText->setFont(fonte);
		pText->setPosition(sf::Vector2f(500.0f, 100.0f * posicaoRank(*pontuacao)));
		pText->setString(string);
		vtexto.push_back(pText);
	}
}

int CASTELOpp::Menu::MenuRank::posicaoRank(float pontuacao)
{
	for (int i = 0;i <= rank.size() - 1; i++) {
		if (rank.operator[](i) >= pontuacao) {
			rank.insert(rank.begin() + i,pontuacao);
			if (rank.size() > MAXIMO_PONTUACOES) {
				rank.pop_back();
			}
			return i + 1;
		}
		
	}
	if (rank.size() < MAXIMO_PONTUACOES) {
		rank.push_back(pontuacao);
		return (rank.size());
	}
	
	return -1;
	
}

void CASTELOpp::Menu::MenuRank::Atualizar(double t)
{
	fundo.Atualizar(t);
	if (vtexto.size() > 0) {
		pGerGrafico->atualizaCamera(vtexto.operator[](0)->getPosition());
	}
	else {
		pGerGrafico->atualizaCamera(sf::Vector2f(500.0f,400.0f));
	}
	

	desenha();
}

void CASTELOpp::Menu::MenuRank::desenha()
{
	if (vtexto.size()) {
		for (int i = 0; i < vtexto.size(); i++) {
			sf::Text* txto = vtexto.operator[](i);
			pGerGrafico->getGerGrafico()->getWindow()->draw(*txto);
		}
	}
}

void CASTELOpp::Menu::MenuRank::criarFundo()
{
	fundo.addCamada(CAMINHO "Fundo/Fundo_mPrincipal.png", 0.00f);
}
