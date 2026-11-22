// func _apmngr_db_get_addr_by_capa @ 00539f0c size=828

/* WARNING: Removing unreachable block (ram,0x00539ff4) */

undefined4 _apmngr_db_get_addr_by_capa(int param_1,undefined4 *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__format;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined1 auStack_2f0 [12];
  int local_2e4;
  int local_2d4;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined2 local_70;
  int local_44;
  
  memset(auStack_2f0,0,0x2d8);
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
    iVar6 = *(int *)(param_1 + 0x14);
LAB_00539fa8:
    if ((1 << (iVar6 + 0x10U & 0x1f) & param_2[3]) != 0) {
      iVar4 = 0;
      iVar5 = 0;
      while (iVar5 < (int)param_2[4]) {
        iVar2 = *(int *)(param_2[5] + iVar4);
        if (param_2[1] == 0) {
          iVar3 = iVar2;
          if (iVar2 < 0) {
            iVar3 = iVar2 + 0x1f;
          }
          iVar5 = iVar5 + 1;
          if ((1 << (iVar2 % 0x20 & 0x1fU) & *(uint *)(param_1 + ((iVar3 >> 5) + 0x94) * 4)) != 0) {
            return 0;
          }
          iVar4 = iVar4 + 4;
        }
        else {
          iVar3 = iVar2;
          if (iVar2 < 0) {
            iVar3 = iVar2 + 0x1f;
          }
          if ((1 << (iVar2 % 0x20 & 0x1fU) & *(uint *)(param_1 + ((iVar3 >> 5) + 0x94) * 4)) == 0) {
            return 0;
          }
          iVar5 = iVar5 + 1;
          iVar4 = iVar4 + 4;
        }
      }
      if (iVar6 != 5) {
        serv_wtp_address_arg_add
                  (*param_2,*(undefined4 *)(param_1 + 0x26c),*(undefined4 *)(param_1 + 0x270),
                   *(undefined4 *)(param_1 + 0x274),*(undefined4 *)(param_1 + 0x278),
                   *(undefined4 *)(param_1 + 0x27c),*(undefined2 *)(param_1 + 0x280),param_1 + 0x48,
                   0);
        return 0;
      }
      sVar1 = *(short *)(param_1 + 0x18);
      uVar8 = (uint)sVar1;
      if (sVar1 == -1) {
        return 0;
      }
      iVar6 = apmngr_db_entry_get_by_id(sVar1,auStack_2f0);
      if (iVar6 != 0) {
        return 0;
      }
      if ((local_2d4 == 0) || (local_2e4 == 0)) {
        if (apmngr_debug_switch == '\0') {
          return 0;
        }
        iVar6 = is_target_debug_ap();
        if (iVar6 == 0) {
          return 0;
        }
        __format = "[APMNGR_DEBUG]%s()/%d cap(%d) is not used\n";
        uVar7 = 0x3e9;
      }
      else {
        if (local_44 - 2U < 2) {
          serv_wtp_address_arg_add
                    (*param_2,local_84,local_80,local_7c,local_78,local_74,local_70,param_1 + 0x48,1
                    );
          return 0;
        }
        if (apmngr_debug_switch == '\0') {
          return 0;
        }
        iVar6 = is_target_debug_ap();
        if (iVar6 == 0) {
          return 0;
        }
        __format = "[APMNGR_DEBUG]%s()/%d cap(%d) is not in right state\n";
        uVar7 = 0x3ee;
      }
      goto LAB_0053a074;
    }
    if (apmngr_debug_switch == '\0') {
      return 0;
    }
    iVar6 = is_target_debug_ap();
    if (iVar6 == 0) {
      return 0;
    }
    __format = "[APMNGR_DEBUG]%s()/%d ap(%d) role is not matched\n";
    uVar7 = 0x3ce;
  }
  else {
    iVar6 = multi_link_status_get(*(undefined2 *)(param_1 + 0x10));
    if (iVar6 != 0) {
      iVar6 = *(int *)(param_1 + 0x14);
      goto LAB_00539fa8;
    }
    if (apmngr_debug_switch == '\0') {
      return 0;
    }
    iVar6 = is_target_debug_ap();
    if (iVar6 == 0) {
      return 0;
    }
    __format = "[APMNGR_DEBUG]%s()/%d ap(%d) is not in master link state\n";
    uVar7 = 0x3c9;
  }
  uVar8 = (uint)*(ushort *)(param_1 + 0x10);
LAB_0053a074:
  printf(__format,"_apmngr_db_get_addr_by_capa",uVar7,uVar8);
  return 0;
}

