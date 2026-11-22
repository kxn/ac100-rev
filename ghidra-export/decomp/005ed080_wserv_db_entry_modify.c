// func wserv_db_entry_modify @ 005ed080 size=684

undefined4 wserv_db_entry_modify(void *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *__format;
  void *pvVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  if (param_1 == (void *)0x0) {
    if (g_wserv_warning == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 != 0) {
      printf("<wserv>[warning]%s(): %d  -> entry is null!\r\n","wserv_db_entry_modify",0xa4b);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  if (((int)*(uint *)((int)param_1 + 0x80) < 0) ||
     (l_wserv_profile <= *(uint *)((int)param_1 + 0x80))) {
    if (g_wserv_warning == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    uVar5 = (int)param_1 + 0x80U & 3;
    uVar1 = (int)param_1 + 0x83U & 3;
    printf("<wserv>[warning]%s(): %d  -> id[%d] is invalid!\r\n","wserv_db_entry_modify",0xa51,
           (*(int *)(((int)param_1 + 0x80U) - uVar5) << uVar5 * 8 |
           param_4 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar1 + 1) * 8 |
           *(uint *)(((int)param_1 + 0x83U) - uVar1) >> (3 - uVar1) * 8);
    return 0xffffffff;
  }
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  iVar3 = DAT_007cbefc;
  iVar4 = DAT_007cbefc + *(int *)((int)param_1 + 0x80) * 0x21c;
  uVar5 = *(uint *)(iVar4 + 0xc);
  if (uVar5 == 0) {
    uVar8 = 0xffffffff;
    if ((g_wserv_warning == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005ed154;
    uVar5 = (int)param_1 + 0x80U & 3;
    uVar5 = *(int *)(((int)param_1 + 0x80U) - uVar5) << uVar5 * 8 |
            param_4 & 0xffffffffU >> (4 - uVar5) * 8;
    __format = "<wserv>[warning]%s(): %d  -> entry.id[%d] is not used!\r\n";
    uVar7 = 0xa58;
  }
  else {
    uVar1 = (int)param_1 + 0x11bU & 3;
    uVar2 = (int)param_1 + 0x11eU & 3;
    *(uint *)(iVar4 + 299) =
         (*(int *)(((int)param_1 + 0x11bU) - uVar1) << uVar1 * 8 |
         uVar5 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar2 + 1) * 8 |
         *(uint *)(((int)param_1 + 0x11eU) - uVar2) >> (3 - uVar2) * 8;
    pvVar6 = param_1;
    iVar3 = memcmp((void *)(iVar3 + *(int *)((int)param_1 + 0x80) * 0x21c + 0x10),param_1,0x205);
    if (iVar3 != 0) {
      if (g_wserv_debug == 0) {
        uVar5 = *(uint *)((int)param_1 + 0x80);
      }
      else {
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          uVar5 = (int)param_1 + 0x80U & 3;
          uVar5 = *(int *)(((int)param_1 + 0x80U) - uVar5) << uVar5 * 8 |
                  (uint)pvVar6 & 0xffffffffU >> (4 - uVar5) * 8;
        }
        else {
          printf("<wserv>[debug]%s(): %d  -> entry.id[%d] something has changed\r\n",
                 "wserv_db_entry_modify",0xa5f,*(undefined4 *)((int)param_1 + 0x80));
          uVar5 = *(uint *)((int)param_1 + 0x80);
        }
      }
      FUN_00407f40(g_wserv_hash,DAT_007cbefc + uVar5 * 0x21c + 0x10);
      memcpy((void *)(DAT_007cbefc + *(int *)((int)param_1 + 0x80) * 0x21c + 0x10),param_1,0x205);
      uVar8 = 0;
      FUN_00408380(g_wserv_hash,DAT_007cbefc + *(int *)((int)param_1 + 0x80) * 0x21c + 0x10);
      goto LAB_005ed154;
    }
    uVar8 = 0;
    if ((g_wserv_debug == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005ed154;
    uVar5 = (int)param_1 + 0x80U & 3;
    uVar5 = *(int *)(((int)param_1 + 0x80U) - uVar5) << uVar5 * 8 |
            param_4 & 0xffffffffU >> (4 - uVar5) * 8;
    __format = "<wserv>[debug]%s(): %d  -> entry.id[%d] no changed\r\n";
    uVar7 = 0xa66;
  }
  uVar1 = (int)param_1 + 0x83U & 3;
  printf(__format,"wserv_db_entry_modify",uVar7,
         uVar5 & -1 << (uVar1 + 1) * 8 |
         *(uint *)(((int)param_1 + 0x83U) - uVar1) >> (3 - uVar1) * 8);
LAB_005ed154:
  FUN_00407f30(DAT_007cbef0);
  return uVar8;
}

