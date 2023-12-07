.PHONY: all clean

all:
	@echo "Building Start...!"
	mkdir -p build
	mkdir -p build/bin
	cd build && cmake -S ..
	cd build && $(MAKE)
	@echo "Building Completed"

clean:
	@echo "Cleaning Start...!"
	rm -rf ../build .cashe
	@echo "Cleaning Finished"
