# NAND MD5 Checker - NAND Memory Integrity Verification  
![Embedded Systems](https://img.shields.io/badge/Platform-Embedded-blue)  
![MD5](https://img.shields.io/badge/Algorithm-MD5-green)  

## 📌 Description  
An embedded tool to calculate and verify MD5 checksums of critical regions in NAND flash memory. Ideal for validating firmware and filesystem integrity in embedded environments.  

## ✨ Key Features  
✅ MD5 calculation for 5 configurable memory regions  
📟 Clear UART output with region names  
🏗️ MD5 implementation optimized for embedded systems  
🔍 Firmware integrity verification  
🛡️ Data corruption detection  

## 🗃️ Verified Regions  
| Region Name     | Memory Address | Size     |  
|-----------------|----------------|----------|  
| Bootstrap       | 0x00040000     | 0x1D00   |  
| U-Boot          | 0x00060000     | 0x5B000  |  
| RootFS          | 0x00200000     | 0x3B20000|  
| DataFS          | 0x0A200000     | 0x480000 |  
| FactoryDataFS   | 0x0F700000     | 0x1E0000 |  

## 🚀 Usage  
1. Flash the program to target device  
2. Connect UART output to serial terminal  
3. MD5 checksums will display automatically on startup
   
## 📂 Project Structure  
.
├── main.c # Main logic and configuration
├── md5.c # Optimized MD5 implementation
├── md5.h # MD5 algorithm header
└── README.md # This file

## 🛠️ Configuration  
Modify `main.c` to:  
- Adjust memory regions addresses/sizes  
- Adapt UART initialization for your hardware

⚠️ Important Notes
-UART initialization must be adapted to target hardware
-Sizes must match actual partition layouts
-Tested on ARM architecture (adaptable to other platforms)

```c
RegionToCheck regions[] = {
    { "Name", (uint8_t*)ADDRESS, SIZE },
    // ...
};
