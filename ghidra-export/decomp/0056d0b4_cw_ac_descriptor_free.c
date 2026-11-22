// func cw_ac_descriptor_free @ 0056d0b4 size=60

undefined4 cw_ac_descriptor_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    cw_ac_descriptor_val_free();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

