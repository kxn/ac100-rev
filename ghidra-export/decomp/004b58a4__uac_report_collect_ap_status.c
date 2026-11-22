// func _uac_report_collect_ap_status @ 004b58a4 size=272

undefined4 _uac_report_collect_ap_status(void *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if ((((param_2 != 0) && (uVar2 = 0, *(int *)((int)param_1 + 0xc) != 0)) &&
      (*(short *)(DAT_00767d58 + (uint)*(ushort *)((int)param_1 + 0x12) * 2) != 0)) &&
     ((((DAT_00767d5c & 1) != 0 || (*(int *)((int)param_1 + 0x20) != 1)) &&
      (((DAT_00767d5c & 2) != 0 || (uVar2 = 0, *(int *)((int)param_1 + 0x20) != 0)))))) {
    iVar1 = FUN_00408450(0x2e8,0x2de);
    if (iVar1 == 0) {
      uVar2 = 1;
      if (report_err_switch != 0) {
        printf("[REPORT_ERROR]%s()/line %d : mem alloc fail for ap_node\n",
               "_uac_report_collect_ap_status",0x2e1);
      }
    }
    else {
      memcpy((void *)(iVar1 + 0x10),param_1,0x2d8);
      uVar2 = 0;
      FUN_004086b0(param_2,iVar1);
    }
  }
  return uVar2;
}

