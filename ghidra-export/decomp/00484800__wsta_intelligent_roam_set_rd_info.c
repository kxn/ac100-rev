// func _wsta_intelligent_roam_set_rd_info @ 00484800 size=936

undefined4 _wsta_intelligent_roam_set_rd_info(int param_1,char *param_2)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  char cVar5;
  char *__format;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 uStack_a0;
  char local_9f;
  undefined1 auStack_7c [8];
  char local_74;
  
  memset(auStack_7c,0,0x54);
  memset(&uStack_a0,0,0x22);
  if (param_1 == 0) {
    uVar7 = 1;
    if (wsta_roam_err_switch == '\0') {
      return 1;
    }
    __format = "[WSTA_ROAM_ERROR]%s()/%d input error\n";
    uVar6 = 0xa91;
  }
  else {
    iVar2 = wsta_roam_db_cfg_get(&uStack_a0);
    if (iVar2 == -1) {
      uVar7 = 1;
      if (wsta_roam_err_switch == '\0') {
        return 1;
      }
      __format = "[WSTA_ROAM_ERROR]%s()/%d stats_db_ctl_get failed\n";
      uVar6 = 0xa99;
    }
    else if (local_9f == '\x01') {
      psVar3 = (short *)get_high_per_ap_chn_info();
      if (psVar3 != (short *)0x0) {
        iVar2 = apdb_radio_count_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218);
        iVar8 = 1;
LAB_00484928:
        while( true ) {
          while( true ) {
            if (iVar2 < iVar8) {
              return 0;
            }
            uVar7 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar8);
            iVar4 = rdmngr_db_rd_entry_get(uVar7,auStack_7c);
            if (iVar4 == 0) break;
            iVar8 = iVar8 + 1;
          }
          if ((((local_74 == '\0') && (*psVar3 != 0)) &&
              ((param_2 == (char *)0x0 || (*param_2 == iVar8)))) &&
             (_uac_rdmngr_rd_chnl_bw_set(uVar7,(int)*psVar3,2), wsta_roam_debug_switch != '\0')) {
            printf("[WSTA_ROAM_DEBUG]%s()/%d rd_id:%d, set chnl:%d\n",
                   "_wsta_intelligent_roam_set_rd_info",0xab1,uVar7,(int)*psVar3);
          }
          if (local_74 == '\x01') break;
          iVar8 = iVar8 + 1;
        }
        if (iVar2 == 2) {
          if (param_2 == (char *)0x0) {
            sVar1 = psVar3[1];
LAB_00484b14:
            if (sVar1 != 0) {
              _uac_rdmngr_rd_chnl_bw_set(uVar7,(int)sVar1,2);
              if (wsta_roam_debug_switch != '\0') {
                iVar4 = (int)psVar3[1];
                uVar6 = 0xabb;
                goto LAB_00484a44;
              }
              iVar8 = iVar8 + 1;
              goto LAB_00484928;
            }
            if (param_2 != (char *)0x0) {
              cVar5 = *param_2;
              goto LAB_00484acc;
            }
            sVar1 = psVar3[2];
          }
          else {
            if (*param_2 == '\x02') {
              sVar1 = psVar3[1];
              goto LAB_00484b14;
            }
            cVar5 = *param_2;
LAB_00484acc:
            if (cVar5 != '\x03') {
              iVar8 = iVar8 + 1;
              goto LAB_00484928;
            }
            sVar1 = psVar3[2];
          }
          if (sVar1 == 0) {
            iVar8 = iVar8 + 1;
            goto LAB_00484928;
          }
          _uac_rdmngr_rd_chnl_bw_set(uVar7,(int)sVar1,2);
          if (wsta_roam_debug_switch == '\0') {
            iVar8 = iVar8 + 1;
            goto LAB_00484928;
          }
          iVar4 = (int)psVar3[2];
          uVar6 = 0xac0;
        }
        else {
          if (iVar2 != 3) {
            iVar8 = iVar8 + 1;
            goto LAB_00484928;
          }
          if (iVar8 != 2) {
            if (iVar8 == 3) {
              if (param_2 == (char *)0x0) {
                sVar1 = psVar3[2];
              }
              else {
                if (*param_2 != '\x03') {
                  iVar8 = 4;
                  goto LAB_00484928;
                }
                sVar1 = psVar3[2];
              }
              if (sVar1 == 0) {
                iVar8 = 4;
              }
              else {
                _uac_rdmngr_rd_chnl_bw_set(uVar7,(int)sVar1,2);
                if (wsta_roam_debug_switch != '\0') {
                  iVar4 = (int)psVar3[2];
                  uVar6 = 0xad1;
                  goto LAB_00484a44;
                }
                iVar8 = 4;
              }
              goto LAB_00484928;
            }
            iVar8 = iVar8 + 1;
            goto LAB_00484928;
          }
          if (param_2 == (char *)0x0) {
            sVar1 = psVar3[1];
          }
          else {
            if (*param_2 != '\x02') {
              iVar8 = 3;
              goto LAB_00484928;
            }
            sVar1 = psVar3[1];
          }
          if (sVar1 == 0) {
            iVar8 = 3;
            goto LAB_00484928;
          }
          _uac_rdmngr_rd_chnl_bw_set(uVar7,(int)sVar1,2);
          if (wsta_roam_debug_switch == '\0') {
            iVar8 = 3;
            goto LAB_00484928;
          }
          iVar4 = (int)psVar3[1];
          uVar6 = 0xaca;
        }
LAB_00484a44:
        printf("[WSTA_ROAM_DEBUG]%s()/%d rd_id:%d, set chnl:%d\n",
               "_wsta_intelligent_roam_set_rd_info",uVar6,uVar7,iVar4);
        iVar8 = iVar8 + 1;
        goto LAB_00484928;
      }
      uVar7 = 1;
      if (wsta_roam_err_switch == '\0') {
        return 1;
      }
      __format = "[WSTA_ROAM_ERROR]%s()/%d get_high_per_ap_chn_info failed\n";
      uVar6 = 0xaa3;
    }
    else {
      uVar7 = 2;
      if (wsta_roam_debug_switch == '\0') {
        return 2;
      }
      __format = "[WSTA_ROAM_DEBUG]%s()/%d no need to set chn info\n";
      uVar6 = 0xa9e;
    }
  }
  printf(__format,"_wsta_intelligent_roam_set_rd_info",uVar6);
  return uVar7;
}

