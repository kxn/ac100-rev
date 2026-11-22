// func rdmngr_db_is_ap_all_rd_disabled @ 0061c544 size=568

bool rdmngr_db_is_ap_all_rd_disabled(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  undefined4 local_310 [2];
  undefined1 auStack_308 [64];
  undefined4 local_2c8;
  undefined1 auStack_f0 [192];
  uint local_30;
  
  local_310[0] = 0;
  iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_308);
  if (iVar1 == -1) {
    if (rdmngr_err_switch != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return true;
      }
      printf("[RDMNGR_ERROR]%s()/%d get ap entry by id failed.\n","rdmngr_db_is_ap_all_rd_disabled",
             0xd08);
      return true;
    }
  }
  else {
    iVar1 = rdmngr_db_get_ap_radio_cnt(local_2c8,auStack_f0,local_310);
    if (-1 < iVar1) {
      uVar8 = 1;
      FUN_004082d0(DAT_007cc64c,0xffffffff);
      local_30 = param_1 << 4;
      while (cVar7 = '\0', (int)uVar8 <= iVar1) {
        uVar2 = rdmngr_db_generate_rd_idx_by_rd_id(uVar8 & 0xf | local_30);
        iVar6 = DAT_007cc65c;
        if ((int)uVar2 < 0) {
LAB_0061c6d8:
          if (rdmngr_err_switch == 0) {
            uVar8 = uVar8 + 1;
          }
          else {
            iVar6 = is_target_debug_ap();
            if (iVar6 == 0) {
              uVar8 = uVar8 + 1;
            }
            else {
              printf("[RDMNGR_ERROR]%s()/%d idx[%d] is invalid!\n","rdmngr_db_is_ap_all_rd_disabled"
                     ,0xd1e,uVar2);
              uVar8 = uVar8 + 1;
            }
          }
        }
        else {
          iVar3 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          iVar5 = apmngr_db_get_sensor_max();
          if (((uint)((iVar3 + iVar4 + iVar5) * iVar6) <= uVar2) ||
             (iVar6 = *(int *)(DAT_007cc650 + uVar2 * 8 + 4), iVar6 == 0)) goto LAB_0061c6d8;
          cVar7 = *(char *)(iVar6 + 0x48);
          if (cVar7 != '\0') break;
          uVar8 = uVar8 + 1;
        }
      }
      FUN_00407f30(DAT_007cc64c);
      return cVar7 == '\0';
    }
    if (rdmngr_err_switch != 0) {
      iVar6 = is_target_debug_ap();
      if (iVar6 == 0) {
        return true;
      }
      printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n",
             "rdmngr_db_is_ap_all_rd_disabled",0xd12,iVar1);
      return true;
    }
  }
  return true;
}

