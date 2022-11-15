/*
 * This lib for making simple mqtt packages (for educational purposes only, mmkay)
 * For reference https://public.dhe.ibm.com/software/dw/webservices/ws-mqtt/mqtt-v3r1.html
**/

int esp01_mqtt_connect(char *buff, char *clientID);
int esp01_mqtt_publish(char *buff, char *topic, char *message);