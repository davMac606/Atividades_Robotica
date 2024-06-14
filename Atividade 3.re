tarefa parar {
    Motor("l", 0)
    Motor("r", 0)
}

tarefa destravarMotores {
    TravarMotor("r", falso)
    TravarMotor("l", falso)
}

tarefa frente com numero velocidadeMotor {
    destravarMotores()
    Motor("l", velocidadeMotor + 0)
    Motor("r", velocidadeMotor + 0)
}

tarefa virarEsquerda com numero velocidadeL, numero velocidadeR {
    destravarMotores()
        Motor("r", 0+velocidadeR)
        Motor("l", 0-velocidadeL)
}

tarefa virarDireita com numero velocidadeL, numero velocidadeR {
    destravarMotores()
        Motor("l", 0+velocidadeL)
        Motor("r", 0-velocidadeR)
}


inicio
    AbrirConsole()
    EscreverLinha("Início do programa.")
    LigarLuz("led", 0, 255, 0)
    enquanto (verdadeiro) farei {
			TocarFrequencia("buzzer", 2000.14)
        se (Colorido("rc") e Colorido("lc")) entao {
            frente(300)
            Escrever("Seguir em frente.")
			LigarCaneta("tv", 128, 0, 128)
			LigarCaneta("girl", 0, 0, 255)

        }
        senao se (Colorido("rc")) entao {
            Escrever("Virar à esquerda.")
            virarEsquerda(200,300)
			LigarCaneta("tv", 0, 0, 255)
			LigarCaneta("girl", 128, 0, 128)
			TocarFrequencia("buzzer",260.4)
        }
        senao se (Colorido("lc")) entao {
            Escrever("Virar à direita.")
            virarDireita(200,300)
			LigarCaneta("tv", 0, 0, 255)
			LigarCaneta("girl", 128, 0, 128)
			TocarFrequencia("buzzer",300.5)
        }
        se (Cor("lc") == "Vermelho" ou Cor("rc") == "Vermelho") entao {
            DesligarLuz("led")
            LimparConsole()
			ApagarCaneta("tv")
			ApagarCaneta("girl")
            Escrever("Fim do programa.")
            parar()
            Interromper()
        }
    }
fim