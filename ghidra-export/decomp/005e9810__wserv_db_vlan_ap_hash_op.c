// func _wserv_db_vlan_ap_hash_op @ 005e9810 size=912

undefined4 _wserv_db_vlan_ap_hash_op(int param_1,uint param_2,int param_3,int param_4)

{
  char cVar1;
  undefined4 *__s;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  size_t __n;
  int *piVar8;
  uint uVar9;
  undefined4 *puVar10;
  char *pcVar11;
  undefined4 local_30 [3];
  
  param_1 = param_1 * 4;
  local_30[0] = 0xffffffff;
  local_30[0] = rdmngr_db_generate_ap_id(param_2);
  if (param_4 == 0) {
    if (*(int *)(DAT_007cbf08 + param_1) == 0) {
      return 0xffffffff;
    }
    iVar3 = FUN_00407fa0(*(int *)(DAT_007cbf08 + param_1),local_30);
    if (iVar3 != 0) {
      pcVar11 = (char *)(*(int *)(iVar3 + (((param_2 & 0xf) - 1 & 0xff) + 2) * 4) + param_3 + -1);
      cVar1 = *pcVar11;
      uVar9 = 0;
      iVar4 = iVar3;
      if (cVar1 != '\0') {
        *pcVar11 = cVar1 + -1;
      }
      do {
        uVar6 = rdmngr_profile_get_max_rd_per_ap();
        if (uVar6 <= uVar9) {
          FUN_00407f40(*(undefined4 *)(DAT_007cbf08 + param_1),iVar3);
          FUN_00407df0(iVar3);
          if (*(int *)(*(int *)(DAT_007cbf08 + param_1) + 0x10) == 0) {
            FUN_00408310();
            *(undefined4 *)(DAT_007cbf08 + param_1) = 0;
            return 0;
          }
          return 0;
        }
        uVar6 = 0;
        while (uVar2 = rdmngr_profile_get_max_wlan_per_rd(), uVar6 < uVar2) {
          pcVar11 = (char *)(*(int *)(iVar4 + 8) + uVar6);
          uVar6 = uVar6 + 1;
          if (*pcVar11 != '\0') {
            return 0;
          }
        }
        uVar9 = uVar9 + 1;
        iVar4 = iVar4 + 4;
      } while( true );
    }
    return 0;
  }
  piVar8 = (int *)(DAT_007cbf08 + param_1);
  if (*piVar8 == 0) {
    iVar3 = FUN_004086f0(_wserv_ap_hash_obj,_wserv_ap_hash_key,_wserv_ap_hash_cmp);
    *piVar8 = iVar3;
    if (*(int *)(DAT_007cbf08 + param_1) == 0) {
      if (g_wserv_error == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      pcVar11 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
      uVar7 = 0x366;
      goto LAB_005e9b08;
    }
  }
  __s = (undefined4 *)FUN_00407fa0(*(undefined4 *)(DAT_007cbf08 + param_1),local_30);
  if (__s != (undefined4 *)0x0) {
LAB_005e98a0:
    pcVar11 = (char *)(__s[((param_2 & 0xf) - 1 & 0xff) + 2] + param_3 + -1);
    *pcVar11 = *pcVar11 + '\x01';
    return 0;
  }
  iVar3 = rdmngr_profile_get_max_rd_per_ap();
  iVar4 = rdmngr_profile_get_max_rd_per_ap();
  iVar5 = rdmngr_profile_get_max_wlan_per_rd();
  __n = (iVar3 + 2) * 4 + iVar5 * iVar4;
  __s = (undefined4 *)wserv_malloc(__n);
  if (__s == (undefined4 *)0x0) {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    pcVar11 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
    uVar7 = 0x371;
  }
  else {
    memset(__s,0,__n);
    uVar9 = 0;
    *(undefined1 *)(__s + 1) = 0;
    *__s = local_30[0];
    puVar10 = __s;
    while( true ) {
      uVar6 = rdmngr_profile_get_max_rd_per_ap();
      if (uVar6 <= uVar9) break;
      iVar3 = rdmngr_profile_get_max_rd_per_ap();
      iVar4 = rdmngr_profile_get_max_wlan_per_rd();
      iVar4 = iVar4 * uVar9;
      uVar9 = uVar9 + 1;
      puVar10[2] = (int)__s + (iVar3 + 2) * 4 + iVar4;
      puVar10 = puVar10 + 1;
    }
    iVar3 = FUN_00408380(*(undefined4 *)(DAT_007cbf08 + param_1));
    if (iVar3 == 0) goto LAB_005e98a0;
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    pcVar11 = "<wserv>[error]%s(): %d  -> uac_hash_add() fail!\r\n";
    uVar7 = 0x37d;
  }
LAB_005e9b08:
  printf(pcVar11,"_wserv_db_vlan_ap_hash_op",uVar7);
  return 0xffffffff;
}

