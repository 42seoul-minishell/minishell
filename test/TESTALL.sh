make -C ./doublylist all
make -C ./btree all

./doublylist/testDoublylist
sleep 1

./btree/testBtree
sleep 2

make -C ./doublylist fclean
make -C ./btree fclean