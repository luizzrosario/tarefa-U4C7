# Servo Motor

Este projeto implementa o controle de um **Servo Motor** e de um **LED RGB Azul** usando **PWM**, com simulação funcional no **Wokwi**.

## 🔧 **Sobre o Projeto**
- O código controla um **Servo Motor** e o **LED Azul do RGB** no **pino 12**.
- Utiliza **PWM (Modulação por Largura de Pulso)** para ajustar a posição do servo e o brilho do LED.
- A movimentação do servo ocorre em três posições: **0°, 90° e 180°**.
- Também inclui um **loop de movimentação suave** do servo entre 0° e 180°.

## Instruções de Instalação

1. **Clonar o repositório**:
   ```bash
   git clone <URL_DO_REPOSITORIO>
   ```

2. **Compilar o código**:
   Utilize o CMake para compilar o código para o RP2040.

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Carregar o código no RP2040**:
   Copie o arquivo compilado para a memória flash do microcontrolador.

4. **Conectar via USB**:
   O projeto utiliza comunicação USB, então conecte a Raspberry Pi Pico ao computador via cabo USB e abra um terminal serial para visualizar as saídas.

## 🛠 **Configuração no Wokwi**
Para simular o projeto no **Wokwi**, siga estes passos:

1. Acesse o site do Wokwi: [https://wokwi.com](https://wokwi.com)
2. Crie um novo projeto para **Raspberry Pi Pico**.
3. Adicione os seguintes componentes:
   - **Servo motor** conectado ao pino **GP12**.
   - **LED RGB** com o **canal azul no GP12**.
4. Copie e cole o código do projeto.
5. Clique em **Run** para iniciar a simulação.

## 📺 **Demonstração em Vídeo**
Confira um vídeo demonstrativo no YouTube: [[Vídeo Tarefa - U4C7](https://youtu.be/2NBxtkaRAiI)]
