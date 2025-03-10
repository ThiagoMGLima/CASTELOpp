#pragma once

#include "Inimigo.h"

#include "Fase.h"


namespace CASTELOpp {
    namespace Entidade {
        namespace Personagens {
            namespace Inimigo {
                class Imp :
                    public Inimigo
                {
                private:
                    float igneo;
                    void Inicializa();
                public:
                    Imp(const sf::Vector2f Pos, vector<Entidade*> Jogador);
                    ~Imp();
                    float getVida() const;
                    bool Aparecer() const;
                    void Atacar(Entidade* EntidadeAtacada);
                    void SoltarFogo(bool Esq);
                };
            }
        }
    }
};

