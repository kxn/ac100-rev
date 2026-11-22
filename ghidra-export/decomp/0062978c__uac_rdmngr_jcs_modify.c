// func _uac_rdmngr_jcs_modify @ 0062978c size=10372

/* WARNING: Removing unreachable block (ram,0x006299e4) */

void _uac_rdmngr_jcs_modify(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar7;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  undefined1 uVar8;
  int iVar6;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  bool bVar12;
  undefined8 uVar13;
  undefined1 local_6d8 [80];
  undefined1 auStack_688 [8];
  char local_680;
  short local_67c;
  undefined4 local_634;
  undefined4 local_630;
  undefined4 local_62c;
  undefined4 local_628;
  undefined2 local_624;
  undefined2 local_622;
  undefined2 local_61e;
  undefined1 local_61c;
  undefined1 local_61b;
  undefined2 local_61a;
  undefined1 local_618;
  undefined2 local_616;
  undefined2 local_614;
  undefined2 local_612;
  undefined2 local_610;
  undefined1 local_60e;
  undefined1 local_60d;
  undefined1 local_60c;
  undefined1 local_60b;
  undefined1 local_60a;
  undefined1 local_609;
  undefined1 local_608;
  undefined1 local_607;
  undefined1 local_606;
  undefined1 local_605;
  undefined1 local_604;
  undefined1 local_603;
  undefined1 local_602;
  undefined1 local_601;
  undefined1 local_600;
  undefined1 local_5ff;
  undefined1 local_5fe;
  undefined1 local_5fd;
  undefined1 local_5fc;
  undefined1 local_5fb;
  undefined1 local_5f3;
  undefined1 local_5f2;
  undefined1 local_5f1;
  undefined1 local_5f0;
  undefined2 local_5ee;
  char local_5ec;
  char local_5eb;
  undefined1 auStack_5e0 [728];
  undefined1 auStack_308 [64];
  undefined4 local_2c8;
  undefined1 auStack_f0 [192];
  int local_30;
  
  memset(&local_634,0,0x54);
  memset(auStack_688,0,0x54);
  memset(auStack_308,0,0x2d8);
  iVar1 = json_object_object_get(param_1,"rf_id");
  if (iVar1 == 0) {
    pcVar9 = (char *)0xffffffff;
    if (rdmngr_err_switch == 0) goto LAB_0062986c;
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) goto LAB_00629870;
    pcVar9 = "[RDMNGR_ERROR]%s()/%d %s not found!\n";
    uVar3 = 0x5d6;
    pcVar10 = "rf_id";
LAB_00629a5c:
    printf(pcVar9,"_uac_rdmngr_jcs_modify",uVar3,pcVar10);
    pcVar9 = (char *)0xffffffff;
    goto LAB_00629870;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 3) {
    pcVar10 = (char *)json_object_get_int(iVar1);
  }
  else {
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar13 = json_object_get_double(iVar1);
      pcVar10 = (char *)__fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
    }
    else {
      pcVar10 = (char *)0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_uac_rdmngr_jcs_modify",0x5d7);
      }
    }
  }
  uVar7 = rdmngr_db_generate_ap_id(pcVar10);
  iVar1 = apmngr_db_entry_get_by_id(uVar7,auStack_308);
  if ((iVar1 == 0) && (iVar1 = rdmngr_db_rd_entry_get(pcVar10,&local_634), iVar1 == 0)) {
    local_30 = (int)local_5ec;
    memcpy(auStack_688,&local_634,0x54);
    iVar1 = json_object_object_get(param_1,"rf_state");
    if (iVar1 == 0) {
LAB_00629998:
      if (jcs_err_switch == 0) {
        bVar12 = true;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_rdmngr_jcs_modify"
               ,0x5e3);
        bVar12 = true;
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      iVar11 = 0;
      if (iVar2 != 6) {
        if (jcs_err_switch != 0) {
          pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_00629984:
          printf(pcVar9,"_uac_rdmngr_jcs_modify",0x5e3);
        }
        goto LAB_00629998;
      }
      do {
        while( true ) {
          if (onoff_map <= iVar11) {
            if (jcs_err_switch == 0) goto LAB_00629998;
            pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
            goto LAB_00629984;
          }
          iVar2 = iVar11 * 0x10;
          pcVar9 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
          if (pcVar9 != (char *)0x0) break;
          iVar11 = iVar11 + 1;
        }
        pcVar5 = (char *)json_object_get_string(iVar1);
        iVar6 = strcmp(pcVar9,pcVar5);
        iVar11 = iVar11 + 1;
      } while (iVar6 != 0);
      bVar12 = *(int *)(PTR__mt_onoff_00731f8c + iVar2 + 8) != 0 ||
               *(int *)(PTR__mt_onoff_00731f8c + iVar2 + 0xc) != 0;
    }
    if (bVar12 == false) {
      memset(auStack_5e0,0,0x2d8);
      memset(auStack_5e0,0,0x2d8);
      rdmngr_db_rd_entry_disable(local_634);
      local_5ec = bVar12;
      uVar7 = rdmngr_db_generate_ap_id(local_634);
      iVar1 = apmngr_db_entry_get_by_id(uVar7,auStack_5e0);
      if ((iVar1 == 0) && (iVar1 = apmngr_checksum_update(auStack_5e0,0), iVar1 == 0)) {
        uVar3 = rdmngr_db_generate_ap_id(local_634);
        iVar1 = rdmngr_wtp_pkt_send(uVar3,&local_634);
        if (iVar1 == 0) {
          rdmngr_callback_proc(0,local_634,0,0);
          rdmngr_trigger_radio_onoff_nms_event(local_634,0);
          pcVar9 = pcVar10;
          goto LAB_00629870;
        }
        if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          pcVar9 = "[RDMNGR_ERROR]%s()/%d rdmngr_wtp_pkt_send() failed.\n";
          uVar3 = 0x4e4;
          goto LAB_00629bbc;
        }
      }
      else {
        pcVar9 = (char *)0xffffffff;
        if (rdmngr_err_switch != 0) {
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) goto LAB_00629870;
          pcVar9 = "[RDMNGR_ERROR]%s()/%d update md5 failed.\n";
          uVar3 = 0x4df;
LAB_00629bbc:
          printf(pcVar9,"_uac_rdmngr_jcs_op_single",uVar3);
          pcVar9 = (char *)0xffffffff;
          goto LAB_00629870;
        }
      }
    }
    else {
      iVar1 = json_object_object_get(param_1,"freq_band");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          uVar8 = json_object_get_int(iVar1);
          local_62c = CONCAT13(uVar8,local_62c._1_3_);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 == 2) {
            uVar13 = json_object_get_double(iVar1);
            uVar8 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
            local_62c = CONCAT13(uVar8,local_62c._1_3_);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_uac_rdmngr_jcs_modify",0x5f1);
            }
            local_62c = CONCAT13(0xff,local_62c._1_3_);
          }
        }
      }
      if (local_62c._0_1_ != local_680) {
        iVar1 = apdb_support_multi_radio_by_id(local_2c8,auStack_f0,(uint)pcVar10 & 0xf);
        if (iVar1 == 0) {
          pcVar9 = (char *)0xffffffff;
          if (rdmngr_debug_switch != 0) {
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) goto LAB_00629870;
            pcVar9 = "[RDMNGR_DEBUG]%s()/%d radio %d not support multi radio, can not change.\n";
            uVar3 = 0x5f5;
            goto LAB_00629a5c;
          }
          goto LAB_0062986c;
        }
      }
      if (local_62c._0_1_ != local_680) {
        _uac_rdmngr_para_adjust_by_freq(&local_634,local_2c8);
      }
      iVar1 = json_object_object_get(param_1,"mode");
      if (iVar1 == 0) {
LAB_00629c40:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x600);
        }
        uVar8 = 0xff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          uVar8 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_00629c40;
          uVar13 = json_object_get_double(iVar1);
          uVar8 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      local_62c._1_3_ = CONCAT12(uVar8,local_62c._2_2_);
      iVar1 = json_object_object_get(param_1,"bandwidth");
      if (iVar1 == 0) {
LAB_00629c98:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x603);
        }
        uVar8 = 0xff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          uVar8 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_00629c98;
          uVar13 = json_object_get_double(iVar1);
          uVar8 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      local_62c._2_2_ = CONCAT11(uVar8,(undefined1)local_62c);
      iVar1 = json_object_object_get(param_1,"channel");
      if (iVar1 == 0) {
LAB_00629cf0:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x606);
        }
        uVar7 = 0xffff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          uVar7 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_00629cf0;
          uVar13 = json_object_get_double(iVar1);
          uVar7 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      local_628 = CONCAT22(uVar7,local_628._2_2_);
      iVar1 = json_object_object_get(param_1,"power_level");
      if (iVar1 == 0) {
LAB_00629d48:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x609);
        }
        local_61b = 0xff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_61b = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_00629d48;
          uVar13 = json_object_get_double(iVar1);
          local_61b = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = json_object_object_get(param_1,"max_usr");
      if (iVar1 == 0) {
LAB_00629da0:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x60c);
        }
        local_61a = 0xffff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_61a = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_00629da0;
          uVar13 = json_object_get_double(iVar1);
          local_61a = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = json_object_object_get(param_1,"antenna");
      if (iVar1 == 0) {
LAB_00629df8:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x60f);
        }
        local_618 = 0xff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_618 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_00629df8;
          uVar13 = json_object_get_double(iVar1);
          local_618 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = json_object_object_get(param_1,"frag_thr");
      if (iVar1 == 0) {
LAB_00629e50:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x612);
        }
        local_616 = 0xffff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_616 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_00629e50;
          uVar13 = json_object_get_double(iVar1);
          local_616 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = json_object_object_get(param_1,"bcn_intvl");
      if (iVar1 == 0) {
LAB_00629ea8:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x615);
        }
        local_614 = 0xffff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_614 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_00629ea8;
          uVar13 = json_object_get_double(iVar1);
          local_614 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = json_object_object_get(param_1,"manage_frame_rate");
      if (iVar1 == 0) {
LAB_00629f00:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x618);
        }
        local_60b = 0xff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_60b = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_00629f00;
          uVar13 = json_object_get_double(iVar1);
          local_60b = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = json_object_object_get(param_1,"rts_thr");
      if (iVar1 == 0) {
LAB_00629f58:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x61b);
        }
        local_610 = 0xffff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_610 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_00629f58;
          uVar13 = json_object_get_double(iVar1);
          local_610 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = json_object_object_get(param_1,"dtim_prd");
      if (iVar1 == 0) {
LAB_00629fb0:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x61e);
        }
        local_60e = 0xff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_60e = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_00629fb0;
          uVar13 = json_object_get_double(iVar1);
          local_60e = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = json_object_object_get(param_1,&DAT_006fe1c0);
      if (iVar1 == 0) {
LAB_0062a008:
        if (jcs_err_switch == 0) {
          local_60d = 0xff;
        }
        else {
          printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                 "_uac_rdmngr_jcs_modify",0x621);
          local_60d = 0xff;
        }
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        iVar11 = 0;
        if (iVar2 != 6) {
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_0062b144:
            printf(pcVar9,"_uac_rdmngr_jcs_modify",0x621);
          }
          goto LAB_0062a008;
        }
        do {
          while( true ) {
            if (onoff_map <= iVar11) {
              if (jcs_err_switch == 0) goto LAB_0062a008;
              pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
              goto LAB_0062b144;
            }
            iVar2 = iVar11 * 0x10;
            pcVar9 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
            if (pcVar9 != (char *)0x0) break;
            iVar11 = iVar11 + 1;
          }
          pcVar5 = (char *)json_object_get_string(iVar1);
          iVar6 = strcmp(pcVar9,pcVar5);
          iVar11 = iVar11 + 1;
        } while (iVar6 != 0);
        local_60d = (undefined1)*(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 + 0xc);
      }
      iVar1 = json_object_object_get(param_1,"brd_probe");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          iVar2 = 0;
          while (iVar2 < onoff_map) {
            pcVar9 = *(char **)(PTR__mt_onoff_00731f8c + iVar2 * 0x10);
            if (pcVar9 == (char *)0x0) {
              iVar2 = iVar2 + 1;
            }
            else {
              pcVar5 = (char *)json_object_get_string(iVar1);
              iVar11 = strcmp(pcVar9,pcVar5);
              if (iVar11 == 0) {
                local_60c = (undefined1)*(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 * 0x10 + 0xc)
                ;
                goto LAB_0062a06c;
              }
              iVar2 = iVar2 + 1;
            }
          }
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062b1b4:
            printf(pcVar9,"_uac_rdmngr_jcs_modify",0x624);
          }
        }
        else if (jcs_err_switch != 0) {
          pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
          goto LAB_0062b1b4;
        }
      }
      if (jcs_err_switch == 0) {
        local_60c = 0xff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_rdmngr_jcs_modify"
               ,0x624);
        local_60c = 0xff;
      }
