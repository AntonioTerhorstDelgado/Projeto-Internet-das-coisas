#define servomotor 2
char senha[2] = {'1', '2'};
char tecla[4][4] = { {'1','2','3','A'}, 
                     {'4','5','6','B'}, 
                     {'7','8','9','C'}, 
                     {'*','0','#','D'} };

char leTeclado(void) {
  byte lin, col;

  for (col = 0; col < 4; col++)
    digitalWrite(8 - col, HIGH);  // todas as colunas desabilitadas
    
  for (lin = 0; lin < 4; lin++)
    for (col = 0; col < 4; col++) {
      digitalWrite(8 - col, LOW);
      if (digitalRead(12 - lin) == LOW)
        return tecla[lin][col];
      digitalWrite(8 - col, HIGH);  // retorna o valor da tecla
    }
  return '\0';  // nenhuma tecla foi pressionada
}
 
void setup() {
  pinMode(12, INPUT_PULLUP);  // linha 1
  pinMode(11, INPUT_PULLUP);  // linha 2
  pinMode(10, INPUT_PULLUP);  // linha 3
  pinMode(9, INPUT_PULLUP);   // linha 4
  pinMode(8, OUTPUT);         // coluna 1
  pinMode(7, OUTPUT);         // coluna 2
  pinMode(6, OUTPUT);         // coluna 3
  pinMode(5, OUTPUT);         // coluna 4
  pinMode(servomotor, OUTPUT); // servo motor
   digitalWrite(servomotor, LOW);
  Serial.begin(9600);
}

void loop() {
  char tec = leTeclado();
  if (tec == senha[0]) {
    // Primeiro dígito correto
    // Armazenar o primeiro dígito
  } else if (tec == senha[1]) {
    // Segundo dígito correto
    // Verificar se o primeiro dígito estava correto
    // Acionar o servomotor se a senha estiver correta
    digitalWrite(servomotor,HIGH);
  } else {
    // Dígito incorreto
    // Resetar o processo de leitura de senha
    digitalWrite(servomotor, LOW);
  }
}
