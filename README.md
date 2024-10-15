Este projeto é uma extensão da calculadora em C++ que executa 20 operações aritméticas escolhidas de forma aleatória.
Utiliza herança, polimorfismo, e unordered_map para mapear operadores a classes específicas. 
O programa gera números aleatórios e seleciona operações aritméticas para automatizar o cálculo, tornando-o adaptável e flexível.

Funcionalidades

	•	Suporte para operações: +, -, *, /
	•	Implementação de herança e polimorfismo
	•	Uso de unordered_map para mapear operadores às suas respectivas operações
	•	Geração de operações e números de forma aleatória
	•	Verificação de divisão por zero

Estrutura do Código

	•	Classe base Operacao: Define o método abstrato calcular() para ser implementado pelas subclasses.
	•	Subclasses: Soma, Subtracao, Multiplicacao, Divisao que implementam o método calcular() conforme a operação desejada.
	•	unordered_map: Mapeia os operadores para as suas respectivas classes, evitando condicionais.
	•	Geração Aleatória: Gera números entre 0 e 99 e escolhe operações aleatórias.