LAB_0062a06c:
      iVar1 = json_object_object_get(param_1,"short_gi");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          iVar2 = 0;
          while (iVar2 < onoff_map) {
            pcVar9 = *(char **)(PTR__mt_onoff_00731f8c + iVar2 * 0x10);
            if (pcVar9 == (char *)0x0) {
              iVar2 = iVar2 + 1;
            }
            else {
              pcVar5 = (char *)json_object_get_string(iVar1);
              iVar11 = strcmp(pcVar9,pcVar5);
              if (iVar11 == 0) {
                local_60a = (undefined1)*(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 * 0x10 + 0xc)
                ;
                goto LAB_0062a0c0;
              }
              iVar2 = iVar2 + 1;
            }
          }
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062b080:
            printf(pcVar9,"_uac_rdmngr_jcs_modify",0x627);
          }
        }
        else if (jcs_err_switch != 0) {
          pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
          goto LAB_0062b080;
        }
      }
      if (jcs_err_switch == 0) {
        local_60a = 0xff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_rdmngr_jcs_modify"
               ,0x627);
        local_60a = 0xff;
      }
LAB_0062a0c0:
      iVar1 = json_object_object_get(param_1,"rssi_restrict");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          iVar2 = 0;
          while (iVar2 < onoff_map) {
            pcVar9 = *(char **)(PTR__mt_onoff_00731f8c + iVar2 * 0x10);
            if (pcVar9 == (char *)0x0) {
              iVar2 = iVar2 + 1;
            }
            else {
              pcVar5 = (char *)json_object_get_string(iVar1);
              iVar11 = strcmp(pcVar9,pcVar5);
              if (iVar11 == 0) {
                local_609 = (undefined1)*(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 * 0x10 + 0xc)
                ;
                goto LAB_0062a114;
              }
              iVar2 = iVar2 + 1;
            }
          }
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062b09c:
            printf(pcVar9,"_uac_rdmngr_jcs_modify",0x62a);
          }
        }
        else if (jcs_err_switch != 0) {
          pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
          goto LAB_0062b09c;
        }
      }
      if (jcs_err_switch == 0) {
        local_609 = 0xff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_rdmngr_jcs_modify"
               ,0x62a);
        local_609 = 0xff;
      }
