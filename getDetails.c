#include "validate.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

char *getName() {
  char *name = (char *)malloc(MAX * sizeof(char));
  bool status;
  getchar();
  do {
    printf("\nEnter Name (Firstname Middlename Lastname)\n");
    fgets(name, MAX, stdin);
    name[strlen(name) - 1] = '\0';
    status = validName(name);
    if (!status) {
      printf("Invalid Name\n");
    }
  } while (!status);
  // printf("\n%s\n", name);
  return name;
}

char *getAge() {
  char *age = (char *)malloc(MAX * sizeof(char));
  bool status;
  do {
    printf("\nEnter Age\n");
    fgets(age, MAX, stdin);
    age[strlen(age) - 1] = '\0';
    status = validAge(age);
    if (!status) {
      printf("Invalid Age\n");
    }
  } while (!status);
  return age;
}

char *getGender() {
  char *gender = (char *)malloc(MAX * sizeof(char));
  int choice;
  printf("\nEnter Gender\n");
  do {
    printf("1.Male\n2.Female\n3.Other\n");
    scanf("%d", &choice);
    getchar();
    switch (choice) {
    case 1:
      strcpy(gender, "Male");
      break;
    case 2:
      strcpy(gender, "Female");
      break;
    case 3:
      strcpy(gender, "Other");
      break;
    default:
      printf("Invalid Choice\n");
    }
  } while (choice < 1 || choice > 3);
  return gender;
}

char *getDOB() {
  char *dob = (char *)malloc(MAX * sizeof(char));
  bool status;
  do {
    printf("\nEnter Date of Birth (DD/MM/YYYY)\n");
    fgets(dob, MAX, stdin);
    dob[strlen(dob) - 1] = '\0';
    status = validDOB(dob);
    if (!status) {
      printf("Invalid DOB\n");
    }
  } while (!status);
  return dob;
}

char *getCity() {
  char *city = (char *)malloc(MAX * sizeof(char));
  bool status;
  do {
    printf("\nEnter City\n");
    fgets(city, MAX, stdin);
    city[strlen(city) - 1] = '\0';
    status = validCity(city);
    if (!status) {
      printf("Invalid City\n");
    }
  } while (!status);
  return city;
}

char *getAccType() {
  char *accType = (char *)malloc(MAX * sizeof(char));
  int choice;
  printf("\nEnter Bank Account Type\n");
  do {
    printf("1.Savings\n2.Current\n");
    scanf("%d", &choice);
    getchar();
    switch (choice) {
    case 1:
      strcpy(accType, "Savings");
      break;
    case 2:
      strcpy(accType, "Current");
      break;
    default:
      printf("Invalid Choice\n");
    }
  } while (choice != 1 && choice != 2);
  return accType;
}

char *getPan() {
  char *pan = (char *)malloc(MAX * sizeof(char));
  bool status;
  do {
    printf("\nEnter Pan Number\n");
    fgets(pan, MAX, stdin);
    pan[strlen(pan) - 1] = '\0';
    status = validPan(pan);
    if (!status) {
      printf("Invalid Pan\n");
    }
  } while (!status);
  return pan;
}

char *getAadhaar() {
  char *aadhaar = (char *)malloc(MAX * sizeof(char));
  bool status;
  do {
    printf("\nEnter Aadhaar Number\n");
    fgets(aadhaar, 30, stdin);
    // scanf("%[^\n]s", aadhaar);
    //  printf("\n%s\n", aadhaar);
    aadhaar[strlen(aadhaar) - 1] = '\0';
    status = validAadhaar(aadhaar);
    if (!status) {
      printf("Invalid Aadhaar\n");
    }
  } while (!status);
  return aadhaar;
}

char *getAccNo(char *name) {
  char *accNo = (char *)malloc(MAX * sizeof(char));
  char temp[MAX];
  temp[0] = '\0';
  int j = 0;
  for (int i = 0; name[i] != '\0'; i++) {
    if (name[i] >= 'A' && name[i] <= 'Z') {
      temp[j++] = name[i];
    }
  }
  temp[j] = '\0';
  int number = rand() % 900 + 100;
  char random[4];
  sprintf(random, "%d", number);
  strcpy(accNo, temp);
  strcat(accNo, random);
  return accNo;
}