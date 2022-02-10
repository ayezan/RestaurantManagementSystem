#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<string>

using namespace std;

class Node
{
public:

    char foodname[100];
    int quantity;
    float price;
    int data;
    Node* prev;
    Node* next;
};
//GLOBAL NODE POINTER WHICH ARE USED THROUGHOUT THE PROGRAM TO CREAT LINKLIST AND MAINTAIN IT
Node* headc = NULL;
Node* newNode = NULL;
Node* tailc = NULL;
Node* heada = NULL;
Node* taila = NULL;
Node* head_s;

// THIS FUNCTION PRINT THE OPTION AVAILABLE FOR ADMIN TO CHOOSE
void adminmenu()
{
    system("color 6f");
    cout << "\n\t\t\t\t\t\t\t1. View total sales\n";
    cout << "\t\t\t\t\t\t\t2. Add new items in the order menu\n";
    cout << "\t\t\t\t\t\t\t3. Delete items from the order menu\n";
    cout << "\t\t\t\t\t\t\t4. Display order menu\n";
    cout << "\t\t\t\t\t\t\t5. Back To Main Menu \n";
    cout << "\t\t\t\t\t\t\t6. Search Food Item \n";
    cout << "\t\t\t\t\t\t\t   Enter Your Choice --->";
}
// THIS FUNCTION PRINT THE OPTION AVAILABLE FOR CUSTOMER TO CHOOSE
void customermenu()
{
    system("color 4f");
    cout << "\n\t\t\t\t\t\t\t1. Place your order\n";
    cout << "\t\t\t\t\t\t\t2. View your ordered items\n";
    cout << "\t\t\t\t\t\t\t3. Delete an item from order\n";
    cout << "\t\t\t\t\t\t\t4. Display final bill\n";
    cout << "\t\t\t\t\t\t\t5. Back To Main Menu \n";
    cout << "\t\t\t\t\t\t\t6. Search Food Item \n";
    cout << "\t\t\t\t\t\t\t7. Display All Total Data \n\n";
    cout << "\t\t\t\t\t\t\t   Enter Your Choice --->";
}
// THIS FUNCTION CREATE A NODE FOR ADMIN LINK LIST 
Node* createadmin(Node* head, int data, const char* foodname, float price)
{
    newNode = new Node();

    newNode->data = data;
    newNode->price = price;
    newNode->quantity = 0;
    strcpy_s(newNode->foodname, foodname);
    newNode->next = NULL;
    newNode->prev = NULL;

    Node* temp = head;

    if (temp == NULL)
        heada = taila = newNode;
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = taila;
        taila = newNode;
    }

    return heada;
}
// THIS FUNCTION CREATE A NODE FOR CUSTOMER LINK LIST
Node* createcustomer(Node* head, int data, int quantity)
{
    newNode = new Node();

    Node* temp1 = heada;
    int check = 0;
    while (temp1 != NULL)
    {
        if (temp1->data == data)
        {
            check = 1;
            break;
        }
        temp1 = temp1->next;
    }

    if (check == 1)
    {
        newNode->data = data;
        newNode->price = quantity * (temp1->price);
        newNode->quantity = quantity;
        strcpy_s(newNode->foodname, temp1->foodname);
        newNode->next = NULL;
        newNode->prev = NULL;

        Node* temp = head;

        if (temp == NULL)
            headc = tailc = newNode;
        else
        {
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
            newNode->prev = tailc;
            tailc = newNode;
        }


    }
    else
    {
        cout << "\n\t\t\t\t\t\t---====------===---===--===-------=======";
        cout << "\n\t\t\t\t\t\t\tThis item is not present in the menu!\n";
        cout << "\n\t\t\t\t\t\t---====------===---===--===-------=======";
    }
    return headc;
}