LAB_0062a114:
      iVar1 = json_object_object_get(param_1,"rssi_restrict_val");
      if (iVar1 == 0) {
LAB_0062a158:
        if (jcs_err_switch == 0) {
          local_608 = 0xff;
        }
        else {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x62d);
          local_608 = 0xff;
        }
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_608 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_0062a158;
          uVar13 = json_object_get_double(iVar1);
          local_608 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = rdmngr_profile_support_rssi_kick();
      if (iVar1 != 0) {
        iVar1 = json_object_object_get(param_1,"rssi_kick");
        if (iVar1 == 0) {
LAB_0062adec:
          if (jcs_err_switch == 0) {
            local_607 = 0xff;
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_uac_rdmngr_jcs_modify",0x632);
            local_607 = 0xff;
          }
        }
        else {
          iVar2 = json_object_get_type(iVar1);
          iVar11 = 0;
          if (iVar2 != 6) {
            if (jcs_err_switch != 0) {
              pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_0062bbd8:
              printf(pcVar9,"_uac_rdmngr_jcs_modify",0x632);
            }
            goto LAB_0062adec;
          }
          do {
            while( true ) {
              if (onoff_map <= iVar11) {
                if (jcs_err_switch == 0) goto LAB_0062adec;
                pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
                goto LAB_0062bbd8;
              }
              iVar2 = iVar11 * 0x10;
              pcVar9 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
              if (pcVar9 != (char *)0x0) break;
              iVar11 = iVar11 + 1;
            }
            pcVar5 = (char *)json_object_get_string(iVar1);
            iVar6 = strcmp(pcVar9,pcVar5);
            iVar11 = iVar11 + 1;
          } while (iVar6 != 0);
          local_607 = (undefined1)*(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 + 0xc);
        }
        iVar1 = json_object_object_get(param_1,"rssi_kick_val");
        if (iVar1 == 0) {
LAB_0062ae40:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_uac_rdmngr_jcs_modify",0x635);
          }
          local_606 = 0xff;
        }
        else {
          iVar2 = json_object_get_type(iVar1);
          if (iVar2 == 3) {
            local_606 = json_object_get_int(iVar1);
          }
          else {
            iVar2 = json_object_get_type();
            if (iVar2 != 2) goto LAB_0062ae40;
            uVar13 = json_object_get_double(iVar1);
            local_606 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
          }
        }
      }
      iVar1 = json_object_object_get(param_1,"chLock");
      if (iVar1 == 0) {
LAB_0062a1bc:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x639);
        }
        local_5f3 = 0xff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_5f3 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_0062a1bc;
          uVar13 = json_object_get_double(iVar1);
          local_5f3 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = json_object_object_get(param_1,"pwrLock");
      if (iVar1 == 0) {
LAB_0062a214:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x63c);
        }
        local_5f2 = 0xff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_5f2 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_0062a214;
          uVar13 = json_object_get_double(iVar1);
          local_5f2 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = json_object_object_get(param_1,"scanMode");
      if (iVar1 == 0) {
LAB_0062a26c:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x63f);
        }
        local_5f1 = 0xff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_5f1 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_0062a26c;
          uVar13 = json_object_get_double(iVar1);
          local_5f1 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = json_object_object_get(param_1,"scanType");
      if (iVar1 == 0) {
LAB_0062a2c4:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x642);
        }
        local_5f0 = 0xff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_5f0 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_0062a2c4;
          uVar13 = json_object_get_double(iVar1);
          local_5f0 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = json_object_object_get(param_1,"scanIntvl");
      if (iVar1 == 0) {
LAB_0062a31c:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x645);
        }
        local_5ee = 0xffff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_5ee = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_0062a31c;
          uVar13 = json_object_get_double(iVar1);
          local_5ee = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = json_object_object_get(param_1,"airtime");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          iVar2 = 0;
          while (iVar2 < onoff_map) {
            pcVar9 = *(char **)(PTR__mt_onoff_00731f8c + iVar2 * 0x10);
            if (pcVar9 == (char *)0x0) {
              iVar2 = iVar2 + 1;
            }
            else {
              pcVar5 = (char *)json_object_get_string(iVar1);
              iVar11 = strcmp(pcVar9,pcVar5);
              if (iVar11 == 0) {
                local_612 = (undefined2)*(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 * 0x10 + 0xc)
                ;
                goto LAB_0062a384;
              }
              iVar2 = iVar2 + 1;
            }
          }
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062b10c:
            printf(pcVar9,"_uac_rdmngr_jcs_modify",0x64a);
          }
        }
        else if (jcs_err_switch != 0) {
          pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
          goto LAB_0062b10c;
        }
      }
      if (jcs_err_switch == 0) {
        local_612 = 0xffff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_rdmngr_jcs_modify"
               ,0x64a);
        local_612 = 0xffff;
      }
