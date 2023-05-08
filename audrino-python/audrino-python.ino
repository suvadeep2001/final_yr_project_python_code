char input;
int count;

void setup() {
    Serial.begin(9600); 
    

}
 
void loop() {
    if(Serial.available()){
        input = Serial.read();
        delay(1000);
        count+=1;
        Serial.println(String(count)+'-'+String(input));
        
    }
}