//THIS FUNCTION IS SEARCHING THE VALUE AT SPECIFIC POSITION OF LINKED LIST
void searchAt(Node* head, int foodname) {
    int position = 0; int ForCheck = 0;
    Node* currentNode = head;
    while (currentNode != NULL)
    {
        if (currentNode->data == foodname) {
            cout << "\n\t-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=--=-=-=-=-=--=" << endl;
            cout << "\n\tElement Found At Location[" << position + 1 << "] In LinkedList!" << endl;
            cout << "\n\t-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=--=-=-=-=-=--=" << endl;
            ForCheck = 1;
            return;
        }
        position++;
        currentNode = currentNode->next;
    }

    if (ForCheck == 0) {
        cout << "\nElement Not Found In LinkedList!";
    }
}
//THIS NODE IS DISPLAYING THE LIST OF FOOD ITEMS
//THIS FUNCTION DISPLAY THE RESPECTIVE ENTIRE LINKLIST WHOSE HAD POINTER IS PASSED TO IT 
void displayList(Node* head)
{
    system("color 2f");

    Node* temp1 = head;
    if (temp1 == NULL)
    {
        cout << "\n\t\t\t===================================================";
        cout << "\n\t\t\t\t!!________________LIST IS EMPTY____________!!\n\n";
        cout << "\n\t\t\t===================================================";
    }
    else
    {
        cout << "\n";

        // cout << "\n\t\t||||||||||||/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/|||||||||||||||";
        while (temp1 != NULL)
        {

                if (temp1->quantity == 0) {

                    cout << "\n\t\t\t\t S.no: " << temp1->data << "\t FOOD NAME: " << temp1->foodname << " \t PRICE: " << temp1->price << "\n";
                }
                else
                {

                    cout << "\n\t\t\t\t S.no: " << temp1->data << "\t FOOD NAME: " << temp1->foodname << "\t QUANTITY: " << temp1->quantity << " \t PRICE: " << temp1->price << "\n";
                    
                }

                temp1 = temp1->next;


        }
        // cout << "\n\t\t=============================================================================================";
    }

}
//THIS FUNCTION MAINTAIN THE TOTAL VALUE OF SALES DONE BY MAINTAING ANOTHER LINKLIST WHICH KEEPS A TRACK OF
// TOTAL SALES NODES OF TO EACH CUSTOMER REPRESENTED BY EACH NODE 
//THIS NODE CREATES THE TOTAL SALES OF THE ITEM OF RESTUARANT 
Node* totalsales(int data, int quantity)
{
    newNode = new Node();
    int check = 0;

    Node* temp1 = heada;
    while (temp1->data != data)
    {
        temp1 = temp1->next;
    }

    newNode->data = data;
    newNode->price = quantity * (temp1->price);
    newNode->quantity = quantity;
    strcpy_s(newNode->foodname, temp1->foodname);
    newNode->next = NULL;
    newNode->prev = NULL;

    Node* temp = head_s;

    if (temp == NULL)
        head_s = newNode;
    else
    {
        while (temp->next != NULL)
        {
            if (temp->data == data)
            {
                check = 1;
                break;
            }
            temp = temp->next;
        }

        if (check == 1)
        {
            temp->quantity += newNode->quantity;
            temp->price += newNode->price;
        }
        else
        {
            temp->next = newNode;
        }
    }

    return head_s;
}
//THIS FUNCTION CALCULATES THE TOTAL SALES OF EACH CUSTOMER 
void calculatetotsales()
{
    Node* temp = headc;
    while (temp != NULL)
    {
        head_s = totalsales(temp->data, temp->quantity);
        temp = temp->next;
    }
}

