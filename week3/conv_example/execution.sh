SET=$(seq 0 9)
for i in $SET
do
	./lenet ./test_data/$i.txt
done
