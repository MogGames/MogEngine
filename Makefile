# Run the build commands in the "build" directory
BUILD_DIR = ./build
EXECUTABLE = MogEngine

# Build target (default)
all: build

# Build the project (release mode)
build:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake .. -DCMAKE_BUILD_TYPE=Release
	cd $(BUILD_DIR) && make

# Clean the build directory
clean:
	rm -rf $(BUILD_DIR)

# Build in debug mode
debug:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake .. -DCMAKE_BUILD_TYPE=Debug
	cd $(BUILD_DIR) && make

# Start gdb in TUI mode
gdb:
	make debug
	cd $(BUILD_DIR) && gdb -tui ./$(EXECUTABLE)

# Run the executable from build directory
run:
	$(BUILD_DIR)/$(EXECUTABLE)

