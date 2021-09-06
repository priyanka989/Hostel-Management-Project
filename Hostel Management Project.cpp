/* 

Data Structure and Algorithm PROJECT:

Name -- Priyanka Dahikamble
 




Topic -- Hostel Booking System
        
        User can login as admin or student.
        We have 1 building having 3 floors . Each floor has 10 rooms.
        Room can either accomodate 2 students or 3 students.
        
        
Other group members:
2314 – Roshani Sanjay Bhojane
2324 – Harshada Ravindra Chavan
2327 – Priyanka Uttam Dahikamble

*/



        
        
        
        
        
#include <iostream>
#include <string.h>
using namespace std;
class node        //creates node class 
{
    public:
    // Data members 
    int roomNo ;
    int no_cots;
    string name[3],address[3];
    long int phone[3];
    int year[3];
    node *next;
    
    node() // Default constructor of node class
    {
        roomNo=0;
        no_cots=2;
        next=NULL;
    }
    
    friend class hostelFloor;
};

class hostelFloor        //creates class hostelFloor
{
            
    int del[30];      //array for storing room numbers to be deleted
    int delCount=-1;   //counter for counting number of rooms that are deleted 
    node *head;
    public:
      
    hostelFloor()      //Default constructor foe hostelFloor class
    {
        head=NULL;
    }
    
    void hostelInfo();
    void create(int);
    void displayFloors(int);
    void book(int,int);
    void displayStudents(int,int);
    void cancelBooking(int);
    void updateInformtion(int);
    int chkFloor(int);
    int chkroom(int,int);
    void deleteRoom(int);
    int chkDelete(int);
    
};

//function to check if entered room number is deleted.
//Time Complexity -->  O(n)
int hostelFloor::chkDelete(int r)    
{
    int flag=0;
    for(int i=0;i<30;i++)    //traverse through the array of deleted room number
    {
        if(del[i]==r)
            {
                flag=1;
                return 1;
                break;
            }
    }
    if(flag==0)
    {
        return 0;
    }
}


//function to check if entered room number is valid or not 
//Time Complexity -->  O(1)
int hostelFloor::chkroom(int r,int f)
{   
    
        if(r>(f*100) && r<=(f*100+10))
            {
                return 1;
            }
        else 
           {
               cout<<"------------------------"<<endl;
               cout<<"Invalid room number"<<endl;
               cout<<"------------------------"<<endl;
               return 0;
            }
    
}


//function to check if entered floor number is valid or not 
//Time Complexity -->  O(1)
int hostelFloor::chkFloor(int f)
{
    if(f>=1 && f<=3)
    {
        return 1;
    }
    else
    {   cout<<"------------------------"<<endl;
        cout<<"Invalid floor number"<<endl;
        cout<<"------------------------"<<endl;
        return 0;
    }
}


// function to display hostel information
//Time Complexity -->  O(1)
void hostelFloor::hostelInfo()     
{
   cout<<"\n\t-------------------------------------------------------------------------------------------------------------------";
   cout<<"\n\t\tIt is endowed with all facilities.\n\t\tSurrounded by lush greenery, bright sunshine and fresh ambience \n\t\thostel complex is crafted to suit the requirements of all college students making\n\t\ttheir stay an accomplished one.\n\t\tThe hostel complex is situated in close proximity to the educational institutions for the convenience of the students.\n\t\t Baya Karve Hostel Complex provides worthy, safe and reliable accommodation at economical charges."<<endl;
   cout<<"\n\t\t\t\t\tContact Us";
   cout<<"\n\t\tAddress: Karve Nagar, Pune - 411052";
   cout<<"\n\t\tPhone: +91.20.25313000 / 25313200";
   cout<<"\n\t\tFax: +91.20.25313300";
   cout<<"\n\t\tEmail Id: info@maharshikarve.org"<<endl;
   cout<<"\n\t-------------------------------------------------------------------------------------------------------------------";
}


//function to create new rooms and assign number of cots in each room
//Time Complexity -->  O(n^2)
void hostelFloor::create(int i)
{
    for (int j = 0; j < 10; j++)
    {
        node *newRoom = new node;        //creates nodes for rooms
        newRoom->roomNo=(100*i)+(j+1);   //assigns room number
        newRoom->next = NULL;
        
        if (head == NULL)    //if list is empty
        {
            head = newRoom;
        }
        
        else
        {
            node *ptr=head;
            while (ptr->next != NULL)    //traverse ptr till last node
            {
                ptr = ptr->next;
            }
            
            if (ptr->roomNo%2==0)   //if room number is even then total number of cots=2
            {
                ptr->no_cots = 2;
            }
            else                      
            {
                ptr->no_cots = 3;     //if room number is odd then total number of cots=3
            }
                    
            ptr->next = newRoom;
        }           
    }
}


//function to display status of rooms on particular floor
//Time Complexity -->  O(n)
void hostelFloor::displayFloors(int f)
{  
    node *ptr=head;
    cout<<"\t\t";
    
    for(int i=0;i<10;i++)
    {
        cout<<"-------";
    }
    
    cout<<"\n";
    cout<<"\t\t\t\t\t Floor number "<<f;
    cout<<"\n";
    cout<<"\t\t";
    for(int i=0;i<10;i++)
    {
        cout<<"-------";
    }
    while(ptr!=NULL)
    {
        cout<<"\n\t\t\t\tRoom number:"<<ptr->roomNo;
        if(ptr->no_cots==0)          //displays status of room /vacant cots after booking
        {
            cout<<"\t\t Room is occupied";      
        }
        else
        {
            cout<<"\t Number of vacant cots:"<<ptr->no_cots;
        }
        
        ptr=ptr->next;
    }
    cout<<"\n\t\t";
    
    for(int i=0;i<10;i++)
    {
        cout<<"-------";
    }
    cout<<"\n\n";
    
}

