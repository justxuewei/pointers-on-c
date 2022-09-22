BUILD_DIR := build
DEAFULT_OUTPUT_FILE := a.out

define run_user_application
	@echo "===== Starting to run user application ====="
	@./$(BUILD_DIR)/$(1)
endef

init:
	@mkdir -p $(BUILD_DIR)

1.1: init
	@gcc 1.1-rearrange-string/main.c -o $(BUILD_DIR)/$(DEAFULT_OUTPUT_FILE)
	$(call run_user_application,$(DEAFULT_OUTPUT_FILE))

3.3: init
	@gcc 3.3-typedef/main.c -o $(BUILD_DIR)/$(DEAFULT_OUTPUT_FILE)
	$(call run_user_application,$(DEAFULT_OUTPUT_FILE))

3.4: init
	@gcc 3.4-const/main.c -o $(BUILD_DIR)/$(DEAFULT_OUTPUT_FILE)
	$(call run_user_application,$(DEAFULT_OUTPUT_FILE))

6.2: init
	@gcc 6.2-find-char/main.c -o $(BUILD_DIR)/$(DEAFULT_OUTPUT_FILE)
	$(call run_user_application,$(DEAFULT_OUTPUT_FILE))

6.3: init
	@gcc 6.3-find-char/main.c -o $(BUILD_DIR)/$(DEAFULT_OUTPUT_FILE)
	$(call run_user_application,$(DEAFULT_OUTPUT_FILE))
