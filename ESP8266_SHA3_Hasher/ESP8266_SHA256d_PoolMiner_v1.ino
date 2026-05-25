#include "BTC.h"

void setup() {
  Serial.begin(9600);

  // This is a real block from https://learnmeabitcoin.com/explorer/block/00000000000000000001aa8bd5aea63f63e9141f601abb9e69198efd8697c948
  // Block mining has been passed succesfully but we did not brute force to get the nonce we got it after the block was mined
  // Block #921633 header fields (correct order, no reversal on prevHash)
  const char* versionHex   = "00804021";  // Version: 0x21408000 // Needs reversal
  const char* prevHashHex  = "adfba2b408e45f0b37a7f0860070b66c35608ad38fc800000000000000000000";  // Already little-endian
  const char* merkleHex    = "25a331ef9c4cfc2828fe5b810f6347011d0c348a8d058e73150feeac2d528eef";  // Needs reversal
  const char* timeHex      = "e7ec0469";  // Timestamp: 0x6904ece7 // Needs reversal
  const char* bitsHex      = "fbcd0117";  // Bits: 0x1701cdfb // Needs reversal
  const char* nonceHex     = "670d3b5a";  // Nonce: 0x5a3b0d67 // Needs reversal

  uint8_t header[80];
  size_t offset = 0;

  // Fill header with little-endian formatted fields
  hexToBytes(versionHex, header + offset, 4); offset += 4;
  hexToBytes(prevHashHex, header + offset, 32); offset += 32;  // DO NOT reverse
  hexToBytes(merkleHex, header + offset, 32); reverseBytes(header + offset, 32); offset += 32;
  hexToBytes(timeHex, header + offset, 4); offset += 4;
  hexToBytes(bitsHex, header + offset, 4); offset += 4;
  hexToBytes(nonceHex, header + offset, 4); offset += 4;

  // Print raw header for verification
  Serial.println("Raw block header (hex):");
  for (int i = 0; i < 80; i++) {
    if (header[i] < 0x10) Serial.print("0");
    Serial.print(header[i], HEX);
  }
  Serial.println();

  // Hash the header using SHA256d
  uint8_t hash[32];
  sha256d(header, 80, hash);

  Serial.println("SHA256d of block #921633:");
  Serial.println(toHex(hash, 32));
}

void loop() {}
