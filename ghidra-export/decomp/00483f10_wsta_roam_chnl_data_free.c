// func wsta_roam_chnl_data_free @ 00483f10 size=108

void wsta_roam_chnl_data_free(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x18) != 0) {
      if (*(int *)(*(int *)(param_1 + 0x18) + 4) != 0) {
        FUN_00407df0();
        *(undefined4 *)(*(int *)(param_1 + 0x18) + 4) = 0;
      }
      FUN_00407df0(*(undefined4 *)(param_1 + 0x18));
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    FUN_00407df0(param_1);
    return;
  }
  return;
}

