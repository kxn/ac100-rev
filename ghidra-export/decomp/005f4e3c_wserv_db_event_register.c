// func wserv_db_event_register @ 005f4e3c size=528

undefined4 wserv_db_event_register(uint param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  
  if (param_1 < 6) {
    iVar1 = wserv_malloc(0x38);
    if (iVar1 == 0) {
      uVar4 = 0xffffffff;
      if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[error]%s(): %d  -> no memory\r\n","wserv_db_event_register",0x1727);
      }
    }
    else {
      memcpy((void *)(iVar1 + 0xc),param_2,0x2c);
      switch(param_1) {
      case 1:
        puVar3 = &DAT_007cbf24;
        break;
      case 2:
        puVar3 = &DAT_007cbf30;
        break;
      case 3:
        puVar3 = &DAT_007cbf3c;
        break;
      case 4:
        puVar3 = &DAT_007cbf48;
        break;
      case 5:
        puVar3 = &DAT_007cbf54;
        break;
      default:
        puVar3 = &DAT_007cbf18;
      }
      if (-1 < *(int *)((int)param_2 + 0x20)) {
        iVar2 = FUN_004081b0(puVar3);
        while (iVar2 != 0) {
          if (*(int *)(iVar2 + 0x2c) <= *(int *)((int)param_2 + 0x20)) {
            FUN_00408170(iVar2,iVar1);
            goto LAB_005f4fdc;
          }
          iVar2 = FUN_00408680();
        }
      }
      FUN_004086b0(puVar3,iVar1);
LAB_005f4fdc:
      uVar4 = 0;
      if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[debug]%s(): %d  -> wserv reg event[%s]: name[%s] prio[%d]. event_list->size=%d.\r\n"
               ,"wserv_db_event_register",0x175d,(&PTR_DAT_006fa204)[param_1],param_2,
               *(undefined4 *)((int)param_2 + 0x20),*(undefined4 *)(puVar3 + 8));
      }
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[error]%s(): %d  -> invalid event[%d].\r\n","wserv_db_event_register",0x1720,
             param_1);
    }
  }
  return uVar4;
}

