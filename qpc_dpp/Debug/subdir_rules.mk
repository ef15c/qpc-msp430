################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"/home/nounours/ti/ccs1200/ccs/tools/compiler/ti-cgt-msp430_21.6.0.LTS/bin/cl430" -vmsp --use_hw_mpy=none --include_path="/home/nounours/ti/ccs1200/ccs/ccs_base/msp430/include" --include_path="/home/nounours/workspace_v12/qpc_dpp" --include_path="/home/nounours/QuantumLeaps/qpc/include" --include_path="../qv/qv_mini" --include_path="/home/nounours/ti/ccs1200/ccs/tools/compiler/ti-cgt-msp430_21.6.0.LTS/include" --advice:power=all --define=__MSP430G2553__ -g --c99 --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


