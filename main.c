#include "getDetails.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

int total = 0; // total no of accounts

struct BankAccount {
  char bankName[MAX];
  char ifsc[13];
  char accNo[7];
  char name[MAX];
  char age[MAX];
  char gender[MAX];
  char dob[MAX];
  char address[2 * MAX];
  char city[MAX];
  char accType[MAX];
  float Balance;
  char pan[MAX];
  char aadhaar[MAX];
} typedef BankAcc;

BankAcc accept() {
  BankAcc acc;
  bool status;
  int choice;
  strcpy(acc.name, getName());
  // printf("\n%s\n", acc.name);
  strcpy(acc.age, getAge());
  strcpy(acc.gender, getGender());
  strcpy(acc.dob, getDOB());

  printf("\nEnter Address\n");
  fgets(acc.address, 2 * MAX, stdin);
  acc.address[strlen(acc.address) - 1] = '\0';

  strcpy(acc.city, getCity());
  strcpy(acc.accType, getAccType());
  strcpy(acc.pan, getPan());
  strcpy(acc.aadhaar, getAadhaar());
  strcpy(acc.bankName, "State Bank of India");
  strcpy(acc.ifsc, "SBIN00098");
  strcpy(acc.accNo, getAccNo(acc.name));
  // printf("\n%s\n", acc.name);

  acc.Balance = 0;
  printf("\nAcc No = %s\n", acc.accNo);
  return acc;
}

void displayDetails(BankAcc acc) {
  printf("\n--------------- Account Details ---------------\n");
  printf("\nName = %s\n", acc.name);
  printf("Account No = %s\n", acc.accNo);
  printf("Balance = %f\n", acc.Balance);
  printf("Age = %s\n", acc.age);
  printf("Gender = %s\n", acc.gender);
  printf("DOB = %s\n", acc.dob);
  printf("Address = %s\n", acc.address);
  printf("City = %s\n", acc.city);
  printf("Account Type = %s\n", acc.accType);
  printf("PAN = %s\n", acc.pan);
  printf("Aadhaar = %s\n", acc.aadhaar);
  printf("Bank Name = %s\n", acc.bankName);
  printf("IFSC = %s\n", acc.ifsc);
}

int searchAccNo(BankAcc acc[], char *accNo) {
  for (int i = 0; i < total; i++) {
    if (strcmp(acc[i].accNo, accNo) == 0) {
      return i + 1;
    }
  }
  return 0;
}

int searchAccName(BankAcc acc[], char *name) {
  for (int i = 0; i < total; i++) {
    if (strcmp(acc[i].name, name) == 0) {
      return i + 1;
    }
  }
  return 0;
}
void balanceEnquiry(BankAcc);

void searchAccType(BankAcc acc[], char *accType) {
  printf("\nAccounts with %s account type: \n", accType);
  int flag = 1;
  for (int i = 0; i < total; i++) {
    if (strcmp(acc[i].accType, accType) == 0) {
      balanceEnquiry(acc[i]);
      flag = 0;
    }
  }
  if (flag)
    printf("\nNo accounts with %s account type\n", accType);
}

void balanceEnquiry(BankAcc acc) {
  printf("\nName = %s\n", acc.name);
  printf("Account No = %s\n", acc.accNo);
  printf("Account Type: %s\n", acc.accType);
  printf("Balance = %f\n", acc.Balance);
}