//THIS NODE DELETES THE NODE WHEN I PARTICULAR ITEM IS NOT REQUIRED
Node* Delete(int data, Node* head, Node* tail)
{
    system("color A0");
    if (head == NULL)
    {
        cout << "\n\t\t\t\t\t\t\t!!_____LIST IS EMPTY______!!\n";
    }
    else
    {
        Node* temp;
        if (data == head->data)
        {
            temp = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            delete temp;
        }
        else if (data == tail->data)
        {
            temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
        else
        {
            temp = head;
            while (data != temp->data)
            {
                temp = temp->next;
            }
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            delete temp;
        }
    }
    return head;
}
//THIS FUNCTION PERFORMING THE TASK OF DELETING FOOD ITEM FROM ADMIN LINK LIST 
int Deleteadmin()
{
    system("color B0");
    cout << "\n\n\t\t\t\t\tEnter serial no. of the food item which is to be Deleted: ";
    int num;
    cin >> num;

    Node* temp = heada;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            heada = Delete(num, heada, taila);
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

//THIS FUNCTION PERFORMING THE TASK OF DELETING FOOD ITEM FROM CUSTOMER LINK LIST 
int Deletecustomer()
{
    system("color Cf");
    cout << "\n\n\t\tEnter serial no . of the food item which is to be Deleted: ";
    int num;
    cin >> num;

    Node* temp = headc;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            headc = Delete(num, headc, tailc);
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

float total_price;
//THIS FUNCTION DISPLAYS THE TOTAL  BILL OF FOOD ITEM ORDERD BY CUSTOMER
void displaybill()
{
  //  system("color 12f");

    displayList(headc);
    Node* temp = headc;
    total_price = 0;
    while (temp != NULL)
    {
        total_price += temp->price;
        temp = temp->next;
    }

    cout << "\n\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
    cout << "\n\t\t\t\t\tYOUR TOTAL PRICE :" << total_price << " Rs";
    cout << "\n\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";

}

//THIS FUNVCTION PERFORMING THE TASK OF DELETING ENTIRE LINK LIST 
Node* DeleteList(Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        Node* temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
            delete temp->prev;
        }
        delete temp;
        head = NULL;
    }

    return head;
}

//THIS FUNCTIONS WILL ALLOWS THE ADMIN TO UPGRADE MENU
void admin()
{
    cout << "\n\t\t\t\t\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||\n";
    cout << "\t\t\t\t\t\t\t\t\t\t>>>ADMIN SECTION<<<\t \n";
    cout << "\t\t\t\t\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||\n";
    ofstream file;
    file.open("AdminMenu.txt", ios::app);
    while (1)
    {
        adminmenu();//print admin functionality 

        int opt;
        cin >> opt;

        if (opt == 5)
            break;

        int check = 0;
        Node* temp = heada;

        switch (opt)
        {
        case 1:
            displayList(head_s);
            break;

        case 2:
          //  cout << "\n\t\t\t\t\t\t******************************************\t";
            cout << "\n\t\t\t\t\t\t\tEnter serial no. of the food item: ";
         
            int num;
            char name[50];
            float price;
            cin >> num;
          //  cout << "\n\t\t\t\t\t\t*******************************************\t\n";
          


            while (temp != NULL)
            {
                if (temp->data == num)
                {
                    cout << "\n\t\t\t\t\t|||||Food item with given serial number already exists|||||\n\n";
                    check = 1;
                    break;
                }
                temp = temp->next;
            }

            if (check == 1)
                break;
           // cout << "\t\t\t\t\\\\\\\\||||||||////////\n";
            cout << "\t\t\t\t\tEnter food item name: ";
            cin >> name;
            cout << "\t\t\t\t\t\t\tEnter price: ";
            cin >> price;
            heada = createadmin(heada, num, name, price);
            if (file.is_open()) {
                Node* current = headc;
                while (current != NULL) {
                    file << "\nFood Name : " << current->foodname << "\n";
                    file << "Food Price : " << current->price << "\n";
                    current = current->next;
                }
                //file << "Total Price : " << total_price << "\n";
            }
            file.close();

            cout << "\n\t\t\t\t\t\t\tNew food item added to the list\n\n\n";
           
            break;
        case 3:
            if (Deleteadmin())
            {
                cout<<"\n\t\t\t\t\t\t### Updated list of food items menu ###\n";
                displayList(heada);
            }
            else
                cout<<"\n\t\t\t\t\t\tFood item with given serial number doesn't exist!\n\n";

            break;
        case 4:
            cout << "\n\t\t\t\t\t\t\t   ### Order menu ###\n";
            displayList(heada);
            break;

        default:
            cout << "\n\t\t\t\t\t\tWrong Input !! PLease choose valid option\n";
            break;
        }
    }
}
void ReadFile() {

    ifstream file("orderList.txt", ios::in);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << "\n";
        }
    }

    file.close();
}

//THIS FUCNTION WILL ALLOW A CUSTOMER TO PLACE AN ORDER
void customer()
{
    int check = 0, j = 1;
    char ch;
    cout << "\n\t\t\t\t\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||\n";
    cout << "\t\t\t\t\t\t\t\t\t\t>>>CUSTOMER SECTION<<<\t \n";
    cout << "\t\t\t\t\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||\n";
    ofstream file;
    file.open("orderList.txt", ios::app);

    while (1)
    {
        customermenu();

        int opt;
        cin >> opt;

        if (opt == 5)
            break;

        switch (opt)
        {
        case 1:
            displayList(heada);
            cout << "\n\n\t\t\t\t\t\tEnter number corresponding to the item you want to order: ";
            int n;
            cin >> n;
            cout << "\t\t\t\t\t\tEnter quantity: ";
            int quantity;
            cin >> quantity;
            headc = createcustomer(headc, n, quantity);

            if (file.is_open()) {
                Node* current = headc;
                while (current != NULL) {
                    file << "\nFood Name : " << current->foodname << "\n";
                    file << "Food Quantity : " << current->quantity << "\n";
                    file << "Food Price : " << current->price << "\n";
                    current = current->next;
                }
                //file << "Total Price : " << total_price << "\n";
            }
                file.close();

            break;
        case 2:
            system("color 1f");
            cout << "\n\t\t\t\t\t\t\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
            cout << "\n\t\t\t\t\t\t\t  ### List of ordered items ###\n";

            displayList(headc);
            cout << "\n\t\t\t\t\t\t\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
            break;
        case 3:
            if (Deletecustomer())
            {
                cout << "\n\t\t\t\t\t\t### Updated list of your ordered food i ###\n";
                displayList(headc);
            }
            else
                cout << "\n\t\t\t\t\t\tFood item with given serial number doesn't exist!!\n";
            break;
        case 4:
            calculatetotsales();
            cout << "\n\t\t\t\t\t\t\t  ### Final Bill ###\n";
            displaybill();
            headc = DeleteList(headc);
            cout << "\n\t\t\t\t\t\tPress any key to return to main menu:\n\t\t\t\t\t\t";
            fflush(stdin);
            ch = fgetc(stdin);
            check = 1;
            break;
        case 6:
            cout << "\nWhich item you want to search " << endl;
          int searchno;
            cin >>searchno ;
            searchAt(headc, searchno);
            break;

      case 7:
        // for reading from a file
          ReadFile();

          break;
        default:
            cout << "\n\t\t\t\t\t\tWrong Input !! PLease choose valid option\n";
            break;
        }
        if (check == 1)
            break;
    }
}