LAB_0062a384:
      iVar1 = json_object_object_get(param_1,&DAT_00707dbc);
      if (iVar1 == 0) {
LAB_0062a3c8:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x64d);
        }
        uVar8 = 0xff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          uVar8 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_0062a3c8;
          uVar13 = json_object_get_double(iVar1);
          uVar8 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      local_628._2_2_ = CONCAT11(uVar8,(undefined1)local_628);
      iVar1 = json_object_object_get(param_1,"rf_chnl_reselect");
      if (iVar1 == 0) {
LAB_0062a420:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x650);
        }
        local_5eb = -1;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_5eb = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_0062a420;
          uVar13 = json_object_get_double(iVar1);
          local_5eb = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      if (local_628._2_1_ == '\0') {
        iVar1 = json_object_object_get(param_1,"rf_online_switch");
        if (iVar1 == 0) {
LAB_0062aed0:
          if (jcs_err_switch == 0) {
            local_61c = 0xff;
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_uac_rdmngr_jcs_modify",0x655);
            local_61c = 0xff;
          }
        }
        else {
          iVar2 = json_object_get_type(iVar1);
          iVar11 = 0;
          if (iVar2 != 6) {
            if (jcs_err_switch != 0) {
              pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_0062bc50:
              printf(pcVar9,"_uac_rdmngr_jcs_modify",0x655);
            }
            goto LAB_0062aed0;
          }
          do {
            while( true ) {
              if (onoff_map <= iVar11) {
                if (jcs_err_switch == 0) goto LAB_0062aed0;
                pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
                goto LAB_0062bc50;
              }
              iVar2 = iVar11 * 0x10;
              pcVar9 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
              if (pcVar9 != (char *)0x0) break;
              iVar11 = iVar11 + 1;
            }
            pcVar5 = (char *)json_object_get_string(iVar1);
            iVar6 = strcmp(pcVar9,pcVar5);
            iVar11 = iVar11 + 1;
          } while (iVar6 != 0);
          local_61c = (undefined1)*(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 + 0xc);
        }
        iVar1 = json_object_object_get(param_1,"rf_check_circle");
        if (iVar1 == 0) {
LAB_0062af24:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_uac_rdmngr_jcs_modify",0x658);
          }
          local_624 = 0xffff;
        }
        else {
          iVar2 = json_object_get_type(iVar1);
          if (iVar2 == 3) {
            local_624 = json_object_get_int(iVar1);
          }
          else {
            iVar2 = json_object_get_type();
            if (iVar2 != 2) goto LAB_0062af24;
            uVar13 = json_object_get_double(iVar1);
            local_624 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
          }
        }
        iVar1 = json_object_object_get(param_1,"rf_chnl_occup_threshold");
        if (iVar1 == 0) {
LAB_0062af7c:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_uac_rdmngr_jcs_modify",0x65b);
          }
          local_622 = 0xffff;
        }
        else {
          iVar2 = json_object_get_type(iVar1);
          if (iVar2 == 3) {
            local_622 = json_object_get_int(iVar1);
          }
          else {
            iVar2 = json_object_get_type();
            if (iVar2 != 2) goto LAB_0062af7c;
            uVar13 = json_object_get_double(iVar1);
            local_622 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
          }
        }
        iVar1 = json_object_object_get(param_1,"rf_chnl_tolerance");
        if (iVar1 == 0) {
LAB_0062afd4:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_uac_rdmngr_jcs_modify",0x65e);
          }
          local_61e = 0xffff;
        }
        else {
          iVar2 = json_object_get_type(iVar1);
          if (iVar2 == 3) {
            local_61e = json_object_get_int(iVar1);
          }
          else {
            iVar2 = json_object_get_type();
            if (iVar2 != 2) goto LAB_0062afd4;
            uVar13 = json_object_get_double(iVar1);
            local_61e = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
          }
        }
      }
      iVar1 = json_object_object_get(param_1,"reject_limit");
      if (iVar1 == 0) {
LAB_0062a484:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x664);
        }
        local_605 = 0xff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_605 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_0062a484;
          uVar13 = json_object_get_double(iVar1);
          local_605 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = json_object_object_get(param_1,"reject_enable");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          iVar2 = 0;
          while (iVar2 < onoff_map) {
            pcVar9 = *(char **)(PTR__mt_onoff_00731f8c + iVar2 * 0x10);
            if (pcVar9 == (char *)0x0) {
              iVar2 = iVar2 + 1;
            }
            else {
              pcVar5 = (char *)json_object_get_string(iVar1);
              iVar11 = strcmp(pcVar9,pcVar5);
              if (iVar11 == 0) {
                local_604 = (undefined1)*(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 * 0x10 + 0xc)
                ;
                goto LAB_0062a4ec;
              }
              iVar2 = iVar2 + 1;
            }
          }
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062b128:
            printf(pcVar9,"_uac_rdmngr_jcs_modify",0x667);
          }
        }
        else if (jcs_err_switch != 0) {
          pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
          goto LAB_0062b128;
        }
      }
      if (jcs_err_switch == 0) {
        local_604 = 0xff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_rdmngr_jcs_modify"
               ,0x667);
        local_604 = 0xff;
      }
