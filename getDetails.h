#ifndef GETDETAILS_H
#define GETDETAILS_H

#include "validate.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char *getName();
char *getAge();
char *getGender();
char *getDOB();
char *getCity();
char *getAccType();
char *getPan();
char *getAadhaar();
char *getAccNo(char *);

void getDetails() {
  // ...

  char *name = getName();
  char *age = getAge();
  char *gender = getGender();
  char *dob = getDOB();
  char *city = getCity();
  char *accType = getAccType();
  char *pan = getPan();
  char *aadhaar = getAadhaar();

  // ...

  // Free dynamically allocated memory
  free(name);
  free(age);
  free(gender);
  free(dob);
  free(city);
  free(accType);
  free(pan);
  free(aadhaar);

  // ...

  // No return statement for a void function
}

#endif // GETDETAILS_H