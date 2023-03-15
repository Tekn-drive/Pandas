#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

FILE *file=fopen("listings.csv","r");

//I still don't know which dynamic data structure to use, I was considering dynamically allocated 2D arrays but I just don't know in what way I can implement them
//I am still brainstorming for the DS

/*Core functionalities of Pandas
1. Count the size of the data (rows) (Completed?)
2. Identify columns (Completed)
2. Display the columns with the data, ignore empty rows (Completed)
3. Head function (Completed)
4. Show data types of each column (In progress)
More to be implemented in C++
*/

//Counts how many rows aside from the title of the columns
int countSize(){
    int size=0;
    while(!feof(file)){
        char line[1000];
        fgets(line,1000,file);
        if(strcmp(line,"")==0){
            break;
        }
        size++;
    }
    return size-1;
}

void columns(){
    //Get the first line of csv, cause it has all of the column names
    char line[1000];
    fgets(line,1000,file);
    
    //replace comas with \n
    for(int i=0;i<strlen(line);i++){
        if(line[i]==','){
            line[i]='\n';
        }
    }

    printf("%s",line);
}

//Prints all of the first n rows (except for the column titles ofcourse)
void head(int number){
    char line[1000];
    fgets(line,1000,file);

    int rows=0;

    while(rows<number){
        char line[1000];
        fgets(line,1000,file);

        for(int i=0;i<strlen(line);i++){
            if(line[i]==','){
                line[i]=' ';
            }
        }
        printf("%s",line);
        rows++;
    }

}

void printAll(){
    char line[1000];
    fgets(line,1000,file);
    
    for(int i=0;i<strlen(line);i++){
        if(line[i]==','){
            line[i]=' ';
        }
    }
    printf("%s\n",line);

    while(!feof(file)){
        char line[1000];
        fgets(line,1000,file);
        if(strcmp(line,"")==0){
            break;
        }else{
            for(int i=0;i<strlen(line);i++){
                if(line[i]==','){
                    line[i]=' ';
                }
            }
            printf("%s",line);
        }
    }
}

int main(){
    printf("Welcome to Pandas emulation in CPP!! (still under development)\n");
    printf("Here are the available options for now:\n");
    printf("1. View columns\n");
    printf("2. View data count\n");
    printf("3. View the first view data of the file\n");
    printf("4. Display the entire data\n");
    printf("Option: ");
    int choice;
    scanf("%d",&choice);

    if(choice==1){
        columns();
    }else if(choice==2){
        printf("Data entries: %d entries\n",countSize());
    }else if(choice==3){
        int n=0;
        printf("PLease input the n for the data to be viewed: ");
        scanf("%d",&n);
        head(n);
    }else if(choice==4){
        printAll();
    }else{
        printf("Function is still under development\n");
    }

}
