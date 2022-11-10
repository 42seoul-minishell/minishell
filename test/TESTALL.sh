make -C ./doublylist all

./doublylist/testDoublyList
sleep 3

make -C ./doublylist fclean

make -C ./btree all
