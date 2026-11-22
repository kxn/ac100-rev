// func check_can_direct_report_by_ac @ 0048de0c size=164

undefined4 check_can_direct_report_by_ac(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (((param_1 != 0) && (*(int *)(param_1 + 0x14) != 7)) &&
     (uVar2 = 0xffffffff, *(int *)(param_1 + 0x2ac) - 2U < 2)) {
    iVar1 = get_nms_support_switch();
    uVar2 = 0;
    if (((iVar1 == 1) && (*(int *)(param_1 + 0x254) << 0xe < 0)) && (uVar2 = 0, param_2 == 0)) {
      iVar1 = cloud_mngt_ap_is_nms_spupport(*(undefined2 *)(param_1 + 0x10),0);
      uVar2 = 0xffffffff;
      if (iVar1 != 1) {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

