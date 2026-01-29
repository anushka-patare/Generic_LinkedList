//////////////////////////////////////////
// Generic Singly Circular linked list
//////////////////////////////////////////

/*
----------------------------------------------------------------------------------------------------------------
Type                  Name of class for node                 Name of class for functionality: SinglyLLL
----------------------------------------------------------------------------------------------------------------

Singly Circular       SinglyCLLnode                          SinglyCLL                  Done

----------------------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
//          Singly Circular linked list using generic approach
//////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>

class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> *first;
        SinglyCLLnode<T> *last;
        int iCount;
    
    public:
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);    
        void InsertAtPos(T,int);
        void DeleteFirst(); 
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

template<class T>

SinglyCLL<T> :: SinglyCLL()
{
    cout<<"Object of singlyCL gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   InsertFirst
//    Input         :   Data of node
//    Output        :   Nothing
//    Description   :   Used to insert node at first position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
void SinglyCLL<T> ::  InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = NULL;
    newn = new SinglyCLLnode<T>(no) ;

    if(this->first== NULL && this->last== NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next  = this->first;
        this->first = newn; 
        
    }
    this->last->next = this->first;
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   InsertLast
//    Input         :   Data of node
//    Output        :   Nothing
//    Description   :   Used to insert node at last position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>

void SinglyCLL<T> :: InsertLast(T no)
{ 
    SinglyCLLnode<T> *newn = NULL;
    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }
    this->last->next = first;
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   InsertAtPos
//    Input         :   Data of node, int
//    Output        :   Nothing
//    Description   :   Used to insert node at specific position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>

void SinglyCLL<T> ::  InsertAtPos(T no,int pos)
{
    int iCnt = 0;
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *newn = NULL;
    
    if(pos<1 || pos>this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos==1)
    {
        InsertFirst(no);
    }
    else if(pos==iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);
        temp = this->first;

        for(iCnt=1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   DeleteFirst
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to delete node at first position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>

void SinglyCLL<T> :: DeleteFirst()
{
    SinglyCLLnode<T> *temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }

    else if(this->first==last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        this->first  = this->first->next;
        delete temp;
        this->last->next = this->first;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   DeleteLast
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to insert node at last position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 
        
template <class T>

void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T> *temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        while(temp->next != this->last)
        {
            temp = temp->next;
        }
        
        delete temp->next;
        this->last = temp;
        this->last->next = this->first;
    }  
    this->iCount--;  
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   DeleteAtPos
//    Input         :   int
//    Output        :   Nothing
//    Description   :   Used to delete node at specific position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>

void SinglyCLL<T> ::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *target = NULL;
    int iCnt = 0;
    
    if(pos<1 || pos>iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt=1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;
        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Display
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to display all nodes
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
void SinglyCLL<T> :: Display()
{
    SinglyCLLnode<T> *temp = NULL;
    temp = this->first;
    do
    {
        cout<< "| " << temp->data << "| ->";
        temp = temp->next; 
    } 
    while(temp != last->next);
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Countt
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to count total node 
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template<class T>
int SinglyCLL<T>:: Count()
{
    return iCount;
}


int main()
{
    
    int datatype = 0;

    cout<<"Select data type :\n";
    cout<<"1. int\n";
    cout<<"2. float\n";
    cout<<"3. char\n";
    cout<<"4. double\n";
    cout<<"Enter choice:\n";
    cin>>datatype;

    if(datatype ==1)
    {
        SinglyCLL<int> *sobj = new SinglyCLL<int>();
        int iValue = 0,choice = 0;
        int iRet = 0, pos = 0;
        while(1)
        {
            cout<<"\n------------------------------------------------------------------------\n";
            cout<<"-----------------------Singly Linear Linked List--------------------------\n";
            cout<<"--------------------------------------------------------------------------\n";
            cout<<"----------------Please select the option-------------------\n";
            cout<<"1 : Insert First element into linked list\n";
            cout<<"2 : Insert Last element into linked list\n";
            cout<<"3 : Insert element at specific position\n";
            cout<<"4 : Delete the first element from linked list\n";
            cout<<"5 : Delete the last element from linked list\n";
            cout<<"6 : Delete the element from specific position :\n";
            cout<<"7 : Display the elements of linked list\n";
            cout<<"8 : Count the elements of linked list\n";
            cout<<"0 : Exit the application\n";

            cin>>choice;

            switch(choice)
            {
                case 1:
                    cout<<"Enter the elements that you want to insert first:\n";
                    cin>>iValue;
                    sobj->InsertFirst(iValue);
                    cout<<"Elements gets inserted successfully.\n";
                    break;

                case 2:
                    cout<<"Enter the elements that you want to insert last :\n";
                    cin>>iValue;
                    sobj->InsertLast(iValue);
                    cout<<"Elements gets inserted successfully.\n";
                    break;

                case 3:
                    cout<<"Enter the elements that you want to insert at specific position :\n";
                    cin>>iValue;
                    cin>>pos;
                    sobj->InsertAtPos(iValue,pos);
                    cout<<"Elements gets inserted successfully.\n";
                    break;

                case 4:
                    cout<<"Delete the first element from linked list\n";
                    sobj->DeleteFirst();
                    cout<<"Elements gets deleted successfully.\n";
                    break;
                
                case 5:
                    cout<<"Delete the last element from linked list :\n";
                    sobj->DeleteLast();
                    cout<<"Elements gets deleted successfully.\n";
                    break;

                case 6:
                    cout<<"Delete the element from given position from the linked list :\n";
                    cin>>pos;
                    sobj->DeleteAtPos(pos);
                    cout<<"Elements gets deleted successfully.\n";
                    break;

                case 7:
                    cout<<"Display the elements of linked list:\n";
                    sobj->Display();
                    cout<<"Elements gets displayed successfully.\n";
                    break;

                case 8:
                    cout<<"Count the elements of linked list:\n";
                    iRet = sobj->Count();
                    cout<<"Total elements of linked list is " <<iRet<<"\n";
                    break;

                case 0:
                    cout<<"Thank you for using our application\n";
                    delete sobj;
                    return 0;

                default:
                    cout<<"Please enter valid option\n";
            }
        }
    }
    else if(datatype ==2)
    {
        SinglyCLL<float> *sobj = new SinglyCLL<float>();
        float fValue = 0;
        int choice = 0;
        int iRet = 0, pos = 0;
        while(1)
        {
            cout<<"\n------------------------------------------------------------------------\n";
            cout<<"-----------------------Singly Linear Linked List--------------------------\n";
            cout<<"--------------------------------------------------------------------------\n";
            cout<<"----------------Please select the option-------------------\n";
            cout<<"1 : Insert First element into linked list\n";
            cout<<"2 : Insert Last element into linked list\n";
            cout<<"3 : Insert element at specific position\n";
            cout<<"4 : Delete the first element from linked list\n";
            cout<<"5 : Delete the last element from linked list\n";
            cout<<"6 : Delete the element from specific position :\n";
            cout<<"7 : Display the elements of linked list\n";
            cout<<"8 : Count the elements of linked list\n";
            cout<<"0 : Exit the application\n";

            cin>>choice;

            switch(choice)
            {
                case 1:
                    cout<<"Enter the elements that you want to insert first:\n";
                    cin>>fValue;
                    sobj->InsertFirst(fValue);
                    cout<<"Elements gets inserted successfully.\n";
                    break;

                case 2:
                    cout<<"Enter the elements that you want to insert last :\n";
                    cin>>fValue;
                    sobj->InsertLast(fValue);
                    cout<<"Elements gets inserted successfully.\n";
                    break;

                case 3:
                    cout<<"Enter the elements that you want to insert at specific position :\n";
                    cin>>fValue;
                    cin>>pos;
                    sobj->InsertAtPos(fValue,pos);
                    cout<<"Elements gets inserted successfully.\n";
                    break;

                case 4:
                    cout<<"Delete the first element from linked list\n";
                    sobj->DeleteFirst();
                    cout<<"Elements gets deleted successfully.\n";
                    break;
                
                case 5:
                    cout<<"Delete the last element from linked list :\n";
                    sobj->DeleteLast();
                    cout<<"Elements gets deleted successfully.\n";
                    break;

                case 6:
                    cout<<"Delete the element from given position from the linked list :\n";
                    cin>>pos;
                    sobj->DeleteAtPos(pos);
                    cout<<"Elements gets deleted successfully.\n";
                    break;

                case 7:
                    cout<<"Display the elements of linked list:\n";
                    sobj->Display();
                    cout<<"Elements gets displayed successfully.\n";
                    break;

                case 8:
                    cout<<"Count the elements of linked list:\n";
                    iRet = sobj->Count();
                    cout<<"Total elements of linked list is " <<iRet<<"\n";
                    break;

                case 0:
                    cout<<"Thank you for using our application\n";
                    delete sobj;
                    return 0;

                default:
                    cout<<"Please enter valid option\n";
            }
        }
    }
    else if(datatype ==3)
    {
        SinglyCLL<char> *sobj = new SinglyCLL<char>();
        char cValue = 0;
        int choice = 0;
        int iRet = 0, pos = 0;
        while(1)
        {
            cout<<"\n------------------------------------------------------------------------\n";
            cout<<"-----------------------Singly Linear Linked List--------------------------\n";
            cout<<"--------------------------------------------------------------------------\n";
            cout<<"----------------Please select the option-------------------\n";
            cout<<"1 : Insert First element into linked list\n";
            cout<<"2 : Insert Last element into linked list\n";
            cout<<"3 : Insert element at specific position\n";
            cout<<"4 : Delete the first element from linked list\n";
            cout<<"5 : Delete the last element from linked list\n";
            cout<<"6 : Delete the element from specific position :\n";
            cout<<"7 : Display the elements of linked list\n";
            cout<<"8 : Count the elements of linked list\n";
            cout<<"0 : Exit the application\n";

            cin>>choice;

            switch(choice)
            {
                case 1:
                    cout<<"Enter the elements that you want to insert first:\n";
                    cin>>cValue;
                    sobj->InsertFirst(cValue);
                    cout<<"Elements gets inserted successfully.\n";
                    break;

                case 2:
                    cout<<"Enter the elements that you want to insert last :\n";
                    cin>>cValue;
                    sobj->InsertLast(cValue);
                    cout<<"Elements gets inserted successfully.\n";
                    break;

                case 3:
                    cout<<"Enter the elements that you want to insert at specific position :\n";
                    cin>>cValue;
                    cin>>pos;
                    sobj->InsertAtPos(cValue,pos);
                    cout<<"Elements gets inserted successfully.\n";
                    break;

                case 4:
                    cout<<"Delete the first element from linked list\n";
                    sobj->DeleteFirst();
                    cout<<"Elements gets deleted successfully.\n";
                    break;
                
                case 5:
                    cout<<"Delete the last element from linked list :\n";
                    sobj->DeleteLast();
                    cout<<"Elements gets deleted successfully.\n";
                    break;

                case 6:
                    cout<<"Delete the element from given position from the linked list :\n";
                    cin>>pos;
                    sobj->DeleteAtPos(pos);
                    cout<<"Elements gets deleted successfully.\n";
                    break;

                case 7:
                    cout<<"Display the elements of linked list:\n";
                    sobj->Display();
                    cout<<"Elements gets displayed successfully.\n";
                    break;

                case 8:
                    cout<<"Count the elements of linked list:\n";
                    iRet = sobj->Count();
                    cout<<"Total elements of linked list is " <<iRet<<"\n";
                    break;

                case 0:
                    cout<<"Thank you for using our application\n";
                    delete sobj;
                    return 0;

                default:
                    cout<<"Please enter valid option\n";
            }
        }
    }

    else if(datatype ==4)
    {
        SinglyCLL<double> *sobj = new SinglyCLL<double>();
        double dValue = 0.0;
        int choice = 0;
        int iRet = 0, pos = 0;
        while(1)
        {
            cout<<"\n------------------------------------------------------------------------\n";
            cout<<"-----------------------Singly Linear Linked List--------------------------\n";
            cout<<"--------------------------------------------------------------------------\n";
            cout<<"----------------Please select the option-------------------\n";
            cout<<"1 : Insert First element into linked list\n";
            cout<<"2 : Insert Last element into linked list\n";
            cout<<"3 : Insert element at specific position\n";
            cout<<"4 : Delete the first element from linked list\n";
            cout<<"5 : Delete the last element from linked list\n";
            cout<<"6 : Delete the element from specific position :\n";
            cout<<"7 : Display the elements of linked list\n";
            cout<<"8 : Count the elements of linked list\n";
            cout<<"0 : Exit the application\n";

            cin>>choice;

            switch(choice)
            {
                case 1:
                    cout<<"Enter the elements that you want to insert first:\n";
                    cin>>dValue;
                    sobj->InsertFirst(dValue);
                    cout<<"Elements gets inserted successfully.\n";
                    break;

                case 2:
                    cout<<"Enter the elements that you want to insert last :\n";
                    cin>>dValue;
                    sobj->InsertLast(dValue);
                    cout<<"Elements gets inserted successfully.\n";
                    break;

                case 3:
                    cout<<"Enter the elements that you want to insert at specific position :\n";
                    cin>>dValue;
                    cin>>pos;
                    sobj->InsertAtPos(dValue,pos);
                    cout<<"Elements gets inserted successfully.\n";
                    break;

                case 4:
                    cout<<"Delete the first element from linked list\n";
                    sobj->DeleteFirst();
                    cout<<"Elements gets deleted successfully.\n";
                    break;
                
                case 5:
                    cout<<"Delete the last element from linked list :\n";
                    sobj->DeleteLast();
                    cout<<"Elements gets deleted successfully.\n";
                    break;

                case 6:
                    cout<<"Delete the element from given position from the linked list :\n";
                    cin>>pos;
                    sobj->DeleteAtPos(pos);
                    cout<<"Elements gets deleted successfully.\n";
                    break;

                case 7:
                    cout<<"Display the elements of linked list:\n";
                    sobj->Display();
                    cout<<"Elements gets displayed successfully.\n";
                    break;

                case 8:
                    cout<<"Count the elements of linked list:\n";
                    iRet = sobj->Count();
                    cout<<"Total elements of linked list is " <<iRet<<"\n";
                    break;

                case 0:
                    cout<<"Thank you for using our application\n";
                    delete sobj;
                    return 0;

                default:
                    cout<<"Please enter valid option\n";
            }
        }
    }
    else
    {
        cout<<"Sorry..! You have entered invalid datatype.\n";
    }
    return 0;
}