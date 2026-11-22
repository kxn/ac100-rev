// func check_is_nms_ap_by_id @ 0049eaa0 size=148

undefined4 check_is_nms_ap_by_id(undefined2 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  int local_94;
  
  memset(auStack_2e8,0,0x2d8);
  uVar2 = 0xffffffff;
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  uVar3 = uVar2;
  if ((((iVar1 != -1) && (g_nms_support_switch == 1)) && (local_94 << 0xe < 0)) &&
     ((uVar3 = 0xffffffff, param_2 == 0 &&
      (iVar1 = cloud_mngt_ap_is_nms_spupport(local_2d8,0), uVar3 = uVar2, iVar1 == 1)))) {
    uVar3 = 0;
  }
  return uVar3;
}

