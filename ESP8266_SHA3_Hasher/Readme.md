Real BTC difficulty is 18 leading zero bytes to be found by hashing a message with a nonce. We have to find on which nonce does the hashed result have 18 leading zero bytes.

Example:
"Message Nonce"
Hash
Receive a hex byte sequence with 18 leading zero bytes like 0x00 0x00 0x00 0x00.......

The hashed for ESP8266 can only do 2 leading zero bytes, that is a nonce up to 65,536.

Install the Crypto library from the Library manager for the SHA3.h.
https://rweather.github.io/arduinolibs/crypto.html
