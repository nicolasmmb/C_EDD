#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

// Binary search tree implementation
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

typedef struct tree
{
    node *root;
} tree;

// Insert a new node into the tree
void insert(node **root, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    node *current = *root;
    if (current == NULL)
    {
        *root = new_node;
        return;
    }
    while (current != NULL)
    {
        if (data < current->data)
        {
            if (current->left == NULL)
            {
                current->left = new_node;
                return;
            }
            current = current->left;
        }
        else
        {
            if (current->right == NULL)
            {
                current->right = new_node;
                return;
            }
            current = current->right;
        }
    }
}

// Delete a node from the tree
void delete (node **root, int data)
{
    node *current = *root;
    if (current == NULL)
    {
        return;
    }
    if (data < current->data)
    {
        delete (&current->left, data);
    }
    else if (data > current->data)
    {
        delete (&current->right, data);
    }
    else
    {
        if (current->left == NULL)
        {
            node *temp = current->right;
            free(current);
            *root = temp;
            return;
        }
        if (current->right == NULL)
        {
            node *temp = current->left;
            free(current);
            *root = temp;
            return;
        }
        node *temp = current;
        current = current->left;
        while (current->right != NULL)
        {
            temp = current;
            current = current->right;
        }
        temp->data = current->data;
        delete (&current->left, current->data);
    }
    return;
}

// Inorder traversal
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Find the node with the minimum value
void find_min(node *root, int *min)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL)
    {
        *min = root->data;
        return;
    }
    find_min(root->left, min);
}

//Find the node with the maximum value
void find_max(node *root, int *max)
{
    if (root == NULL)
    {
        return;
    }
    if (root->right == NULL)
    {
        *max = root->data;
        return;
    }
    find_max(root->right, max);
}

// Find the node with the given value
void find(node *root, int data, int *found)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == data)
    {
        *found = 1;
        return;
    }
    if (data < root->data)
    {
        find(root->left, data, found);
    }
    else
    {
        find(root->right, data, found);
    }
}

// Is the tree empty
int is_empty(node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    return 0;
}

int menu()
{
    int opcao = 0;
    printf(BOLDMAGENTA "\n ------------------------------------------" RESET);
    printf(BOLDMAGENTA "\n |       --> ENTRE COM UMA OPCAO <--      |" RESET);
    printf(BOLDMAGENTA "\n ------------------------------------------" RESET);
    printf(BOLDGREEN "\n |      1 - VERIFICA SE VAZIA             |" RESET);
    printf(BOLDGREEN "\n |      2 - INSERIR  ITEN  NA ARVORE      |" RESET);
    printf(BOLDGREEN "\n |      3 - DELETAR  ITEM  NA ARVORE      |" RESET);
    printf(BOLDGREEN "\n |      4 - IMPRIMIR ITENS DA ARVORE      |" RESET);
    printf(BOLDGREEN "\n |      5 - ENCONTRAR MIN/MAX NA ARVORE   |" RESET);
    printf(BOLDGREEN "\n |      6 - BUSCAR NA ARVORE              |" RESET);
    printf(BOLDGREEN "\n |      0 - Sair                          |" RESET);
    printf(BOLDGREEN "\n ------------------------------------------" RESET);
    printf(BOLDCYAN "\n DIGITE UMA OPCAO: " RESET);
    scanf("%d", &opcao);
    return opcao;
}

int main()
{
    int n, data, min, max, opcao;
    int found = 0;
    node *root = NULL;

    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            if (is_empty(root))
            {
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n |           -----> VAZIA <-----          |" RESET);
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n " RESET);
            }
            else
            {
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n |      -----> HA ITENS ARVORE <-----     |" RESET);
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n " RESET);
            }
            break;
        case 2:
        {
            printf(BOLDMAGENTA "\n ------------------------------------------" RESET);
            printf(BOLDMAGENTA "\n | -- QUANTIDADE DE ITENS PARA INSERIR? --|" RESET);
            printf(BOLDMAGENTA "\n ------------------------------------------" RESET);
            printf(BOLDMAGENTA "\n | --> " RESET);
            scanf("%d", &n);
            printf(BOLDMAGENTA " | --          INSIRA OS ITENS          --| \n" RESET);
            for (int i = 0; i < n; i++)
            {
                printf(BOLDMAGENTA " | --> " RESET);
                scanf("%d", &data);
                insert(&root, data);
            }
            printf(BOLDMAGENTA " ------------------------------------------" RESET);
        }
        break;
        case 3:
        {
            if (is_empty(root))
            {
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n |           -----> VAZIA <-----          |" RESET);
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n " RESET);
            }
            else
            {
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n | --     REMOVER ITEM NA ARVORE        --|" RESET);
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n | --> REMOVER ITEM : " RESET);
                scanf("%d", &data);
                delete (&root, data);
                printf(BOLDYELLOW " ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n| --     IMPRIMA a ARVORE NO MENU     -- | " RESET);
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
            }
        }
        break;
        case 4:
        {
            if (is_empty(root))
            {
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n |           -----> VAZIA <-----          |" RESET);
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n " RESET);
            }
            else
            {
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n | --     IMPRIMIR ITENS NA ARVORE      --|" RESET);
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n | --> Em Ordem     : " RESET);
                inorder(root);
                printf(BOLDYELLOW "\n | --> Em Pre-Ordem : " RESET);
                preorder(root);
                printf(BOLDYELLOW "\n | --> Em Pos-Ordem : " RESET);
                postorder(root);
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
            }
        }
        break;

        case 5:
        {
            if (is_empty(root))
            {
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n |           -----> VAZIA <-----          |" RESET);
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n " RESET);
            }
            else
            {
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n | --    ENCONTRAR MIN/MAX NA ARVORE    --|" RESET);
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n | --> MIN: " RESET);
                find_min(root, &min);
                printf("%d", min);
                printf(BOLDYELLOW "\n | --> MAX: " RESET);
                find_max(root, &max);
                printf("%d", max);
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
            }
        }
        break;
        case 6:
        {
            if (is_empty(root))
            {
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n |           -----> VAZIA <-----          |" RESET);
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n " RESET);
            }
            else
            {
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n | --     ENCONTRAR ITEN NA ARVORE      --|" RESET);
                printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                printf(BOLDYELLOW "\n | --> ENCONTRAR ITEM : " RESET);
                scanf("%d", &data);
                find(root, data, &found);
                if (found)
                {
                    printf(BOLDYELLOW " ------------------------------------------" RESET);
                    printf(BOLDYELLOW "\n | --         ITEM ENCONTRADO           --|" RESET);
                    printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                }
                else
                {
                    printf(BOLDYELLOW " ------------------------------------------" RESET);
                    printf(BOLDYELLOW "\n | --        ITEM NAO ENCONTRADO        --|" RESET);
                    printf(BOLDYELLOW "\n ------------------------------------------" RESET);
                }
            }
        }
        break;
        }
    } while (opcao != 0);
    return 0;
}
