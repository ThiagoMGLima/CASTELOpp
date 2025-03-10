#pragma once

//entidades
#include "Jogador.h"
#include "Fantasma.h"
#include "Imp.h"
#include "Chefe.h"
#include "Plataforma.h"
#include "Toxico.h"
#include "Lama.h"
#include "Projetil.h"

#include "ListaEntidade.h"
#include "GerenciadorColisao.h"

#include "Fundo.h"

namespace CASTELOpp {
    namespace Fase {
        class Fase :
            public Ente {

        private:
            
            virtual void InstanciaEnt(int numJogadores) = 0;
        protected:
            static int num_Jog;

            static float tempoemFase;

            Listas::ListaEntidade listaEntidades;
            Gerenciador::GerenciadorColisao* colisor;
            Parallax::Fundo fundo;
            bool AcaboFase;
            static vector<Entidade::Entidade*> vJogadores;

        public:
            
            Fase(ID id);
            ~Fase();
            bool JogadoresMorreram();
            void setNumJog(int nJog);

            static Fase* pFase;

            Fase* getpFase();
            int getNumJog() const;
            virtual void criarFundo() = 0;
            virtual bool acabouFase() = 0;

            void Atualizar(double t);

            void clearvJogadores();
            void criaJogador(sf::Vector2f pos, sf::Vector2f tam);
            void criaInimigoFantasma(sf::Vector2f pos, sf::Vector2f tam, vector<Entidade::Entidade*> pJog);
            void criaImp(sf::Vector2f pos, vector<Entidade::Entidade*> pJog);
            void criaPlataforma(sf::Vector2f pos);
            void criaPlataforma(sf::Vector2f pos, sf::Vector2f tam, const char* caminhoTextura);
            void criaChao(sf::Vector2f pos,sf::Vector2f tam,bool invi);
            void criaToxic(sf::Vector2f pos);
            void criaProjetil(sf::Vector2f pos, bool Esq);
            void criaChefe(sf::Vector2f Pos, sf::Vector2f Tam, vector<Entidade::Entidade*> pJog);
            void criaLama(sf::Vector2f Pos);
            

            float getTmpfase() const;
            void atualizatmpfase(double t);
            void zeraTmpfase();

            vector<Entidade::Entidade*> getJogador();

        };
    }
}

