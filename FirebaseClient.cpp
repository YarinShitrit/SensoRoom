#include "Firebase_Arduino_WiFiNINA.h"
void updateDatabase(FirebaseData data){
  if(Firebase.pushFloat(data, "/places/float_data" , 10.123)){

   if(data.dataType() =="float"){
     Serial.print(data.floatData());
   }
  }
   else{
     Serial.println(data.errorReason());
   }
}