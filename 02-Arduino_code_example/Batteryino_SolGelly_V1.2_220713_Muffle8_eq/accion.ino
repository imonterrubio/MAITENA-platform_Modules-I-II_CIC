
void accion() {

  while (y < 13) {               
    posicion(15);                
    for (int x = 1; x < 8; x++) {   
      delay(1000);
      bombeo(O[x][y], A[(O[x][y]) - 2][y]); 
      }

    
    delay(2000);                  
    bombeo(Lagartija, "20");        
    posicion(0);              
    delay(1000);
    posicion(y);               
    delay(1000);
    bombeo(Lagartija, MixVolume);  
    posicion(0);                 
    delay(1000);
    posicion(15);
    washing();                     
    
    y++;                           
  }
  y = 1;                         
  Serial.print("\n\n\n");
}
