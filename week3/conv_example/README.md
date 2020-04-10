# conv_example

## pytorch와 비슷하게 만들기 위해 노력했습니다. 

layer들을 원소로 가지는 network class까지는 완성하지 못했지만  

각 layer들은 class화 시켜서 사용하기 쉽도록 만들어 두었습니다.  

weight 값들은 pytorch를 통해 학습시킨 값을 가져다가 txt형태로 저장하여  

불러오도록 하였습니다.   

## 사용방식

```Makefile
make clean
make
./lenet ./test_data/1.txt
```

```Makefile
make clean
make
./execution.sh
```


## 추가해야하는 기능들

1. 각 layer들의 묶음인 network class 추가  
2. network class의 weight load 기능 추가  
3. network 구조 호출 및 load 상태 확인 기능 추가  