int main(void) {
  BankAcc acc[MAX];
  // printf("%ld", sizeof(acc));
  int choice;
  do {
    printf("\n****************** Banking System ******************\n");
    printf("\nPlease select the option \n1. Create Account \n2. Update Account "
           "Details\n3. Deposit \n4. Withdraw \n5. Funds "
           "Transfer \n6. Search details of account holder \n7. Balance "
           "Enquiry \n8. All account Details \n9. Exit \n");
    int status = scanf("%d", &choice);
    if (!status) {
      choice = 9;
    }
    switch (choice) {
    case 1:
      acc[total] = accept();
      displayDetails(acc[total]);
      total++;
      break;

    case 2: {
      char ch;
      char accNo[MAX];
      getchar();
      printf("\nEnter the account number to update details\n");
      fgets(accNo, MAX, stdin);
      accNo[strlen(accNo) - 1] = '\0';
      // printf("\n%s\n", accNo);
      int i = searchAccNo(acc, accNo);
      do {
        if (i == 0) {
          printf("\nAccount not found\n");
          break;
        }
        printf("\n*************** Update account details ***************\n  a. "
               "Update name of account holder "
               "\n  b. Update address of account holder \n  c. Update DOB of "
               "account holder \n  d. Exit\nOption: ");
        scanf("%c", &ch);
        switch (ch) {
        case 'a':
          strcpy(acc[i - 1].name, getName());
          break;
        case 'b':
          printf("\nEnter Address\n");
          fgets(acc[i - 1].address, 2 * MAX, stdin);
          acc[i - 1].address[strlen(acc[i - 1].address) - 1] = '\0';
          break;
        case 'c':
          strcpy(acc[i - 1].dob, getDOB());
          break;
        case 'd':
          break;
        default:
          printf("\nInvalid choice\n");
        }
      } while (ch != 'd');
    } break;
    case 3: {
      char accNo[MAX];
      getchar();
      printf("\nDeposit Money\n\nEnter the account number : ");
      fgets(accNo, MAX, stdin);
      accNo[strlen(accNo) - 1] = '\0';
      // printf("\n%s\n", accNo);
      int i = searchAccNo(acc, accNo);
      if (!i) {
        printf("\nAccount not found\n");
        continue;
      }
      char amount[MAX];
      bool status;
      do {
        printf("\nEnter amount you want to deposit\n");
        fgets(amount, MAX, stdin);
        amount[strlen(amount) - 1] = '\0';
        status = validAmount(amount);
        if (status && amount > 0) {
          acc[i - 1].Balance += atof(amount);
          printf("\nAmount deposited successfully\n");
        } else {
          printf("\nInvalid amount\n");
        }
      } while (!status);
    } break;
    case 4: {
      char accNo[MAX];
      getchar();
      printf("\nWithdraw Money\n\nEnter the account number : ");
      fgets(accNo, MAX, stdin);
      accNo[strlen(accNo) - 1] = '\0';
      // printf("\n%s\n", accNo);
      int i = searchAccNo(acc, accNo);
      if (!i) {
        printf("\nAccount not found\n");
        continue;
      }
      char amount[MAX];
      bool status;
      do {
        printf("\nEnter amount you want to withdraw\n");
        fgets(amount, MAX, stdin);
        amount[strlen(amount) - 1] = '\0';
        status = validAmount(amount);
        if (status && atof(amount) + acc[i - 1].Balance > 0) {
          acc[i - 1].Balance -= atof(amount);
          printf("\nAmount debited successfully\n");
        } else {
          printf("\nInsufficient amount\n");
        }
      } while (!status);
    } break;
    case 5: {
      printf("\nEnter your Account No: ");
      char sendAcc[MAX], recAcc[MAX];
      getchar();
      fgets(sendAcc, MAX, stdin);
      sendAcc[strlen(sendAcc) - 1] = '\0';
      int i = searchAccNo(acc, sendAcc);
      if (!i) {
        printf("\nSender's Account No not found\n");
        continue;
      }
      printf("\nEnter Receiver's Account No: ");
      fgets(recAcc, MAX, stdin);
      recAcc[strlen(recAcc) - 1] = '\0';
      // printf("\n%s\n", accNo);
      int j = searchAccNo(acc, recAcc);
      if (!j) {
        printf("\nReceiver's Account No not found\n");
        continue;
      }
      char amount[MAX];
      printf("\nEnter amount you want to transfer\n");
      fgets(amount, MAX, stdin);
      amount[strlen(amount) - 1] = '\0';
      status = validAmount(amount);
      if (status && atof(amount) + acc[i - 1].Balance > 0) {
        acc[j - 1].Balance += atof(amount);
        acc[i - 1].Balance -= atof(amount);
        printf("\nAmount transferred successfully\n");
      } else {
        printf("\nInsufficient amount\n");
      }
    } break;
    case 6: {
      printf("\n***************** Search Account Details ***************** \n  "
             "a. Search by account "
             "number \n  b. Search by name \n  c. Search by Type of "
             "Account\nOption: ");
      char ch;
      getchar();
      scanf("%c", &ch);
      switch (ch) {
      case 'a': {
        char accNo[MAX];
        getchar();
        printf("Enter the account number to search details\n");
        fgets(accNo, MAX, stdin);
        accNo[strlen(accNo) - 1] = '\0';
        // printf("\n%s\n", accNo);
        int i = searchAccNo(acc, accNo);
        if (i) {
          displayDetails(acc[i - 1]);
        } else {
          printf("Account not found\n");
        }
      } break;
      case 'b': {
        char name[MAX];
        getchar();
        printf("Enter the account holder's name to search details\n");
        fgets(name, MAX, stdin);
        name[strlen(name) - 1] = '\0';
        int i = searchAccName(acc, name);
        if (i) {
          displayDetails(acc[i - 1]);
        } else {
          printf("Account not found\n");
        }
      } break;
      case 'c': {
        int choice;
        printf("Enter the account type to search details\n1. Savings Account "
               "\n2. Current Account\nOption:");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
          searchAccType(acc, "Savings");
          break;
        case 2:
          searchAccType(acc, "Current");
          break;
        default:
          printf("Invalid choice\n");
        }
      } break;
      case 'd':
        break;
      default:
        printf("\nInvalid choice\n");
      }
    } break;
    case 7: {
      char accNo[MAX];
      getchar();
      printf(
          "\nBalance Enquiry\n\nEnter the account number to check balance\n");
      fgets(accNo, MAX, stdin);
      accNo[strlen(accNo) - 1] = '\0';
      // printf("\n%s\n", accNo);
      int i = searchAccNo(acc, accNo);
      if (i) {
        balanceEnquiry(acc[i - 1]);
      } else {
        printf("\nAccount not found\n");
      }
    } break;

    case 8: {
      printf("\nAll account details\n");
      for (int i = 0; i < total; i++) {
        displayDetails(acc[i]);
      }
    } break;
    case 9:
      printf("\nThank you for using our services\n");
      break;
    default:
      printf("Invalid Choice\n");
    }
  } while (choice != 9);
  return 0;
}