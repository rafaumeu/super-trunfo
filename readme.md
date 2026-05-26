# Super Trunfo - Cidades Brasileiras 🏢

[English](README_en.md) | Português

Jogo de cartas que compara características de cidades brasileiras.

## Sobre o Projeto

Este é um jogo estilo Super Trunfo que utiliza dados de cidades brasileiras como população, área, PIB e pontos turísticos para comparação.

## Funcionalidades

- Criar e salvar cartas de cidades
- Comparar cartas usando diferentes atributos
- Visualizar ranking das cidades
- Suporte a múltiplos idiomas (Português e Inglês)

## Como Usar

### Compilação

```bash
make clean && make
```

### Execução

```bash
./bin/super_trunfo      # Português (padrão)
./bin/super_trunfo en   # English
```

## Estrutura do Projeto

```
super_trunfo/
├── src/          # Código fonte
├── include/      # Headers
├── obj/          # Objetos compilados
└── bin/          # Executável
```

## ⚠️ Validações

### Dados de Entrada

<<<<<<< HEAD
- Código: 3 caracteres alfanuméricos
- Estado: 2 letras maiúsculas (UF válida)
- Cidade: Nome não vazio, máximo 50 caracteres
- Valores numéricos: Sempre positivos

### Sistema

- Verifica espaço em disco antes de salvar
- Valida existência e acesso a arquivos
- Verifica alocação de memória
- Trata erros de leitura/escrita
||||||| 07e7ba7
- Basic card registration
- Data visualization
- Unique code system

### 🏃 Adventurer Level (Implemented)

- Population density calculation
- GDP per capita calculation
- Advanced data analysis
- Decision structures for card classification
- Enhanced visual formatting
=======
- Population density calculation
- GDP per capita calculation
- Advanced data analysis
- Decision structures for card classification
- Enhanced visual formatting
>>>>>>> origin/main

<<<<<<< HEAD
### Testes Automatizados
||||||| 07e7ba7
### 👑 Master Level (Implemented)
=======
### 🏃 Adventurer Level (Implemented)

- Interactive attribute selection menu
- Multiple comparison modes (6 attributes)
- Inverse comparison rules for density
- Input validation system
- Advanced result display formatting

### 👑 Master Level (Implemented)
>>>>>>> origin/main

- Testes de inicialização
- Testes de comparação
- Testes de super poder
- Testes de persistência
- Testes de ranking

## 🎮 Menu Principal

1. Criar nova carta
2. Exibir última carta
3. Comparar cartas
4. Listar cartas salvas
5. Carregar última carta
6. Exibir ranking
7. Executar testes
8. Ajuda/Instruções
0. Sair

## 🤝 Contribuindo

1. Faça um fork do projeto
2. Crie uma branch para sua feature (`git checkout -b feature/NovaFeature`)
3. Commit suas mudanças (`git commit -m 'feat: Adiciona nova feature'`)
4. Push para a branch (`git push origin feature/NovaFeature`)
5. Abra um Pull Request

## 📝 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

---

<div align="center">
Desenvolvido como parte do curso MateCheck

[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/rafaumeu)
</div>
