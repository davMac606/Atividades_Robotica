tarefa parar{
    TravarMotor("r",verdadeiro)
    TravarMotor("l",verdadeiro)
}
tarefa esquerda com numero velocidade {
    TravarMotor("r",falso)
    Motor("l",0+velocidade)
}
tarefa frente com numero velocidade {
    TravarMotor("r",falso)
    TravarMotor("l",falso)
    Motor("r",0+velocidade)
    Motor("l",0+velocidade)
}

tarefa viraEsquerda com numero velocidade {
    TravarMotor("l",verdadeiro)
    TravarMotor("r",falso)
    Motor("r",0+velocidade)
}

tarefa viraDireita com numero velocidade {
    TravarMotor("r",verdadeiro)
    TravarMotor("l",falso)
    Motor("l",0+velocidade)
}

inicio
    AbrirConsole()
    EscreverLinha("Início do programa")
    LigarLuz("led",0,255,0)
    enquanto (verdadeiro) farei {
		parar()
        se(Colorido("rc") e Colorido("lc")) entao {
            frente(300)
            Escrever("Indo para frente.")
            }
        senao se (Colorido("rc")) entao {
            Escrever("Virando à esquerda.")
            viraEsquerda(200)
            }
        senao se (Colorido("lc")) entao {
            Escrever("Virando à direita.")
            viraDireita(200)
            }
        se (Cor("lc") == "Vermelho" e Cor("rc") == "Vermelho") entao {
            Escrever("Finalizando o programa.")
            DesligarLuz("led")
            parar()
            Interromper()
		} 
    }
fim