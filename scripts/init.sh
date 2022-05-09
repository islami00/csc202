# Init build tool https://www.gnu.org/software/automake/manual/automake.html#Hello-World
cd ubuntu
autoreconf --install
./configure
make

# Release lock
gp sync-done setup
