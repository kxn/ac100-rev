// func wserv_db_get_next_entry_by_id @ 005ec170 size=564

undefined4 wserv_db_get_next_entry_by_id(uint param_1,void *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *__format;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (param_2 == (void *)0x0) {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 != 0) {
      printf("<wserv>[error]%s(): %d  -> entry is null!\r\n","wserv_db_get_next_entry_by_id",0x8dd);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  if (((int)param_1 < 0) || (l_wserv_profile <= param_1)) {
    if (g_wserv_warning == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("<wserv>[warning]%s(): %d  -> id[%d] is invalid!\r\n","wserv_db_get_next_entry_by_id",
           0x8e3,param_1);
    return 0xffffffff;
  }
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  if (*(int *)(DAT_007cbefc + param_1 * 0x21c + 0xc) == 0) {
    uVar6 = 0xffffffff;
    if ((g_wserv_warning == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005ec230;
    __format = "<wserv>[warning]%s(): %d  -> id[%d] has not been used!\r\n";
    uVar5 = 0x8ea;
  }
  else {
    uVar4 = FUN_00408680();
    if (uVar4 == 0) {
      uVar6 = 0xffffffff;
      if ((g_wserv_warning == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005ec230;
      param_1 = FUN_00407fe0(&g_wserv_list);
      __format = "<wserv>[warning]%s(): %d  -> This is the last entry,total list size: %d!\r\n";
      uVar5 = 0x8f0;
    }
    else {
      uVar1 = uVar4 + 0x90 & 3;
      uVar2 = uVar4 + 0x93 & 3;
      if (*(int *)(DAT_007cbefc +
                   ((*(int *)((uVar4 + 0x90) - uVar1) << uVar1 * 8 |
                    uVar4 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar2 + 1) * 8 |
                   *(uint *)((uVar4 + 0x93) - uVar2) >> (3 - uVar2) * 8) * 0x21c + 0xc) != 0) {
        memcpy(param_2,(void *)(uVar4 + 0x10),0x205);
        uVar6 = 0;
        goto LAB_005ec230;
      }
      uVar6 = 0xffffffff;
      if ((g_wserv_warning == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005ec230;
      param_1 = *(uint *)(uVar4 + 0x90);
      __format = "<wserv>[warning]%s(): %d  -> id[%d] has not been used!\r\n";
      uVar5 = 0x8f7;
    }
  }
  uVar6 = 0xffffffff;
  printf(__format,"wserv_db_get_next_entry_by_id",uVar5,param_1);
LAB_005ec230:
  FUN_00407f30(DAT_007cbef0);
  return uVar6;
}