LAB_0062a4ec:
      iVar1 = json_object_object_get(param_1,"reject_diff");
      if (iVar1 == 0) {
LAB_0062a530:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_modify",0x66a);
        }
        local_603 = 0xff;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_603 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_0062a530;
          uVar13 = json_object_get_double(iVar1);
          local_603 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
      }
      iVar1 = json_object_object_get(param_1,"downlink_mumimo");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          iVar2 = 0;
          while (iVar2 < switch_type_map) {
            pcVar9 = *(char **)(PTR__mt_switch_type_00758b74 + iVar2 * 0x10);
            if (pcVar9 == (char *)0x0) {
              iVar2 = iVar2 + 1;
            }
            else {
              pcVar5 = (char *)json_object_get_string(iVar1);
              iVar11 = strcmp(pcVar9,pcVar5);
              if (iVar11 == 0) {
                local_602 = (undefined1)
                            *(undefined4 *)(PTR__mt_switch_type_00758b74 + iVar2 * 0x10 + 0xc);
                goto LAB_0062a598;
              }
              iVar2 = iVar2 + 1;
            }
          }
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062b0d4:
            printf(pcVar9,"_uac_rdmngr_jcs_modify",0x66d);
          }
        }
        else if (jcs_err_switch != 0) {
          pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
          goto LAB_0062b0d4;
        }
      }
      if (jcs_err_switch == 0) {
        local_602 = 0xff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_rdmngr_jcs_modify"
               ,0x66d);
        local_602 = 0xff;
      }
