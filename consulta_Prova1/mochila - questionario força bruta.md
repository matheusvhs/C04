# Seja o problema da mochila com uma mochila de capacidade C e N objetos. Se N=5, então quantas opções a solução por força bruta para este problema vai avaliar?

No problema da mochila, uma solução por força bruta avaliaria todas as combinações possíveis de objetos. Se temos N=5 objetos, então o número total de combinações seria 2^N.

Portanto, para N=5, a solução por força bruta avaliaria 2^5 = 32 opções. Isso inclui a opção de não pegar nenhum objeto, que é uma das combinações possíveis.

# e se fosse usar estrategia gulosa

Se usarmos uma estratégia gulosa para resolver o problema da mochila, a quantidade de opções avaliadas seria diferente. A estratégia gulosa não avalia todas as combinações possíveis, mas faz a escolha que parece ser a melhor em cada passo.

No caso do problema da mochila, uma estratégia gulosa comum é escolher sempre o objeto com o maior valor por unidade de peso que ainda cabe na mochila. Portanto, o número de opções avaliadas seria no máximo N, que é o número de objetos disponíveis.

Então, se N=5, a estratégia gulosa avaliaria no máximo 5 opções. No entanto, é importante notar que a estratégia gulosa nem sempre produz a solução ótima para o problema da mochila. Ela produz uma solução ótima apenas quando os objetos podem ser divididos, ou seja, quando temos uma versão fracionária do problema da mochila. Para a versão 0/1 do problema da mochila, onde os objetos não podem ser divididos, a estratégia gulosa pode não encontrar a solução ótima.