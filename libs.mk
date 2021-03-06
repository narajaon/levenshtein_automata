###
# FT_PRINTF
###

FT_PRINTF:=ft_printf
FT_PRINTF_DIR:=$(LIB_D)/$(FT_PRINTF)
FT_PRINTF_INC:=-I $(FT_PRINTF_DIR)/$(INC_D)

###
# LIBFT
###

LIBFT:=libft
LIBFT_DIR:=$(LIB_D)/$(LIBFT)
LIBFT_INC:=-I $(LIBFT_DIR)/$(INC_D)


INCLUDES+=\
		  $(LIBFT_INC)\
		  $(FT_PRINTF_INC)
