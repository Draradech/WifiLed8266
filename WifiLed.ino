void setup(void){
  setupWifi();
  setupUdp();
  setupWeb();
  setupLeds();
}

void loop(void){
  loopWifi();
  loopUdp();
  loopWeb();
  loopLeds();
}
