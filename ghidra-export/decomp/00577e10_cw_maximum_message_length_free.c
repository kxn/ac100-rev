// func cw_maximum_message_length_free @ 00577e10 size=60

undefined4 cw_maximum_message_length_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

