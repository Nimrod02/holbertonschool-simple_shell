#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[])
{
	// Vérifier si l'utilisateur a entré la commande "env"
	if (argc > 1 && strcmp(argv[1], "env") == 0)
	{
		// Parcourir le tableau des variables d'environnement jusqu'à trouver la fin
		for (int index = 0; envp[index] != NULL; index++)
		{
			// Afficher la variable d'environnement actuelle
			printf("%s\n", envp[index]);
		}
	} else
	{
		// Afficher un message d'erreur si la commande n'est pas valide
		printf("Tape: ./x5-env env\n");
	}

	// Attendre que l'utilisateur appuie sur Entrée pour continuer
	printf("Press Enter to continue...");
	getchar();

	// Renvoyer un code de sortie normal
	return (0);
}
