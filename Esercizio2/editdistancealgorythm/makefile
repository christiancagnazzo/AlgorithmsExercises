JFLAGS = -cp .:Resources/hamcrest-core-1.3.jar:Resources/junit-4.12.jar:
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	EditDistanceAlgorithm.java \
	TestEditDistanceAlgorithm.java \
	AppEditDistance.java
	

all: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
	
test: 
	java $(JFLAGS) org.junit.runner.JUnitCore TestEditDistanceAlgorithm
	
app: 
	java AppEditDistance dataset/dictionary.txt dataset/correctme.txt
	

