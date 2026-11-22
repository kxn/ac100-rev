// func wserv_db_entry_add @ 005ec620 size=716

int wserv_db_entry_add(void *param_1)

{
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  char *__format;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (param_1 == (void *)0x0) {
    if (g_wserv_error == 0) {
      return -1;
    }
    iVar7 = is_target_debug_ap();
    if (iVar7 == 0) {
      return -1;
    }
    printf("<wserv>[error]%s(): %d  -> entry is null!\r\n","wserv_db_entry_add",0x946);
    return -1;
  }
  pcVar5 = (char *)0xffffffff;
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  uVar2 = FUN_004085b0(DAT_007cbef4);
  *(uint *)((int)param_1 + 0x80) = uVar2;
  if (((int)uVar2 < 0) || (l_wserv_profile <= uVar2)) {
    iVar7 = -1;
    if ((g_wserv_warning == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005ec698;
    __format = "<wserv>[warning]%s(): %d  -> uac_id_alloc fail!\r\n";
    uVar6 = 0x94e;
  }
  else {
    iVar7 = DAT_007cbefc + uVar2 * 0x21c;
    if (*(int *)(iVar7 + 0xc) != 0) {
      iVar7 = -1;
      if ((g_wserv_warning != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        pcVar5 = "wserv_db_entry_add";
        printf("<wserv>[warning]%s(): %d  -> entry.id[%d] has been used!\r\n","wserv_db_entry_add",
               0x954,*(undefined4 *)((int)param_1 + 0x80));
      }
      goto LAB_005ec698;
    }
    pvVar3 = memcpy((void *)(iVar7 + 0x10),param_1,0x205);
    uVar2 = (int)param_1 + 0x80U & 3;
    uVar1 = (int)param_1 + 0x83U & 3;
    *(undefined4 *)
     (DAT_007cbefc +
      ((*(int *)(((int)param_1 + 0x80U) - uVar2) << uVar2 * 8 |
       (uint)pvVar3 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar1 + 1) * 8 |
      *(uint *)(((int)param_1 + 0x83U) - uVar1) >> (3 - uVar1) * 8) * 0x21c + 0xc) = 1;
    iVar7 = DAT_007cbefc + *(int *)((int)param_1 + 0x80) * 0x21c;
    uVar6 = FUN_004086f0(_wserv_rd_wlan_obj,_wserv_rd_wlan_key,_wserv_rd_wlan_cmp);
    *(undefined4 *)(iVar7 + 0x218) = uVar6;
    pcVar5 = (char *)(DAT_007cbefc + *(int *)((int)param_1 + 0x80) * 0x21c);
    if (*(int *)(pcVar5 + 0x218) == 0) {
      iVar7 = -1;
      if ((g_wserv_error == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005ec698;
      __format = "<wserv>[error]%s(): %d  -> no memory!\r\n";
      uVar6 = 0x95e;
    }
    else {
      pcVar5 = pcVar5 + 0x10;
      iVar7 = FUN_00408380(g_wserv_hash,pcVar5);
      if (iVar7 == 0) {
        pcVar5 = (char *)(DAT_007cbefc + *(int *)((int)param_1 + 0x80) * 0x21c);
        FUN_004086b0(&g_wserv_list,pcVar5);
        DAT_007cbef8 = DAT_007cbef8 + 1;
        iVar7 = *(int *)((int)param_1 + 0x80);
        goto LAB_005ec698;
      }
      iVar7 = -1;
      if ((g_wserv_error == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005ec698;
      __format = "<wserv>[error]%s(): %d  -> add to hash failed!\r\n";
      uVar6 = 0x963;
    }
  }
  pcVar5 = "wserv_db_entry_add";
  iVar7 = -1;
  printf(__format,"wserv_db_entry_add",uVar6);
LAB_005ec698:
  FUN_00407f30(DAT_007cbef0);
  if (iVar7 == -1) {
    uVar2 = (int)param_1 + 0x80U & 3;
    uVar1 = (int)param_1 + 0x83U & 3;
    FUN_004080f0(DAT_007cbef4,
                 (*(int *)(((int)param_1 + 0x80U) - uVar2) << uVar2 * 8 |
                 (uint)pcVar5 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar1 + 1) * 8 |
                 *(uint *)(((int)param_1 + 0x83U) - uVar1) >> (3 - uVar1) * 8);
  }
  return iVar7;
}

