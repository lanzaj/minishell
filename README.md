# minishell

This is a shell coded in C with [mbocquel](https://github.com/mbocquel).

![Alt Text](./readme/minishell.webp)

## About this project
- This is an individual project at [School 42](https://42.fr/en/homepage/).
- This project handle :
    * ’ and `
    * Redirections `<`, `>`, `<<`, `>>`
    * Pipes `|`
    * Environment variables
    * `$?`
    * `ctrl-C`, `ctrl-D` and `ctrl-\`
    * Builtins : echo, cd, pwd, export, unset, env, exit
    * Has a working history
- Parsing is done thanks to an abstract syntax tree (AST).

## Usage (linux)

```bash
make && ./minishell
```

