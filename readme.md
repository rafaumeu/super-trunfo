# 🎮 Super Trunfo - Countries

<div align="center">

A Super Trunfo (Top Trumps) style card game implemented in C, focused on comparing country characteristics.

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com/rafaumeu/super-trunfo)

---

## 📖 Table of Contents

| [Features](#-features) | [Requirements](#-requirements) | [How to Run](#-how-to-run) |
|---------------------|--------------------------|------------------------|
| [Structure](#-structure) | [Game Levels](#-game-levels) | [Contributing](#-contributing) |

---
</div>

## 🎯 Features

### Card System

- Unique property card registration
- 8 states (A-H) with 4 cities each
- Unique code system (e.g., A01, B02)
- Property comparison system

### Card Properties

- Population
- Area
- GDP
- Tourist Attractions

## 💻 Requirements

- GCC Compiler
- Windows, Linux, or macOS operating system
- Basic terminal/command line knowledge

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

3. Run the program:

```bash
./supertrunfo
```

## 📁 Structure

```
super-trunfo/
├── src/
│   └── supertrunfo.c    # Main game implementation
├── .github/
│   └── workflows/
│       └── project-automation.yml
├── .vscode/
│   └── tasks.json
└── README.md            # Documentation
```

## 🎮 Game Levels

### 🌟 Novice Level

- Basic card registration
- Data visualization
- Unique code system

### 🏃 Adventurer Level

- Population density calculation (inhabitants/km²)
  - Uses population and area for calculation
  - 2 decimal places formatting
  - Scientific notation for large values

- GDP per capita calculation (GDP/population)
  - GDP divided by total population
  - Proper monetary formatting
  - Development level classification

- Advanced data analysis
  - Card comparison
  - Economic indicator ranking
  - Tabular visualization

### 👑 Master Level

- Card comparison system
- "Super Power" calculation
- Advanced game logic

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
Made with ❤️ by Rafael Dias Zendron
</div>
<div align="center">
<img src="https://github.com/rafaumeu.png" width="100" height="100" style="border-radius: 50%;">

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/rafael-dias-zendron-528290132/)
[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/rafaumeu)
</div>
