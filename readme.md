# 🎮 Super Trunfo - Countries

<div align="center">

A Super Trunfo style card game implemented in C, focused on comparing characteristics between countries.

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com/rafaumeu/super-trunfo)

---

## 📖 Index

| [Features](#-features) | [Requirements](#-requirements) | [How to Run](#-how-to-run) |
|-------------------------------------|---------------------------|----------------------------------|
| [Structure](#-structure) | [Game Levels](#-game-levels) | [Game Modes](#-game-modes) | [Contributing](#-contributing) |

---
</div>

## 🎯 Features

### Card System

- Registration of cards with unique properties
- 8 states (A-H) with 4 cities each
- Unique codes for each card (e.g., A01, B02)
- Property comparison system
- Automatic calculation of indicators (population density and GDP per capita)
- Classification of economic development and population density
- Support for city names with multiple words (e.g., "São Paulo", "Rio de Janeiro")
- Advanced comparison with multiple attributes

### Card Properties

- Population
- Area
- GDP
- Tourist Attractions
- Population Density (calculated)
- GDP per Capita (calculated)
- City Name (supports full names with spaces)
- State Code

## 💻 Requirements

- GCC Compiler
- Operating system: Windows, Linux, or macOS
- Basic knowledge of terminal/command line

## 🚀 How to Run

1. Clone the repository:

```bash
git clone <https://github.com/rafaumeu/super-trunfo.git>
cd super-trunfo
```

2. Compile the program:

```bash
gcc supertrunfo.c -o supertrunfo
```

3. Execute the program:

```bash
./supertrunfo
```

## 📁 Structure

```
super-trunfo/
├── supertrunfo.c     # source code
└── README.md         # Documentation
```

## 🎮 Game Levels

### 🌟 Novice Level

- Population density calculation
- GDP per capita calculation
- Advanced data analysis
- Decision structures for card classification
- Enhanced visual formatting

### 🏃 Adventurer Level (Implemented)

- Interactive attribute selection menu
- Multiple comparison modes (6 attributes)
- Inverse comparison rules for density
- Input validation system
- Advanced result display formatting

### 👑 Master Level (Implemented)

- Card comparison system (implemented with PIB per capita comparison)
- "Super Power" calculation
- Advanced game logic
- Multi-attribute comparison system
- Dynamic attribute selection menus
- Weighted comparison algorithms
- Special handling for attributes where lower values are better

## 🎲 Game Modes

### Single Attribute Comparison

Compare cards based on a single selected attribute like Population, Area, GDP, etc.

### Advanced Multi-Attribute Comparison

- Select two different attributes to compare cards
- System calculates a weighted sum of the attributes
- Special handling for attributes like Population Density where lower values are better
- Detailed results display showing individual attribute values and final scores

## 🤝 Contributing

1. Fork the project
2. Create your Feature Branch (`git checkout -b feature/NewFeature`)
3. Commit your changes (`git commit -m 'feat: Add new feature'`)
4. Push to the Branch (`git push origin feature/NewFeature`)
5. Open a Pull Request

## 📝 License

This project is under the MIT license. See the [LICENSE](LICENSE) file for more details.

---

<div align="center">
Developed as part of the MateCheck course

[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/rafaumeu)
</div>
