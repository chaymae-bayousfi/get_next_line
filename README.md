# 🚀 get_next_line

Bienvenue sur **get_next_line** !  
Ce projet a pour but de vous apprendre à lire une ligne d’un descripteur de fichier à chaque appel de fonction, tout en gérant efficacement la mémoire et les cas particuliers.  
C’est un exercice phare du cursus 42, mettant à l’épreuve votre capacité à manipuler les fichiers, la mémoire dynamique et la gestion de buffers, le tout en C.  

---

## ✨ Fonctionnalités

- 📄 Lire une ligne à la fois depuis un fichier ou l'entrée standard.
- 💾 Gestion efficace de la mémoire (pas de leaks !)
- ⚡️ Support de plusieurs descripteurs de fichiers simultanément (bonus).
- 🔄 Compatible avec n’importe quelle taille de buffer (`BUFFER_SIZE` paramétrable).

---

## 📚 Utilisation

### 1️⃣ Compilation

```bash
git clone https://github.com/chaymae-bayousfi/get_next_line.git
cd get_next_line/get_next_line
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl_test
```

### 2️⃣ Exemple d’utilisation

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("mon_fichier.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

### 3️⃣ Exécuter le binaire

```bash
./gnl_test
```

---

## 🛠️ Fonctions principales

- `char *get_next_line(int fd);`
- Fonctions utilitaires :  
  - `ft_strchr`, `ft_strjoin`, `ft_strdup`, `ft_substr`, `ft_strlen`

---

## 🎁 Bonus

- 🗂️ **get_next_line_bonus.c** : Gère plusieurs fichiers à la fois (tableau statique).
- 💡 Utilisation de `OPEN_MAX` pour supporter un grand nombre de descripteurs.

---

## 🤝 Interactions & Contributions

- ⭐️ Star ce repo pour soutenir le projet !
- 🐛 Trouvé un bug ? [Ouvre une issue](https://github.com/chaymae-bayousfi/get_next_line/issues/new).
- 🔀 Pull Request bienvenues !  
  Merci de bien tester et de respecter le style 42.

---

## 🎨 Design & Astuces

- Modifiez `BUFFER_SIZE` pour tester la robustesse de votre fonction.

---

## 📂 Structure du projet

```
get_next_line/
├── get_next_line.c
├── get_next_line.h
├── get_next_line_bonus.c
├── get_next_line_bonus.h
├── get_next_line_utils.c
```

---

## 🤓 Ressources utiles

- [Man page de read(2)](https://man7.org/linux/man-pages/man2/read.2.html)
- [Documentation 42 sur get_next_line](https://github.com/42Paris/42cursus-get_next_line)

---

## 👩‍💻 Auteur

- **Chaymae Bayousfi**  
  [GitHub](https://github.com/chaymae-bayousfi)

---

## 🏆 Bon courage et happy coding ! 🚦
