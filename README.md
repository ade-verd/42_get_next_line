int get_next_line(const int fd, char **line);

On appelle “ligne” une suite de caractères terminée par un ’\n’ (code ascii 0x0a) ou bien par End Of File (EOF).

EOF : cf. https://latedev.wordpress.com/2012/12/04/all-about-eof/ 
EOF/FEOF Règles de base :
- Il n'existe pas de caractère EOF, sauf si le fichier est ouvert sous Windows en mode Texte ou qu'il a été manuellement ajouté.
- En C et C++, le symbole EOF n'est pas un caractère de fin de fichier. C'est un retour spécial de certaines fonctions de librairies.
- Ne jamais boucler avec les fonctions eof() et foef().

Le premier paramètre est le file descriptor depuis lequel lire.

Le second paramètre est l’adresse d’un pointeur sur caractère qui servira à stocker
la ligne lue sur le file descriptor.

Return
- 1 : une ligne a été lue
- 0 : la lecture est terminée
- -1 : une erreur est survenue
Le char **line ne contient pas le '\n'


