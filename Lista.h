#pragma once
#include "Elemento.h"
#include <iostream>
using namespace std;


template <class TL>
class Lista
{
private:
	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;
	unsigned int len;
public:
	Lista();
	~Lista();

	unsigned int getLen() {
		return len;
	}

	TL* getItem(unsigned int posicao) {
		if (posicao > len) {
			cout << "posicao do item pedido fora de alcance" << endl;
			return nullptr;
		}
		Elemento<TL>* temp = pPrimeiro;
		if (posicao == 0)
			return temp->getItem();
		for (int i = 0; i < posicao; i++) {
			temp = temp->getPProx();
		}
		return temp->getItem();
	}

	void push(TL* item) {
		if (pPrimeiro == nullptr) {
			pPrimeiro = new(Elemento<TL>);
			pPrimeiro->setitem(item);
			pUltimo = pPrimeiro;
		}
		else {
			Elemento<TL>* temp = new Elemento<TL>;
			temp->setitem(item);
			pUltimo->setPProx(temp);
			pUltimo = temp;
		}
		len++;
	}

	void popItem(TL* item) {
		Elemento<TL>* temp = pPrimeiro;
		Elemento<TL>* tempAnt = nullptr;

		while (temp->getItem() != item) {
			tempAnt = temp;
			temp = temp->getPProx();
		}
		if (temp == pPrimeiro) {
			pPrimeiro = temp->getPProx();
		}
		else if (temp = pUltimo) {
			tempAnt->setPProx(nullptr);
			pUltimo = tempAnt;
		}
		else {
			tempAnt->setPProx(temp->getpProx());
		}
		delete temp;
		len--;
	}

	void popPos(unsigned int pos) {
		Elemento<TL>* temp = pPrimeiro;
		Elemento<TL>* tempAnt = nullptr;

		if (pos > 1)
		{
			for (unsigned int i = 0; i < pos; i++) {
				tempAnt = temp;
				temp = temp->getPProx();
			}
			tempAnt->setPProx(temp->getPProx());
			delete temp;
			len--;
		}
	}

	Elemento<TL> getStart() {
		return pPrimeiro;
	}

	Elemento<TL>getLast() {
		return pUltimo;
	}
};


template <class TL> inline Lista<TL>::Lista() {
	pPrimeiro = nullptr;
	pUltimo = nullptr;
	len = 0;
}

template <class TL> inline Lista<TL>::~Lista() {
	if (pPrimeiro != nullptr) {
		pPrimeiro = nullptr;
		pUltimo = nullptr;
	}
	len = 0;
}