//function to book a room for given number of people
//Time Complexity -->  O(n)
void hostelFloor::book(int f,int p1)
{
    int rn;
    int count=0;                      //counter to count number of booked cots
    cout<<"\nEnter room number : ";
    cin>>rn;
    
if(chkDelete(rn))    //to check if the room number number entered by user is deleted
{
    cout<<"-----------------------------------------------"<<endl;
    cout<<"Room is not available for booking of students"<<endl;
    cout<<"-----------------------------------------------"<<endl;
}

else
{
    
    if(chkroom(rn,f))     //checks if the room number is valid or not
    {
        node *ptr=head;
        while(ptr!=NULL)    //traverse the pointer to entered room number
        {
            if(ptr->roomNo==rn)
            {
                break;
            }
            else
            {
                ptr=ptr->next;
            }
        }
        
        if(ptr->no_cots>=p1)        //checks if the room is available for given number of people
        {
            cout<<"\n Room is vaccant you can apply for room !\n";
            for(int i=0;i<p1;i++)
            {
                cout<<"\nEnter the details of student below";
                cout<<"\n\nEnter name : ";
                cin.ignore();
                getline(cin,ptr->name[i]);
                cout<<"Enter year : ";
                cin>>ptr->year[i];
                cout<<"Enter contact number : ";
                cin>>ptr->phone[i];
                cout<<"Enter address : ";
                cin.ignore();
                getline(cin,ptr->address[i]);
                count++;                        //increment the counter
                
            }
            
            ptr->no_cots=ptr->no_cots-count;      //updates the number of cots after booking and displays number of vacant cots
        }
        else if(ptr->no_cots==0)               //if all the cots are occupied
        {
            cout<<"--------------------------"<<endl;
            cout<<"   Room is occupied !!"<<endl;
            cout<<"--------------------------"<<endl;
        }
        else 
        {
            //if vacant cots are less than entered number of students
            cout<<"------------------------------------------"<<endl;
            cout<<"Room is not available for "<<p1<<" students!"<<endl;
            cout<<"------------------------------------------"<<endl;
        }
    }
}
}



 
//fuction to display information of students in a particular room
//Time Complexity -->  O(n)
void hostelFloor::displayStudents(int r1,int f)
{    
    node *ptr;
     
  if(chkDelete(r1))
{
    cout<<"-----------------------------------------------"<<endl;
    cout<<"Room is not available for booking of students"<<endl;
    cout<<"-----------------------------------------------"<<endl;
}
 else
 {

    if(chkroom(r1,f))                  //check if room number is valid or not
            {
                ptr=head;
        while(ptr!=NULL)    
            { 
                if(ptr->roomNo==r1)
                    { 
                        break;
                    }
                else 
                    {
                        ptr=ptr->next;
                    }
            }
            }
        else 
           {
               cout<<"------------------------"<<endl;
               cout<<"Invalid room number"<<endl;
               cout<<"------------------------"<<endl;
               
            }
        
     
    if(ptr->year[0]==0)      //checks if the room is empty
    {
        cout<<"------------------------"<<endl;
        cout<<"  Room is empty!"<<endl;
        cout<<"------------------------"<<endl;
    }
    else
    {
        cout<<"\n\t\t\t\t\t----------------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t\t  ROOM NUMBER : "<<r1;
        cout<<"\n\t\t\t\t\t----------------------------------------------------------";
        
        if(r1%2==0)             //checks if the room has 2 cots
        {
            int i=2-ptr->no_cots;      // variable i stores number of filled cots
            for(int j=0;j<i;j++)       //to display information of students who booked room
            {
                cout<<"\n\t\t\t\t\t\t";
                cout<<"Student :"<<j+1<<"--->";
                cout<<"\t\tName:"<<ptr->name[j];
                cout<<"\n\t\t\t\t\t\t\t\t\tYear of study:"<<ptr->year[j];
                cout<<"\n\t\t\t\t\t\t\t\t\tAddress:"<<ptr->address[j];
                cout<<"\n\t\t\t\t\t\t\t\t\tContact number:"<<ptr->phone[j]<<endl;
                cout<<"\t\t\t\t\t----------------------------------------------------------";
        
            }
        }
        else                  //for rooms having 3 cots
        {
            int i=3-ptr->no_cots;
            for(int j=0;j<i;j++)
            {
                cout<<"\n\t\t\t\t\t\t";
                cout<<"Student :"<<j+1<<"--->";
                cout<<"\t\tName:"<<ptr->name[j];
                cout<<"\n\t\t\t\t\t\t\t\t\tYear of study:"<<ptr->year[j];
                cout<<"\n\t\t\t\t\t\t\t\t\tAddress:"<<ptr->address[j];
                cout<<"\n\t\t\t\t\t\t\t\t\tContact number:"<<ptr->phone[j]<<endl;
                cout<<"\t\t\t\t\t----------------------------------------------------------";
            }
        }
    }
}
}


