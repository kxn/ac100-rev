// func _apdb_ap_model_free @ 005ffc44 size=152

void _apdb_ap_model_free(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
      if (*(int *)(param_1 + 0x164) == 0) {
        *(undefined4 *)(param_1 + 0x160) = 0;
      }
      else {
        _apdb_ap_model_radios_free(*(int *)(param_1 + 0x164),*(undefined4 *)(param_1 + 0x160));
        _apdb_ap_model_phy_info_free
                  (*(undefined4 *)(param_1 + 0x164),*(undefined4 *)(param_1 + 0x160));
        _apdb_ap_model_rrst_free(*(undefined4 *)(param_1 + 0x164),*(undefined4 *)(param_1 + 0x160));
        _apdb_ap_model_region_list_free
                  (*(undefined4 *)(param_1 + 0x164),*(undefined4 *)(param_1 + 0x160));
        FUN_00407df0(*(undefined4 *)(param_1 + 0x164));
        *(undefined4 *)(param_1 + 0x164) = 0;
        *(undefined4 *)(param_1 + 0x160) = 0;
      }
      param_1 = param_1 + 0x168;
    }
  }
  return;
}

