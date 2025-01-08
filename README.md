# What's AGV - IoT - Project ?

sebuah rancangan IoT dengan membuat sebuah mobil yang dapat bergerak mengikuti jalur yang ditentukan menggunakan Infrared sensor & Control aplikasi Blynk

# Component :
- Esp32 - Wifi : untuk menghubungkan Remote control dengan aplikasi BLYNK
- x4 motor DC : sebagai penggerak Ban
- x1 Infrared sensor : sebagai pendeteksi jalur
- baterai Lithium-ion : sebagai sumber daya energi

# how to implement ?
- Rancang komponen sensor sesuai mekanisme rancnagan
- Instalasi / buka arduino ide -> select ESP8266 Board
- upload code ESP-8266

# how to integrated with BLNYK application : 
- firstly copy template on the code (esp-8266)

```cpp
char auth[] = "ejgdo13y0bvi-a2KB9m_hYlLZ5LUzDqd"; // Replace with your Blynk Auth Token
```
- open BLYNK in the chrome
- connect ESP-8266 with local wifi
- AGV is ready to run

# Preview : 
- gambar rancangan kontrol aplikasi BLYNK : https://github.com/Vanss3375/AGV-IoT-Project/blob/main/blynk%20app.jpg
- gambar rancangan video : https://github.com/Vanss3375/AGV-IoT-Project/blob/main/video%20demo.mp4
