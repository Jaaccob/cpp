#include <ncurses.h>
#include <iostream>
#include <iomanip>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <ctime>
#include <fstream>
#include <string>
#include <filesystem>

int previousMonth [6][7];
int currentMonth [6][7];
int nextMonth [6][7];

int currentD;
int currentM;
int currentY;
int numberOfWeek = 6;

namespace fs = std::filesystem;
using namespace std;
void createFile(int day, int month, int year, int row);
void deleteFile(int day, int month, int year);
string write(int day, int month, int year, int row);


int dayNumber(int day, int month, int year){
   static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
   year -= month < 3;
   return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}

int numberOfDays (int monthNumber, int year){
   switch(monthNumber % 12){
      case 0 :
      case 2 :
      case 4 :
      case 6 :
      case 7 :
      case 9 :
      case 11: return(31);
      break;
      case 1 :
         if (year % 400 == 0 || (year % 4 == 0 && year %100 != 0))
            return (29);
         else
            return (28);
      break;
      case 3 :
      case 5 :
      case 8 :
      case 10 : return(30);
      break;
   }
   return(30);
}

void numberOfWeeks (int table[6][7]){
    int tempolary = 0;
    int week = 0;
    int last = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            if(tempolary <= table[i][j]){
                tempolary = table[i][j];
            }
            else{
                i = 6;
                break;
            }
        }
        if(i == 6){
            break;
        }
        week++;
    }
    numberOfWeek = week;
}

int actualyWeek(int day, int current){
    return (int) (6+day-(current-1))/7;
}

void showBar(int col, int row){
    //Funkcja ma za zadanie wyświetlać górną belkę kalendarza
    mvprintw(2, col-21, "Kalendarz TODO");
    char const *days[] = {"N","P","W","S","C","P","S"};
    int p = 0;
    for (int i = 0; i < 7; i++)
    {
        mvprintw(3, col - 21 + p, days[i]);
        p++;
        if (i == 6)
        {
            break;
        }
        mvprintw(3, col - 21 + p, "  ");
        p+= 2;
    }
}

void showNameMonth(int monthNumber, int col){
    int x = col - 21;
    int y = 0;
    switch ((monthNumber-1)%12)
    {
    case 0:
        mvprintw(y+1,x,"Styczen");
        break;
    case 1:
        mvprintw(y+1,x,"Luty");
        break;
    case 2:
        mvprintw(y+1,x,"Marzec");
        break;
    case 3:
        mvprintw(y+1,x,"Kwiecien");
        break;
    case 4:
        mvprintw(y+1,x,"Maj");
        break;
    case 5:
        mvprintw(y+1,x,"Czerwiec");
        break;
    case 6:
        mvprintw(y+1,x,"Lipiec");
        break;
    case 7:
        mvprintw(y+1,x,"Sierpień");
        break;
    case 8:
        mvprintw(y+1,x,"Wrzesień");
        break;
    case 9:
        mvprintw(y+1,x,"Październik");
        break;
    case 10:
        mvprintw(y+1,x,"Listopad");
        break;
    case 11:
        mvprintw(y+1,x,"Grudzień");
        break;
    default:
        break;
    }
}

void fillTable(int table[6][7], int day, int month, int year){
    int current = dayNumber(1, month, year);
    int days = numberOfDays(month - 1, year);
    
    // cout << "current: " << current << endl;
    // cout << "days: " << days << endl;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            table[i][j] = 0;
        }
    }

    int k;
    for(k = 0; k < current; k++){
        table[0][k] = 0;
    }
    
    int r = 0;
    for(int j = 1; j <= days; j++){
        table[r][k] = j;
        if(++k > 6){
            k = 0;
            r++;
        }
    }
}

void showCalendar(int col, int current){
    int p = 0;
    int y = 4;
    int k = current;
    for(int i =0; i < 6; i++){
        for(int j=0; j < 7; j++){
            if(currentMonth[i][j] != 0){
                mvprintw(y, col + p + k - 21, "%d", currentMonth[i][j]);
            }
            p += 2;
            ++k;
        }
        y++;
        p = 0;
        k = 0;
    }
}

void copyTable(int table[6][7]){
    for(int i=0; i < 6; i++){
        for(int j=0; j < 7; j++){
            currentMonth[i][j] = table[i][j];
        }
    }
}

