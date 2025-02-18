# 🎮 Super Trunfo - Países

<div align="center">

Um jogo de cartas estilo Super Trunfo implementado em C, focado em comparação de características entre países.

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com/rafaumeu/super-trunfo)

---

## 📖 Índice

| [Funcionalidades](#-funcionalidades) | [Requisitos](#-requisitos) | [Como Executar](#-como-executar) |
|-------------------------------------|---------------------------|----------------------------------|
| [Estrutura](#-estrutura) | [Níveis do Jogo](#-níveis-do-jogo) | [Contribuindo](#-contribuindo) |

---
</div>

## 🎯 Funcionalidades

### Sistema de Cartas

- Cadastro de cartas com propriedades únicas
- 8 estados (A-H) com 4 cidades cada
- Códigos únicos para cada carta (ex: A01, B02)
- Sistema de comparação de propriedades

### Propriedades das Cartas

- População
- Área
- PIB
- Pontos Turísticos

## 💻 Requisitos

- Compilador GCC
- Sistema operacional Windows, Linux ou macOS
- Conhecimentos básicos de terminal/linha de comando

## 🚀 Como Executar

1. Clone o repositório:

```bash
git clone <https://github.com/rafaumeu/super-trunfo.git>
cd super-trunfo
```

2. Compile o programa:

```bash
gcc novato.c -o novato
```

3. Execute o programa:

```bash
./novato
```

## 📁 Estrutura

```
super-trunfo/
├── novato.c          # Implementação nível novato
├── aventureiro.c     # Implementação nível aventureiro
├── mestre.c          # Implementação nível mestre
└── README.md         # Documentação
```

## 🎮 Níveis do Jogo

### 🌟 Nível Novato

- Cadastro básico de cartas
- Visualização de dados
- Sistema de códigos único

### 🏃 Nível Aventureiro

- Cálculo de densidade populacional
- Cálculo de PIB per capita
- Análise avançada de dados

### 👑 Nível Mestre

- Sistema de comparação entre cartas
- Cálculo de "Super Poder"
- Lógica avançada de jogo

## 🤝 Contribuindo

1. Faça um Fork do projeto
2. Crie sua Feature Branch (`git checkout -b feature/NovaFuncionalidade`)
3. Commit suas mudanças (`git commit -m 'feat: Adiciona nova funcionalidade'`)
4. Push para a Branch (`git push origin feature/NovaFuncionalidade`)
5. Abra um Pull Request

## 📝 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

---

<div align="center">
Desenvolvido como parte do curso da MateCheck

[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/rafaumeu)
</div>
