#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char type[10];  // "Income" or "Expense"
    float amount;
    char category[20];
} Transaction;

Transaction transactions[MAX_TRANSACTIONS];
int count = 0;
float balance = 0;

void addTransaction() {
    if (count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached!\n");
        return;
    }
    
    printf("Enter transaction type (Income/Expense): ");
    fflush(stdout);
    scanf("%s", transactions[count].type);

    
    printf("Enter amount: ");
    scanf("%f", &transactions[count].amount);
    
    printf("Enter category: ");
    scanf("%s", transactions[count].category);
    
    if (strcmp(transactions[count].type, "Income") == 0) {
        balance += transactions[count].amount;
    } else if (strcmp(transactions[count].type, "Expense") == 0) {
        balance -= transactions[count].amount;
    } else {
        printf("Invalid transaction type!\n");
        return;
    }
    
    count++;
    printf("Transaction added successfully!\n");
}

void viewTransactions() {
    printf("\nTransaction History:\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s | Amount: %.2f | Category: %s\n", i + 1, transactions[i].type, transactions[i].amount, transactions[i].category);
    }
    printf("-----------------------------------\n");
    printf("Current Balance: %.2f\n", balance);
}

void saveToFile() {
    FILE *file = fopen("transactions.txt", "w");
    if (!file) {
        printf("Error saving data!\n");
        return;
    }
    
    fprintf(file, "%d %.2f\n", count, balance);
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %.2f %s\n", transactions[i].type, transactions[i].amount, transactions[i].category);
    }
    fclose(file);
    printf("Data saved successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("transactions.txt", "r");
    if (!file) {
        printf("No previous data found.\n");
        return;
    }
    
    fscanf(file, "%d %f", &count, &balance);
    for (int i = 0; i < count; i++) {
        fscanf(file, "%s %f %s", transactions[i].type, &transactions[i].amount, transactions[i].category);
    }
    fclose(file);
    printf("Data loaded successfully!\n");
}

int main() {
    int choice;
    loadFromFile();
    
    while (1) {
        printf("\n1. Add Transaction\n2. View Transactions\n3. Save & Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addTransaction();
                break;
            case 2:
                viewTransactions();
                break;
            case 3:
                saveToFile();
                exit(0);
            default:
                printf("Invalid choice!\n");
    return 0;
}