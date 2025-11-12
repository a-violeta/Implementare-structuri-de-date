//neverificate: arboriIdentici, arboreComplet

//operatii cu arbore
#include <iostream>
#include <queue>
#include <fstream>
#include <string>
// Structura pentru un nod din arborele binar
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
// Functie pentru a citi arborele din fisier
TreeNode* citesteArboreDinFisier(const std::string& numeFisier)
{
    std::ifstream fisier(numeFisier);
    if (!fisier.is_open())
    {
        std::cerr << "Eroare la deschiderea fisierului.\n";
        return nullptr;
    }
    int val;
    fisier >> val;
    TreeNode* radacina = new TreeNode(val);
    std::queue<TreeNode*> coada;
    coada.push(radacina);
    while (!coada.empty())
    {
        TreeNode* curent = coada.front();
        coada.pop();
        int leftVal, rightVal;
        if (!(fisier >> leftVal >> rightVal)) break;
        if (leftVal != -1)
        {
            curent->left = new TreeNode(leftVal);
            coada.push(curent->left);
        }
        if (rightVal != -1)
        {
            curent->right = new TreeNode(rightVal);
            coada.push(curent->right);
        }
    }
    fisier.close();
    return radacina;
}
// Functie pentru calculul inaltimii unui subarbore
int inaltimeSubarbore(TreeNode* radacina)
{
    if (radacina == nullptr) return 0;
    return 1 + std::max(inaltimeSubarbore(radacina->left), inaltimeSubarbore(radacina->right));
}
// Functie pentru parcurgerea arborelui in RSD (preordine)
void RSD(TreeNode* radacina)
{
    if (radacina == nullptr) return;
    std::cout << radacina->data << " ";
    RSD(radacina->left);
    RSD(radacina->right);
}
// Functie pentru parcurgerea arborelui in SRD (inordine)
void SRD(TreeNode* radacina)
{
    if (radacina == nullptr) return;
    SRD(radacina->left);
    std::cout << radacina->data << " ";
    SRD(radacina->right);
}
// Functie pentru parcurgerea arborelui in SDR (postordine)
void SDR(TreeNode* radacina)
{
    if (radacina == nullptr) return;
    SDR(radacina->left);
    SDR(radacina->right);
    std::cout << radacina->data << " ";
}
// Functie pentru parcurgerea arborelui pe nivele
void parcurgereNivele(TreeNode* radacina)
{
    if (radacina == nullptr) return;
    std::queue<TreeNode*> coada;
    coada.push(radacina);
    while (!coada.empty())
    {
        TreeNode* curent = coada.front();
        coada.pop();
        std::cout << curent->data << " ";
        if (curent->left != nullptr) coada.push(curent->left);
        if (curent->right != nullptr) coada.push(curent->right);
    }
}
// Functie care afiseaza frunzele de la stanga la dreapta
void afiseazaFrunze(TreeNode* radacina)
{
    if (radacina == nullptr) return;
    if (radacina->left == nullptr && radacina->right == nullptr)
    {
        std::cout << radacina->data << " ";
        return;
    }
    if (radacina->left != nullptr) afiseazaFrunze(radacina->left);
    if (radacina->right != nullptr) afiseazaFrunze(radacina->right);
}
// Functie care verifica daca doi arbori sunt identici
bool arboriIdentici(TreeNode* radacina1, TreeNode* radacina2)
{
    if (radacina1 == nullptr && radacina2 == nullptr) return true;
    if (radacina1 == nullptr || radacina2 == nullptr) return false;
    return (radacina1->data == radacina2->data) &&
        arboriIdentici(radacina1->left, radacina2->left) &&
        arboriIdentici(radacina1->right, radacina2->right);
}
// Functie care verifica daca un arbore este complet
bool arboreComplet(TreeNode* radacina)
{
    if (radacina == nullptr) return true;
    if (radacina->left == nullptr && radacina->right == nullptr) return true;
    if (radacina->left == nullptr || radacina->right == nullptr) return false;
    return arboreComplet(radacina->left) && arboreComplet(radacina->right);
}
// Functie care determina adancimea unui nod
int adancimeNod(TreeNode* radacina, int val, int nivel)
{
    if (radacina == nullptr) return -1;
    if (radacina->data == val) return nivel;
    int adancimeStanga = adancimeNod(radacina->left, val, nivel + 1);
    if (adancimeStanga != -1) return adancimeStanga;
    return adancimeNod(radacina->right, val, nivel + 1);
}
int main()
{
    TreeNode* radacina = citesteArboreDinFisier("arbore.txt");
    // Exemple de utilizare a functiilor definite
    std::cout << "Inaltimea arborelui: " << inaltimeSubarbore(radacina) << "\n";
    std::cout << "Parcurgere RSD (preordine): "; RSD(radacina); std::cout << "\n";
    std::cout << "Parcurgere SRD (inordine): "; SRD(radacina); std::cout << "\n";
    std::cout << "Parcurgere SDR (postordine): "; SDR(radacina); std::cout << "\n";
    std::cout << "Parcurgere pe nivele: "; parcurgereNivele(radacina); std::cout << "\n";
    std::cout << "Frunzele de la stanga la dreapta: "; afiseazaFrunze(radacina); std::cout << "\n";
    std::cout << "Adancimea nodului cu valoarea 5: " << adancimeNod(radacina, 5, 0) << "\n";
    delete radacina; // Eliberare memorie
    return 0;

}
