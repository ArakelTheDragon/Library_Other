Real BTC difficulty is 18 leading zero bytes to be found by hashing a message with a nonce. We have to find on which nonce does the hashed result have 18 leading zero bytes.

Example:
"Message Nonce"
Hash
Receive a hex byte sequence with 18 leading zero bytes like 0x00 0x00 0x00 0x00.......

The hashed for ESP8266 can only do 2 leading zero bytes, that is a nonce up to 65,536.

Install the Crypto library from the Library manager for the SHA3.h.
https://rweather.github.io/arduinolibs/crypto.html

The BTC block format is also important in real BTC hashing, the parts of the 80 bytes block are taken from different places.
https://www.blockchain.com/explorer/blocks/btc/0

The details of what every part of the block contains can be found here.
https://bitaps.com/000000000019d6689c085ae165831e934ff763ae46a2a6c172b3f1b60a8ce26f
