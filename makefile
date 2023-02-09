out:
	g++ ClientFeedback.cpp main.cpp LockBox.cpp SmartClient.cpp -o out

clean:
	rm out
