proFile: src/recruitEmployee.o src/printAll.o src/printOne.o src/lookOnId.o src/lookOnFullName.o src/sortEmployeesId.o src/countEmployees.o src/fireAll.o src/fireOne.o src/helperA3.o src/mainA3.o include/headerA3.h
	gcc -std=c99 -Wall -g src/recruitEmployee.o src/printAll.o src/printOne.o src/lookOnId.o src/lookOnFullName.o src/sortEmployeesId.o src/countEmployees.o src/fireAll.o src/fireOne.o  src/helperA3.o src/mainA3.o -o bin/proFile
mainA3.o: src/mainA3.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/mainA3.c
recruitEmployee.o: src/recruitEmployee.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/recruitEmployee.c
printAll.o: src/printAll.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/printAll.c
printOne.o: src/printOne.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/printOne.c
lookOnId.o: src/lookOnId.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/lookOnId.c
lookOnFullName.o: src/lookOnFullName.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/lookOnFullName.c
sortEmployeesId.o: src/sortEmployeesId.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/sortEmployeesId.c
countEmployees.o: src/countEmployees.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/countEmployees.c
fireAll.o: src/fireAll.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/fireAll.c
fireOne.o: src/fireOne.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/fireOne.c
helperA3.o: src/helperA3.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/helperA3.o
clean:
	rm src/*.o bin/proFile