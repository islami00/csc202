#ifndef BUTTON_H
#define BUTTON_H
/**
 * A generic button from the first class on classes.
 * Best practice:
 * https://www.learncpp.com/cpp-tutorial/class-code-and-header-files/#:~:text=Traditionally%2C%20the%20class%20definition%20is,same%20name%20as%20the%20class.&text=Now%20any%20other%20header%20or,h%22%20.
 * */
class button {
 private:
  int count;
  //   The data in the class is subject to same rules as regular vars.
  //   Initialise or you get garbage value;
  int baseCount;

 public:
  int increase();
  button();
  ~button();
};
#endif  //
