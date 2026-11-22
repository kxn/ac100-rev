// func dhcpdef_db_apbind_entry_deep_get @ 00469ba8 size=1

undefined4 dhcpdef_db_apbind_entry_deep_get(char *param_1,void *param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *__format;
  void *__src;
  undefined4 uVar7;
  void *__dest;
  uint uVar8;
  uint uVar9;
  
  if (param_2 == (void *)0x0) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    param_1 = "entry";
    __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
    uVar7 = 0x3ec;
    goto code_r0x00469d98;
  }
  if (-1 < (int)param_1) {
    iVar3 = apmngr_db_get_ap_max();
    iVar4 = apmngr_db_get_template_max();
    if (((int)param_1 < iVar3 + iVar4) ||
       ((49999 < (int)param_1 && (iVar3 = apmngr_db_get_sensor_max(), (int)param_1 < iVar3 + 50000))
       )) {
      FUN_004082d0(DAT_00767094,0xffffffff);
      iVar3 = DAT_007670a8;
      uVar5 = (uint)((int)param_1 < 50000);
      iVar4 = (int)param_1 * 0x11;
      if (uVar5 == 0) {
        iVar4 = apmngr_db_get_ap_max();
        uVar5 = apmngr_db_get_template_max();
        iVar4 = (int)(param_1 + uVar5 + iVar4 + -50000) * 0x11;
      }
      iVar6 = DAT_007670a8;
      uVar9 = iVar3 + iVar4;
      uVar1 = uVar9 & 3;
      uVar8 = uVar9 + 3 & 3;
      if ((int)((*(int *)(uVar9 - uVar1) << uVar1 * 8 | uVar5 & 0xffffffffU >> (4 - uVar1) * 8) &
                -1 << (uVar8 + 1) * 8 | *(uint *)((uVar9 + 3) - uVar8) >> (3 - uVar8) * 8) < 0) {
code_r0x00469dac:
        iVar3 = DAT_007670a8;
        uVar5 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar4 = apmngr_db_get_ap_max();
          iVar6 = apmngr_db_get_template_max();
          uVar5 = (int)(param_1 + iVar6 + iVar4 + -50000) * 0x11;
        }
        iVar4 = DAT_007670a8;
        uVar9 = iVar3 + uVar5;
        uVar1 = uVar9 & 3;
        uVar8 = uVar9 + 3 & 3;
        if (49999 < (int)((*(int *)(uVar9 - uVar1) << uVar1 * 8 |
                          uVar5 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar8 + 1) * 8 |
                         *(uint *)((uVar9 + 3) - uVar8) >> (3 - uVar8) * 8)) {
          iVar3 = (int)param_1 * 0x11;
          if (49999 < (int)param_1) {
            iVar3 = apmngr_db_get_ap_max();
            iVar6 = apmngr_db_get_template_max();
            iVar3 = (int)(param_1 + iVar6 + iVar3 + -50000) * 0x11;
          }
          uVar8 = iVar4 + iVar3;
          uVar5 = uVar8 & 3;
          iVar3 = *(int *)(uVar8 - uVar5);
          uVar1 = uVar8 + 3 & 3;
          uVar8 = *(uint *)((uVar8 + 3) - uVar1);
          iVar4 = apmngr_db_get_sensor_max();
          uVar5 = (uint)((int)((iVar3 << uVar5 * 8 | 0xffffffffU >> (4 - uVar5) * 8 & 50000) &
                               -1 << (uVar1 + 1) * 8 | uVar8 >> (3 - uVar1) * 8) < iVar4 + 50000);
          if (uVar5 != 0) goto code_r0x00469ca8;
        }
        uVar7 = 0xffffffff;
        if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("\x1b[31;49m[%s]<%s():%d> ap_id[%d] is not used!\x1b[0m\r\n","dhcp_defend",
                 "dhcpdef_db_apbind_entry_deep_get",0x3f0,param_1);
        }
      }
      else {
        iVar3 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar3 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          iVar3 = (int)(param_1 + iVar4 + iVar3 + -50000) * 0x11;
        }
        uVar8 = iVar6 + iVar3;
        uVar5 = uVar8 & 3;
        iVar3 = *(int *)(uVar8 - uVar5);
        uVar1 = uVar8 + 3 & 3;
        uVar8 = *(uint *)((uVar8 + 3) - uVar1);
        iVar4 = apmngr_db_get_ap_max();
        iVar6 = apmngr_db_get_template_max();
        uVar5 = (uint)((int)((iVar3 << uVar5 * 8 | 0xffffffffU >> (4 - uVar5) * 8 & 0x11) &
                             -1 << (uVar1 + 1) * 8 | uVar8 >> (3 - uVar1) * 8) < iVar4 + iVar6);
        if (uVar5 == 0) goto code_r0x00469dac;
