#define GREEN 3
#define BLANCA 4
#define TIGGER 5
#define ECHO 6

void setup()
{
  
  Serial.begin(9600);//iniciailzamos la comunicación 
  pinMode(TIGGER, OUTPUT); //pin como salida
  pinMode(ECHO, INPUT);  //pin como entrada
  digitalWrite(TIGGER, LOW);//Inicializamos el pin con 0

  pinMode(GREEN, OUTPUT);
  digitalWrite(GREEN, LOW);
  pinMode(BLANCA, OUTPUT);
  digitalWrite(BLANCA, LOW);

}
void loop()
{

  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(TIGGER, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(TIGGER, LOW);
  
  t = pulseIn(ECHO, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.println();

  if (d > 20){
    digitalWrite(BLANCA, LOW);  
    digitalWrite(GREEN, HIGH);
  }else{
    digitalWrite(BLANCA, HIGH); 
    digitalWrite(GREEN, LOW);  
  }
  
  
}
