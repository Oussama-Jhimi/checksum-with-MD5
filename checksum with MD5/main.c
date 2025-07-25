
#include "md5.h"
#include <stdint.h>
#include <stdio.h>

typedef struct {
    const char* name;
    uint8_t* address;
    size_t size;
} RegionToCheck;

// Simule l'initialisation UART (à adapter selon ton matériel)
void uart_init(void) {
    // Initialiser UART ici si besoin (ou déjà fait par SAM-BA)
}

// Affiche le MD5 d'une région mémoire avec nom
void print_md5_region(const RegionToCheck* region) {
    uint8_t digest[16];
    md5(region->address, region->size, digest);

    printf("%s MD5: ", region->name);
    for (int i = 0; i < 16; i++) {
        printf("%02x", digest[i]);
    }
    printf("\r\n");
}

int main(void) {
    uart_init();

    RegionToCheck regions[] = {
        { "Bootstrap",      (uint8_t*)0x00040000, 0x00001D00 },
        { "U-Boot",         (uint8_t*)0x00060000, 0x0005B000 },
        { "RootFS",         (uint8_t*)0x00200000, 0x03B20000 },
        { "DataFS",         (uint8_t*)0x0a200000, 0x00480000 },
        { "FactoryDataFS",  (uint8_t*)0x0f700000, 0x001E0000 }
    };

    int num_regions = sizeof(regions) / sizeof(regions[0]);

    printf("=== Vérification MD5 des 5 zones NAND ===\r\n");

    for (int i = 0; i < num_regions; i++) {
        print_md5_region(&regions[i]);
    }

    printf("=== Fin vérification NAND ===\r\n");

    while (1);
}
