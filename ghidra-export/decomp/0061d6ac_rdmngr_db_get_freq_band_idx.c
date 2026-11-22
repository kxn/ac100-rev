// func rdmngr_db_get_freq_band_idx @ 0061d6ac size=608

undefined4 rdmngr_db_get_freq_band_idx(uint param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *__format;
  undefined4 uVar6;
  uint uVar7;
  undefined1 auStack_2f8 [16];
  ushort local_2e8;
  undefined4 local_2b8;
  undefined1 auStack_e0 [192];
  
  memset(auStack_2f8,0,0x2d8);
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id(param_1);
  iVar5 = DAT_007cc65c;
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    if (((uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) && (param_2 != (int *)0x0)) &&
       (param_3 != (int *)0x0)) {
      uVar1 = (param_1 << 4) >> 8;
      iVar5 = apmngr_db_entry_get_by_id(uVar1 & 0xffff,auStack_2f8);
      if (iVar5 == 0) {
        iVar5 = apdb_radio_count_by_id(local_2b8,auStack_e0);
        if (iVar5 == -1) {
          if (rdmngr_err_switch == 0) {
            return 0xffffffff;
          }
          iVar5 = is_target_debug_ap();
          if (iVar5 == 0) {
            return 0xffffffff;
          }
          printf("[RDMNGR_ERROR]%s()/%d apdb_radio_count_by_id() fail.\n",
                 "rdmngr_db_get_freq_band_idx",0x8f5);
          return 0xffffffff;
        }
        uVar1 = param_1 & 0xf;
        if ((uVar1 != 0) && ((int)uVar1 <= iVar5)) {
          uVar7 = 1;
          iVar3 = 0;
          iVar2 = 0;
          while( true ) {
            iVar4 = rdmngr_db_get_rd_freq_band(uVar7 & 0xf | (uint)local_2e8 << 4);
            if (iVar4 == 0) {
              iVar2 = iVar2 + 1;
            }
            else {
              iVar3 = iVar3 + (uint)(iVar4 == 1);
            }
            if (uVar7 == uVar1) break;
            uVar7 = uVar7 + 1;
            if (iVar5 < (int)uVar7) {
              return 0xffffffff;
            }
          }
          if (iVar4 != 0) {
            iVar2 = iVar3;
          }
          *param_2 = iVar4;
          *param_3 = iVar2;
          return 0;
        }
        if (rdmngr_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        __format = "[RDMNGR_ERROR]%s()/%d Illegal rdx:%d.\n";
        uVar6 = 0x8fb;
      }
      else {
        if (rdmngr_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        __format = "[RDMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id() fail:%d.\n";
        uVar6 = 0x8ef;
      }
      goto LAB_0061d7ec;
    }
  }
  if (rdmngr_err_switch == 0) {
    return 0xffffffff;
  }
  iVar5 = is_target_debug_ap();
  if (iVar5 == 0) {
    return 0xffffffff;
  }
  __format = "[RDMNGR_ERROR]%s()/%d idx[%d] is invalid or input error!\n";
  uVar6 = 0x8e9;
  uVar1 = param_1;
LAB_0061d7ec:
  printf(__format,"rdmngr_db_get_freq_band_idx",uVar6,uVar1);
  return 0xffffffff;
}