LAB_0062a598:
      iVar1 = json_object_object_get(param_1,"uplink_mumimo");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          iVar2 = 0;
          while (iVar2 < switch_type_map) {
            pcVar9 = *(char **)(PTR__mt_switch_type_00758b74 + iVar2 * 0x10);
            if (pcVar9 == (char *)0x0) {
              iVar2 = iVar2 + 1;
            }
            else {
              pcVar5 = (char *)json_object_get_string(iVar1);
              iVar11 = strcmp(pcVar9,pcVar5);
              if (iVar11 == 0) {
                local_601 = (undefined1)
                            *(undefined4 *)(PTR__mt_switch_type_00758b74 + iVar2 * 0x10 + 0xc);
                goto LAB_0062a5ec;
              }
              iVar2 = iVar2 + 1;
            }
          }
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062b0f0:
            printf(pcVar9,"_uac_rdmngr_jcs_modify",0x66f);
          }
        }
        else if (jcs_err_switch != 0) {
          pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
          goto LAB_0062b0f0;
        }
      }
      if (jcs_err_switch == 0) {
        local_601 = 0xff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_rdmngr_jcs_modify"
               ,0x66f);
        local_601 = 0xff;
      }
LAB_0062a5ec:
      iVar1 = json_object_object_get(param_1,"downlink_ofdma");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          iVar2 = 0;
          while (iVar2 < switch_type_map) {
            pcVar9 = *(char **)(PTR__mt_switch_type_00758b74 + iVar2 * 0x10);
            if (pcVar9 == (char *)0x0) {
              iVar2 = iVar2 + 1;
            }
            else {
              pcVar5 = (char *)json_object_get_string(iVar1);
              iVar11 = strcmp(pcVar9,pcVar5);
              if (iVar11 == 0) {
                local_600 = (undefined1)
                            *(undefined4 *)(PTR__mt_switch_type_00758b74 + iVar2 * 0x10 + 0xc);
                goto LAB_0062a640;
              }
              iVar2 = iVar2 + 1;
            }
          }
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062b0b8:
            printf(pcVar9,"_uac_rdmngr_jcs_modify",0x672);
          }
        }
        else if (jcs_err_switch != 0) {
          pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
          goto LAB_0062b0b8;
        }
      }
      if (jcs_err_switch == 0) {
        local_600 = 0xff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_rdmngr_jcs_modify"
               ,0x672);
        local_600 = 0xff;
      }
