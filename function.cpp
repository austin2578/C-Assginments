#include<string>
string parameter;
MenuPick getMenuPick(string &parameter) {              
   int input; //user input
   bool isValid = 0;  //input validity
   MenuPick userChoice; //input as MenuPick enum

        do {                                                                          //keyboard input validation loop
        cout << "Please select from one of the following options:\n1. Read names from file\n2. Display names\n3. Sort names ascending\n4. Sort names descending\n5. Count name\n6. Exit program\nSelection: ";        
        cin >> input;
        cin.clear();
        cin.ignore(1000,'\n');
          switch(input-1) {                              
             case 0: 
                isValid = 1;
                userChoice = READ_DATA;
                break;
             case 1: 
                isValid = 1;
                userChoice = DISPLAY;
                break;
             case 2: 
                isValid = 1; 
                userChoice = SORT_ASC;
                break;
             case 3: 
                isValid = 1;
                userChoice = SORT_DEC;
                break;
             case 4: 
                isValid = 1;
                userChoice = COUNT;
                cout << "\nEnter a name to count (case sensitive): ";
                getline(cin,parameter);  
                cin.clear() ;
                break;
             case 5: 
                isValid = 1;
                userChoice = EXIT;
                break;
          }                                   //switch case assigns userChoice a value
          if(isValid == 0) {
           cout << "\n\nPlease enter valid integer between 1 and 6!\n\n";
        }
     } while(isValid == 0);
   
     return userChoice;
} //Function to show menu and get user input

int count(const string STR_AR[], const string KEY, const int SIZE) {
   int i;  //index for loop
   int count = 0;  //count of key

   for(i = 0; i < SIZE; i++) {
      if(STR_AR[i] == KEY) {
         count++;
      }
   }           //counting loop
   return count;
}   //Counts how many times a certain name appears.

void bubbleSort(string STR_AR[], const int SIZE, const bool ASCENDING) {
   int i; //index for loop
   int j; //index for loop
   ofstream nameData;      //output file
   string temp;  //temporary string for bubble sort
   
   if(ASCENDING == 1) {
      for(i = 0; i < SIZE; i++) {
         for(j = i+1; j < SIZE; j++) {
            if(STR_AR[i]>STR_AR[j]) {
               temp = STR_AR[i];
               STR_AR[i] = STR_AR[j];
               STR_AR[j] = temp;
            }
         }
      }                                          //ascending order loop
   } else {
      for(i = 0; i < SIZE; i++) {
         for(j = i+1; j < SIZE; j++) {
            if(STR_AR[i]<STR_AR[j]) {
               temp = STR_AR[i];
               STR_AR[i] = STR_AR[j];
               STR_AR[j] = temp;
            }
         }
      }
   }                                              //descending order loop   

}
