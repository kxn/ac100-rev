// func wserv_db_get_first_entry @ 005ebcac size=1

undefined4
wserv_db_get_first_entry(void *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_1 == (void *)0x0) {
    uVar5 = 0xffffffff;
    if ((g_wserv_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("<wserv>[error]%s(): %d  -> entry is null!\r\n","wserv_db_get_first_entry",0x88c);
    }
  }
  else {
    FUN_004082d0(DAT_007cbef0,0xffffffff);
    uVar3 = FUN_004081b0(&g_wserv_list);
    if (uVar3 == 0) {
      uVar5 = 0xffffffff;
      if ((g_wserv_warning != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> There is no wserv entry!\r\n",
               "wserv_db_get_first_entry",0x894);
      }
    }
    else {
      uVar1 = uVar3 + 0x90 & 3;
      uVar2 = uVar3 + 0x93 & 3;
      if (*(int *)(DAT_007cbefc +
                   ((*(int *)((uVar3 + 0x90) - uVar1) << uVar1 * 8 |
                    uVar3 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar2 + 1) * 8 |
                   *(uint *)((uVar3 + 0x93) - uVar2) >> (3 - uVar2) * 8) * 0x21c + 0xc) == 0) {
        uVar5 = 0xffffffff;
        if ((g_wserv_warning != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          uVar1 = uVar3 + 0x90 & 3;
          uVar2 = uVar3 + 0x93 & 3;
          printf("<wserv>[warning]%s(): %d  -> id[%d] has not been used!\r\n",
                 "wserv_db_get_first_entry",0x89b,
                 (*(int *)((uVar3 + 0x90) - uVar1) << uVar1 * 8 |
                 param_4 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar2 + 1) * 8 |
                 *(uint *)((uVar3 + 0x93) - uVar2) >> (3 - uVar2) * 8);
        }
      }
      else {
        memcpy(param_1,(void *)(uVar3 + 0x10),0x205);
        uVar5 = 0;
      }
    }
    FUN_00407f30(DAT_007cbef0);
  }
  return uVar5;
}