//function to cancel booking 
//Time Complexity -->  O(n)
void hostelFloor::cancelBooking(int f)
{
    node *ptr=head;
    int key;
    int rn,i;
    string n;
    
    cout<<"\nEnter room number:";
    cin>>rn;
    
if(chkDelete(rn))
{
    cout<<"-----------------------------------------------"<<endl;
    cout<<"Room is not available for booking of students"<<endl;
    cout<<"-----------------------------------------------"<<endl;
}
else
{
      
    if(chkroom(rn,f))      //checks if room number is valid or not
    {
        node *ptr=head;
                   
        while(ptr!=NULL)
        {
            if(ptr->roomNo==rn)
            {
                break;
            }
            else
            {
                ptr=ptr->next;
            }
        }
        
        if(ptr->name[0]=="")     //check if room is empty
        {
            cout<<"------------------"<<endl;
            cout<<"  Room is empty !"<<endl; 
            cout<<"------------------"<<endl;
        }
        
        else
        {
            cout<<"\nEnter the name of student :";
            cin>>n;
            for( i=0;i<3;i++)     //to compare the entered name with names present in array
                {
                    key=n.compare(ptr->name[i]);
                    if(key==0)
                        {
                            break;
                        }
        }
        
        if(key==0)
        {
            //removing the details of the student
            ptr->name[i]="";
            ptr->address[i]="";
            ptr->phone[i]=0;
            ptr->year[i]=0;
            ptr->no_cots=ptr->no_cots+1;
            
            if(ptr->roomNo%2==0)   //for the rooms having two number of cots
            {
               if(i==0)            //if the details at index 0 are deleted
               {
                   //shift the details of student at index 1 to index 0
                   ptr->name[i]=ptr->name[i+1];
                   ptr->year[i]=ptr->year[i+1];
                   ptr->address[i]=ptr->address[i+1];
                   ptr->phone[i]=ptr->phone[i+1];
                }
            }
            else                  //for the rooms having 3 number of cots
            {
                if(i==0)           //if the details at index 0 are deleted
                {
                    for(int j=0;j<2;j++)    
                    {
                    //shift the details of student to previous indices
                     ptr->name[j]=ptr->name[j+1];
                     ptr->year[j]=ptr->year[j+1];
                     ptr->address[j]=ptr->address[j+1];
                     ptr->phone[j]=ptr->phone[j+1];
                    }
                }
                else if(i==1)     //if the details at index 1 are deleted
                {
                   //shift the details of student at index 2 to index 1
                   ptr->name[i]=ptr->name[i+1];
                   ptr->year[i]=ptr->year[i+1];
                   ptr->address[i]=ptr->address[i+1];
                   ptr->phone[i]=ptr->phone[i+1];
                }
               
            }
            cout<<"------------------------------------------"<<endl;
            cout<<"\tBooking cancelled successfully."<<endl;
            cout<<"------------------------------------------"<<endl;
        }
        else 
        {
            cout<<"------------------------------------"<<endl;
            cout<<"   Student record not found !!!"<<endl;
            cout<<"------------------------------------"<<endl;
        }
        }
    }
}
}

//function to update information of a student
////Time Complexity -->  O(n)
void hostelFloor::updateInformtion(int f)
{
    node *ptr=head;
    int ch,y2,flag,i,r;    
    string n2,n;
    long int ph;
     
    cout<<"\nEnter room number: ";
    cin>>r;
    
if(chkDelete(r))                 //To check if entered room number is deleted
{
    cout<<"-----------------------------------------------"<<endl;
    cout<<"Room is not available for booking of students"<<endl;
    cout<<"-----------------------------------------------"<<endl;
}

else
{
    
    if(chkroom(r,f))       //checks if the room number is valid or not
    {
        while(ptr!=NULL)
        {
            if(ptr->roomNo==r)      //traverse linked list till we reach node having entered room number
            {
                break;
            }
            else
            {
                ptr=ptr->next;
            }
        }
       
        cout<<"\nEnter name of student:";
        cin.ignore();         //to clear unwanted buffer
        getline(cin,n);      // standard library function to read string
        
        for(i=0;i<3;i++)    //to iterate through array of names
        {
            int key=n.compare(ptr->name[i]); 
            if(key==0)
            {
                flag=1;    //flag is set to 1 if student name is present
                break;
            }
        }
        
        if(flag==1)  //if student name is present in the node
        {   
            do
            {
                //ask the user what to update
                cout<<"\nWhat do you want to update:"<<endl;
                cout<<"\n1.Name\n2.Year\n3.Phone Number\n4.Address\n5.Exit"<<endl;
                cin>>ch;
                switch(ch)
                {
                    case 1: //updates name
                            {
                             cout<<"\nEnter updated name:"<<endl;
                             cin.ignore();
                             getline(cin,n2);
                             ptr->name[i]=n2;
                             break;
                            }
                   
                    case 2: //updates year
                            {                  
                            cout<<"\nEnter updated year:"<<endl;
                            cin>>y2;
                            ptr->year[i]=y2;
                            break;
                            }
                   
                   case 3://updates phone number
                          {
                            cout<<"\nEnter updated phone number:"<<endl;
                            cin>>ph;
                            ptr->phone[i]=ph;
                            break;
                          }
                    
                   case 4://updates address
                         { 
                            cout<<"\nEnter updated address:"<<endl;
                            cin.ignore();
                            getline(cin,n2);
                            ptr->address[i]=n2;
                            break;
                         }
                    
                    case 5:
                           break;
                    
                    default: cout<<"\nInvalid choice entered!"<<endl;
                    
                }
            }while(ch!=5);
            cout<<"------------------------------------------"<<endl;
            cout<<"\tInformation updated successfully !"<<endl;
            cout<<"------------------------------------------"<<endl;
        }
        
        else
        {
            cout<<"------------------------------------------"<<endl;
           cout<<"   Student record not found!!!"<<endl;
           cout<<"------------------------------------------"<<endl;
        }
    }
}
    
}


