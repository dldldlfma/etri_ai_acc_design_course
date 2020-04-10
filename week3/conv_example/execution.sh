SET=$(seq 0 9)
for i in $SET
do
	./lenet $i.txt
done
