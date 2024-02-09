# Definições

1. Um Autômato Finito é um modelo matemático para expressar um Diagrama de Estados para abstrair um Modelo Computacional.

2. Para tal, é fundamental entender o conceito de Estados nessa situação.

    * A melhor forma de entender o que é um Estado, é pensar que cada Estado é uma abstração de uma situação Real, ou caso seja um modelo puramente abstrato sem conexão com a realidade, uma posição que o Autômato aponta e que poderá apontar para outro Estado devido a uma entrada.

3. Mas o que é uma Entrada?

    * Primeiramente, a Entrada do Autômato é como o input de um teclado para seu computador, é apenas uma forma abstrata de permitir iterações com o meio externo e ter consequências no seu modelo computacional. 

4. Formato da Entrada: 
    * É importante entender o Conceito de Caractere, pode-se entender como o "char" que usamos em C++. Essa entrada será uma Cadeia de Caracteres, ou seja, uma String.

5. Esse modelo Computacional terá uma definição Formal, ele apresentará:
    * Um Conjunto de Estados;
    * Um Conjunto de Caracteres que serão o alfabeto do Autômato;
    * Uma função de Transição, em que terá o Estado e um caractere, com resultado para outro Estado;
    * Um Estado inícial para nosso Modelo;
    * Um conjunto de Estados de Aceitação.

---

# Objetivos deste projeto

* Desenvolver uma aplicação de terminal que permita atribuir entradas para um Autômato finito.
    * O usuário irá atribuir a definição formal do autômato como entrada;