//Function to delete a room from floor
//Time Complexity -->  O(n)
void hostelFloor::deleteRoom(int f)
{   
    int r;
    node *ptr=head; 
    node *prev=NULL;   //to keep track of previous node
    cout<<"\nEnter room number you want to delete:";
    cin>>r;
    
    if(chkroom(r,f)) 
    
{
      delCount++;        //variable increments every time a room is deleted
      del[delCount]=r;  //stores room number of deleted room in array
      while(ptr!=NULL) //to bring ptr to node having given room number
     {
         if(ptr->roomNo==r)
         {
             break;
         }
         else          
         { 
             prev=ptr;   //bring prev pointer to ptr
             ptr=ptr->next;
         }
     }
     if(ptr==head)  //if node to be deleted is the first node
     {
         head=head->next;  
          ptr=NULL;
         
     }
     else    
     {
         prev->next=ptr->next;  
         ptr=NULL;
     }
  }
     
}
    
int main()
{
    int ch,ch1,ch3,ch2,r;
    string n;
    int f;
    hostelFloor floor1;   //object for creating list of room in floor 1
    hostelFloor floor2;   //object for creating list of room in floor 2
    hostelFloor floor3;   //object for creating list of room in floor 3
    
   cout<<"\n                                        :::::::::::::::::::::::::::::::::::::::::::::";
   cout<<"\n                                        ::                                         ::";
   cout<<"\n                                        ::     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     ::";
   cout<<"\n                                        ::     @                             @     ::";
   cout<<"\n                                        ::     @       * WELCOME TO *        @     ::"; 
   cout<<"\n                                        ::     @                             @     ::";
   cout<<"\n                                        ::     @  BAYA KARVE HOSTEL COMPLEX  @     ::";
   cout<<"\n                                        ::     @       KARVENAGAR,PUNE       @     ::";
   cout<<"\n                                        ::     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     ::";
   cout<<"\n                                        ::                                         ::";
   cout<<"\n                                        :::::::::::::::::::::::::::::::::::::::::::::\n\n";
 
   cout<<"\t\t\t\t------------------------------------------------------------------";
   cout<<"\n\t\tMaharshi Karve Stree Shikshan Samstha (MKSSS), Pune provides hostel facility to its students."; 
   cout<<"\n\t\tBaya Karve Hostel Complex within the Karvenagar campus of MKSSS is truly “A Home Away From Home”."<<endl;
   cout<<"\t\t\t\t------------------------------------------------------------------";
   floor1.create(1);
   floor2.create(2);
   floor3.create(3);
   do
   {
        cout<<"\n\n\t\t\t\t\t\t1.Login as admin\n\t\t\t\t\t\t2.Login as student\n\t\t\t\t\t\t3.Exit"<<endl;
        cout<<"\n\t\t\t\t\t\tEnter your choice:";
        cin>>ch;
  
        switch(ch)
        {
            case 1://login admin
                do
                {
                    cout<<"\n\n\t\t\t\t\t\t1.See the details of student in room.\n\t\t\t\t\t\t2.Delete a room.\n\t\t\t\t\t\t3.Back to login.";
                    cout<<"\n\t\t\t\t\t\tEnter your choice:";
                    cin>>ch1;
              
                    switch(ch1)
                    {
                        case 1:
                            {
                                cout<<"\nEnter floor number : ";
                                cin>>f;
                                if(f==1)
                                {
                                    cout<<"\nEnter a room number:";
                                    cin>>r;
                                    floor1.displayStudents(r,f);
                                }
                    
                                else if(f==2)
                                {
                                    cout<<"\nEnter a room number:";
                                    cin>>r;
                                    floor2.displayStudents(r,f);
                                }
                    
                                else if(f==3)
                                {
                                    cout<<"\nEnter a room number:";
                                    cin>>r;
                                    floor3.displayStudents(r,f);
                                }
                                
                                else
                                {
                                    cout<<"-----------------------"<<endl;
                                    cout<<" Invalid floor number "<<endl;
                                    cout<<"-----------------------"<<endl;
                                }
                  
                                break;
                            }
             
                
                        case 2:
                            {
                                 cout<<"\nEnter room floor number:";
                                 cin>>f;
                    
                                if(f==1)
                                {
                                    floor1.deleteRoom(1);
                                }
                                else if(f==2)
                                {
                                    floor2.deleteRoom(2);
                                }
                                else if(f==3)
                                {
                                    floor3.deleteRoom(3);
                                }
                                else
                                {
                                    cout<<"------------------------------------------"<<endl;
                                    cout<<"\tInvalid floor number entered!"<<endl;
                                    cout<<"------------------------------------------"<<endl;
                                }
                                break;
                            }
                 
                        case 3:  
                        break;
                
                        default : cout<<"Invalid choice entered ! "<<endl;
                    }
                
                }while(ch1!=3);
                break;
       
       
            case 2:
                do   //Menu driven
                { 
                    cout<<"\n\n\t\t\t\t\t\t1.Hostel information\n\t\t\t\t\t\t2.Book a room on floor 1.\n\t\t\t\t\t\t3.Book a room on floor 2.\n\t\t\t\t\t\t4.Book a room on floor 3.\n\t\t\t\t\t\t5.See status of rooms.\n\t\t\t\t\t\t6.Cancle booking.\n\t\t\t\t\t\t7.Update student information.\n\t\t\t\t\t\t8.Back to login.";
                    cout<<"\n\t\t\t\t\t\tEnter your choice:";
                    cin>>ch2;
                    switch(ch2)
                    {
                        case 1: //display hostel information
                            floor1.hostelInfo();
                            break;
        
                        case 2: //display options to book a room on floor 1
                            do
                            {    
                                cout<<"\n1.See the status of rooms.\n2.Book a room for 1 person.\n3.Book a room for 2 people.\n4.Book a room for 3 people.\n5.Go back to main menu";
                                cout<<"\nEnter your choice:";
                                cin>>ch3;
                                switch(ch3)
                                {
                                    case 1:
                                         floor1.displayFloors(1);
                                         break;
                           
                                    case 2:
                                        floor1.book(1,1);
                                        break;
                            
                                    case 3:
                                        floor1.book(1,2);
                                        break;
                          
                                    case 4:
                                        floor1.book(1,3);
                                        break;
                            
                                    case 5:
                                        break;
                               
                                    default: 
                                        cout<<"Invalid choice entered !"<<endl;
                       
                                }
                            }while(ch3!=5);
                             break;
                       
                        case 3:  //display options to book a room on floor 2
                            do
                            {
                                cout<<"\n1.See the status of rooms.\n2.Book a room for 1 person.\n3.Book a room for 2 people.\n4.Book a room for 3 people.\n5.Go back to main menu";
                                cout<<"\nEnter your choice:";
                                cin>>ch3;
                                switch(ch3)
                                {
                                    case 1:
                                    floor2.displayFloors(2);
                                    break;
                           
                                    case 2:
                                    floor2.book(2,1);
                                    break;
                            
                                    case 3:
                                    floor2.book(2,2);
                                    break;
                          
                                    case 4:
                                    floor2.book(2,3);
                                    break;
                            
                                    case 5:
                                    break;
                                   
                                    default: 
                                    cout<<"Invalid choice entered !"<<endl;
                       
                                }
                            }while(ch3!=5);
                            break;
                        
        
                        case 4:  //display options to book a room on floor 3
                            do
                            {
                                cout<<"\n1.See the status of rooms.\n2.Book a room for 1 person.\n3.Book a room for 2 people.\n4.Book a room for 3 people.\n5.Go back to main menu";
                                cout<<"\nEnter your choice:";
                                cin>>ch3;
                                switch(ch3)
                                {
                                    case 1:
                                       floor3.displayFloors(3);
                                       break;
                           
                                    case 2:
                                        floor3.book(3,1);
                                        break;
                            
                                    case 3:
                                       floor3.book(3,2);
                                       break;
                          
                                    case 4:
                                       floor3.book(3,3);
                                       break;
                            
                                    case 5:
                                       break;
                                       
                                    default: 
                                         cout<<"Invalid choice entered !"<<endl;
                                }
                            }while(ch3!=5);
                            break;
                       
                        case 5://displays the status of roooms on all the floors 
                             floor1.displayFloors(1);
                             floor2.displayFloors(2);
                             floor3.displayFloors(3);
                             break;
                     
                        case 6:
                            {
                                cout<<"\nEnter floor number:";
                                cin>>ch3;
                                if(ch3==1)
                                {
                                     floor1.cancelBooking(1);
                                }
                                
                                else if(ch3==2)
                                {
                                    floor2.cancelBooking(2);
                                }
                                
                                else if(ch3==3)
                                {
                                    floor3.cancelBooking(3);
                                }
                                
                                else
                                {
                                    cout<<"------------------------------------------"<<endl;
                                    cout<<"\tInvalid floor number entered!"<<endl;
                                    cout<<"------------------------------------------"<<endl;
                                }
                            break;
                        }
            
                        case 7:
                            {
                                cout<<"\nEnter room floor number:";
                                cin>>ch3;
           
                                if(ch3==1)
                                {
                                     floor1.updateInformtion(1);
                                }
                                else if(ch3==2)
                                {
                                    floor2.updateInformtion(2);
                                }
                                else if(ch3==3)
                                {
                                     floor3.updateInformtion(3);
                                }
                                else
                                {
                                     cout<<"------------------------------------------"<<endl;
                                     cout<<"\tInvalid floor number entered!"<<endl;
                                     cout<<"------------------------------------------"<<endl;
                                }
                                break;
                            }
                    
                        case 8: break;
            
                        default : cout<<"Invalid choice entered ! "<<endl;
                    }
    
    
                }while(ch2!=8);
                 break;
    
            case 3: break;
    
            default: cout<<"Invalid choice entered ! "<<endl;
       
        }
   
    }while(ch!=3);
}