void showActivity(char sign, int col, int row, int* x, int *y){
    int min_x = -1;
    int max_x = 7;
    int min_y = -1;
    int max_y = numberOfWeek;
    if (sign == 'a'){   
        *x = *x - 1 ;
    }
    else if(sign == 's'){
        *y = *y + 1;
    }
    else if(sign == 'd'){
        *x = *x + 1;
    }
    else if(sign == 'w'){
        *y = *y - 1;
    }
    else if(sign == 10){
        if(currentMonth[*y][*x] != 0){
            createFile(currentMonth[*y][*x],currentM, currentY, row);
        }
        else
            mvprintw(2,0,"Niepoprawny dzień");
        
    }
    else if(sign == 127){
        if(currentMonth[*y][*x] != 0){
            deleteFile(currentMonth[*y][*x],currentM, currentY);
        }
        else
            mvprintw(2,0,"Niepoprawny dzień");
    }
     if( *x >= max_x){
        *x = 0;
        *y = *y + 1;
    }
    else if (*x <= min_x){
        *x = 6;
        *y = *y - 1;
    }
    if (*y > max_y){
        copyTable(nextMonth);
        numberOfWeeks(currentMonth);
        currentM ++;
        fillTable(previousMonth, currentD, currentM - 1, currentY);
        fillTable(nextMonth, currentD, currentM + 1, currentY);
        *y = 0;
    }
    else if(*y <= min_y){
        copyTable(previousMonth);
        numberOfWeeks(currentMonth);
        currentM --;
        fillTable(previousMonth, currentD, currentM - 1, currentY);
        fillTable(nextMonth, currentD, currentM + 1, currentY);
        *y = numberOfWeek;
    }
    mvprintw(*y+4, (*x * 3) + col -1 - 21, "[");
    mvprintw(*y+4, (*x * 3) + col +2 - 21, "]");
}

void actualyDay(int *x, int *y){
            mvprintw(5, 0, "Dzien");
            mvprintw(5, 10, "%d", currentMonth[*x][*y]);
            mvprintw(6, 0, "Miesiac");
            mvprintw(6, 10, "%d", currentM);
            mvprintw(7, 0, "Rok");
            mvprintw(7, 10, "%d", currentY);
}

void showTable(int col, int current){
    int p = 0;
    int y = 4;
    int k = current;
    mvprintw(7,col/2 + 30, "Curr");
    for(int i =0; i < 6; i++){
        for(int j=0; j < 7; j++){
            mvprintw(y+4, col/2 + 30 + p + k, "%d", currentMonth[i][j]);
            p += 2;
            ++k;
        }
        y++;
        p = 0;
        k = 0;
    }

    p = 0;
    y = 1;
    k = current;
    mvprintw(0,col/2 + 30, "Prev");
    for(int i =0; i < 6; i++){
        for(int j=0; j < 7; j++){
            mvprintw(y, col/2 + 30 + p + k, "%d", previousMonth[i][j]);
            p += 2;
            ++k;
        }
        y++;
        p = 0;
        k = 0;
    }

    p = 0;
    y = 4;
    k = current;
    mvprintw(14,col/2 + 30, "Next");
    for(int i =0; i < 6; i++){
        for(int j=0; j < 7; j++){
            mvprintw(y+11, col/2 + 30 + p + k, "%d", nextMonth[i][j]);
            p += 2;
            ++k;
        }
        y++;
        p = 0;
        k = 0;
    }
}

void openFile(int day, int month, int year, int col){
    string nameFile;
    if(day < 10 and month < 10)
        nameFile = "todo" + to_string(year) + "0" + to_string(month) + "0" + to_string(day);
    else if (day < 10)
        nameFile = "todo" + to_string(year) + to_string(month) + "0" + to_string(day);
    else if (month < 10)
        nameFile = "todo" + to_string(year) + "0" + to_string(month) + to_string(day);
        
    ifstream file(nameFile + ".txt", ios::in);
    string line;
    if(file.is_open()){
        int i = 0;
        int x = -1;
        while( getline(file, line) ){
            if (line.compare("\n")){
                x++;
                i =0;
            }
            if (line.length() > col - 30){
                string subLine;
                for (int j = 0; j < line.length(); j += (col - 30)){
                    subLine = line.substr(j,j+col-30);
                    mvprintw(x, i, "%s", subLine.c_str());
                    x++;
                    i = 0;
                }
            }else{
                mvprintw(x,i,"%s",line.c_str());
                i++;
            }
        }
    }
    else{
        mvprintw(0,0,"Nie utworzono jeszcze zadnych taskow. Chcesz cos nowego zapisac ?");
    }
    file.close();
}

void createFile(int day, int month, int year, int row){
    string nameFile;
    if(day < 10 and month < 10)
        nameFile = "todo" + to_string(year) + "0" + to_string(month) + "0" + to_string(day);
    else if (day < 10)
    {
        nameFile = "todo" + to_string(year) + to_string(month) + "0" + to_string(day);
    }else if (month < 10)
    {
        nameFile = "todo" + to_string(year) + "0" + to_string(month) + to_string(day);
    }
    string line = write(day, month, year, row); 
    ofstream fileO(nameFile + ".txt", ios::out);
    if(fileO.is_open()){
        fileO << line;
        fileO.close();
    }
}

