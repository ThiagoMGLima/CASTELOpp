#pragma once
#include "Entidade.h"

#define DANO_PROJETIL 1
#define VEL_PROJETIL 10000.0f

namespace CASTELOpp{
    namespace Entidade{

        class Projetil :
            public Entidade {
        private:

            bool JaAtacou;
            
        public:
            Projetil(const sf::Vector2f pos, const bool Esq);
            ~Projetil();
            void darDano (Entidade* pJog); 
            bool GerirAtk(Entidade* pEntidade);
            void TomaDano(float quantidade);
            void Atacar(Entidade* pEntidade); //const
            bool Aparecer() const;
            void Atualizar(double t);
        };
    }
}
