// Incluir las bibliotecas necesarias
#include <Wire.h>
#include <Adafruit_MLX90614.h>

//Generar instancia de objeto que manejará las variables y funciones de la lectura del sensor
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
int temperatura=0;

//Inicialización de programa, la parte del programa que sucede sólo una vez al energizar
void setup() {

  //Iniciar comunicación serial
  Serial.begin(115200);
  Serial.println("Adafruit MLX90614 test");  
  // Configuracion de los pines I2C (SDA,SCL)
  Wire.begin (14,15);
  //Inicio de comunicación con el sensor
  mlx.begin();  
}

//Cuerpo del programa, la parte que se repite constantemente
void loop() {
   temperatura=mlx.readObjectTempC();
  //Secuencia donde se imprime la lectura del sensor mlx.readAmbientTempC ()
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); Serial.print(temperatura); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF()); 
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");

  Serial.println();

  //Espera entre lecturas
  delay(500);
}
