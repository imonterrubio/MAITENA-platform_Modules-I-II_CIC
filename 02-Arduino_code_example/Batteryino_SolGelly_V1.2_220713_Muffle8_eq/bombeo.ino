

void bombeo(int bomba, String volumen) {
  
  Wire.beginTransmission(bomba);  
  Wire.write("d,");                
  Wire.write(volumen.c_str());
  Wire.endTransmission();            

  if (volumen=="W"){

    delay(60000);             
    }

  
  while (s < volumen.toFloat()) {
    for (i = 0; i <= received_from_computer; i++) {                              
      computerdata[i] = tolower(computerdata[i]);                          
      }
    i = 0;                                                                    


    Wire.beginTransmission(bomba);                                            
    Wire.write("r");                                                   
    Wire.endTransmission();                                                     

    if (strcmp("r", "sleep") != 0) {                                   

      delay(time_);                                                            

      Wire.requestFrom(bomba, 20, 1);                                         
      code = Wire.read();                                                      
    }

    while (Wire.available()) {          //are there bytes to receive.
      in_char = Wire.read();            //receive a byte.
      pmp_data[i] = in_char;            //load this byte into our array.
      i += 1;                           //incur the counter for the array element.
      if (in_char == 0) {               //if we see that we have been sent a null command.
        i = 0;                          //reset the counter i to 0.
        break;                          //exit the while loop.
      }
    }
    s = atof(pmp_data);
    Serial.println(s);          //print the data.
  }
  s = 0;

}
