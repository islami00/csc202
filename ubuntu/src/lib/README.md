# On the stack class
[g4gs](https://www.geeksforgeeks.org/stack-data-structure-introduction-program/)

# On include paths.

Note: VScode cpp will throw an odd error of not being able to find a user-defined include if we have one wrong include path.
This is most silent in the `.code-workspace` file.

E.g for this repo's `lib.h`, it'll throw an `Unable to find source file "lib.h"` error.

# On wildcard in automake

Read to the end as to why:

https://www.gnu.org/software/automake/manual/html_node/Wildcards.html.

Essentially, you'll never forget to add a file to your sources list. But you can mistakenly forget with a glob pattern. It even suggests using a script to generate it, which I like. I'll look it up and maybe use nodejs for it (Nah, not bash. Bash hurts).
Start with find: `find lib -name '*.cpp'`
