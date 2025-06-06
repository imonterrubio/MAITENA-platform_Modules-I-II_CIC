void PosSelectionMenu() {

  Serial.println("Please, select the position you want to try:");
  Serial.println("Possible options:");
  Serial.println("");
  Serial.println("1. Pos 1");
  Serial.println("2. Pos 2");
  Serial.println("3. Pos 3");
  Serial.println("4. Pos 4");
  Serial.println("5. Pos 5");
  Serial.println("6. Pos 6");
  Serial.println("7. Pos 7");
  Serial.println("8. Pos 8");
  Serial.println("9. Pos 9");
  Serial.println("10. Pos 10");
  Serial.println("11. Pos 11");
  Serial.println("12. Pos 12");
  Serial.println("15. Pos 15 (waste)");
  Serial.println("100. Pos 0 (origin)");


}


void PosSelection() {

  int PS = 0;

  while (PS == 0) {
    PS = Serial.parseInt();
  }


  switch (PS) {

    case 1:

      Serial.println("\nTrying position 1");
      posicion(1);
      delay(1500);
      posicion(0);
      break;

    case 2:

      Serial.println("\nTrying position 2");
      posicion(2);
      delay(1500);
      posicion(0);
      break;

    case 3:

      Serial.println("\nTrying position 3");
      posicion(3);
      delay(1500);
      posicion(0);
      break;

    case 4:

      Serial.println("\nTrying position 4");
      posicion(4);
      delay(1500);
      posicion(0);
      break;

    case 5:

      Serial.println("\nTrying position 5");
      posicion(5);
      delay(1500);
      posicion(0);
      break;

    case 6:

      Serial.println("\nTrying position 6");
      posicion(6);
      delay(1500);
      posicion(0);
      break;

    case 7:

      Serial.println("\nTrying position 7");
      posicion(7);
      delay(1500);
      posicion(0);
      break;

    case 8:

      Serial.println("\nTrying position 8");
      posicion(8);
      delay(1500);
      posicion(0);
      break;

    case 9:

      Serial.println("\nTrying position 9");
      posicion(9);
      delay(1500);
      posicion(0);
      break;

    case 10:

      Serial.println("\nTrying position 10");
      posicion(10);
      delay(1500);
      posicion(0);
      break;

    case 11:

      Serial.println("\nTrying position 11");
      posicion(11);
      delay(1500);
      posicion(0);
      break;

    case 12:

      Serial.println("\nTrying position 12");
      posicion(12);
      delay(1500);
      posicion(0);
      break;

    case 15:

      Serial.println("\nTrying position 15 (waste)");
      posicion(15);
      delay(1500);
      posicion(0);
      break;

    case 100:

      Serial.println("\nTrying position 0 (origin)");
      posicion(0);
      delay(1500);
      posicion(0);
      break;

    default:

      Serial.println("\nNo pump selected. Try to select again. \n\n");


  }
  delay(1000);
  Serial.print("\n\n\n");

}
