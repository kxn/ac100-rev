// func cloud_mngt_first_report_ap_add_to_json @ 004976a8 size=60

undefined4 cloud_mngt_first_report_ap_add_to_json(int param_1)

{
  undefined4 uVar1;
  
  if ((((param_1 != 0) && (*(char *)(param_1 + 0x1c5) == '\0')) && (*(int *)(param_1 + 0x3c) != 0))
     && (*(int *)(param_1 + 0xc) != 0)) {
    uVar1 = cloud_mngt_report_ap_add_to_json();
    return uVar1;
  }
  return 0;
}

