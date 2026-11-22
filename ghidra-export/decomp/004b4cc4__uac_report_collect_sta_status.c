// func _uac_report_collect_sta_status @ 004b4cc4 size=332

undefined4 _uac_report_collect_sta_status(void *param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_2f0 [12];
  int local_2e4;
  ushort local_2de;
  
  memset(auStack_2f0,0,0x2d8);
  if (param_2 == 0) {
    uVar3 = 0xffffffff;
    if (report_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[REPORT_ERROR]%s()/line %d : sta_entry is NULL.\n";
    uVar2 = 0x2f1;
  }
  else {
    iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)((int)param_1 + 0x22),auStack_2f0);
    if (iVar1 == 0) {
      if (local_2e4 == 0) {
        return 0;
      }
      if (*(short *)(DAT_00767d58 + (uint)local_2de * 2) == 0) {
        return 0;
      }
      iVar1 = FUN_00408450(0x8c,0x305);
      if (iVar1 != 0) {
        memcpy((void *)(iVar1 + 0xc),param_1,0x80);
        FUN_004086b0(param_2,iVar1);
        return 0;
      }
      uVar3 = 0xffffffff;
      if (report_err_switch == 0) {
        return 0xffffffff;
      }
      __format = "[REPORT_ERROR]%s()/line %d : mem alloc fail for sta_node\n";
      uVar2 = 0x308;
    }
    else {
      uVar3 = 1;
      if (report_err_switch == 0) {
        return 1;
      }
      __format = "[REPORT_ERROR]%s()/line %d : sta_entry get ap_entry failed.\n";
      uVar2 = 0x2f7;
    }
  }
  printf(__format,"_uac_report_collect_sta_status",uVar2);
  return uVar3;
}

