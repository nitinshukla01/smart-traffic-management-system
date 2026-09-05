#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
    char username[30], password[30];

    printf("\n============================================\n");
    printf("       SMART TRAFFIC MANAGEMENT SYSTEM\n");
    printf("============================================\n");

    printf("Username: ");
    scanf("%29s", username);

    printf("Password: ");
    scanf("%29s", password);

    if (strcmp(username, "nitin") != 0 || strcmp(password, "9219") != 0)
      {
        printf("\nWrong username or password.\n");
        return 0;
    }

    printf("\nLogin successful.\n");

  // TRAFFIC INPUT 
    int north = 0, south = 0, east = 0, west = 0;
    int totalVehicles;

    // SIGNAL CONTROL 
    int max, lane, greenTime;

    // EMERGENCY MODE 
    int emergency, road;

    // REPORT AND FILE STORAGE 
    int choice;
    FILE *file;
    char date[20];

    while (1)
    {
        printf("\n============================================\n");
        printf("       SMART TRAFFIC MANAGEMENT SYSTEM\n");
        printf("============================================\n");
        printf("1. Traffic Input\n");
        printf("2. Signal Control\n");
        printf("3. Emergency Mode\n");
        printf("4. Daily Report\n");
        printf("5. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //DAY 3 : TRAFFIC INPUT
     if (choice == 1)
          {
     printf("\n------------- TRAFFIC INPUT ----------------\n");
     printf("Enter North vehicles: ");
     scanf("%d", &north);
     printf("Enter South vehicles: ");
     scanf("%d", &south);
     printf("Enter East vehicles : ");
     scanf("%d", &east);
     printf("Enter West vehicles : ");
     scanf("%d", &west);

      totalVehicles = north + south + east + west;

            // Get current date 
        time_t now = time(NULL);
         struct tm *t = localtime(&now);

        sprintf(date, "%02d-%02d-%04d",
                    t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);

            // SAVE DATA IN FILE 
            file = fopen("trafficReport.csv", "a");

            if (file == NULL)
               {
                printf("\nFile could not be opened.\n");
                printf("Data was NOT saved.\n");
             }
            else
              {
                fprintf(file, "%s,%d,%d,%d,%d,%d\n",
                        date, north, east, south, west, totalVehicles);

                fclose(file);

                printf("\n--------------------------------------------\n");
                printf("Traffic data saved successfully!\n");
                printf("Date           : %s\n", date);
                printf("Total vehicles : %d\n", totalVehicles);
                printf("--------------------------------------------\n");
               }
          }

        // SIGNAL CONTROL 
        else if (choice == 2)
        {
            if (north == 0 && south == 0 && east == 0 && west == 0){
              
                printf("\nPlease enter traffic data first.\n");
            }
            else
            {
               max = north;
               lane = 1;
               if (south > max)
               {
                   max = south;
                   lane = 2;
               }
               if (east > max)
               {
                   max = east;
                   lane = 3;
               }
               if (west > max)
               {
                   max = west;
                   lane = 4;
               }
               greenTime = max * 2;
               if (greenTime > 60)
                   greenTime = 60;
               printf("\n------------- SIGNAL STATUS ----------------\n");

          if (lane == 1)
             {
                 printf("North : GREEN (%d sec)\n", greenTime);
                 printf("South : RED\n");
                 printf("East  : RED\n");
                 printf("West  : RED\n");
             }
             else if (lane == 2)
             {
                 printf("North : RED\n");
                 printf("South : GREEN (%d sec)\n", greenTime);
                 printf("East  : RED\n");
                 printf("West  : RED\n");
             }
             else if (lane == 3)
             {
                 printf("North : RED\n");
                 printf("South : RED\n");
                 printf("East  : GREEN (%d sec)\n", greenTime);
                 printf("West  : RED\n");
             }
             else
             {
                 printf("North : RED\n");
                 printf("South : RED\n");
                 printf("East  : RED\n");
                 printf("West  : GREEN (%d sec)\n", greenTime);
             }
                printf("--------------------------------------------\n");
            }
        }

        // EMERGENCY MODE 
        else if (choice == 3)
        {
            printf("\n------------- EMERGENCY MODE ---------------\n");

            printf("1. Ambulance\n");
            printf("2. Fire Brigade\n");
            printf("3. Police\n");
            printf("Enter vehicle: ");
            scanf("%d", &emergency);

            printf("\n1. North\n");
            printf("2. South\n");
            printf("3. East\n");
            printf("4. West\n");
            printf("Enter road: ");
            scanf("%d", &road);

            printf("\nEmergency priority activated.\n");

            if (road == 1)
                printf("North: GREEN | South: RED | East: RED | West: RED\n");
            else if (road == 2)
                printf("North: RED | South: GREEN | East: RED | West: RED\n");
            else if (road == 3)
                printf("North: RED | South: RED | East: GREEN | West: RED\n");
            else if (road == 4)
                printf("North: RED | South: RED | East: RED | West: GREEN\n");
            else
                printf("Invalid road choice.\n");

            printf("Emergency mode completed.\n");
        }

        // DAILY REPORT 
        else if (choice == 4){
    
         char line[200];
         int n, e, s, w, total;
         int count = 0;

          printf("\n===============================================================\n");
          printf("                    DAILY TRAFFIC REPORT\n");
          printf("===============================================================\n");
          printf("No.   Date         North     East      South     West      Total\n");
          printf("---------------------------------------------------------------\n");

            file = fopen("traffic_records.csv", "r");

            if (file == NULL)
            {
                printf("No saved traffic data found.\n");
            }
            else
            {
                while (fgets(line, sizeof(line), file) != NULL){
               
                  if (sscanf(line, "%19[^,],%d,%d,%d,%d,%d",
                             date, &n, &e, &s, &w, &total) == 6)
                  {
                      count++;
                      printf("%-5d %-12s %-9d %-9d %-9d %-9d %-9d\n",
                             count, date, n, e, s, w, total);
                  }
                }

                fclose(file);

                printf("---------------------------------------------------------------\n");
                printf("Total Records: %d\n", count);
                printf("===============================================================\n");
            }
        }

        // EXIT 
        else if (choice == 5)
        {
         printf("\n============================================\n");
         printf("        SMART TRAFFIC SYSTEM CLOSED\n");
         printf("============================================\n");
            break;
        }

        else
        {
            printf("\nInvalid menu choice.\n");
        }
    }

    return 0;
}
