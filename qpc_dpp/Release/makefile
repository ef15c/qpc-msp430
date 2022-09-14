################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /home/nounours/ti/ccs1200/ccs/tools/compiler/ti-cgt-msp430_21.6.0.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./philo.obj" \
"./table.obj" \
"./qf/qep_hsm.obj" \
"./qf/qep_msm.obj" \
"./qf/qf_act.obj" \
"./qf/qf_actq.obj" \
"./qf/qf_defer.obj" \
"./qf/qf_dyn.obj" \
"./qf/qf_mem.obj" \
"./qf/qf_ps.obj" \
"./qf/qf_qact.obj" \
"./qf/qf_qeq.obj" \
"./qf/qf_qmact.obj" \
"./qf/qf_time.obj" \
"./qv/bsp.obj" \
"./qv/qv.obj" \
"../lnk_msp430g2553.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include qf/subdir_vars.mk
-include qv/subdir_vars.mk
-include subdir_rules.mk
-include qf/subdir_rules.mk
-include qv/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
qpc_dpp.out \

EXE_OUTPUTS__QUOTED += \
"qpc_dpp.out" \

BIN_OUTPUTS += \
qpc_dpp.hex \

BIN_OUTPUTS__QUOTED += \
"qpc_dpp.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "qpc_dpp.out"

# Tool invocations
qpc_dpp.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: MSP430 Linker'
	"/home/nounours/ti/ccs1200/ccs/tools/compiler/ti-cgt-msp430_21.6.0.LTS/bin/cl430" -vmsp -O2 --use_hw_mpy=none --advice:power=all --define=__MSP430G2553__ --define=NDEBUG --c99 --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number -z -m"qpc_dpp.map" --heap_size=80 --stack_size=80 -i"/home/nounours/ti/ccs1200/ccs/ccs_base/msp430/include" -i"/home/nounours/ti/ccs1200/ccs/tools/compiler/ti-cgt-msp430_21.6.0.LTS/lib" -i"/home/nounours/ti/ccs1200/ccs/tools/compiler/ti-cgt-msp430_21.6.0.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="qpc_dpp_linkInfo.xml" --use_hw_mpy=none --rom_model -o "qpc_dpp.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

qpc_dpp.hex: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: MSP430 Hex Utility'
	"/home/nounours/ti/ccs1200/ccs/tools/compiler/ti-cgt-msp430_21.6.0.LTS/bin/hex430" --memwidth=8 --romwidth=8 --diag_wrap=off -o "qpc_dpp.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "philo.obj" "table.obj" "qf/qep_hsm.obj" "qf/qep_msm.obj" "qf/qf_act.obj" "qf/qf_actq.obj" "qf/qf_defer.obj" "qf/qf_dyn.obj" "qf/qf_mem.obj" "qf/qf_ps.obj" "qf/qf_qact.obj" "qf/qf_qeq.obj" "qf/qf_qmact.obj" "qf/qf_time.obj" "qv/bsp.obj" "qv/qv.obj" 
	-$(RM) "main.d" "philo.d" "table.d" "qf/qep_hsm.d" "qf/qep_msm.d" "qf/qf_act.d" "qf/qf_actq.d" "qf/qf_defer.d" "qf/qf_dyn.d" "qf/qf_mem.d" "qf/qf_ps.d" "qf/qf_qact.d" "qf/qf_qeq.d" "qf/qf_qmact.d" "qf/qf_time.d" "qv/bsp.d" "qv/qv.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

