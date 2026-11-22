// func wserv_db_entry_load @ 005ec3a4 size=636

undefined4 wserv_db_entry_load(void *param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if (param_1 == (void *)0x0) {
    if (g_wserv_error != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "<wserv>[error]%s(): %d  -> entry is null!\r\n";
      uVar2 = 0x911;
      goto LAB_005ec490;
    }
  }
  else {
    if ((-1 < (int)*(uint *)((int)param_1 + 0x80)) &&
       (*(uint *)((int)param_1 + 0x80) < l_wserv_profile)) {
      FUN_004082d0(DAT_007cbef0,0xffffffff);
      iVar1 = DAT_007cbefc + *(int *)((int)param_1 + 0x80) * 0x21c;
      if (*(int *)(iVar1 + 0xc) == 0) {
        uVar2 = FUN_004086f0(_wserv_rd_wlan_obj,_wserv_rd_wlan_key,_wserv_rd_wlan_cmp);
        *(undefined4 *)(iVar1 + 0x218) = uVar2;
        iVar1 = DAT_007cbefc + *(int *)((int)param_1 + 0x80) * 0x21c;
        if (*(int *)(iVar1 + 0x218) == 0) {
          uVar2 = 0xffffffff;
          if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("<wserv>[error]%s(): %d  -> no memory!\r\n","wserv_db_entry_load",0x927);
          }
        }
        else {
          memcpy((void *)(iVar1 + 0x10),param_1,0x205);
          uVar2 = DAT_007cbef4;
          *(undefined4 *)(DAT_007cbefc + *(int *)((int)param_1 + 0x80) * 0x21c + 0xc) = 1;
          FUN_00408440(uVar2,*(undefined4 *)((int)param_1 + 0x80));
          FUN_004086b0(&g_wserv_list,DAT_007cbefc + *(int *)((int)param_1 + 0x80) * 0x21c);
          FUN_00408380(g_wserv_hash,DAT_007cbefc + *(int *)((int)param_1 + 0x80) * 0x21c + 0x10);
          DAT_007cbef8 = DAT_007cbef8 + 1;
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0xffffffff;
        if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> entry.id[%d] has been used!\r\n",
                 "wserv_db_entry_load",0x91e,*(undefined4 *)((int)param_1 + 0x80));
        }
      }
      FUN_00407f30(DAT_007cbef0);
      return uVar2;
    }
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      __format = "<wserv>[warning]%s(): %d  -> uac_id_alloc fail!\r\n";
      uVar2 = 0x917;
LAB_005ec490:
      printf(__format,"wserv_db_entry_load",uVar2);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

