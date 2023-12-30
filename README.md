# ISS Notification System

Some background, In 2013 I made some PHP scripts that run in the CLI (I've included them here if you wish to run them). There was one that would tell where and about how far away the ISS was from my location. It would also change the color of a Blink Stick, the idea was as the ISS got closer it would go from RED to GREEN and as it got farther away it would go from GREEN back to RED and then OFF. This was to make it easier to setup and contact the ISS with APRS.  
The 2nd PHP script would tell how many people were in space, and which space craft they were on board at the time.  
The 3rd script would give times for future ISS passes over my location.  

For a long time I've wanted to move these scripts to an arduino, and I finally did that.  
The D-Duino (NodeMCU with OLED) displays more or less the same information the PHP scripts did. I'm pretty happy with the formating of the screen. The Pass prediction needs some work - it currently tells passes in UTC time.  And I can only display 5 astronuts.   If you open a serial console at 9600 you'll see a bit more information.  

## Project and Videos

https://www.instructables.com/id/Simple-ISS-Notification-System  

Videos:  
https://youtu.be/gRf5m8jprZA  
https://youtu.be/1VR1-9QUc8k  

## Installation

Libraries Needed:  
ArduinoJson.h https://github.com/bblanchon/ArduinoJson  
Adafruit_NeoPixel https://github.com/adafruit/Adafruit_NeoPixel  
WifiManager.h https://github.com/tzapu/WiFiManager  
TimeLib.h  
esp8266-oled-ssd1306 https://github.com/squix78/esp8266-oled-ssd1306  

## Things to do

* Find away to display PASS information in local time. (Not UTC)  
* Update To use the ESP32 X-boards with OLED.

## Hardware

D-Duino (NodeMCU)  
https://www.aliexpress.com/item/NodeMCU-CP2102-ESP8266-ESP-12F-For-Wemos-For-Arduino-Wifi-Wireless-0-96-Inch-Digital-OLED/32847714220.html?ws_ab_test=searchweb0_0,searchweb201602_1_10065_10344_10068_10130_10324_10342_10547_10325_10343_10546_10340_10548_10341_10545_10084_10617_10083_10616_10618_10615_10307_5920011_10313_10059_10534_100031_10103_441_10624_442_10623_10622_10621_10620_10142,searchweb201603_2,ppcSwitch_5&algo_expid=7d3179c6-10cc-4b5a-b20f-4ab8a6a08231-8&algo_pvid=7d3179c6-10cc-4b5a-b20f-4ab8a6a08231&priceBeautifyAB=4  

* See related project for "Eric" hardware is a D1 Mini, WS2812 Shield, and lens  

## Related Project

Instructable and More information:  
https://www.instructables.com/id/Supervisor-Eric-Inspired-LED-Cube-People-of-Earth

Videos:  
Eric Build Video (start to finish) https://youtu.be/G468Jh-z9yk  
Google Home & Dweet.io video https://youtu.be/d3GBDp08U_U  

## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request

## Support Me

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  

https://ko-fi.com/lfmiller  

## Other Projects

https://www.youtube.com/channel/UCP6Vh4hfyJF288MTaRAF36w  
https://kd8bxp.blogspot.com/  


## Credits

Copyright (c) 2018 LeRoy Miller  
Copyright (c) 2023 LeRoy Miller  

## License

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>
