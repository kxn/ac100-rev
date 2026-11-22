// func _uac_print_cookie @ 00523880 size=104

undefined4 _uac_print_cookie(int param_1)

{
  int in_t9;
  
  (**(code **)(in_t9 + 0x236050))
            (*(int *)(in_t9 + 0x2358a8) + 0x3cc0,param_1 + 4,*(undefined4 *)(param_1 + 0x2c),
             *(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x30),
             *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),
             *(undefined4 *)(param_1 + 0x3c),in_t9 + 0x23d880);
  return 0;
}

