#include "esp01_mqtt.h"

/*  Устанавливает соединение с MQTT
 *  @return Возвращает длину полученного сообщения
**/ 
int esp01_mqtt_connect(char *buff, char *clientID)
{
  int packet_len = 14;
  int clientID_len = strlen(clientID);
  buff[0] = 0x10;
  //buff[1] = 0x11;
  buff[1] = 0x0c + clientID_len; // remaining length
  buff[2] = 0x00; // variable len2
  buff[3] = 0x04; // variable len1
  buff[4] = 'M';
  buff[5] = 'Q';
  buff[6] = 'T';
  buff[7] = 'T';
  buff[8] = 0x04;
  buff[9] = 0x02;
  buff[10] = 0x00;
  buff[11] = 0x3c;
  buff[12] = 0x00; // payload len2
  buff[13] = clientID_len; // payload len1
  for (int i = 0; i <= clientID_len; i++)
  {
    buff[14 + i] = clientID[i];
    packet_len++;
  }
  return packet_len;
}

/*  Публикация в mqtt
 *  @return Возвращает длину полученного сообщения
**/ 
int esp01_mqtt_publish(char *buff, char *topic, char *message)
{
  int packet_len = 4;

  int topic_len = strlen(topic);
  int message_len = strlen(message);

  buff[0] = 0x30;
  buff[1] = 0x04 + topic_len + message_len;
  
  buff[2] = 0x00; // Length MSB 0
  buff[3] = topic_len; // Length LSB
  // topic name
  for (int i = 0; i <= topic_len; i++)
  {
    buff[packet_len] = topic[i];
    packet_len++;
  }

  buff[packet_len] = 0x00;
  buff[packet_len++] = 0x02;
  for (int i = 0; i <= message_len; i++)
  {
    buff[packet_len] = message[i];
    packet_len++;
  }

  return packet_len;
}
