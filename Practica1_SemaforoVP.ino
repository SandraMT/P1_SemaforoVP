
#define led_verde 13
#define led_amarillo 12
#define led_rojo 11


void setup() {
  // put your setup code here, to run once:
  pinMode(led_verde,OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_rojo,OUTPUT);
 
}

void loop() { 

Serial.println(valor_pote);
   
  verde();
  preventivaVerde();
  amarillo();   // al activarse se ve la funcionalidad normal de semaforos vehicular y peatonal
  rojo(); 
  
 
/* S E M A F O R O */
void verde (){
  
  //verde
  digitalWrite(led_verde,HIGH);   //alto
  delay(31500); //31500 original 

}

void preventivaVerde (){
  
    //verde
  digitalWrite(led_verde,HIGH);   //alto
  delay(31500); //31500 original

  digitalWrite(led_verde, LOW);
    //parpadeo
  for(int i = 0; i < 3; i++) {

    digitalWrite(led_verde, HIGH); //alto
    delay (500);
  
    digitalWrite(led_verde,LOW); //bajo
    delay(500);
  } //fin for
  
}

void amarillo (){
   //amarillo
  digitalWrite(led_amarillo, HIGH);  //alto
  delay(3000); //3000 

  digitalWrite(led_amarillo,LOW); 
}

void rojo (){
  //rojo sem
  digitalWrite(led_rojo, HIGH); //alto vehiculo
  delay(3000);

    
  digitalWrite(led_rojo,LOW); //bajo

}
