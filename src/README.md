# Diretório de Atividades

## [Atividade 1: Algoritmo de Bresenham](./activity1/activity1.py)
Este exercício implementa o algoritmo de Bresenham para traçar linhas vetoriais em um plano matricial. O algoritmo é eficiente e amplamente utilizado em computação gráfica para desenhar linhas entre dois pontos.

A saída do algoritmo retorna uma lista de tuplas, onde as tupla representam as coordenadas dos pontos que formam a linha entre os pontos de início e fim especificados.
Segue um exemplo de uso do algoritmo:

```python
Pontos calculados pelo algoritmo de Bresenham:
(1, 1) (2, 2)(3, 2) (4, 3)  (5, 3) (6, 4) (7, 4) (8, 5)
```

> [!NOTE]
> A parte manuscrita da atividade [está disponível aqui](https://drive.google.com/file/d/1QeYxhLlDFvzG8X-So6OUxdDqNpHj3Ohu/view?usp=drive_link).

## [Atividade 2: Flor de Abril em OpenGL](./activity2/activity2.c)
Este exercício desenha uma "flor de abril" utilizando OpenGL. A flor é composta por um caule e quatro pétalas coloridas, cada uma desenhada como um triângulo.

> [!NOTE]
> Como resultado do exercício, você deve obter uma flor semelhante à imagem abaixo:
> ![Flor de Abril](./activity2/flower.png)

# [Atividade 3: A Flor de Abril agora é um catavento!](./activity3/activity3.c)

Este exercício expande a atividade anterior, onde a flor de abril agora se comporta como um catavento. A flor pode ser rotacionada no sentido horário ou anti-horário, dependendo da tecla pressionada.
Para rotacionar a flor, utilize as seguintes teclas:
- Pressione `r` para rotacionar no sentido horário.
- Pressione `e` para rotacionar no sentido anti-horário.

A flor também pode ser parada ao soltar as teclas, e a velocidade de rotação é limitada para evitar rotações muito rápidas.

> [!NOTE]
> Como resultado do exercício, você deve obter um catavento semelhante à animação abaixo:
> ![Catavento](./activity3/catavento.gif)

> [!WARNING]
> Devido a limitações de framerate do formato GIF (24 fps), a animação pode não ser tão suave quanto a implementação real.

# [Atividade 4: Translação de planetas ao redor do sol com luas!](./activity4/activity4.c)

Este exercício propõe a criação de um sistema solar simples, onde dois planetas, nessa atividade azul e vermelho, giram ao redor do sol. Um dos planetas, no nosso caso, o vermelho, deve possuir duas luas que orbitam ao seu redor. Um das luas deve girar no eixo X, enquanto a outra deve girar no plano XY.

A rotação do planeta e das luas é controlada por uma variável de tempo, simulando o movimento orbital.

Para facilitar a visualização, o sol é opaco e os planetas são representados por esferas wireframe. As luas também são esferas wireframe, com cores diferentes para cada uma.

#### Observações:
- Fiz uso de `glEnable(GL_DEPTH_TEST);` para garantir que as esferas sejam desenhadas corretamente em relação à profundidade.
- Além disso, o código inclui uma rotação estética de 90 graus no eixo Y para alinhar a texture de wireframe dos planetas e luas.

> [!NOTE]
> Como resultado do exercício, você deve obter uma animação semelhante à imagem abaixo:
> ![Sistema Solar](./activity4/sistema_solar.gif)

> [!WARNING]
> Devido a limitações de framerate do formato GIF (24 fps), a animação pode não ser tão suave quanto a implementação real.