LAB_0062a640:
      iVar1 = json_object_object_get(param_1,"uplink_ofdma");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          iVar2 = 0;
          while (iVar2 < switch_type_map) {
            pcVar9 = *(char **)(PTR__mt_switch_type_00758b74 + iVar2 * 0x10);
            if (pcVar9 == (char *)0x0) {
              iVar2 = iVar2 + 1;
            }
            else {
              pcVar5 = (char *)json_object_get_string(iVar1);
              iVar11 = strcmp(pcVar9,pcVar5);
              if (iVar11 == 0) {
                local_5ff = (undefined1)
                            *(undefined4 *)(PTR__mt_switch_type_00758b74 + iVar2 * 0x10 + 0xc);
                goto LAB_0062a694;
              }
              iVar2 = iVar2 + 1;
            }
          }
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062b17c:
            printf(pcVar9,"_uac_rdmngr_jcs_modify",0x674);
          }
        }
        else if (jcs_err_switch != 0) {
          pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
          goto LAB_0062b17c;
        }
      }
      if (jcs_err_switch == 0) {
        local_5ff = 0xff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_rdmngr_jcs_modify"
               ,0x674);
        local_5ff = 0xff;
      }
LAB_0062a694:
      iVar1 = json_object_object_get(param_1,&DAT_00707e84);
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          iVar2 = 0;
          while (iVar2 < switch_type_map) {
            pcVar9 = *(char **)(PTR__mt_switch_type_00758b74 + iVar2 * 0x10);
            if (pcVar9 == (char *)0x0) {
              iVar2 = iVar2 + 1;
            }
            else {
              pcVar5 = (char *)json_object_get_string(iVar1);
              iVar11 = strcmp(pcVar9,pcVar5);
              if (iVar11 == 0) {
                local_5fe = (undefined1)
                            *(undefined4 *)(PTR__mt_switch_type_00758b74 + iVar2 * 0x10 + 0xc);
                goto LAB_0062a6e8;
              }
              iVar2 = iVar2 + 1;
            }
          }
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062b160:
            printf(pcVar9,"_uac_rdmngr_jcs_modify",0x677);
          }
        }
        else if (jcs_err_switch != 0) {
          pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
          goto LAB_0062b160;
        }
      }
      if (jcs_err_switch == 0) {
        local_5fe = 0xff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_rdmngr_jcs_modify"
               ,0x677);
        local_5fe = 0xff;
      }
LAB_0062a6e8:
      iVar1 = json_object_object_get(param_1,"gi_mode");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_5fd = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 == 2) {
            uVar13 = json_object_get_double(iVar1);
            local_5fd = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_uac_rdmngr_jcs_modify",0x67a);
            }
            local_5fd = 0xff;
          }
        }
      }
      iVar1 = json_object_object_get(param_1,"enable_6g");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          iVar2 = 0;
          while (iVar2 < switch_type_map) {
            pcVar9 = *(char **)(PTR__mt_switch_type_00758b74 + iVar2 * 0x10);
            if (pcVar9 == (char *)0x0) {
              iVar2 = iVar2 + 1;
            }
            else {
              pcVar5 = (char *)json_object_get_string(iVar1);
              iVar11 = strcmp(pcVar9,pcVar5);
              if (iVar11 == 0) {
                local_5fc = (undefined1)
                            *(undefined4 *)(PTR__mt_switch_type_00758b74 + iVar2 * 0x10 + 0xc);
                goto LAB_0062a794;
              }
              iVar2 = iVar2 + 1;
            }
          }
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062b198:
            printf(pcVar9,"_uac_rdmngr_jcs_modify",0x67d);
          }
        }
        else if (jcs_err_switch != 0) {
          pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
          goto LAB_0062b198;
        }
      }
      if (jcs_err_switch == 0) {
        local_5fc = 0xff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_rdmngr_jcs_modify"
               ,0x67d);
        local_5fc = 0xff;
      }
LAB_0062a794:
      iVar1 = json_object_object_get(param_1,"enable_6g_psc");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          iVar2 = 0;
          while (iVar2 < switch_type_map) {
            pcVar9 = *(char **)(PTR__mt_switch_type_00758b74 + iVar2 * 0x10);
            if (pcVar9 == (char *)0x0) {
              iVar2 = iVar2 + 1;
            }
            else {
              pcVar5 = (char *)json_object_get_string(iVar1);
              iVar11 = strcmp(pcVar9,pcVar5);
              if (iVar11 == 0) {
                local_5fb = (undefined1)
                            *(undefined4 *)(PTR__mt_switch_type_00758b74 + iVar2 * 0x10 + 0xc);
                goto LAB_0062a7e8;
              }
              iVar2 = iVar2 + 1;
            }
          }
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062b064:
            printf(pcVar9,"_uac_rdmngr_jcs_modify",0x680);
          }
        }
        else if (jcs_err_switch != 0) {
          pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
          goto LAB_0062b064;
        }
      }
      if (jcs_err_switch == 0) {
        local_5fb = 0xff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_rdmngr_jcs_modify"
               ,0x680);
        local_5fb = 0xff;
      }
