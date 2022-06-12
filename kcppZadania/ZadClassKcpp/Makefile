#Example of Makefile

#--------- Link command -------------------------------------
ZadKcpp: ZadKcpp.o Class.o
	    g++ ZadKcpp.o Class.o -o ZadKcpp
	    
#--------- Compilation commands -----------------------------
ZadKcpp.o: ZadKcpp.cxx
	      g++ -c ZadKcpp.cxx -I./include -o ZadKcpp.o
			  
Class.o: src/Class.cxx
	  g++ -c src/Class.cxx -I./include -o Class.o
	  
#--------- Cleaning command ---------------------------------
clean:
	  rm -rf *.o *.o
	  
distclean:
	  rm -rf *.o *.o *~ ZadKcpp