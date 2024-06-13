#!/bin/bash

# Chemin vers les binaires
binaire1="../../corewar/corewar"
binaire2="./corewar_pedago"

# Dossier contenant les fichiers "test"
dossier_tests="../../champions"

# Liste des fichiers .cor dans le dossier
fichiers_cor=("$dossier_tests"/*.cor)

# Couleurs
rouge="\e[31m"
vert="\e[32m"
gris="\e[90m"
violet="\e[35m"
bleu="\e[34m"
reset="\e[0m"

# Codes de formatage
gras="\e[1m"
reset="\e[0m"

# Vérification du nombre de fichiers .cor
if [ "${#fichiers_cor[@]}" -lt 2 ]; then
    echo -e "${rouge}Erreur : Il doit y avoir au moins deux fichiers .cor dans le dossier.${reset}"
    exit 1
fi

echo -e "${bleu}${gras}"
echo -e "======================================================================"
echo -e "=================== Comparaison des fichiers .cor ===================="
echo -e "======================================================================"
echo -e "${reset}"


# Boucle pour comparer les fichiers .cor
for ((i = 0; i < ${#fichiers_cor[@]} - 1; i++)); do
    fichier1="${fichiers_cor[$i]}"
    for ((j = i + 1; j < ${#fichiers_cor[@]}; j++)); do
        fichier2="${fichiers_cor[$j]}"
        echo -e "${gris}Comparaison entre ${violet}$fichier1${reset} et ${violet}$fichier2${reset}"

        # Exécution du premier binaire avec les fichiers 1 et 2
        resultat1=$("$binaire1" "$fichier1" "$fichier2")

        # Exécution du deuxième binaire avec les fichiers 1 et 2
        resultat2=$("$binaire2" "$fichier1" "$fichier2")

        # Comparaison des résultats
        if [ "$resultat1" = "$resultat2" ]; then
            echo "✅ Les résultats sont identiques. ✅"
        else
            echo -e "${rouge}❌ Les résultats sont différents. ❌${reset}"
            echo -e "${gris}Différences trouvées :"
            echo -e "${reset}"
            diff <(echo "$resultat1") <(echo "$resultat2")
        fi

        echo -e "${bleu}${gras}"
        echo "====================================================================="
        echo -e "${reset}"
    done
done