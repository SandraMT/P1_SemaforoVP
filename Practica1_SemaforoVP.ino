#define led_verde 13
#define led_amarillo 12
#define led_rojo 11

#define verde1 10
#define rojo1 9
#define verde2 8 
#define rojo2 7

#define pote 1

int valor_pote = 0;

int boton1 = 6;
int push1 = 0;
int boton2 = 5;
int push2 = 0 ;
int control = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(led_verde,OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_rojo,OUTPUT);
  pinMode(verde1, OUTPUT);
  pinMode(rojo1, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(rojo2, OUTPUT);
  
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);

  Serial.begin(9600); //--------------- efectos de comprobacion funcion del potenciometro

}

void loop() { 

 push1 = LOW;//boton1
 push2 = LOW; // boton2

valor_pote = analogRead(pote);
//cambio = map(valor_pote,0,1023,10,60)*1000; //-------

Serial.println(valor_pote);
   
  verde();
  //preventivaVerde();
 // amarillo();   // al activarse se ve la funcionalidad normal de semaforos vehicular y peatonal
//  rojo(); 
  
  push1 = digitalRead(boton1);
  push2 = digitalRead(boton2);
  
  if(push1 == LOW || push2 == LOW) {

    control = 1; 
    }else {control = 0;} 
    
    if (control == 1) {
      preventivaVerde();
      amarillo();
      rojo();    
    } else { if (control = 0) { verde();}}
    
} 
 
/* S E M A F O R O */
void verde (){
  digitalWrite(rojo1,HIGH); //alto peaton//----
  digitalWrite(rojo2,HIGH);
  
  //verde
  digitalWrite(led_verde,HIGH);   //alto
  delay(valor_pote*17.05); //31500 original valor_pote

  digitalWrite(led_verde, LOW);
}

void preventivaVerde (){
  
  digitalWrite(rojo1,HIGH); //alto peaton
  digitalWrite(rojo2,HIGH);//-------
  
  //verde
  digitalWrite(led_verde,HIGH);   //alto
  delay(valor_pote*17.05); //31500 original

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
  delay(3000); //3000 ----------------

  digitalWrite(led_amarillo,LOW); 
}

void rojo (){
  //rojo sem
  digitalWrite(led_rojo, HIGH); //alto vehiculo
  
  delay(3000);
  digitalWrite(rojo1,LOW);  //peaton
  digitalWrite(rojo2,LOW); //peaton
  
    
//paso peaton
  digitalWrite(verde1,HIGH);
  digitalWrite(verde2,HIGH);
  
  delay(15000); //tiempo original verde peatonal 15000---------------------
  delay(17000); // tiempo original rojo semaforo 17000--------------------
  
  //parpadear 
for(int i = 0; i<3; i++){
  digitalWrite(verde1,HIGH);  //paso peatonal
  digitalWrite(verde2,HIGH); 
  delay (500);

  digitalWrite(verde1,LOW);  //paso peatonal--
  digitalWrite(verde2,LOW); //----
  delay(500);
}

  
  digitalWrite(rojo1,HIGH); //peaton tiempo espera vehiculo y peaton en rojo
  digitalWrite(rojo2,HIGH);// peaton
  
  delay(3000);
  digitalWrite(led_rojo,LOW); //bajo

  
  digitalWrite(verde1,LOW); //peaton---------
  digitalWrite(verde2,LOW);//-------

}
