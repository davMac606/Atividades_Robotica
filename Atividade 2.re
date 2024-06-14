tarefa parar {
    Motor("l", 0)
    Motor("r", 0)
}

tarefa frente com numero velocidadeMotor {
    TravarMotor("r", falso)
    TravarMotor("l", falso)
    Motor("l", 0 + velocidadeMotor)
    Motor("r", 0 + velocidadeMotor)
}

tarefa virarEsquerda com numero velocidadeL, numero velocidadeR {
    TravarMotor("r", falso)
    TravarMotor("l", falso)
    Esperar(20)
        Motor("r", 0+velocidadeR)
        Esperar(20)
        Motor("l", 0-velocidadeL)
}

tarefa virarDireita com numero velocidadeL, numero velocidadeR {
    TravarMotor("r", falso)
    TravarMotor("l", falso)
    Esperar(20)
        Motor("l", 0+velocidadeL)
        Esperar(20)
        Motor("r", 0-velocidadeR)
}

inicio
    AbrirConsole()
    EscreverLinha("Início do programa.")
    LigarLuz("led", 0, 255, 0)
    enquanto (verdadeiro) farei {
        Esperar(50)
        se (Colorido("rc") e Colorido("lc")) entao {
            frente(225)
            Escrever("Seguindo em frente.")
        }
        senao se (Colorido("rc")) entao {
            Escrever("Virando à esquerda.")
             virarEsquerda(150,150)
        }
        senao se (Colorido("lc")) entao {
            Escrever("Virando à direita.")
            virarDireita(150,150)
        }
        se (Cor("lc") == "Vermelho" ou Cor("rc") == "Vermelho") entao {
            LimparConsole()
            Escrever("Fim do programa.")
            DesligarLuz("led")
            parar()
            Interromper()
        }
    }
fim