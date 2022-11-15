# esp01-mqtt
Simple MQTT packet creator, for use with esp01  AT-commands (esp8266 tcp/ip).
* No board dependencies
* No arduino (and other) additional libs

## Example
```C
    int packet_len = 0;
    char buffer[128];
    
    // first make connection
    packet_len = esp01_mqtt_connect(buffer, "your_esp01");
    // send buffer to esp01 via uart like this
    uart_put_all("AT+CIPSENDEX=100\r\n");
    vTaskDelay(300);
    uart_put_all_len(buffer, packet_len);
    uart_put_all("\\0");
    
    // second, publish stuff
    packet_len = esp01_mqtt_publish(buffer, "kitchen", "stuff is ready");
```
