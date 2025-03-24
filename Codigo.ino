#include "Keyboard.h"  // Biblioteca para simular um teclado USB
#include "Mouse.h"     // Biblioteca para simular um mouse USB

// Definindo os pinos dos LEDs (opcional para feedback visual)
const int ledPin = 13;  // LED para mostrar quando o macro é executado

// Variáveis de controle de tempo
unsigned long previousMillis = 0;  // Tempo da última ação
unsigned long interval = 3000;  // Intervalo de 3 segundos entre as ações do macro

void setup() {
  pinMode(ledPin, OUTPUT);  // Configura o pino do LED como saída
  Keyboard.begin();  // Inicializa a funcionalidade de teclado
  Mouse.begin();  // Inicializa a funcionalidade de mouse
}

void loop() {
  unsigned long currentMillis = millis();  // Obtém o tempo atual

  // Verifica se já passou o tempo para realizar o próximo comando
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Atualiza o tempo da última ação

    // Realiza uma série de comandos de teclado e mouse

    // 1. Simula pressionar a tecla "1" (habilidade ou ação)
    Keyboard.press('1');
    delay(100);  // Delay curto para garantir que o jogo reconheça
    Keyboard.release('1');

    // 2. Simula pressionar a tecla "2" (ou outra habilidade)
    Keyboard.press('2');
    delay(100);
    Keyboard.release('2');

    // 3. Simula pressionar a tecla "Q" (habilidade 3)
    Keyboard.press('q');
    delay(100);
    Keyboard.release('q');

    // 4. Simula pressionar a tecla "E" (habilidade 4)
    Keyboard.press('e');
    delay(100);
    Keyboard.release('e');

    // 5. Simula pressionar a tecla "R" (habilidade 5)
    Keyboard.press('r');
    delay(100);
    Keyboard.release('r');

    // 6. Simula pressionar "W" para mover o personagem para frente
    Keyboard.press('w');
    delay(200);  // Simula o personagem se movendo por 200ms
    Keyboard.release('w');

    // 7. Simula pressionar "A" para mover o personagem para a esquerda
    Keyboard.press('a');
    delay(200);
    Keyboard.release('a');

    // 8. Simula pressionar "D" para mover o personagem para a direita
    Keyboard.press('d');
    delay(200);
    Keyboard.release('d');

    // 9. Simula pressionar a tecla "F" para interagir com objetos
    Keyboard.press('f');
    delay(100);
    Keyboard.release('f');

    // 10. Simula pressionar "F1" para ativar uma habilidade ou interação
    Keyboard.press(KEY_F1);
    delay(100);
    Keyboard.release(KEY_F1);

    // 11. Simula um clique do mouse esquerdo (interação no jogo)
    Mouse.click(MOUSE_LEFT);
    delay(200);

    // 12. Simula um clique do mouse direito (para abrir menus ou opções)
    Mouse.click(MOUSE_RIGHT);
    delay(200);

    // 13. Realiza um duplo clique com o botão esquerdo do mouse
    doubleClick();

    // 14. Realiza uma rolagem do mouse (por exemplo, para rolar entre as habilidades ou itens)
    Mouse.move(0, 0, 1);  // Rola para cima
    delay(100);
    Mouse.move(0, 0, -1);  // Rola para baixo
    delay(100);

    // 15. Alterna para a próxima habilidade usando a tecla "Tab"
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.release(KEY_TAB);

    // Feedback com LED (indica que o macro foi executado)
    digitalWrite(ledPin, HIGH);
    delay(200);  // Mantém o LED aceso por 200ms
    digitalWrite(ledPin, LOW);

    // Define o próximo intervalo entre as ações do macro
    interval = random(2000, 4000);  // Intervalo aleatório entre 2 e 4 segundos
  }
}

void doubleClick() {
  for (int i = 0; i < 2; i++) {
    Mouse.press(MOUSE_LEFT);
    delay(300);  // Pequeno atraso para simular um clique duplo
    Mouse.release(MOUSE_LEFT);
    delay(300);  // Pequeno intervalo entre os cliques
  }
}
