#include <cstdlib>
#include <string>
#pragma ONCE
#include <fstream>
#include <iostream>
#include <stack>
using namespace std;

class coordinate {
public:
  // x is a vector in R^2
  coordinate(void) {
    x = new double[2]();
    *x = *(x + 8) = 0.0;
  }
  void setcoord(double x1, double x2) {
    *x = x1;
    *(x + 8) = x2;
  }
  double x0(void) { return *x; }
  double x1(void) { return *(x + 8); }

  double distance(coordinate *c) {
    // Calculating distance from the coordinate at c
    return sqrt(pow(*(x)-c->x0(), 2) + pow(*(x + 8) - c->x1(), 2) * 1.0);
  }
  void printcoords(void) {
    cout << "( " << *x;
    cout << " , " << *(x + 8) << " )" << endl;
  }

private:
  double *x;
};
// Assignment 1
class PlaneArithmetic {
public:
  // HELPERS
  char *find(string str, char a, int start) {
    char *t = &str[start];
    while (t != '\0') {
      if (*t == a) {
        return t;
      }
      t++;
    }
    return nullptr;
  }
  void printvec(vector<coordinate **> nums) {
    for (int i = 0; i < nums.size(); i++) {
      coordinate *p = nums[i][0];
      unsigned short counter = 0;
      do {
        if (p != 0x0) {
          p->printcoords();
          p += sizeof(coordinate);
          counter++;
        }
      } while (counter < 10);
    }
    cout << endl;
  }

  // adjust for sorting by coordinates

  void alphastr(string &check) {
    // does check have all alphanumeric characters?
    // alphanumeric characters lie in the ASCII value range of [65, 90] for
    // uppercase alphabets, [97, 122] for lowercase alphabets, and [48, 57] for
    // digits
    char *c = &check[0];
    for (; *c != '\0'; c++) {
      if (*c >= 65 && *c <= 90 || *c >= 97 && *c <= 122 ||
          *c >= 48 && *c <= 57) {
        // alphanumeric
        continue;
      } else {
        // will need to be changed to45t3y fully remove the nonalphanumeric
        // indices
        *c = ' ';
      }
    }
    return;
  }

  double numparse(string line, char start, char *&i ){
    string ans = string();

    char *p = &line[line.find(start) + 1];
    if (*p == ' ') {
      p++;
    }
    while ((*p <= '9' && *p >= '0') || *p == '.') {
      ans += *p;
      p++;
    }
    i=p;
    return stod(ans);
  }

  // END HELPERS
  //  - -- - --- -- - - - - - - -- - -------------------->               FOR
  //  CECS            < ------ - - - - - - - - - -- - - - - -- - - -
  vector<coordinate *> filein(string in) {
    // start AFTER first bracket
    ifstream f;
    f.open(in);
    // vector of rows of arrays of max size 20 representing coordinates
    vector<coordinate *> nums;

    string line;
    // array of "window" of coordinate pointers being compared at a time
    // max of 10 pairs of points per line.

    if (!f.fail()) {

      vector<coordinate *> points;
      while (getline(f, line, '\n')) {
        if (!line.empty()) {
          // 9 is first number
          char *i = &line[0];
          if (*i != '\n') {
            switch (*i) {
            case '{': {
              // open bracket
               coordinate *p = new coordinate();
              p->setcoord(numparse(line, '{',i), numparse(line, ',',i));
              p->printcoords();
              points.push_back(p);
              break;
            }
            // close bracket;
            case '}': {
              i++;
              break;
            }
            case ',': {
              // end of line
              break;
            }

            default: {

              break;
            }
              // will insert newline char at end of string
              // double answer = atof(buffer);
              //  temp.push_back(buffer)
              // each point in array represents a pair of coordinates
            }

            // nums.push_back(points);
            i++;
          }

          cout << endl;
          // float parse
        }
        if (line.empty()) {
          return points;
        }
        // asdfsd
      }
      return vector<coordinate *>();
    } else {
      cout << "ERROR reading from file. Please check your spelling and "
              "placement of filename within this directory."
           << endl;
      return vector<coordinate *>();
      ;
    }
  }
};
