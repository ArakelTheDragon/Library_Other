**Disclaimer!!!** All files are provided as is and no guarantee is given that they will work or have no negative impact.

# All other topics
Every file is a separate project, or there will be a folder named "Tool_Project_Other" if there are more than 1 files needed.

Example:
Python_RenamePrefixOfFiles

**We have now started to try to profit so we can support our work by implementing Duino-Coin mining on our nodeMCU projects, the nodeMCU mines on the background a small amount and does the thing its suppose to do as well. For these projects only a binary will be included and no sketch.**

List of projects:
1. Python_AlarmOnWiFiDrop.zip
Sounds an alarm when the internet connection drops

2. Python_RDPInfo.zip
Displays the remote desktop connection information in the terminal and stores the info in a file. There is an exe file that you can run.
Includes:
- Python_RDPInfo_ExtendedWorking.py
- Python_RDPInfo_OriginalWorking.py
- Python_RDPInfo.exe - this file is based on the extended version, the original version does not have the option to add the info to a file and close the CMD on key press

4. Python_VPNTest.py
Test the VPN connection

5. Python_Speedtest_v3_extended.py
Test the WiFi speed for a long time and gives a middle result

6. Python_Discod_BasicBot.py
A Python Discord Basic Bo, it gets the bot online, you will need your bot token from the discord developer program.

7. Python_InternetSpeedTest.zip
Tests the average speed over time. Open the pspeedtest_v3_extendedWorking.exe file and leave it open, the results are also saved into log.txt

8. Python_AlarmOnWiFiDrop.zip
Sounds an alarm when the WiFi drops, it includes a Python script with the source code and an exe file that you can use. Please remember to download and place the wav and mp3 files in the same folder.

9. DancefloorPop_v2.m4a
Sample music made by us

10. DancefloorPop_v3.m4a
Sample music made by us

11. DancefloorPop_v4.m4a
Sample music made by us

12. FunkyPop_v2.m4a

13. FunkyPop_v3.m4a

14. FunkyPop_v4.m4a
    
15. ESP8266_LCD
The project works, display address is 0x27, 16x2 LCD, after many attempts I finally managed to get it to work, VCC to Vin(5V), SDA to D4, SCL D3

16. ESP8266_LCD_WebServer After getting the LCD to work, we made a web server that sends the info to the LCD. The LCD has 32 chars max, the server is set to 32 chars now. In the zip folder from the GitHub link you will find the ESP8266 project for setting up the LCD and the LCD with WebServer.

17. ESP8266_SmarHome_LCDLockDevice_v3 First step to develop a smart home, contains a nodeMCU wemost D1 mini, LCD 16x2 I2C, password login to a web server, the IP address can be found from your router at 192.168.0.1, possible improvements are add a keypad and door lock, develop the switch logic and motor  control, add sound alarm

18. ESP8266_LCD096_MonitorMining_v5_Working_v3_Final.zip A server which takes the stats from the mintme pool json response https://www.mintme.com/pool/api/accounts/0xe8911e98a00d36a1841945d6270611510f1c7e88, and displays on an OLED 0.96inch 128x32 display the stats for workers. It stores the earned tokens in an address with pointers and reads it back after a reboot.

19. Speedtest-master.zip Upload the unzipped files to your host, make sure the hosts supports js, css and is fast enough for downloading files for the speedtest. Test at cfctools.unaux.com/speedtest

20. Web_Tool_OnlineCalc a simple calc, can be found at http://cfctools.unaux.com/calc/

21. ESP8266_Repeater.zip A WiFi Mesh Repeaterm can be meshed or with a separate WiFi network, meshed devices have the same WiFi name and password as the original WiFi, they just boost the signal, NOT mesh devices have a different name than the original WiFi

22. Python_Windows_AutoInstall.zip The script installs a list of software to a Windows based system. This simplified the installation times and helps to setup client(worker) PCs faster.

The list so far contains:
7-zip
LibreOffice
Notepad++

23. Python_RaspberiPi_ClapBulb.zip
!!! This project is not tested !!!

The task involves writing a code for a Raspberry Pi 4 that operates indoors.

The project has two main components:
- The Raspberry Pi should send an SMS alert through Twilio whenever it detects a 'clap' sound.
- Upon receiving a "Y" reply via SMS, it should light up an LED bulb.
- 
24. ESP8266_Mining_Mineme_v2_Working.zip a working miner with nodeMCU ESP8266, it takes a long time for the miner to appear in the pool, since it has a valid share after a long time, we are using the lowest difficulty miner we have https://web.gonspool.com/ at port 3333, difficulty is 250 to 10000, we mine the mintme coin, our address is from the wallet on mintme.com

25. **ESP8266_GLCD128x64_Test_v4_WorkingImprovements**.**zip**, ESP8266 nodeMCU & LCD Display ST7567S GM12864-59N
26. **Proteus_XC8_MeasureCarBat_v1.zip** Measures the signal on pin AN0 and turns on LEDs in sequence from pin RB0 to RB3. Uses PIC16F88, PIC16F84A does not have an ADC module.
27. KiCad_SimpleDCMotorControl_v1.zip - simple DC motor direction and RPM control, youtube video
28. KiCad_nodeMCU_BoilerControl_v1.zip - control a boiler with nodeMCU wemos D1 mini and a DH11 temp sensor
29. KiCad Automotive Blinker v1 - cool automotive blinked with measuring car batt.
30. 30. ESP_Alexa_v2.zip - ESP Light Bulb Smart Plug with Alexa, we have now started to try to profit so we can support our work by implementing Duino-Coin mining on our nodeMCU projects, the nodeMCU mines on the background a small amount and does the thing its suppose to do as well.
Instructions on using:
- Connect to nodeMCU-setup wifi
- Set WiFi Name(SSID) and password
- Discover with Alexa
- Switch On/Off
