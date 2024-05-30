#include <stdio.h>
#include <string.h>
#define MAX_PATIENTS 100
struct Patient {
    int id;
    char name[50];
    int age;
    char gender;
    char disease[100];
};
int main() {
    struct Patient patient[MAX_PATIENTS];
    int numPatient = 0;                
    int choice;
    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. View Patient\n");
        printf("3. List All Patients\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                if (numPatient < MAX_PATIENTS) {
                    printf("Enter patient ID: ");
                    scanf("%d", &patient[numPatient].id);
                    printf("Enter patient name: ");
                    scanf("%s", patient[numPatient].name);
                    printf("Enter patient age: ");
                    scanf("%d", &patient[numPatient].age);
                    printf("Enter patient gender (M/F): ");
                    scanf(" %c", &patient[numPatient].gender);
                    printf("Enter patient disease: ");
                    scanf("%s", patient[numPatient].disease);
                    numPatient++;
                    printf("Patient added successfully!\n");
                } else {
                    printf("Maximum number of patients reached!\n");
                }
                break;
            }
            case 2: {
                int id, found = 0;
                printf("Enter patient ID to view: ");
                scanf("%d", &id);
                for (int i = 0; i < numPatient; i++) {
                    if (patient[i].id == id) {
                        printf("\nPatient ID: %d\n", patient[i].id);
                        printf("Name: %s\n", patient[i].name);
                        printf("Age: %d\n", patient[i].age);
                        printf("Gender: %c\n", patient[i].gender);
                        printf("Disease: %s\n", patient[i].disease);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Patient with ID %d not found!\n", id);
                }
                break;
            }
            case 3: {
                // List all patients
                if (numPatient == 0) {
                    printf("No patients in the system.\n");
                } else {
                    printf("\nList of Patients:\n");
                    for (int i = 0; i < numPatient; i++) {
                        printf("ID: %d, Name: %s, Age: %d, Gender: %c, Disease: %s\n",
                               patient[i].id, patient[i].name, patient[i].age, patient[i].gender, patient[i].disease);
                    }
                }
                break;
            }
            case 4: {
                // Exit the program
                printf("Exiting...\n");
                return 0;
            }
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

