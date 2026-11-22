// func apmngr_ap_firm @ 0052dfd8 size=312

undefined4 apmngr_ap_firm(undefined2 *param_1,int param_2,undefined1 *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 auStack_300 [36];
  int local_2dc;
  
  memset(auStack_300,0,0x2d8);
  uVar1 = 0xffffffff;
  if ((param_1 != (undefined2 *)0x0) && (iVar4 = 0, puVar3 = param_3, 0 < param_2)) {
    do {
      iVar2 = apmngr_db_entry_get_by_id(*param_1,auStack_300);
      if ((iVar2 == 0) && (local_2dc == 0)) {
        iVar2 = apmngr_db_entry_firm(*param_1,param_4);
        if (((iVar2 == 0) && (iVar2 = apmngr_evt_notify(2,auStack_300), iVar2 == 0)) ||
           (param_3 == (undefined1 *)0x0)) {
          apmngr_db_sync_ap_entry(auStack_300,0,0,0);
          apmngr_db_datasync_ap_entry(auStack_300,0,0,0);
          if (param_3 != (undefined1 *)0x0) {
            *puVar3 = 0;
          }
        }
        else {
          *puVar3 = 0xff;
        }
      }
      else if (param_3 != (undefined1 *)0x0) {
        *puVar3 = 0xff;
      }
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar4 != param_2);
    uVar1 = 0;
  }
  return uVar1;
}

