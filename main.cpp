#include "mbed.h"
#include "arm_book_lib.h"

int main() {

    DigitalIn liquidDetector(D2);           // Sensor de líquido conectado a D2
    DigitalOut led1(LED1);                  // Led de aviso de llenado de botella en LED1
    PwmOut Servo(A0);                       // Servo conectado a A0

    // Set
    Servo.period_ms(20);                    // El período del servo será de 20 ms
    Servo.pulsewidth_ms(1);                 // Servo en posición inicial

    liquidDetector.mode(PullDown);          // Sensor de líquido en modo pull down        
    led1 = OFF;                             // LED1 apagado

    while (true) {
        if ( liquidDetector == ON ) {
            led1 = ON;                      // Se enciende el LED1 para indicar que se llenó la botella
            Servo.pulsewidth_us(2500);      // Si se detecta el máximo nivel de llenado de la botella el servo gira y baja la llave del dispenser cortando el suministro de agua   
        }
        
        if ( liquidDetector == OFF ) {      // Si no se detecta el máximo nivel de llenado se sigue llenando la botella
            led1 = OFF;                     // sin girar al servo ni apagar el led  
        }
    }
}
