# Guia de Contribuição

## Níveis de Desenvolvimento

Este projeto segue uma estrutura de desenvolvimento em níveis, permitindo uma evolução gradual das funcionalidades e complexidade.

### Branches Principais

- `main`: Versão estável do projeto
- `beginner`: Funcionalidades básicas e essenciais
- `adventurer`: Funcionalidades intermediárias
- `master`: Funcionalidades avançadas

## Workflow de Desenvolvimento

1. **Escolha do Nível**
   - Identifique em qual nível sua contribuição se encaixa
   - Verifique as issues disponíveis no nível escolhido

2. **Desenvolvimento**

   ```bash
   # Clone o repositório
   git clone https://github.com/seu-usuario/super_trunfo.git
   
   # Crie uma branch para sua feature
   git checkout -b feature/nivel-descricao
   
   # Exemplo:
   git checkout -b feature/beginner-validacao-entrada
   ```

3. **Commits**
   - Use commits semânticos:
     - `feat:` Nova funcionalidade
     - `fix:` Correção de bug
     - `docs:` Documentação
     - `test:` Adição/modificação de testes
     - `refactor:` Refatoração de código
     - `style:` Formatação de código
     - `chore:` Tarefas de build, CI, etc

4. **Pull Requests**
   - Crie PRs para a branch do nível apropriado
   - Siga o template de PR fornecido
   - Aguarde review e CI passar

## Padrões de Código

### Estilo

- Indentação: 4 espaços
- Limite de linha: 80 caracteres
- Nomenclatura:
  - Funções: snake_case
  - Tipos: PascalCase
  - Constantes: UPPERCASE

### Documentação

- Comentários em inglês
- Documentação de funções no estilo JSDoc
- README atualizado para novas funcionalidades

### Testes

- Testes unitários para novas funcionalidades
- Cobertura mínima por nível:
  - Beginner: 60%
  - Adventurer: 75%
  - Master: 90%

## CI/CD

### Verificações Automáticas

- Build
- Testes unitários
- Análise estática
- Cobertura de código
- Formatação

### Releases

- Versões seguem SemVer
- Changelogs automáticos
- Tags por nível de desenvolvimento

## Suporte

Para dúvidas ou sugestões:

1. Verifique as issues existentes
2. Crie uma nova issue com a tag apropriada
3. Entre em contato com os mantenedores

## Licença

Este projeto está sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.
