// func _wsta_intelligent_roam_set_rd_info_by_sta @ 00484fd0 size=708

/* WARNING: Removing unreachable block (ram,0x0048514c) */

undefined4 _wsta_intelligent_roam_set_rd_info_by_sta(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *__format;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int local_a8;
  undefined1 uStack_a4;
  char local_a3;
  undefined1 auStack_80 [8];
  char local_78;
  
  memset(auStack_80,0,0x54);
  memset(&uStack_a4,0,0x22);
  local_a8 = 0;
  if (param_1 == 0) {
    uVar7 = 1;
    if (wsta_roam_err_switch == '\0') {
      return 1;
    }
    __format = "[WSTA_ROAM_ERROR]%s()/%d input error\n";
    uVar6 = 0xb04;
  }
  else {
    iVar1 = wsta_roam_db_cfg_get(&uStack_a4);
    if (iVar1 == -1) {
      uVar7 = 1;
      if (wsta_roam_err_switch == '\0') {
        return 1;
      }
      __format = "[WSTA_ROAM_ERROR]%s()/%d stats_db_ctl_get failed\n";
      uVar6 = 0xb0a;
    }
    else {
      if (local_a3 == '\x02') {
        iVar1 = wsta_db_get_ap_sta_num(*(undefined2 *)(param_1 + 0x10));
        iVar2 = get_high_per_sta_cnt();
        iVar3 = get_high_per_ap_cnt();
        if (iVar3 == 0) {
          trap(7);
        }
        if (iVar2 / iVar3 <= iVar1) {
          return 0;
        }
        stats_db_sta_for_each_range_for_specify_ap
                  (_wsta_intelligent_roam_check_sta_is_active,&local_a8,
                   *(undefined2 *)(param_1 + 0x10));
        if (iVar2 / iVar3 <= local_a8) {
          return 0;
        }
        uVar4 = time((time_t *)0x0);
        srand(uVar4);
        iVar1 = rand();
        iVar2 = 1;
        uVar4 = (uint)(byte)(&UNK_00697379)[(uint)(iVar1 * 10) % 3];
        iVar1 = rand();
        uVar8 = (uint)(byte)(&UNK_0069737d)[iVar1 * 10 & 7];
        iVar1 = apdb_radio_count_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218);
        do {
          while( true ) {
            while( true ) {
              if (iVar1 < iVar2) {
                return 0;
              }
              uVar7 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar2);
              iVar3 = rdmngr_db_rd_entry_get(uVar7,auStack_80);
              if (iVar3 == 0) break;
              iVar2 = iVar2 + 1;
            }
            if (local_78 != '\0') break;
            if (uVar4 != 0) {
              uVar5 = uVar4;
              if (wsta_roam_debug_switch != '\0') {
                printf("[WSTA_ROAM_DEBUG]%s()/%d rd_id:%d, set chnl:%d\n",
                       "_wsta_intelligent_roam_set_rd_info_by_sta",0xb2b,uVar7,uVar4);
              }
LAB_004851e8:
              _uac_rdmngr_rd_chnl_set(uVar7,uVar5);
            }
LAB_004851f0:
            iVar2 = iVar2 + 1;
          }
          if (local_78 == '\x01') {
            if (uVar8 != 0) {
              uVar5 = uVar8;
              if (wsta_roam_debug_switch != '\0') {
                printf("[WSTA_ROAM_DEBUG]%s()/%d rd_id:%d, set chnl:%d\n",
                       "_wsta_intelligent_roam_set_rd_info_by_sta",0xb30,uVar7,uVar8);
              }
              goto LAB_004851e8;
            }
            goto LAB_004851f0;
          }
          iVar2 = iVar2 + 1;
        } while( true );
      }
      uVar7 = 2;
      if (wsta_roam_debug_switch == '\0') {
        return 2;
      }
      __format = "[WSTA_ROAM_DEBUG]%s()/%d no need to set chn info\n";
      uVar6 = 0xb0f;
    }
  }
  printf(__format,"_wsta_intelligent_roam_set_rd_info_by_sta",uVar6);
  return uVar7;
}

