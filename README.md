# NAND MD5 Checker - Vérification d'intégrité des régions mémoire NAND

![Embedded Systems](https://img.shields.io/badge/Platform-Embedded-blue)
![MD5](https://img.shields.io/badge/Algorithm-MD5-green)

## 📌 Description

Un outil embarqué pour calculer et vérifier les sommes de contrôle MD5 de régions critiques dans une mémoire flash NAND. Idéal pour valider l'intégrité du firmware et des systèmes de fichiers dans des environnements embarqués.

## ✨ Fonctionnalités

- ✅ Calcul MD5 pour 5 zones mémoire configurables
- 📟 Sortie UART claire avec noms de régions
- 🏗️ Implémentation MD5 optimisée pour systèmes embarqués
- 🔍 Vérification d'intégrité du firmware
- 🛡️ Détection de corruption de données

## 🗃️ Régions Vérifiées

| Nom            | Adresse Mémoire | Taille    |
|----------------|-----------------|-----------|
| Bootstrap      | 0x00040000      | 0x1D00    |
| U-Boot         | 0x00060000      | 0x5B000   |
| RootFS         | 0x00200000      | 0x3B20000 |
| DataFS         | 0x0A200000      | 0x480000  |
| FactoryDataFS  | 0x0F700000      | 0x1E0000  |

## 🚀 Utilisation

1. Flasher le programme sur la cible
2. Connecter la sortie UART à un terminal série
3. Les MD5 s'affichent automatiquement au démarrage
## Structure du Projet
.
├── main.c          # Logique principale et configuration
├── md5.c           # Implémentation MD5 optimisée
├── md5.h           # Header pour l'algorithme MD5
└── README.md       # Ce fichier

## 🛠️ Configuration

Modifier `main.c` pour :
- Ajuster les adresses/taille des régions
- Adapter l'initialisation UART selon le matériel

```c
RegionToCheck regions[] = {
    { "Nom", (uint8_t*)ADRESSE, TAILLE },
    // ...
};


