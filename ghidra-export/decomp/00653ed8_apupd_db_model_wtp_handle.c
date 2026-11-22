// func apupd_db_model_wtp_handle @ 00653ed8 size=884

uint apupd_db_model_wtp_handle
               (uint param_1,int *param_2,undefined4 param_3,uint param_4,uint param_5,code *param_6
               ,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint local_12d8 [2];
  undefined1 auStack_12d0 [18];
  ushort local_12be;
  undefined4 local_12bc;
  uint auStack_ff8 [1010];
  int local_30;
  uint local_2c;
  
  local_12d8[0] = param_1;
  memset(auStack_12d0,0,0x2d8);
  memset(auStack_ff8,0,0xfc8);
  if (apupd_model_hash == 0) {
    uVar10 = 0xffffffff;
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar6 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar8 = 0x1e8e;
LAB_00653fc4:
    printf(pcVar6,"apupd_db_model_wtp_handle",uVar8);
    return uVar10;
  }
  if ((param_6 == (code *)0x0) || (param_5 == 0)) {
    uVar10 = 0;
    if (g_apupd_debug == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    pcVar6 = "[APUPD_DEBUG]%32s() %05d: nothing need be done.\r\n";
    uVar8 = 0x1e95;
    goto LAB_00653fc4;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  if (param_1 == 0xfffffffe) {
    iVar2 = FUN_004081b0(apupd_wtp_list);
    if (param_2 != (int *)0x0) {
      iVar1 = 0;
      if (*param_2 == 0) {
        iVar7 = param_2[0x1fa];
        iVar1 = 0;
        piVar5 = param_2;
        while (iVar1 < iVar7) {
          iVar1 = iVar1 + 1;
          if (*(ushort *)(piVar5 + 1) < 0x3f2) {
            auStack_ff8[*(ushort *)(piVar5 + 1)] = 1;
          }
          piVar5 = (int *)((int)piVar5 + 2);
        }
        iVar1 = 0;
      }
      goto LAB_00654010;
    }
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
    goto LAB_006541d0;
    pcVar6 = "[APUPD_ERROR]%32s() %05d: Input error.\r\n";
    uVar8 = 0x1ea0;
  }
  else {
    iVar1 = FUN_00407fa0(apupd_model_hash,local_12d8);
    if (iVar1 != 0) {
      iVar2 = FUN_004081b0(iVar1 + 0x7f4);
LAB_00654010:
      uVar10 = 0;
      local_2c = param_1 ^ 0xfffffffe;
      uVar9 = 0;
      do {
        while( true ) {
          do {
            if (iVar2 == 0) {
              FUN_00407f30(apupd_db_mutex);
              return uVar9;
            }
            local_30 = FUN_00408680(iVar2);
            iVar7 = iVar2 + -0xc;
            if (local_2c != 0) {
              iVar7 = iVar2;
            }
            iVar3 = apmngr_db_entry_get_by_mac(iVar7 + 0x2e,auStack_12d0);
            iVar2 = local_30;
          } while (iVar3 != 0);
          if (param_1 != 0xfffffffe) break;
          iVar3 = apmngr_db_role_match(local_12bc,param_3);
          iVar2 = local_30;
          if (iVar3 != 0) {
            if (*param_2 != 0) goto LAB_006540a8;
            if (local_12be < 0x3f2) {
              uVar4 = auStack_ff8[local_12be];
              goto LAB_0065409c;
            }
          }
        }
        if ((*(uint *)(iVar1 + 0x18) & 1) != 0) goto LAB_006540a8;
        if (local_12be < 0x200) {
          uVar4 = local_12be + 1;
          uVar4 = *(uint *)(iVar1 + (((int)uVar4 >> 5) + 6) * 4) >> (uVar4 & 0x1f) & 1;
LAB_0065409c:
          iVar2 = local_30;
          if (uVar4 != 0) {
LAB_006540a8:
            uVar9 = uVar9 + 1;
            iVar2 = local_30;
            if ((param_4 < uVar9) && (uVar10 < param_5)) {
              uVar10 = uVar10 + 1;
              (*param_6)(iVar7,param_7);
              iVar2 = local_30;
            }
          }
        }
      } while( true );
    }
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
    goto LAB_006541d0;
    pcVar6 = "[APUPD_ERROR]%32s() %05d: get model by id failed.\r\n";
    uVar8 = 0x1eb4;
  }
  printf(pcVar6,"apupd_db_model_wtp_handle",uVar8);
LAB_006541d0:
  FUN_00407f30(apupd_db_mutex);
  return 0xffffffff;
}

