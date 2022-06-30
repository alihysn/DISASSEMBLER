SRC_FILES = $(shell find ./ -name '*.cpp')
OUTPUT= rvcdiss

compile:	$(SRC_FILES)
	g++ $(SRC_FILES) -o $(OUTPUT)


CTest:
	g++ main1.cpp compressed.cpp -o $(OUTPUT)


clean:
	$(RM) $(OUTPUT)