code_r0x00469ca8:
        iVar3 = DAT_007670a8;
        uVar1 = (int)param_2 + 0xdU & 3;
        uVar8 = (int)param_2 + 0x10U & 3;
        __dest = (void *)((*(int *)(((int)param_2 + 0xdU) - uVar1) << uVar1 * 8 |
                          uVar5 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar8 + 1) * 8 |
                         *(uint *)(((int)param_2 + 0x10U) - uVar8) >> (3 - uVar8) * 8);
        iVar4 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar4 = apmngr_db_get_ap_max();
          iVar6 = apmngr_db_get_template_max();
          iVar4 = (int)(param_1 + iVar6 + iVar4 + -50000) * 0x11;
        }
        __src = (void *)(iVar3 + iVar4);
        memcpy(param_2,__src,0x11);
        iVar3 = DAT_007670a8;
        if (__dest != (void *)0x0) {
          iVar4 = (int)param_1 * 0x11;
          if (49999 < (int)param_1) {
            iVar4 = apmngr_db_get_ap_max();
            iVar6 = apmngr_db_get_template_max();
            iVar4 = (int)(param_1 + iVar6 + iVar4 + -50000) * 0x11;
          }
          uVar5 = iVar3 + iVar4 + 0xd;
          uVar8 = uVar5 & 3;
          uVar1 = iVar3 + iVar4 + 0x10;
          uVar9 = uVar1 & 3;
          memcpy(__dest,(void *)((*(int *)(uVar5 - uVar8) << uVar8 * 8 |
                                 (uint)__src & 0xffffffffU >> (4 - uVar8) * 8) &
                                 -1 << (uVar9 + 1) * 8 | *(uint *)(uVar1 - uVar9) >> (3 - uVar9) * 8
                                ),DAT_0076708c << 2);
        }
        uVar5 = (int)param_2 + 0xdU & 3;
        puVar2 = (uint *)(((int)param_2 + 0xdU) - uVar5);
        *puVar2 = *puVar2 & -1 << (4 - uVar5) * 8 | (uint)__dest >> uVar5 * 8;
        uVar7 = 0;
        uVar5 = (int)param_2 + 0x10U & 3;
        puVar2 = (uint *)(((int)param_2 + 0x10U) - uVar5);
        *puVar2 = *puVar2 & 0xffffffffU >> (uVar5 + 1) * 8 | (int)__dest << (3 - uVar5) * 8;
      }
      FUN_00407f30(DAT_00767094);
      return uVar7;
    }
  }
  if (g_dhcpdef_error == 0) {
    return 0xffffffff;
  }
  iVar3 = is_target_debug_ap();
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  __format = "\x1b[31;49m[%s]<%s():%d> Invalid ap_id[%d]!\x1b[0m\r\n";
  uVar7 = 0x3ed;
code_r0x00469d98:
  printf(__format,"dhcp_defend","dhcpdef_db_apbind_entry_deep_get",uVar7,param_1);
  return 0xffffffff;
}

