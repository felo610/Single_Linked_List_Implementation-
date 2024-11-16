#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node
{
    int Node_Data;          /* Data stored in the node*/
    struct Node *Node_Link; /*Pointer to the next node*/
};

/*Functions Prototype*/
struct Node *Create_New_Node(void);
void Insert_Node_At_Beginning(struct Node **List_Head);
void Insert_Node_At_End(struct Node **List_Head);
void Insert_Node_After(struct Node **List_Head);
void Delete_Node_At_Beginning(struct Node **List_Head);
void Delete_Node_At_End(struct Node **List_Head);
void Delete_Node_At(struct Node **List_Head);
void print_All_Nodes(struct Node **List_Head);
int Linked_List_Length(struct Node **List_Head);
int Options(void);

/*Global Variables*/
struct Node *My_Node;
int My_Option = 1;

/*Main Function*/
int main()
{
    while (1)
    {
        switch (Options())
        {
        case (1):
            Insert_Node_At_Beginning(&My_Node);

            break;

        case (2):
            Insert_Node_At_End(&My_Node);

            break;

        case (3):
            Insert_Node_After(&My_Node);
            break;

        case (4):
            Delete_Node_At_Beginning(&My_Node);
            break;

        case (5):
            Delete_Node_At_End(&My_Node);

            break;

        case (6):
            Delete_Node_At(&My_Node);
            break;

        case (7):
            printf("Linked_List_Length =>%i\n", Linked_List_Length(&My_Node));
            break;

        case (8):
            print_All_Nodes(&My_Node);
            break;

        default:
            My_Option = -1;
            printf("\"End of programe .......Thank you\"\n");
            break;
        }

        if (-1 == My_Option)
        {
            break;
        }
    }

    return (0);
}

/**
 * @brief Create a new node with user input
 * @return Pointer to the newly created node
 */
struct Node *Create_New_Node(void)
{
    int Data = 0;
    printf("Enter Node Data (Integer) :");
    scanf("%i", &Data);

    struct Node *Created_Node = (struct Node *)malloc(sizeof(struct Node));
    if (Created_Node)
    {
        Created_Node->Node_Data = Data;
        Created_Node->Node_Link = NULL;
        //   printf("Create_New_Node has been successfully created\n");
    }
    else
    {
        //  printf("NULL_Pointer");
    }

    return (Created_Node);
}

/**
 * @brief Insert a new node at the beginning of the linked list
 * @param List_Head Pointer to the head of the linked list
 */
void Insert_Node_At_Beginning(struct Node **List_Head)
{
    struct Node *New_Node = Create_New_Node();
    if (*List_Head)
    {
        New_Node->Node_Link = *List_Head;
        *List_Head = New_Node;
    }
    /*Linked list is empty*/
    else
    {
        *List_Head = New_Node;
    }
}

/**
 * @brief Insert a new node at the end of the linked list
 * @param List_Head Pointer to the head of the linked list
 */
void Insert_Node_At_End(struct Node **List_Head)
{
    struct Node *New_Node = Create_New_Node();
    struct Node *End_Node = *List_Head;
    if (*List_Head)
    {
        while (End_Node->Node_Link != NULL)
        {
            End_Node = End_Node->Node_Link;
        }
        End_Node->Node_Link = New_Node;
    }
    /*Linked list is empty*/
    else
    {
        *List_Head = New_Node;
    }
}

/**
 * @brief Calculate the length of the linked list
 * @param List_Head Pointer to the head of the linked list
 * @return Length of the linked list
 */
int Linked_List_Length(struct Node **List_Head)
{
    int Counter = 0;
    struct Node *Temp_Node = *List_Head;

    while (Temp_Node != NULL)
    {
        Counter++;
        Temp_Node = Temp_Node->Node_Link;
    }
    return (Counter);
}

/**
 * @brief Insert a new node after a specified position in the linked list
 * @param List_Head Pointer to the head of the linked list
 */
