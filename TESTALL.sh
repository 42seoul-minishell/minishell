make -C ./doublylist all

./doublylist/testDoublyList
sleep 3

make -C ./doublylist fclean

make -C ./bintree all

./bintree/testBinTree
sleep3

make -C ./bintree fclean