//THIS IS THE MAIN MENU FUCNTION WHICH DISPLAYS THE OPTIONS TO THE CUSTOMER
void mainnenu()
{
    cout << "\n\t\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t\t\t\t\t\tWELCOME TO RESTURANMT TEA CUP HOTEL SYSTEM\n";
    cout << "\t\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t\t\t\t\t\t\t@@@@@@@@@@@@@@@@";
    cout << "\n\t\t\t\t\t\t\t\t\t@\t\t@@@@";
    cout << "\n\t\t\t\t\t\t\t\t\t@\t\t@    @";
    cout << "\n\t\t\t\t\t\t\t\t\t@\t\t@    @";
    cout << "\n\t\t\t\t\t\t\t\t\t@\t\t@    @";
    cout << "\n\t\t\t\t\t\t\t\t\t@\t\t@@@@";
    cout << "\n\t\t\t\t\t\t\t\t\t @             @\t";
    cout << "\n\t\t\t\t\t\t\t\t\t  @@@@@@@@@@@@\t";
    cout << "\n";
    cout << "\n";
    cout << "\n";

    cout << "\t\t\t\t\t1. ADMIN SECTION--> \n";
    cout << "\t\t\t\t\t2. CUSTOMER SECTION--> \n";
    cout << "\t\t\t\t\t3. Exit--> \n\n";
    cout << "\t\t\t\t\tEnter Your Choice --->";
}


//THIS IS THE MAIN FUNCTION WHERE ALL THE FUNCTIONS ARE BEING CALLED
int main()
{
   // system("color 64");
    system("color 9f");
   // system("color 4E");
   // 
    //system("color 97");
    heada = createadmin(heada, 1, "Hot and Sour Soup", 150);
    heada = createadmin(heada, 2, "Manchow Soup", 300);
    heada = createadmin(heada, 3, "Manchurian Noodles", 150);
    heada = createadmin(heada, 4, "Fried Rice     ", 180);
    heada = createadmin(heada, 5, "Special Noodles", 120);
    heada = createadmin(heada, 6, "French Fries    ", 180);
    heada = createadmin(heada, 7, "Pizza Fries     ", 280);
    heada = createadmin(heada, 8, "Chicken karhai", 800);
    heada = createadmin(heada, 9, "Chicken Korma", 750);
    heada = createadmin(heada, 10, "Chicken Sandwish", 270);
    heada = createadmin(heada, 11, "Chicken Biryani", 200);
    
   // system("Color 11");
    while (1)
    {
        mainnenu();
        int choice;
        cin >> choice;

        if (choice == 3)
        {
            cout << "\n\n\t\t\t\t|||||||||||||||||| *** THANK YOU FOR CHOOOSING US TO FULFIL YOUR ORDER **** ||||||||||||||||||||||||\n";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\t\t\t\t\t\t\t\t\t@@@@@@@@@@@@@@@@";
            cout << "\n\t\t\t\t\t\t\t\t\t@\t\t@@@@";
            cout << "\n\t\t\t\t\t\t\t\t\t@\t\t@    @";
            cout << "\n\t\t\t\t\t\t\t\t\t@\t\t@    @";
            cout << "\n\t\t\t\t\t\t\t\t\t@\t\t@    @";
            cout << "\n\t\t\t\t\t\t\t\t\t@\t\t@@@@";
            cout << "\n\t\t\t\t\t\t\t\t\t @             @\t";
            cout << "\n\t\t\t\t\t\t\t\t\t  @@@@@@@@@@@@\t";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            break;
        }

        switch (choice)
        {
        case 1:
            admin();
            break;
        case 2:
            customer();
            break;
        case 3:
            system("color 60");
            break;

        default:
            cout << "\n\t\t\t\t\t\tWrong Input !! PLease choose valid option\n";
            break;
        }
    }
}