void Insert_Node_After(struct Node **List_Head)
{
    int Pos = 0;
    int Len = Linked_List_Length(List_Head);
    printf("Enter Node Pos :");
    scanf("%i", &Pos);

    if (Pos < 0 || Pos > Len)
    {
        printf("Invalid position!\n");
        return;
    }
    else
    {

        struct Node *New_Node = Create_New_Node();
        struct Node *Pos_Node = *List_Head;
        if (*List_Head)
        {
            for (int i = 1; i < Pos; i++)
            {
                Pos_Node = Pos_Node->Node_Link;
            }
            New_Node->Node_Link = Pos_Node->Node_Link;
            Pos_Node->Node_Link = New_Node;
        }

        /*Linked list is empty*/
        else
        {
            *List_Head = New_Node;
        }
    }
}

/**
 * @brief Delete the first node of the linked list
 * @param List_Head Pointer to the head of the linked list
 */
void Delete_Node_At_Beginning(struct Node **List_Head)
{
    struct Node *New_Node = *List_Head;

    if (*List_Head)
    {
        *List_Head = New_Node->Node_Link;
        New_Node->Node_Link = NULL;
        free(New_Node);
    }
    /*Linked list is empty*/
    else
    {
        printf("List is empty cant delete\n");
    }
}

/**
 * @brief Delete the last node of the linked list
 * @param List_Head Pointer to the head of the linked list
 */
void Delete_Node_At_End(struct Node **List_Head)
{
    struct Node *End_Node = *List_Head;
    if (*List_Head)
    {
        /*Special Case : if list has only one node*/
        if (NULL == End_Node->Node_Link)
        {
            free(End_Node);
            *List_Head = NULL;
            return;
        }

        while (End_Node->Node_Link->Node_Link != NULL)
        {
            End_Node = End_Node->Node_Link;
        }
        free(End_Node->Node_Link);
        End_Node->Node_Link = NULL;
    }
    else
    {
        printf("List is Empty cant delete node\n");
    }
}

/**
 * @brief Delete a node at a specified position in the linked list
 * @param List_Head Pointer to the head of the linked list
 */
void Delete_Node_At(struct Node **List_Head)
{
    int Pos = 0;
    printf("Enter Pos :");
    scanf("%i", &Pos);
    int len = Linked_List_Length(List_Head);
    if (*List_Head)
    {
        if (Pos > len || Pos < 0)
        {
            printf("Invalid Position");
            return;
        }

        struct Node *Pos_Node = *List_Head;
        struct Node *Deleted_Node = NULL;

        // Special case: Deleting the head node
        if (Pos == 1)
        {
            *List_Head = Pos_Node->Node_Link; // Update the head pointer
            free(Pos_Node);                   // Free the old head node
            return;
        }
        else
        {

            for (int i = 1; i < Pos - 1; i++)
            {
                Pos_Node = Pos_Node->Node_Link;
            }
            Deleted_Node = Pos_Node->Node_Link;
            Pos_Node->Node_Link = Deleted_Node->Node_Link;
            free(Deleted_Node);
        }
    }

    else
    {
        printf("List is Empty cant delete node\n");
    }
}

/**
 * @brief Print all nodes in the linked list
 * @param List_Head Pointer to the head of the linked list
 */
void print_All_Nodes(struct Node **List_Head)
{
    if (*List_Head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    int len = Linked_List_Length(List_Head);
    struct Node *List_Counter = *List_Head;
    while (len--)
    {
        printf("->%i", List_Counter->Node_Data);
        List_Counter = List_Counter->Node_Link;
    }
}

/**
 * @brief Display options for user input
 * @return Selected option as an integer
 */
int Options(void)
{
    int option = -1;
    printf("\n\n\"Options you can choose\"                \n");
    printf("1 =>\"Insert_Node_At_Beginning\"              \n");
    printf("2 =>\"Insert_Node_At_End\"                    \n");
    printf("3 =>\"Insert_Node_After\"            \n");
    printf("4 =>\"Delete_Node_At_Beginning\"              \n");
    printf("5 =>\"Delete_Node_At_End\"                    \n");
    printf("6 =>\"Delete_Node_At\"            \n");
    printf("7 =>\"Display Linked List Length\"        \n");
    printf("8 =>\"print_All_Nodes\"                   \n");
    printf("-1 =>\"for End programme\"                    \n");
    printf("\nYour option is :");

    if ((scanf("%i", &option)) != 1)
    {
        printf("Invalid Option\n");
        while (getchar() != '\n')
            ; // Clear the input buffer
        option = -1;
    }

    return (option);
}