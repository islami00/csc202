#if !defined(ISLGR_UTIL_H)
#define ISLGR_UTIL_H
#include <iostream>
// https://stackoverflow.com/a/597081/16071410
// Log util https://www.cprogramming.com/reference/preprocessor/__LINE__.html
int logError(int line, const std::string& message);

// https://stackoverflow.com/a/377441/16071410
#define STR(x) #x

// A macro that takes in an expression, fails program if false and does nothing
// if true.
#define EXPECT_T(expr) ($check_assert(STR(expr), (expr), __LINE__))

// Does the actual bool check. we pass line for proper expansion.
void $check_assert(const std::string& expr, bool expr_val, int line);

#endif  // ISLGR_UTIL_H