LAB_0062a7e8:
      iVar1 = apdb_is_hdap_by_id(local_2c8,auStack_f0);
      if (iVar1 != 0) {
        if (((int)local_628._0_2_ - 2U < 0xc) && (local_628._0_2_ != 0xb)) {
          local_628 = CONCAT22(0xffff,local_628._2_2_);
        }
      }
      iVar1 = _uac_rdmngr_check_rd_chnl(local_2c8,auStack_f0,(uint)pcVar10 & 0xf,&local_630);
      if (iVar1 == 1) {
        pcVar9 = (char *)rdmngr_db_rd_entry_set(&local_634);
        if ((pcVar9 == (char *)0x0) &&
           (iVar1 = memcmp(auStack_688,&local_634,0x54), pcVar9 = pcVar10, iVar1 != 0)) {
          rdmngr_callback_proc(2,pcVar10,auStack_688,&local_634);
        }
        if (bVar12 == false) {
LAB_0062a878:
          if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[RDMNGR_DEBUG]%s()/%d rd_entry.rd_cfg.chnl:%d\n","_uac_rdmngr_jcs_modify",0x6b6,
                   (int)local_628._0_2_);
          }
          if (rdmngr_debug_switch != 0) {
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
            }
            else {
              printf("[RDMNGR_DEBUG]%s()/%d old_entry.rd_cfg.chnl:%d\n","_uac_rdmngr_jcs_modify",
                     0x6b7,(int)local_67c);
            }
          }
          if (local_628._0_2_ != local_67c) {
            rdmngr_callback_proc(5,pcVar10,auStack_688,&local_634);
          }
          for (uVar4 = 0; uVar4 < 0x44; uVar4 = uVar4 + 1) {
            local_6d8[uVar4] = *(undefined1 *)((int)&local_624 + uVar4);
          }
          iVar1 = FUN_006270b4(local_634,local_630,local_62c,local_628);
          if (iVar1 == 0) {
            if (local_5eb != '\0') {
              rdmngr_db_rd_entry_channel_reselect_reset(pcVar10);
            }
            goto LAB_00629870;
          }
          pcVar9 = (char *)0xffffffff;
          if (rdmngr_debug_switch != 0) {
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) goto LAB_00629870;
            pcVar10 = "[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_linked_modify() failed.\n";
            uVar3 = 0x6be;
LAB_0062bd0c:
            pcVar9 = (char *)0xffffffff;
            printf(pcVar10,"_uac_rdmngr_jcs_modify",uVar3);
            goto LAB_00629870;
          }
        }
        else {
          iVar1 = rdmngr_db_update_reinit_state(pcVar10);
          if (iVar1 == 0) {
            iVar1 = apmngr_checksum_update(auStack_308,0);
            if (iVar1 == 0) {
              uVar3 = rdmngr_db_generate_ap_id(pcVar10);
              iVar1 = rdmngr_wtp_pkt_send(uVar3,&local_634);
              if (iVar1 == 0) {
                if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  printf("[RDMNGR_DEBUG]%s()/%d shutdown radio %d OK.\n","_uac_rdmngr_jcs_modify",
                         0x6ad,pcVar10);
                }
                rdmngr_callback_proc(0,pcVar10,0,0);
                uVar3 = rdmngr_db_generate_ap_id(pcVar10);
                iVar1 = rdmngr_wtp_pkt_send(uVar3,&local_634);
                if (iVar1 == 0) {
                  if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(1), iVar1 != 0)) {
                    printf("[RDMNGR_DEBUG]%s()/%d open radio %d OK.\n","_uac_rdmngr_jcs_modify",
                           0x6b1,pcVar10);
                  }
                  rdmngr_callback_proc(1,pcVar10,0,0);
                }
              }
              goto LAB_0062a878;
            }
            pcVar9 = (char *)0xffffffff;
            if (rdmngr_err_switch != 0) {
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) goto LAB_00629870;
              pcVar10 = "[RDMNGR_ERROR]%s()/%d update md5 failed.\n";
              uVar3 = 0x6a7;
              goto LAB_0062bd0c;
            }
          }
          else {
            pcVar9 = (char *)0xffffffff;
            if (rdmngr_err_switch != 0) {
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) goto LAB_00629870;
              pcVar10 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_update_reinit_state() failed.\n";
              uVar3 = 0x6a1;
              goto LAB_0062bd0c;
            }
          }
        }
      }
    }
  }
  else {
    pcVar9 = (char *)0xffffffff;
    if (rdmngr_err_switch != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) goto LAB_00629870;
      pcVar9 = "[RDMNGR_ERROR]%s()/%d rd_id:%d, rdmngr_db_rd_entry_get() failed.\n";
      uVar3 = 0x5db;
      goto LAB_00629a5c;
    }
  }
LAB_0062986c:
  pcVar9 = (char *)0xffffffff;
LAB_00629870:
  if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[RDMNGR_ERROR]%s()/%d _uac_rdmngr_jcs_modify() done, ret:%d.\n","_uac_rdmngr_jcs_modify"
           ,0x6c7,pcVar9);
  }
  uVar3 = json_object_new_int(pcVar9);
  json_object_object_add(param_2,"rd_id",uVar3);
  return;
}

