// func _apmngr_db_get_addr_by_sub_capa @ 00539a50 size=1212

/* WARNING: Removing unreachable block (ram,0x00539cf4) */
/* WARNING: Removing unreachable block (ram,0x00539ca8) */

undefined4 _apmngr_db_get_addr_by_sub_capa(int param_1,undefined4 *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  short sVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  undefined1 auStack_308 [12];
  int local_2fc;
  int local_2ec;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined2 local_88;
  int local_5c;
  byte *local_30;
  
  memset(auStack_308,0,0x2d8);
  if (param_1 == 0) {
    return 1;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 1;
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    return 0;
  }
  if (1 < *(int *)(param_1 + 0x2ac) - 2U) {
    return 0;
  }
  if (param_2[2] == 0) {
    iVar7 = *(int *)(param_1 + 0x14);
LAB_00539b14:
    if ((1 << (iVar7 + 0x10U & 0x1f) & param_2[3]) != 0) {
      uVar8 = apmngr_db_get_sub_capability_idx(param_2[4]);
      if (2 < uVar8) {
        uVar14 = 1;
        if (apmngr_err_switch == '\0') {
          return 1;
        }
        iVar7 = is_target_debug_ap();
        if (iVar7 == 0) {
          return 1;
        }
        uVar9 = param_2[4];
        uVar6 = *(ushort *)(param_1 + 0x10);
        pcVar12 = "[APMNGR_ERROR]%s()/%d ap_id(%d), main_cap(%d) no sub capability idx\n";
        uVar13 = 0x41e;
LAB_00539b88:
        printf(pcVar12,"_apmngr_db_get_addr_by_sub_capa",uVar13,(uint)uVar6,uVar9);
        return uVar14;
      }
      iVar7 = 0;
      local_30 = (byte *)(param_1 + (uVar8 + 0x98) * 4);
      for (iVar15 = 0; iVar15 < (int)param_2[5]; iVar15 = iVar15 + 1) {
        bVar1 = *local_30;
        iVar10 = param_1 + uVar8 * 4;
        bVar2 = *(byte *)(iVar10 + 0x261);
        bVar3 = *(byte *)(iVar10 + 0x262);
        bVar4 = *(byte *)(iVar10 + 0x263);
        if (apmngr_warning_switch == '\0') {
          iVar10 = param_2[6];
        }
        else {
          iVar11 = is_target_debug_ap();
          iVar10 = param_2[6];
          if (iVar11 != 0) {
            printf("[APMNGR_WARNING]%s()/%d ap_entry->run_info.sub_capability[%d].cap[0]=%d,cap[1]=%d,cap[2]=%d,cap[3]=%d, item->sub_cap[%d]=%d\n"
                   ,"_apmngr_db_get_addr_by_sub_capa",0x42a,uVar8,(uint)bVar1,(uint)bVar2,
                   (uint)bVar3,(uint)bVar4,iVar15,*(undefined4 *)(iVar10 + iVar7));
            iVar10 = param_2[6];
          }
        }
        iVar10 = *(int *)(iVar10 + iVar7);
        if (param_2[1] == 0) {
          iVar11 = iVar10 + 7;
          if (-1 < iVar10) {
            iVar11 = iVar10;
          }
          if (((int)(uint)*(byte *)(((param_1 + uVar8 * 4) - (iVar11 >> 3)) + 0x263) >>
               (iVar10 % 8 & 0x1fU) & 1U) != 0) goto LAB_00539d18;
        }
        else {
          iVar11 = iVar10 + 7;
          if (-1 < iVar10) {
            iVar11 = iVar10;
          }
          if (((int)(uint)*(byte *)(((param_1 + uVar8 * 4) - (iVar11 >> 3)) + 0x263) >>
               (iVar10 % 8 & 0x1fU) & 1U) == 0) {
LAB_00539d18:
            uVar14 = 0;
            if (apmngr_warning_switch == '\0') {
              return 0;
            }
            iVar7 = is_target_debug_ap();
            if (iVar7 == 0) {
              return 0;
            }
            uVar9 = param_2[4];
            uVar6 = *(ushort *)(param_1 + 0x10);
            pcVar12 = 
            "[APMNGR_WARNING]%s()/%d ap_id(%d), main_cap(%d) sub_capability(%d) not support\n";
            uVar13 = 0x42e;
            goto LAB_00539b88;
          }
        }
        iVar7 = iVar7 + 4;
      }
      if (*(int *)(param_1 + 0x14) != 5) {
        serv_wtp_address_arg_add
                  (*param_2,*(undefined4 *)(param_1 + 0x26c),*(undefined4 *)(param_1 + 0x270),
                   *(undefined4 *)(param_1 + 0x274),*(undefined4 *)(param_1 + 0x278),
                   *(undefined4 *)(param_1 + 0x27c),*(undefined2 *)(param_1 + 0x280),param_1 + 0x48,
                   0);
        return 0;
      }
      sVar5 = *(short *)(param_1 + 0x18);
      uVar8 = (uint)sVar5;
      if (sVar5 == -1) {
        return 0;
      }
      iVar7 = apmngr_db_entry_get_by_id(sVar5,auStack_308);
      if (iVar7 != 0) {
        return 0;
      }
      if ((local_2ec == 0) || (local_2fc == 0)) {
        if (apmngr_debug_switch == '\0') {
          return 0;
        }
        iVar7 = is_target_debug_ap();
        if (iVar7 == 0) {
          return 0;
        }
        pcVar12 = "[APMNGR_DEBUG]%s()/%d cap(%d) is not used\n";
        uVar14 = 0x443;
      }
      else {
        if (local_5c - 2U < 2) {
          serv_wtp_address_arg_add
                    (*param_2,local_9c,local_98,local_94,local_90,local_8c,local_88,param_1 + 0x48,1
                    );
          return 0;
        }
        if (apmngr_debug_switch == '\0') {
          return 0;
        }
        iVar7 = is_target_debug_ap();
        if (iVar7 == 0) {
          return 0;
        }
        pcVar12 = "[APMNGR_DEBUG]%s()/%d cap(%d) is not in right state\n";
        uVar14 = 0x448;
      }
      goto LAB_00539bcc;
    }
    if (apmngr_debug_switch == '\0') {
      return 0;
    }
    iVar7 = is_target_debug_ap();
    if (iVar7 == 0) {
      return 0;
    }
    pcVar12 = "[APMNGR_DEBUG]%s()/%d ap(%d) role is not matched\n";
    uVar14 = 0x416;
  }
  else {
    iVar7 = multi_link_status_get(*(undefined2 *)(param_1 + 0x10));
    if (iVar7 != 0) {
      iVar7 = *(int *)(param_1 + 0x14);
      goto LAB_00539b14;
    }
    if (apmngr_debug_switch == '\0') {
      return 0;
    }
    iVar7 = is_target_debug_ap();
    if (iVar7 == 0) {
      return 0;
    }
    pcVar12 = "[APMNGR_DEBUG]%s()/%d ap(%d) is not in master link state\n";
    uVar14 = 0x411;
  }
  uVar8 = (uint)*(ushort *)(param_1 + 0x10);
LAB_00539bcc:
  printf(pcVar12,"_apmngr_db_get_addr_by_sub_capa",uVar14,uVar8);
  return 0;
}

