#!/bin/bash

set -e

if [ $1 == 'algorithms/warmup/' ] ; then
    THIS_DIR="$(pwd)/algorithms/warmup"
elif [ $1 == 'algorithms/implementation/' ] ; then
    THIS_DIR="$(pwd)/algorithms/implementation"
elif [ $1 == 'algorithms/search/' ] ; then
    THIS_DIR="$(pwd)/algorithms/search"
elif [ $1 == 'algorithms/strings/' ] ; then
    THIS_DIR="$(pwd)/algorithms/strings"
elif [ $1 == 'algorithms/sorting/' ] ; then
    THIS_DIR="$(pwd)/algorithms/sorting"
elif [ $1 == 'algorithms/graph_theory/' ] ; then
    THIS_DIR="$(pwd)/algorithms/graph_theory"
elif [ $1 == 'algorithms/greedy/' ] ; then
    THIS_DIR="$(pwd)/algorithms/greedy"
elif [ $1 == 'algorithms/dynamic_programming/' ] ; then
    THIS_DIR="$(pwd)/algorithms/dynamic_programming"
elif [ $1 == 'algorithms/bit_manipulation/' ] ; then
    THIS_DIR="$(pwd)/algorithms/bit_manipulation"
elif [ $1 == 'algorithms/regex/' ] ; then
    THIS_DIR="$(pwd)/algorithms/regex"
elif [ $1 == 'algorithms/number_theory/' ] ; then
    THIS_DIR="$(pwd)/algorithms/number_theory"
elif [ $1 == 'algorithms/combinatorics/' ] ; then
    THIS_DIR="$(pwd)/algorithms/combinatorics"
elif [ $1 == 'algorithms/summations_and_algebra/' ] ; then
    THIS_DIR="$(pwd)/algorithms/summations_and_algebra"
elif [ $1 == 'algorithms/geometry/' ] ; then
    THIS_DIR="$(pwd)/algorithms/geometry"
elif [ $1 == 'algorithms/probability/' ] ; then
    THIS_DIR="$(pwd)/algorithms/probability"
elif [ $1 == 'algorithms/game_theory/' ] ; then
    THIS_DIR="$(pwd)/algorithms/game_theory"
elif [ $1 == 'algorithms/np_complete/' ] ; then
    THIS_DIR="$(pwd)/algorithms/np_complete"
elif [ $1 == 'algorithms/code_golf/' ] ; then
    THIS_DIR="$(pwd)/algorithms/code_golf"
elif [ $1 == 'algorithms/multiple_choice/' ] ; then
    THIS_DIR="$(pwd)/algorithms/multiple_choice"
elif [ $1 == 'algorithms/data_structures_advanced/' ] ; then
    THIS_DIR="$(pwd)/algorithms/data_structures_advanced"
elif [ $1 == 'tutorials/ctci/' ] ; then
    THIS_DIR="$(pwd)/tutorials/ctci"
else
    echo "Wrong domain. Check the script please!"
    exit 1
fi

NAME=$2

SOURCE="$THIS_DIR/$NAME/$NAME.py"
TEST="$THIS_DIR/$NAME/test.txt"
TEST_FILE="$THIS_DIR/$NAME/test.sh"

mkdir -p "$THIS_DIR/$NAME"
touch $TEST

cat > $SOURCE << EOM
def get_args():
    pass

def main():
    a = get_args()
    pass

if __name__ == "__main__":
    main()
EOM

cat > $TEST_FILE << EOM
#!/bin/bash

if [ -z "\$1" ] ; then
    python3 ${NAME}.py < test.txt
else
    TEST_F="test_\$1.txt"
    python3 ${NAME}.py < \$TEST_F
fi
EOM

chmod +x $TEST_FILE

exit 0
