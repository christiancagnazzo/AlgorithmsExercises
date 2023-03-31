JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	edge/Edge.java \
	graph/Graph.java \
	app/Interrogation.java
	

all: classes

classes: $(CLASSES:.java=.class)

test: 
	ruby run-tests.rb --args "java app/Interrogation"

clean:
	$(RM) app/*.class 
	$(RM) graph/*.class 
	$(RM) edge/*.class
	

 
