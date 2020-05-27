JFLAGS = -cp ..:.:Resources/hamcrest-core-1.3.jar:Resources/junit-4.12.jar:
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	algorithmeditdistance/EditDistanceAlgorithm.java \
	algorithmeditdistance/testeditdistance/TestEditDistanceAlgorithm.java \
	editdistanceapp/AppEditDistance.java
	

all: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) algorithmeditdistance/*.class
	$(RM) algorithmeditdistance/testeditdistance/*.class
	$(RM) editdistanceapp/*.class
	
test: 
	java $(JFLAGS) org.junit.runner.JUnitCore algorithmeditdistance.testeditdistance.TestEditDistanceAlgorithm
	
app: 
	java editdistanceapp/AppEditDistance dataset/dictionary.txt dataset/correctme.txt
	

