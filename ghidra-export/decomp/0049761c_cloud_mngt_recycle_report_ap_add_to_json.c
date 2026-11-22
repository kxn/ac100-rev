// func cloud_mngt_recycle_report_ap_add_to_json @ 0049761c size=140

undefined4 cloud_mngt_recycle_report_ap_add_to_json(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int extraout_v1;
  
  if ((((param_1 != 0) && (*(char *)(param_1 + 0x1c5) == '\0')) && (*(int *)(param_1 + 0x3c) != 0))
     && ((*(int *)(param_1 + 0xc) != 0 &&
         (FUN_00407e70(), 0x14 < (uint)(extraout_v1 - *(int *)(param_1 + 0x284)))))) {
    uVar1 = cloud_mngt_report_ap_add_to_json(param_1,param_2);
    return uVar1;
  }
  return 0;
}

