#include "islgr_util.h"

int logError(int line, const std::string& message) {
  std::cerr << "[" << line << "]"
            << ": " << message << std::endl;
  exit(EXIT_FAILURE);
}

void $check_assert(const std::string& expr, bool expr_val, int line) {
  if (!expr_val) {
    std::cerr << "Assertion error at:" << std::endl;
    // Line must be greater than two because of our adding two lines in main.
    // But still
    int l = line;
    if (line > 2) l = l - 2;
    logError(l, expr);
  }
}