string write(int day, int month, int year, int row){
    string nameFile;
    if(day < 10 and month < 10)
        nameFile = "todo" + to_string(year) + "0" + to_string(month) + "0" + to_string(day);
    else if (day < 10)
    {
        nameFile = "todo" + to_string(year) + to_string(month) + "0" + to_string(day);
    }else if (month < 10)
    {
        nameFile = "todo" + to_string(year) + "0" + to_string(month) + to_string(day);
    }
    ifstream file(nameFile + ".txt", ios::in);
    string line;
    string fileLine;
    int x = -1;
    if(file.is_open()){
        int i = 0;
        while( getline(file, line) ){
            if (line.compare("\n")){
                x++;
                i =0;
                fileLine.append("\n");
            }
            mvprintw(x,i,"%s",line.c_str());
            fileLine += line;
            i++;
        }
    }
    file.close();

    line = "";
    line = line.append(fileLine);
    if (line.length() > 0)
    {
        line.append("\n");
    }
    char znak = '-';

    int y = 0;
    x++;
    move(x,y);
    do
    {   
        if (znak == 10)
        {
            mvprintw(17,0,"enter");
            line += znak;
            x++;
            y = 0;
            move(x,y);
        }else if (znak == 127){
            mvprintw(17,0,"backspace");
            y--;
            line = line.substr(0,line.length()-1);
            mvprintw(x,y," ");
            move(x,y);
        }else{
            mvprintw(x,y,"%c",znak);
            y++;
            line += znak;
        }

        mvprintw(row - 1, 0, "Aby wyjsc nacisnij ESC");
        znak = getch();
    } while (znak != 27);
    return line;
}

void deleteOldFiles(int day, int month, int year){
    std::string path = "/home/jacob/Academic/VI semestr/cpp/Kalendarz To Do/Kalendarz";
    string number;
    if(day < 10 and month < 10)
        number = to_string(year) + "0" + to_string(month) + "0" + to_string(day);
    else if (day < 10)
    {
        number = to_string(year) + to_string(month) + "0" + to_string(day);
    }else if (month < 10)
    {
        number = to_string(year) + "0" + to_string(month) + to_string(day);
    }
    for (const auto & entry : fs::directory_iterator(path)){
        string file = entry.path();
        if(file.substr(file.length()-4, file.length()-1).compare(".txt") == 0){
            file = file.substr(62, file.length());
            if( stoi(file.substr(4,file.length()-8)) < stoi(number)){
                mvprintw(15,0,"Usuwam plik: %s",file.c_str());
                remove(file.c_str());
            }
        }

    }
}

void deleteFile(int day, int month, int year){
    std::string path = "/home/jacob/Academic/VI semestr/cpp/Kalendarz To Do/Kalendarz";
    string number;
    if(day < 10 and month < 10)
        number = to_string(year) + "0" + to_string(month) + "0" + to_string(day);
    else if (day < 10)
    {
        number = to_string(year) + to_string(month) + "0" + to_string(day);
    }else if (month < 10)
    {
        number = to_string(year) + "0" + to_string(month) + to_string(day);
    }
    string file = "todo" + number + ".txt";
    mvprintw(15,0,"Usuwam plik: %s",file.c_str());
    remove(file.c_str());
    }
    
void createBox(int x, int y, int w, int h){
    WINDOW *win = newwin(h,w,x,y);
    refresh();
    box(win, 0, 0);
    wrefresh(win);
}

void showContext(int col, int row){
    mvprintw(row-3, 1, "w/s -> góra/dol");
    mvprintw(row-2, 1, "a/d -> lewi/prawo");

    mvprintw(row-3, 21, "Enter -> wprowadz nowy task");
    mvprintw(row-2, 20, "Backspace -> usun task");

    mvprintw(row-3, 51, "ESC -> KONIEC");
}

int main(){
    time_t now = time(0);
    tm *ltm = localtime(&now);

    currentD = 0  + ltm->tm_mday;
    currentM = 1 + ltm->tm_mon;
    currentY = 1900 + ltm->tm_year;
    fillTable(previousMonth, currentD, currentM - 1, currentY);
    fillTable(nextMonth, currentD, currentM + 1, currentY);
    fillTable(currentMonth, currentD, currentM, currentY);

    initscr();
    printw( "Przycisnij przycisk...\n" );
    noecho();


    //utworzenie okna dla kalendarza
    int row, col;
    getmaxyx(stdscr, row, col);

    int current = dayNumber(0,1,1900);
    int x = ltm->tm_wday;
    int y = 0;
    for(int j= 0; j<7; j++){
        if(currentMonth[0][j] != 0){
            y = actualyWeek(currentD,j);
            break;
        }
    }
    
    numberOfWeeks(currentMonth);
    deleteOldFiles(currentMonth[y][x], currentM, currentY);
    char znak;
    do
    {
        clear();
        // showTable(col,current);
        showActivity(znak, col, row, &x, &y);
        if (currentMonth[y][x] != 0)
            openFile(currentMonth[y][x], currentM, currentY,col);
        // actualyDay(&y,&x);
        createBox(0,col-23,23,11);
        showCalendar(col,current);
        showBar(col, row);
        showNameMonth(currentM, col);
        createBox(row - 4, 0, col, 4);
        showContext(col,row);
        znak = getch();
    } while (znak != 27);
    clear();
    endwin();
}