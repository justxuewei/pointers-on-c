init:
	@mkdir -p build

1.1: init
	@gcc 1.1-rearrange-string/main.c -o build/a.out
	@echo "===== Build succeed, starting to run ====="
	@./build/a.out