/*OUTPUT:

                                        :::::::::::::::::::::::::::::::::::::::::::::
                                        ::                                         ::
                                        ::     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     ::
                                        ::     @                             @     ::
                                        ::     @       * WELCOME TO *        @     ::
                                        ::     @                             @     ::
                                        ::     @  BAYA KARVE HOSTEL COMPLEX  @     ::
                                        ::     @       KARVENAGAR,PUNE       @     ::
                                        ::     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     ::
                                        ::                                         ::
                                        :::::::::::::::::::::::::::::::::::::::::::::

				------------------------------------------------------------------
		Maharshi Karve Stree Shikshan Samstha (MKSSS), Pune provides hostel facility to its students.
		Baya Karve Hostel Complex within the Karvenagar campus of MKSSS is truly “A Home Away From Home”.
				------------------------------------------------------------------

						1.Login as admin
						2.Login as student
						3.Exit

						Enter your choice:1


						1.See the details of student in room.
						2.Delete a room.
						3.Back to login.
						Enter your choice:1

Enter floor number : 1

Enter a room number:105
------------------------
  Room is empty!
------------------------


						1.See the details of student in room.
						2.Delete a room.
						3.Back to login.
						Enter your choice:2 1

Enter floor number : 2

Enter a room number:201
------------------------
  Room is empty!
------------------------


						1.See the details of student in room.
						2.Delete a room.
						3.Back to login.
						Enter your choice:2

Enter room floor number:2

Enter room number you want to delete:201


						1.See the details of student in room.
						2.Delete a room.
						3.Back to login.
						Enter your choice:1

Enter floor number : 2

Enter a room number:201
-----------------------------------------------
Room is not available for booking of students
-----------------------------------------------


						1.See the details of student in room.
						2.Delete a room.
						3.Back to login.
						Enter your choice:3
						
						
						1.Login as admin
						2.Login as student
						3.Exit

						Enter your choice:2


						1.Hostel information
						2.Book a room on floor 1.
						3.Book a room on floor 2.
						4.Book a room on floor 3.
						5.See status of rooms.
						6.Cancle booking.
						7.Update student information.
						8.Back to login.
						Enter your choice:2 1

	-------------------------------------------------------------------------------------------------------------------
		It is endowed with all facilities.
		Surrounded by lush greenery, bright sunshine and fresh ambience 
		hostel complex is crafted to suit the requirements of all college students making
		their stay an accomplished one.
		The hostel complex is situated in close proximity to the educational institutions for the convenience of the students.
		 Baya Karve Hostel Complex provides worthy, safe and reliable accommodation at economical charges.

					Contact Us
		Address: Karve Nagar, Pune - 411052
		Phone: +91.20.25313000 / 25313200
		Fax: +91.20.25313300
		Email Id: info@maharshikarve.org

	-------------------------------------------------------------------------------------------------------------------

						1.Hostel information
						2.Book a room on floor 1.
						3.Book a room on floor 2.
						4.Book a room on floor 3.
						5.See status of rooms.
						6.Cancle booking.
						7.Update student information.
						8.Back to login.
						Enter your choice:2

1.See the status of rooms.
2.Book a room for 1 person.
3.Book a room for 2 people.
4.Book a room for 3 people.
5.Go back to main menu
Enter your choice:1
		----------------------------------------------------------------------
					 Floor number 1
		----------------------------------------------------------------------
				Room number:101	 Number of vacant cots:3
				Room number:102	 Number of vacant cots:2
				Room number:103	 Number of vacant cots:3
				Room number:104	 Number of vacant cots:2
				Room number:105	 Number of vacant cots:3
				Room number:106	 Number of vacant cots:2
				Room number:107	 Number of vacant cots:3
				Room number:108	 Number of vacant cots:2
				Room number:109	 Number of vacant cots:3
				Room number:110	 Number of vacant cots:2
		----------------------------------------------------------------------


1.See the status of rooms.
2.Book a room for 1 person.
3.Book a room for 2 people.
4.Book a room for 3 people.
5.Go back to main menu
Enter your choice:2

Enter room number : 1
------------------------
Invalid room number
------------------------

1.See the status of rooms.
2.Book a room for 1 person.
3.Book a room for 2 people.
4.Book a room for 3 people.
5.Go back to main menu
Enter your choice:102
Invalid choice entered !

1.See the status of rooms.
2.Book a room for 1 person.
3.Book a room for 2 people.
4.Book a room for 3 people.
5.Go back to main menu
Enter your choice:1 2

Enter room number : 102

 Room is vaccant you can apply for room !

Enter the details of student below

Enter name : 1 chinmayi
Enter year : 2
Enter contact number : 789654123
Enter address : Bramati^[[D^[[D^[[D^[[D                       ar  Baramti Pune

1.See the status of rooms.
2.Book a room for 1 person.
3.Book a room for 2 people.
4.Book a room for 3 people.
5.Go back to main menu
Enter your choice:1
		----------------------------------------------------------------------
					 Floor number 1
		----------------------------------------------------------------------
				Room number:101	 Number of vacant cots:3
				Room number:102	 Number of vacant cots:1
				Room number:103	 Number of vacant cots:3
				Room number:104	 Number of vacant cots:2
				Room number:105	 Number of vacant cots:3
				Room number:106	 Number of vacant cots:2
				Room number:107	 Number of vacant cots:3
				Room number:108	 Number of vacant cots:2
				Room number:109	 Number of vacant cots:3
				Room number:110	 Number of vacant cots:2
		----------------------------------------------------------------------


1.See the status of rooms.
2.Book a room for 1 person.
3.Book a room for 2 people.
4.Book a room for 3 people.
5.Go back to main menu
Enter your choice:5


						1.Hostel information
						2.Book a room on floor 1.
						3.Book a room on floor 2.
						4.Book a room on floor 3.
						5.See status of rooms.
						6.Cancle booking.
						7.Update student information.
						8.Back to login.
						Enter your choice:5
		----------------------------------------------------------------------
					 Floor number 1
		----------------------------------------------------------------------
				Room number:101	 Number of vacant cots:3
				Room number:102	 Number of vacant cots:1
				Room number:103	 Number of vacant cots:3
				Room number:104	 Number of vacant cots:2
				Room number:105	 Number of vacant cots:3
				Room number:106	 Number of vacant cots:2
				Room number:107	 Number of vacant cots:3
				Room number:108	 Number of vacant cots:2
				Room number:109	 Number of vacant cots:3
				Room number:110	 Number of vacant cots:2
		----------------------------------------------------------------------

		----------------------------------------------------------------------
					 Floor number 2
		----------------------------------------------------------------------
				Room number:201	 Number of vacant cots:3
				Room number:202	 Number of vacant cots:2
				Room number:203	 Number of vacant cots:3
				Room number:204	 Number of vacant cots:2
				Room number:205	 Number of vacant cots:3
				Room number:206	 Number of vacant cots:2
				Room number:207	 Number of vacant cots:3
				Room number:208	 Number of vacant cots:2
				Room number:209	 Number of vacant cots:3
				Room number:210	 Number of vacant cots:2
		----------------------------------------------------------------------

		----------------------------------------------------------------------
					 Floor number 3
		----------------------------------------------------------------------
				Room number:301	 Number of vacant cots:3
				Room number:302	 Number of vacant cots:2
				Room number:303	 Number of vacant cots:3
				Room number:304	 Number of vacant cots:2
				Room number:305	 Number of vacant cots:3
				Room number:306	 Number of vacant cots:2
				Room number:307	 Number of vacant cots:3
				Room number:308	 Number of vacant cots:2
				Room number:309	 Number of vacant cots:3
				Room number:310	 Number of vacant cots:2
		----------------------------------------------------------------------



						1.Hostel information
						2.Book a room on floor 1.
						3.Book a room on floor 2.
						4.Book a room on floor 3.
						5.See status of rooms.
						6.Cancle booking.
						7.Update student information.
						8.Back to login.
						Enter your choice:2

1.See the status of rooms.
2.Book a room for 1 person.
3.Book a room for 2 people.
4.Book a room for 3 people.
5.Go back to main menu
Enter your choice:3

Enter room number : 202
------------------------
Invalid room number
------------------------

1.See the status of rooms.
2.Book a room for 1 person.
3.Book a room for 2 people.
4.Book a room for 3 people.
5.Go back to main menu
Enter your choice:3

Enter room number : 203
------------------------
Invalid room number
------------------------

1.See the status of rooms.
2.Book a room for 1 person.
3.Book a room for 2 people.
4.Book a room for 3 people.
5.Go back to main menu
Enter your choice:22
Invalid choice entered !

1.See the status of rooms.
2.Book a room for 1 person.
3.Book a room for 2 people.
4.Book a room for 3 people.
5.Go back to main menu
Enter your choice:2

Enter room number : 105

 Room is vaccant you can apply for room !

Enter the details of student below

Enter name : harshada
Enter year : 2
Enter contact number : 56421398756
Enter address : Baramati punr e

1.See the status of rooms.
2.Book a room for 1 person.
3.Book a room for 2 people.
4.Book a room for 3 people.
5.Go back to main menu
Enter your choice:5


						1.Hostel information
						2.Book a room on floor 1.
						3.Book a room on floor 2.
						4.Book a room on floor 3.
						5.See status of rooms.
						6.Cancle booking.
						7.Update student information.
						8.Back to login.
						Enter your choice:6

Enter floor number:1

Enter room number:105

Enter the name of student :harshada
------------------------------------------
	Booking cancelled successfully.
------------------------------------------


						1.Hostel information
						2.Book a room on floor 1.
						3.Book a room on floor 2.
						4.Book a room on floor 3.
						5.See status of rooms.
						6.Cancle booking.
						7.Update student information.
						8.Back to login.
						Enter your choice:6

Enter floor number:5
------------------------------------------
	Invalid floor number entered!
------------------------------------------


						1.Hostel information
						2.Book a room on floor 1.
						3.Book a room on floor 2.
						4.Book a room on floor 3.
						5.See status of rooms.
						6.Cancle booking.
						7.Update student information.
						8.Back to login.
						Enter your choice:5
		----------------------------------------------------------------------
					 Floor number 1
		----------------------------------------------------------------------
				Room number:101	 Number of vacant cots:3
				Room number:102	 Number of vacant cots:1
				Room number:103	 Number of vacant cots:3
				Room number:104	 Number of vacant cots:2
				Room number:105	 Number of vacant cots:3
				Room number:106	 Number of vacant cots:2
				Room number:107	 Number of vacant cots:3
				Room number:108	 Number of vacant cots:2
				Room number:109	 Number of vacant cots:3
				Room number:110	 Number of vacant cots:2
		----------------------------------------------------------------------

		----------------------------------------------------------------------
					 Floor number 2
		----------------------------------------------------------------------
				Room number:201	 Number of vacant cots:3
				Room number:202	 Number of vacant cots:2
				Room number:203	 Number of vacant cots:3
				Room number:204	 Number of vacant cots:2
				Room number:205	 Number of vacant cots:3
				Room number:206	 Number of vacant cots:2
				Room number:207	 Number of vacant cots:3
				Room number:208	 Number of vacant cots:2
				Room number:209	 Number of vacant cots:3
				Room number:210	 Number of vacant cots:2
		----------------------------------------------------------------------

		----------------------------------------------------------------------
					 Floor number 3
		----------------------------------------------------------------------
				Room number:301	 Number of vacant cots:3
				Room number:302	 Number of vacant cots:2
				Room number:303	 Number of vacant cots:3
				Room number:304	 Number of vacant cots:2
				Room number:305	 Number of vacant cots:3
				Room number:306	 Number of vacant cots:2
				Room number:307	 Number of vacant cots:3
				Room number:308	 Number of vacant cots:2
				Room number:309	 Number of vacant cots:3
				Room number:310	 Number of vacant cots:2
		----------------------------------------------------------------------



						1.Hostel information
						2.Book a room on floor 1.
						3.Book a room on floor 2.
						4.Book a room on floor 3.
						5.See status of rooms.
						6.Cancle booking.
						7.Update student information.
						8.Back to login.
						Enter your choice:7

Enter room floor number:1

Enter room number: 106

Enter name of student:roshani
------------------------------------------
   Student record not found!!!
------------------------------------------


						1.Hostel information
						2.Book a room on floor 1.
						3.Book a room on floor 2.
						4.Book a room on floor 3.
						5.See status of rooms.
						6.Cancle booking.
						7.Update student information.
						8.Back to login.
						Enter your choice:4

1.See the status of rooms.
2.Book a room for 1 person.
3.Book a room for 2 people.
4.Book a room for 3 people.
5.Go back to main menu
Enter your choice:2

Enter room number : 303

 Room is vaccant you can apply for room !

Enter the details of student below

Enter name : priyanka
Enter year : 2
Enter contact number : 96385274123
Enter address : Pune Maharashtra

1.See the status of rooms.
2.Book a room for 1 person.
3.Book a room for 2 people.
4.Book a room for 3 people.
5.Go back to main menu
Enter your choice:5


						1.Hostel information
						2.Book a room on floor 1.
						3.Book a room on floor 2.
						4.Book a room on floor 3.
						5.See status of rooms.
						6.Cancle booking.
						7.Update student information.
						8.Back to login.
						Enter your choice:7

Enter room floor number:3

Enter room number: 303

Enter name of student:priyanka

What do you want to update:

1.Name
2.Year
3.Phone Number
4.Address
5.Exit
2

Enter updated year:
3

What do you want to update:

1.Name
2.Year
3.Phone Number
4.Address
5.Exit
5
------------------------------------------
	Information updated successfully !
------------------------------------------


						1.Hostel information
						2.Book a room on floor 1.
						3.Book a room on floor 2.
						4.Book a room on floor 3.
						5.See status of rooms.
						6.Cancle booking.
						7.Update student information.
						8.Back to login.
						Enter your choice:
5
		----------------------------------------------------------------------
					 Floor number 1
		----------------------------------------------------------------------
				Room number:101	 Number of vacant cots:3
				Room number:102	 Number of vacant cots:1
				Room number:103	 Number of vacant cots:3
				Room number:104	 Number of vacant cots:2
				Room number:105	 Number of vacant cots:3
				Room number:106	 Number of vacant cots:2
				Room number:107	 Number of vacant cots:3
				Room number:108	 Number of vacant cots:2
				Room number:109	 Number of vacant cots:3
				Room number:110	 Number of vacant cots:2
		----------------------------------------------------------------------

		----------------------------------------------------------------------
					 Floor number 2
		----------------------------------------------------------------------
				Room number:201	 Number of vacant cots:3
				Room number:202	 Number of vacant cots:2
				Room number:203	 Number of vacant cots:3
				Room number:204	 Number of vacant cots:2
				Room number:205	 Number of vacant cots:3
				Room number:206	 Number of vacant cots:2
				Room number:207	 Number of vacant cots:3
				Room number:208	 Number of vacant cots:2
				Room number:209	 Number of vacant cots:3
				Room number:210	 Number of vacant cots:2
		----------------------------------------------------------------------

		----------------------------------------------------------------------
					 Floor number 3
		----------------------------------------------------------------------
				Room number:301	 Number of vacant cots:3
				Room number:302	 Number of vacant cots:2
				Room number:303	 Number of vacant cots:2
				Room number:304	 Number of vacant cots:2
				Room number:305	 Number of vacant cots:3
				Room number:306	 Number of vacant cots:2
				Room number:307	 Number of vacant cots:3
				Room number:308	 Number of vacant cots:2
				Room number:309	 Number of vacant cots:3
				Room number:310	 Number of vacant cots:2
		----------------------------------------------------------------------



						1.Hostel information
						2.Book a room on floor 1.
						3.Book a room on floor 2.
						4.Book a room on floor 3.
						5.See status of rooms.
						6.Cancle booking.
						7.Update student information.
						8.Back to login.
						Enter your choice:8


						1.Login as admin
						2.Login as student
						3.Exit

						Enter your choice:1


						1.See the details of student in room.
						2.Delete a room.
						3.Back to login.
						Enter your choice:1

Enter floor number : 3

Enter a room number:303

					----------------------------------------------------------
							  ROOM NUMBER : 303
					----------------------------------------------------------
						Student :1--->		Name:priyanka
									Year of study:3
									Address:Pune Maharashtra
									Contact number:96385274123
					----------------------------------------------------------

						1.See the details of student in room.
						2.Delete a room.
						3.Back to login.
						Enter your choice:p 3


						1.Login as admin
						2.Login as student
						3.Exit

						Enter your choice:3*/




                        