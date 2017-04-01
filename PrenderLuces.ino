
//Numero de canal digital a usar por arduino
int audio = 7;

//Acumulador de aplauso
int contador = 0;

//Variable de encendido o apagado de luces
bool encendido = 0;


void setup() {
  //Inicializa el puerto de comunicacion serial a 9600 bits por segundo:
  Serial.begin(9600);
  //Carga la variable de audio como canal de entrada
  pinMode(audio, INPUT);
}


void loop() {

  // Lectura del sensor de audio a una variable de siste,a
  int audioValue = digitalRead(audio);

  // Si el sensor genera sonido incrementa el contador y imprime en pantalla
  if (audioValue == 1) {
    contador++;
    Serial.print("+");
    Serial.print(contador);
    
  }

  // Validacion para encender y apagar la luz cuando el contador llega a 10
  if (contador >= 10) {
    encendido = (encendido == 0 ? 1 : 0);
    Serial.print  (" | Estado:");
    Serial.print(encendido);
    Serial.println("");
    //pausa de 5 segundo para dejar de leer el sensor de audio
    delay(5000);
    contador = 0;
  }
}
