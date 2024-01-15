#include <ctype.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX 30

bool validName(char *name) {
  const char *pattern = "^[A-Z][a-z]+( [A-Z][a-z]+)? [A-Z][a-z]+$";
  regex_t regex;
  int compile = regcomp(&regex, pattern, REG_EXTENDED);
  int match = regexec(&regex, name, 0, NULL, 0);
  regfree(&regex);
  if (!match) {
    return true;
  }
  return false;
}

bool validAge(char *age) {
  const char *pattern = "^(0*[1-9][0-9]?$|^0*100)$";
  regex_t regex;
  regcomp(&regex, pattern, REG_EXTENDED);
  int match = regexec(&regex, age, 0, NULL, 0);
  regfree(&regex);
  if (!match) {
    return true;
  }
  return false;
}
bool validDOB(char *dob) {
  const char *pattern =
      "^([0]?[1-9]|[1-2][0-9]|[3][0-1])[/]([0]?[1-9]|[1][0-2])[/"
      "](19[0-9][0-9]|20[0-1][0-9]|202[0-3])$";
  regex_t regex;
  regcomp(&regex, pattern, REG_EXTENDED);
  int match = regexec(&regex, dob, 0, NULL, 0);
  regfree(&regex);
  if (!match)
    return true;
  return false;
}

bool validCity(char *city) {
  const char *pattern = "^[A-Z][a-z]{2,}$";
  regex_t regex;
  regcomp(&regex, pattern, REG_EXTENDED);
  int match = regexec(&regex, city, 0, NULL, 0);
  regfree(&regex);
  if (!match)
    return true;
  return false;
}

bool validPan(char *pan) {
  int n = strlen(pan);
  if (n != 10) {
    return false;
  }
  for (int i = 0; i < 5; i++) {
    if (isupper(pan[i]) == 0) {
      return false;
    }
  }
  for (int i = 5; i < 9; i++) {
    if (isdigit(pan[i]) == 0) {
      return false;
    }
  }
  if (isupper(pan[9]) == 0) {
    return false;
  }
  return true;
}

bool validAadhaar(char *aadhaar) {
  const char *pattern = "^[2-9][0-9]{11}$";
  regex_t regex;
  regcomp(&regex, pattern, REG_EXTENDED);
  int match = regexec(&regex, aadhaar, 0, NULL, 0);
  regfree(&regex);
  if (!match)
    return true;
  return false;

  // if (strlen(aadhaar) != 12) {
  //   return false;
  // }

  // // Check if all characters are digits
  // for (int i = 0; i < 12; i++) {
  //   if (!isdigit(aadhaar[i])) {
  //     return false;
  //   }
  // }
  // return true;
}

bool validAmount(char *amount) {
  const char *pattern = "^[0-9]+(\\.[0-9]+)?$";
  regex_t regex;
  regcomp(&regex, pattern, REG_EXTENDED);
  int match = regexec(&regex, amount, 0, NULL, 0);
  regfree(&regex);
  if (!match)
    return true;
  return false;
}