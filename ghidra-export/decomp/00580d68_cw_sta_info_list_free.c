// func cw_sta_info_list_free @ 00580d68 size=76

undefined4 cw_sta_info_list_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    if (*(int *)(*(int *)(param_1 + 0x10) + 0xc) != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

