# WifiLed8266

Wifi LED Controller based on ESP8266

The Arduino environment for the ESP8266 can be found here: http://www.arduinesp.com/getting-started

FFMpeg commandline to feed screen to LED Strip:
ffmpeg -video_size 1920x1080 -framerate 25 -f x11grab -i :0.0+0,0 -f rawvideo -pix_fmt rgb24 -s 130x1 pipe: | while :; do dd bs=390 count=1 status=none > /dev/udp/192.168.8.251/2323; done
