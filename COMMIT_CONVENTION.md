# Commit Convention

## Format

```
<type>(<scope>): <subject>

<body>

<footer>
```

## Types

- `feat`: A new feature
- `fix`: A bug fix
- `docs`: Documentation only changes
- `style`: Changes that do not affect the meaning of the code (formatting, etc)
- `refactor`: A code change that neither fixes a bug nor adds a feature
- `perf`: A code change that improves performance
- `test`: Adding missing tests or correcting existing tests
- `chore`: Changes to the build process or auxiliary tools
- `ci`: Changes to CI configuration files and scripts

## Scope

The scope should be the name of the component affected:

- `core`: Core functionality
- `card`: Card related changes
- `game`: Game logic changes
- `ui`: User interface changes
- `build`: Build system changes
- `docs`: Documentation changes
- `test`: Test related changes

## Subject

- Use the imperative, present tense: "change" not "changed" nor "changes"
- Don't capitalize first letter
- No dot (.) at the end

## Body

- Use the imperative, present tense
- Include motivation for the change
- Contrast this with previous behavior

## Footer

- Reference issues and PRs
- Breaking changes should start with `BREAKING CHANGE:`

## Examples

```
feat(card): add basic card structure and functions

- Create Card struct with basic fields
- Implement card initialization
- Add card display function
- Add input validation

Resolves: #123
```

```
fix(game): correct population comparison logic

The population comparison was reversed, causing wrong results.
This fixes the logic to properly compare higher populations.

Fixes: #456
```

```
refactor(ui): improve menu display formatting

- Add clear screen before menu
- Improve header formatting
- Add consistent line separators

Part of #789
```
