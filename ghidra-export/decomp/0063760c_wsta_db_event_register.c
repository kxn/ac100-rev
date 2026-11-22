// func wsta_db_event_register @ 0063760c size=544

undefined4 wsta_db_event_register(uint param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined *puVar4;
  
  if (2 < param_1) {
    if (g_wsta_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("<wsta>[error]%s(): %d  -> invalid event[%d].\r\n","wsta_db_event_register",0x3e2,param_1
          );
    return 0xffffffff;
  }
  if (*(int *)((int)param_2 + 0x24) == 0) {
    if (g_wsta_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "<wsta>[error]%s(): %d  -> reg\'s cb is null.\r\n";
    uVar3 = 1000;
  }
  else {
    iVar1 = FUN_00408450(0x38,0xf9);
    if (iVar1 != 0) {
      l_wsta_mem_stat = l_wsta_mem_stat + 0x38;
      memcpy((void *)(iVar1 + 0xc),param_2,0x2c);
      if (param_1 == 1) {
        puVar4 = &DAT_007cc6f4;
      }
      else if (param_1 == 2) {
        puVar4 = &DAT_007cc700;
      }
      else {
        puVar4 = &DAT_007cc6e8;
      }
      if (-1 < *(int *)((int)param_2 + 0x20)) {
        iVar2 = FUN_004081b0(puVar4);
        while (iVar2 != 0) {
          if (*(int *)(iVar2 + 0x2c) <= *(int *)((int)param_2 + 0x20)) {
            FUN_00408170(iVar2,iVar1);
            goto LAB_00637784;
          }
          iVar2 = FUN_00408680();
        }
      }
      FUN_004086b0(puVar4,iVar1);
LAB_00637784:
      if (g_wsta_debug == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      printf("<wsta>[debug]%s(): %d  -> wsta reg event[%d]: name[%s] prio[%d]. event_list->size=%d.\r\n"
             ,"wsta_db_event_register",0x41c,param_1,param_2,*(undefined4 *)((int)param_2 + 0x20),
             *(undefined4 *)(puVar4 + 8));
      return 0;
    }
    if (g_wsta_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "<wsta>[error]%s(): %d  -> no memory\r\n";
    uVar3 = 0x3ef;
  }
  printf(__format,"wsta_db_event_register",uVar3);
  return 0xffffffff;
}

