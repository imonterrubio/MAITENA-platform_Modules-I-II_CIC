void Opciones() {

  Serial.println("|****************************|");
  Serial.println("|********|Batteryino|********|");
  Serial.println("|**|        Menu          |**|");
  Serial.println("|****************************|");                    
  Serial.println("");
  Serial.println("Select one of the following options:");
  Serial.println("1 STOP at the end of the actual synthesis");
  Serial.println("2 Safe position");
  Serial.println("3 Run complete synthesis cycle");
  Serial.println("4 Position tester");
  Serial.println("5 Mixer purge");
  Serial.println("6 Washing");
  Serial.println("12 Run complete synthesis cycle from synthesis nº2");
  Serial.println("13 Run complete synthesis cycle from synthesis nº3");
  Serial.println("14 Run complete synthesis cycle from synthesis nº4");
  Serial.println("15 Run complete synthesis cycle from synthesis nº5");
  Serial.println("16 Run complete synthesis cycle from synthesis nº6");
  Serial.println("17 Run complete synthesis cycle from synthesis nº7");
  Serial.println("18 Run complete synthesis cycle from synthesis nº8");
  Serial.println("19 Run complete synthesis cycle from synthesis nº9");
  Serial.println("20 Run complete synthesis cycle from synthesis nº10");
  Serial.println("21 Run complete synthesis cycle from synthesis nº11");
  Serial.println("22 Run complete synthesis cycle from synthesis nº12");

}


void Menu() {

  Opciones();
  int i = 0;
  while (i == 0) {
     i = Serial.parseInt();           
     }



  switch (i) {                                            
    
    case 2:
      Serial.println("Safe position");                 
      posicion(15);
      break;
    case 3:
      Serial.println("Complete synthesis cycle");     
      y = 1;                                                 
      accion();
      break;
    case 4:
      Serial.println("Position tester");               
      delay(1000);
      Serial.println("");
      PosSelectionMenu();
      PosSelection();
      break;
    case 5:
      Serial.println("Purgin mixer");                         
      posicion(15);                                         
      bombeo(Lagartija, WashingVolume);
      break;
    case 6:
      Serial.println("Washing");                    
      washing();
      break;
    case 12:
      Serial.println("Running from synthesis 2...");         
      y = 2;                                                   
      accion();
      break;
    case 13:
      Serial.println("Running from synthesis 3...");
      y = 3;
      accion();
      break;
    case 14:
      Serial.println("Running from synthesis 4...");
      y = 4;
      accion();
      break;
    case 15:
      Serial.println("Running from synthesis 5...");
      y = 5;
      accion();
      break;
    case 16:
      Serial.println("Running from synthesis 6...");
      y = 6;
      accion();
      break;
    case 17:
      Serial.println("Running from synthesis 7...");
      y = 7;
      accion();
      break;
    case 18:
      Serial.println("Running from synthesis 8...");
      y = 8;
      accion();
      break;
    case 19:
      Serial.println("Running from synthesis 9...");
      y = 9;
      accion();
      break;
    case 20:
      Serial.println("Running from synthesis 10...");
      y = 10;
      accion();
      break;
    case 21:
      Serial.println("Running from synthesis 11...");
      y = 11;
      accion();
      break;
    case 22:
      Serial.println("Running from synthesis 12...");
      y = 12;
      accion();
      break;

  }

  Serial.print("\n\n\n");
}
