test_prg: Date.o Time.o test_prg.o Report.o
	g++ Date.o Time.o test_prg.o Report.o -o test_prg

test_prg.o: test_prg.cpp Report.h
	g++ -fno-elide-constructors -c test_prg.cpp

Report.o: Report.cpp Date.h Time.h Report.h
	g++ -fno-elide-constructors -c Report.cpp

Date.o: Date.cpp Date.h
	g++ -fno-elide-constructors -c Date.cpp

Time.o: Time.cpp Time.h
	g++ -fno-elide-constructors -c Time.cpp

clean: 
	rm -f *.o test_prg
