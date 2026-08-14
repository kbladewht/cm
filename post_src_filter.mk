CHIBIOS_LIB_NAME := $(curr_kb)
CHIBIOS_LIB_FILE := keyboards/lib$(CHIBIOS_LIB_NAME).a
$(info QQQ CHIBIOS_LIB_FILE = $(CHIBIOS_LIB_FILE))
ifeq ($(wildcard $(CHIBIOS_LIB_FILE)),)
    $(info $(CHIBIOS_LIB_FILE) not found , will build it by change USE_HAL_LIB_IND to N)
    USE_HAL_LIB_IND = N
endif

ifeq ($(USE_HAL_LIB_IND),Y)
    REMOVE_CHIBIOS_SRC := lib/chibios/% ./lib/chibios/% quantum/%

    # 主体文件
    SRC := $(filter-out $(REMOVE_CHIBIOS_SRC),$(SRC))
    PLATFORM_SRC := $(filter-out $(REMOVE_CHIBIOS_SRC),$(PLATFORM_SRC))

    # 库文件也需要处理
    LIB_SRC := $(filter-out $(REMOVE_CHIBIOS_SRC),$(LIB_SRC))
    QUANTUM_LIB_SRC := $(filter-out $(REMOVE_CHIBIOS_SRC),$(QUANTUM_LIB_SRC))
endif


# 合并量子库和chibios库
lib_chibios_target := $(CHIBIOS_LIB_FILE)

$(lib_chibios_target): build
	@printf "*******************************\n"
	@printf "\033[0;32mGenerating.... $(lib_chibios_target) library *****\033[0m \n"
	@if [ -d .build/obj_${TARGET}/lib ]; then \
	ar rcs $@ $(shell find .build/obj_${TARGET}/lib .build/obj_${TARGET}/quantum -name '*.o'); \
	fi
	@printf "\n************Done*******************"


#log 输出用
tmp_log_use_chibios:
	@printf "\033[0;32m********************************\n"
	@printf "\033[0;32mlinked chibios library $(CHIBIOS_LIB_NAME)*****\033[0m \n"
	@printf "********************************\033[0m\n"

ifeq ($(USE_HAL_LIB_IND),Y)
    $(info Use LIB For saving CPU resource, use lib for LDFLAGS)
    LDFLAGS += -Lkeyboards -l$(CHIBIOS_LIB_NAME)
    all: build tmp_log_use_chibios
endif
ifeq ($(USE_HAL_LIB_IND),N)
    all: build $(lib_chibios_target)
endif


ifeq ($(LTO_ENABLE),yes)
lib_433_target := keyboards/libqf433.lto.a
else
lib_433_target := keyboards/libqf433.a
endif

PRODUCE_433_LIB_IND = Y
PRODUCE_401_LIB_IND = Y

#433 打包类库
ifeq ($(PRODUCE_433_LIB_IND),Y)

# The rule to build chibios library
$(lib_433_target): build
	@printf "*******************************\n"
	@printf "\033[0;32mGenerating.... $(lib_433_target) library *****\033[0m \n"
	@if [ -d .build/pivot/p433/lib ]; then \
	ar rcs $@ .build/pivot/p433/lib/*.o; \
	fi
	@printf "\n************Done*******************"

    all: build $(lib_433_target)
endif



ifeq ($(LTO_ENABLE),yes)
    lib_401_target := keyboards/libqf401.lto.a
else
    lib_401_target := keyboards/libqf401.a
endif

ifeq ($(PRODUCE_401_LIB_IND),Y)

# 401 打包类库
$(lib_401_target): build
	@printf "*******************************\n"
	@printf "\033[0;32mGenerating.... $(lib_401_target) library *****\033[0m \n";
	@if [ -d .build/pivot/p401/lib ]; then \
	ar rcs $@ .build/pivot/p401/lib/*.o; \
	fi
	@printf "\n************Done*******************"

    all: build $(lib_401_target)

endif
