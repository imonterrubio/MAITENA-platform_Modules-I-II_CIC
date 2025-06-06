

void movimientoinfinito() {        

  for (int i = 0; i < 13; i++) {


    stepperX1.moveTo(p[i][0]);
    stepperX2.moveTo(p[i][0]);
    pareados.runSpeedToPosition();
    stepperY.runToNewPosition(p[i][1]);

    delay(3000);

    stepperX1.moveTo(p[0][0]);
    stepperX2.moveTo(p[0][0]);
    pareados.runSpeedToPosition();
    stepperY.runToNewPosition(p[0][1]);

  }
}

void posicion(int posicion) {      

  stepperX1.moveTo(p[posicion][0]); 
  stepperX2.moveTo(p[posicion][0]);
  pareados.runSpeedToPosition();   
  stepperY.runToNewPosition(p[posicion][1]);
}
