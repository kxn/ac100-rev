// func _radius_message_process @ 004405a8 size=18684

undefined4 _radius_message_process(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  code *pcVar10;
  uint uVar11;
  undefined8 uVar12;
  char local_8c0 [4];
  undefined4 local_8bc;
  char local_8b8 [16];
  uint local_8a8;
  char local_8a4 [4];
  undefined4 local_8a0;
  undefined4 local_89c;
  undefined4 local_898;
  uint local_894;
  undefined1 auStack_890 [4];
  char local_88c [4];
  undefined1 auStack_888 [4];
  undefined1 auStack_884 [4];
  undefined1 auStack_880 [4];
  undefined1 auStack_87c [4];
  undefined1 auStack_878 [19];
  undefined1 local_865;
  char acStack_864 [39];
  undefined1 local_83d;
  undefined1 auStack_7eb [101];
  undefined1 auStack_786 [50];
  int local_754;
  undefined2 uStack_74e;
  undefined4 local_74c;
  undefined4 local_744;
  undefined4 local_740;
  undefined4 local_73c;
  undefined4 local_738;
  undefined4 local_734;
  undefined1 auStack_730 [121];
  undefined1 auStack_6b7 [101];
  undefined1 auStack_652 [50];
  int local_620;
  undefined2 uStack_61a;
  undefined4 local_618;
  undefined4 local_610;
  undefined4 local_60c;
  undefined4 local_608;
  undefined4 local_604;
  undefined4 local_600;
  int local_5f8;
  char acStack_5f4 [254];
  undefined1 local_4f6;
  char acStack_4f5 [120];
  undefined1 local_47d;
  char acStack_47c [100];
  undefined1 local_418;
  undefined4 local_414;
  undefined4 local_410;
  undefined4 local_40c;
  undefined4 local_408;
  undefined4 local_404;
  undefined4 local_400;
  undefined4 local_3fc;
  undefined4 local_3f8;
  int local_3f4;
  undefined2 local_3f0;
  undefined4 local_3ec;
  char acStack_3e8 [254];
  undefined1 local_2ea;
  char acStack_2e9 [120];
  undefined1 local_271;
  char acStack_270 [100];
  undefined1 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined2 local_1e4;
  undefined4 local_1e0;
  char acStack_1dc [100];
  undefined1 local_178;
  byte local_177 [100];
  undefined1 local_113;
  undefined2 local_112;
  undefined2 local_110;
  undefined2 local_10e;
  undefined2 local_10c;
  undefined2 local_10a;
  undefined2 local_108;
  undefined2 local_106;
  undefined2 local_104;
  char acStack_102 [64];
  undefined1 local_c2;
  undefined1 local_c1 [6];
  undefined1 local_bb [7];
  undefined1 auStack_b4 [20];
  undefined1 auStack_a0 [24];
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined2 local_74;
  byte local_72;
  byte local_71;
  undefined4 local_70;
  char acStack_50 [15];
  undefined1 local_41;
  undefined8 local_40;
  undefined8 local_38;
  
  local_8c0[0] = '1';
  iVar1 = json_object_object_get(param_1,"type");
  if (iVar1 == 0) {
    uVar9 = 0xffffffff;
    if (radius_debug_switch == 0) goto LAB_0044068c;
    uVar8 = 0xdc0;
    pcVar10 = printf;
    pcVar6 = "[RADIUS_DEBUG]%s()/%d Get type error\n";
    pcVar7 = "_radius_message_process";
LAB_00441f50:
    (*pcVar10)(pcVar6,pcVar7,uVar8);
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar12 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
      }
      else {
        iVar1 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_radius_message_process",0xdc3);
        }
      }
    }
    memset(&local_5f8,0,0x5d0);
    local_5f8 = iVar1;
    if (iVar1 == 3) {
      local_8b8[0] = '\0';
      local_8b8[1] = '\0';
      local_8b8[2] = '\0';
      local_8b8[3] = '\0';
      local_8b8[4] = '\0';
      local_8b8[5] = '\0';
      local_8b8[6] = '\0';
      local_8b8[7] = '\0';
      local_8b8[8] = '\0';
      local_8b8[9] = '\0';
      local_8b8[10] = '\0';
      local_8b8[0xb] = '\0';
      local_8b8[0xc] = '\0';
      local_8b8[0xd] = '\0';
      local_8b8[0xe] = '\0';
      local_8b8[0xf] = '\0';
      local_8a8 = 0;
      memset(local_88c,0,0x28);
      iVar1 = json_object_object_get(param_1,"data");
      if (iVar1 == 0) goto LAB_0044068c;
      iVar2 = json_object_object_get(iVar1,"token");
      if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_radius_acct_stop_messege_process",0xc68);
        }
        pcVar6 = "";
      }
      else {
        pcVar6 = (char *)json_object_get_string(iVar2);
      }
      strncpy(acStack_102,pcVar6,0x40);
      local_c2 = 0;
      iVar2 = json_object_object_get(iVar1,"is_common");
      if (iVar2 != 0) {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 3) {
          iVar2 = json_object_get_int(iVar2);
        }
        else {
          iVar3 = json_object_get_type();
          if (iVar3 != 2) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_acct_stop_messege_process",0xc6d);
            }
            goto LAB_00440dec;
          }
          uVar12 = json_object_get_double(iVar2);
          iVar2 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
        }
        if (iVar2 == 1) {
          local_71 = local_71 | 4;
        }
      }
LAB_00440dec:
      if ((local_71 & 4) == 0) {
        iVar2 = wportal_get_mode();
        if (iVar2 == 1) {
          iVar2 = json_object_object_get(iVar1,"vlan_id");
          if (iVar2 == 0) {
LAB_00443924:
            if (jcs_err_switch != 0) {
              uVar9 = 0xc7a;
              goto LAB_00443a80;
            }
            local_70 = 0xffffffff;
          }
          else {
            iVar3 = json_object_get_type(iVar2);
            if (iVar3 == 3) {
LAB_00444d64:
              local_70 = json_object_get_int(iVar2);
            }
            else {
              iVar3 = json_object_get_type(iVar2);
              if (iVar3 != 2) goto LAB_00443924;
LAB_00444da0:
              uVar12 = json_object_get_double(iVar2);
              local_70 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
          }
        }
        else {
          iVar2 = wportal_get_mode();
          if (iVar2 == 0) {
            iVar2 = json_object_object_get(iVar1,"serv_id");
            if (iVar2 != 0) {
              iVar3 = json_object_get_type(iVar2);
              if (iVar3 == 3) goto LAB_00444d64;
              iVar3 = json_object_get_type();
              if (iVar3 == 2) goto LAB_00444da0;
            }
            if (jcs_err_switch == 0) {
              local_70 = 0xffffffff;
            }
            else {
              uVar9 = 0xc7f;
LAB_00443a80:
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_acct_stop_messege_process",uVar9);
              local_70 = 0xffffffff;
            }
          }
          else {
            iVar2 = wportal_get_mode();
            if (iVar2 == 2) {
              iVar2 = json_object_object_get(iVar1,"interface");
              if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_radius_acct_stop_messege_process",0xc84);
                }
                pcVar6 = "";
              }
              else {
                pcVar6 = (char *)json_object_get_string(iVar2);
              }
              strncpy(acStack_50,pcVar6,0xf);
              local_41 = 0;
              iVar2 = json_object_object_get(iVar1,"vlan_id");
              if (iVar2 != 0) {
                iVar3 = json_object_get_type(iVar2);
                if (iVar3 == 3) goto LAB_00444d64;
                iVar3 = json_object_get_type(iVar2);
                if (iVar3 == 2) goto LAB_00444da0;
                if (jcs_err_switch != 0) {
                  uVar9 = 0xc89;
                  goto LAB_00443a80;
                }
                local_70 = 0xffffffff;
              }
            }
          }
        }
        iVar2 = json_object_object_get(iVar1,"apMac");
        if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_radius_acct_stop_messege_process",0xc8e);
          }
          pcVar6 = "";
        }
        else {
          pcVar6 = (char *)json_object_get_string(iVar2);
        }
        strncpy(local_8b8,pcVar6,0x13);
        local_8a8 = local_8a8 & 0xffffff00;
        if (local_8b8[0] != '\0') {
          sscanf(local_8b8,"%2X-%2X-%2X-%2X-%2X-%2X",local_8a4,&local_8a0,&local_89c,&local_898,
                 &local_894,auStack_890);
          pcVar6 = local_8a4;
          iVar2 = 0;
          do {
            uVar9 = *(undefined4 *)pcVar6;
            iVar3 = iVar2 + 1;
            pcVar6 = pcVar6 + 4;
            local_bb[iVar2] = (char)uVar9;
            iVar2 = iVar3;
          } while (iVar3 != 6);
        }
        iVar2 = json_object_object_get(iVar1,&DAT_00679a24);
        if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_radius_acct_stop_messege_process",0xc9e);
          }
          pcVar6 = "";
        }
        else {
          pcVar6 = (char *)json_object_get_string(iVar2);
        }
        strncpy(local_88c,pcVar6,0x27);
        local_865 = 0;
        uac_ipaddr_convert_str2binary(local_88c,auStack_a0);
      }
      iVar2 = json_object_object_get(iVar1,"mac");
      if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_radius_acct_stop_messege_process",0xca4);
        }
        pcVar6 = "";
      }
      else {
        pcVar6 = (char *)json_object_get_string(iVar2);
      }
      strncpy(local_8b8,pcVar6,0x13);
      local_8a8 = local_8a8 & 0xffffff00;
      if (local_8b8[0] != '\0') {
        sscanf(local_8b8,"%2X-%2X-%2X-%2X-%2X-%2X",local_8a4,&local_8a0,&local_89c,&local_898,
               &local_894,auStack_890);
        pcVar6 = local_8a4;
        iVar2 = 0;
        do {
          uVar9 = *(undefined4 *)pcVar6;
          iVar3 = iVar2 + 1;
          pcVar6 = pcVar6 + 4;
          local_c1[iVar2] = (char)uVar9;
          iVar2 = iVar3;
        } while (iVar3 != 6);
      }
      iVar2 = json_object_object_get(iVar1,&DAT_00677c24);
      if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_radius_acct_stop_messege_process",0xcb4);
        }
        pcVar6 = "";
      }
      else {
        pcVar6 = (char *)json_object_get_string(iVar2);
      }
      strncpy(local_88c,pcVar6,0x27);
      local_865 = 0;
      uac_ipaddr_convert_str2binary(local_88c,auStack_b4);
      iVar2 = json_object_object_get(iVar1,"auth_type");
      if (iVar2 == 0) {
LAB_00440f3c:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_radius_acct_stop_messege_process",0xcb8);
        }
        local_74 = 0xffff;
      }
      else {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 3) {
          local_74 = json_object_get_int(iVar2);
        }
        else {
          iVar3 = json_object_get_type();
          if (iVar3 != 2) goto LAB_00440f3c;
          uVar12 = json_object_get_double(iVar2);
          local_74 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
        }
      }
      iVar2 = json_object_object_get(iVar1,"apMac");
      if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_radius_acct_stop_messege_process",0xcbb);
        }
        pcVar6 = "";
      }
      else {
        pcVar6 = (char *)json_object_get_string(iVar2);
      }
      strncpy(local_8b8,pcVar6,0x13);
      local_8a8 = local_8a8 & 0xffffff00;
      if (local_8b8[0] != '\0') {
        sscanf(local_8b8,"%2X-%2X-%2X-%2X-%2X-%2X",local_8a4,&local_8a0,&local_89c,&local_898,
               &local_894,auStack_890);
        pcVar6 = local_8a4;
        iVar2 = 0;
        do {
          uVar9 = *(undefined4 *)pcVar6;
          iVar3 = iVar2 + 1;
          pcVar6 = pcVar6 + 4;
          local_bb[iVar2] = (char)uVar9;
          iVar2 = iVar3;
        } while (iVar3 != 6);
      }
      iVar2 = json_object_object_get(iVar1,&DAT_00679a24);
      if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_radius_acct_stop_messege_process",0xccb);
        }
        pcVar6 = "";
      }
      else {
        pcVar6 = (char *)json_object_get_string(iVar2);
      }
      strncpy(local_88c,pcVar6,0x27);
      local_865 = 0;
      uac_ipaddr_convert_str2binary(local_88c,auStack_a0);
      iVar2 = json_object_object_get(iVar1,"sess_time");
      if (iVar2 == 0) {
LAB_00441094:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_radius_acct_stop_messege_process",0xccf);
        }
        local_80 = 0xffffffff;
      }
      else {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 3) {
          local_80 = json_object_get_int(iVar2);
        }
        else {
          iVar3 = json_object_get_type();
          if (iVar3 != 2) goto LAB_00441094;
          uVar12 = json_object_get_double(iVar2);
          local_80 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
        }
      }
      iVar2 = json_object_object_get(iVar1,"username");
      if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_radius_acct_stop_messege_process",0xcd2);
        }
        pcVar6 = "";
      }
      else {
        pcVar6 = (char *)json_object_get_string(iVar2);
      }
      strncpy(acStack_1dc,pcVar6,100);
      local_178 = 0;
      iVar2 = json_object_object_get(iVar1,"acctSessid");
      if (iVar2 == 0) {
LAB_00441168:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int64 with error obj or value type is unmatch.\n",
                 "_radius_acct_stop_messege_process",0xcd5);
        }
        local_88 = 0xffffffffffffffff;
      }
      else {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 3) {
          local_88 = json_object_get_int64(iVar2);
        }
        else {
          iVar3 = json_object_get_type();
          if (iVar3 != 2) goto LAB_00441168;
          uVar12 = json_object_get_double(iVar2);
          local_88 = __fixunsdfdi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
        }
      }
      iVar2 = json_object_object_get(iVar1,"radius_index");
      if (iVar2 == 0) {
LAB_004411dc:
        uVar9 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_radius_acct_stop_messege_process",0xcd8);
        }
      }
      else {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 3) {
          uVar9 = json_object_get_int(iVar2);
        }
        else {
          iVar3 = json_object_get_type();
          if (iVar3 != 2) goto LAB_004411dc;
          uVar12 = json_object_get_double(iVar2);
          uVar9 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
        }
      }
      iVar2 = json_object_object_get(iVar1,"upstream_load");
      if (iVar2 == 0) {
LAB_00441240:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int64 with error obj or value type is unmatch.\n",
                 "_radius_acct_stop_messege_process",0xcdb);
        }
        local_40 = 0xffffffffffffffff;
      }
      else {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 3) {
          local_40 = json_object_get_int64(iVar2);
        }
        else {
          iVar3 = json_object_get_type();
          if (iVar3 != 2) goto LAB_00441240;
          uVar12 = json_object_get_double(iVar2);
          local_40 = __fixunsdfdi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
        }
      }
      iVar2 = json_object_object_get(iVar1,"downstream_load");
      if (iVar2 == 0) {
LAB_004412b4:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int64 with error obj or value type is unmatch.\n",
                 "_radius_acct_stop_messege_process",0xcdd);
        }
        local_38 = 0xffffffffffffffff;
      }
      else {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 3) {
          local_38 = json_object_get_int64(iVar2);
        }
        else {
          iVar3 = json_object_get_type();
          if (iVar3 != 2) goto LAB_004412b4;
          uVar12 = json_object_get_double(iVar2);
          local_38 = __fixunsdfdi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
        }
      }
      memset(auStack_730,0,0x134);
      iVar2 = wportal_rds_srv_get_by_index(uVar9,auStack_730);
      if (iVar2 == -1) {
        if (radius_debug_switch != 0) {
          uVar8 = 0xce3;
          pcVar6 = "_radius_acct_stop_messege_process";
LAB_00443170:
          printf("[RADIUS_DEBUG]%s()/%d Get radius server entry error: %d\n",pcVar6,uVar8,uVar9);
          return 0xffffffff;
        }
      }
      else if (local_620 != 0) {
        iVar2 = json_object_object_get(iVar1,"no_retry");
        if (iVar2 == 0) {
LAB_00441368:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_radius_acct_stop_messege_process",0xced);
          }
LAB_0044137c:
          local_3fc = local_618;
          local_3f0 = uStack_61a;
        }
        else {
          iVar3 = json_object_get_type(iVar2);
          if (iVar3 == 3) {
            iVar2 = json_object_get_int(iVar2);
          }
          else {
            iVar3 = json_object_get_type();
            if (iVar3 != 2) goto LAB_00441368;
            uVar12 = json_object_get_double(iVar2);
            iVar2 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
          }
          if (iVar2 != 1) goto LAB_0044137c;
          local_3f0 = 0;
          local_3fc = 0;
        }
        uac_ipaddr_convert_binary2str
                  (local_610,local_60c,local_608,local_604,local_600,acStack_5f4,0xff,"---");
        local_3f4 = local_620;
        uac_ipaddr_convert_str2binary(auStack_652,&local_414);
        memcpy(acStack_47c,auStack_6b7,100);
        memcpy(acStack_4f5,auStack_730,0x78);
        iVar1 = json_object_object_get(iVar1,"terminate_type");
        if (iVar1 != 0) {
          iVar2 = json_object_get_type(iVar1);
          if (iVar2 == 3) {
LAB_004448dc:
            local_7c = json_object_get_int(iVar1);
          }
          else {
            iVar2 = json_object_get_type(iVar1);
            if (iVar2 == 2) {
LAB_00444994:
              uVar12 = json_object_get_double(iVar1);
              local_7c = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
            else {
              if (jcs_err_switch != 0) {
                uVar9 = 0xd03;
                pcVar6 = "_radius_acct_stop_messege_process";
LAB_0044148c:
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,pcVar6,uVar9);
              }
LAB_00440cc0:
              local_7c = 0xffffffff;
            }
          }
        }
LAB_00440cc4:
        uVar9 = 3;
LAB_00441ed0:
        if (*(uint *)(PTR_DAT_007591ac + 0x1294) == 0) {
          trap(7);
        }
        uVar11 = DAT_00766ba0 % *(uint *)(PTR_DAT_007591ac + 0x1294);
        DAT_00766ba0 = DAT_00766ba0 + 1;
        iVar2 = uVar11 * 0x30;
        iVar1 = uac_msgQ_send(*(undefined4 *)(threads + iVar2),&local_5f8,0x5d0,uVar9,0);
        if (iVar1 == -1) {
          if (radius_debug_switch != 0) {
            printf("[RADIUS_DEBUG]%s()/%d Send to msgq error\n\n","_radius_message_process",0xdf8);
          }
          g_uac_msgQ_send_msg_process_fail_count = g_uac_msgQ_send_msg_process_fail_count + 1;
          uVar9 = 0xffffffff;
        }
        else {
          uVar9 = 0;
        }
        pcVar7 = local_8c0;
        pcVar10 = write;
        uVar8 = 1;
        pcVar6 = *(char **)(threads + iVar2 + 8);
        goto LAB_00441f50;
      }
    }
    else if (iVar1 == 4) {
      local_8b8[0] = '\0';
      local_8b8[1] = '\0';
      local_8b8[2] = '\0';
      local_8b8[3] = '\0';
      local_8b8[4] = '\0';
      local_8b8[5] = '\0';
      local_8b8[6] = '\0';
      local_8b8[7] = '\0';
      local_8b8[8] = '\0';
      local_8b8[9] = '\0';
      local_8b8[10] = '\0';
      local_8b8[0xb] = '\0';
      local_8b8[0xc] = '\0';
      local_8b8[0xd] = '\0';
      local_8b8[0xe] = '\0';
      local_8b8[0xf] = '\0';
      local_8a8 = 0;
      memset(local_88c,0,0x28);
      iVar1 = json_object_object_get(param_1,"data");
      if (iVar1 != 0) {
        iVar2 = json_object_object_get(iVar1,"token");
        if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_radius_acct_update_message_process",0xd1e);
          }
          pcVar6 = "";
        }
        else {
          pcVar6 = (char *)json_object_get_string(iVar2);
        }
        strncpy(acStack_102,pcVar6,0x40);
        local_c2 = 0;
        iVar2 = json_object_object_get(iVar1,"is_common");
        if (iVar2 != 0) {
          iVar3 = json_object_get_type(iVar2);
          if (iVar3 == 3) {
            iVar2 = json_object_get_int(iVar2);
          }
          else {
            iVar3 = json_object_get_type();
            if (iVar3 != 2) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_radius_acct_update_message_process",0xd23);
              }
              goto LAB_00440804;
            }
            uVar12 = json_object_get_double(iVar2);
            iVar2 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
          }
          if (iVar2 == 1) {
            local_71 = local_71 | 4;
          }
        }
LAB_00440804:
        if ((local_71 & 4) == 0) {
          iVar2 = wportal_get_mode();
          if (iVar2 == 1) {
            iVar2 = json_object_object_get(iVar1,"vlan_id");
            if (iVar2 == 0) {
LAB_004438a8:
              if (jcs_err_switch != 0) {
                uVar9 = 0xd30;
                goto LAB_00443a58;
              }
              local_70 = 0xffffffff;
            }
            else {
              iVar3 = json_object_get_type(iVar2);
              if (iVar3 == 3) {
LAB_00444d3c:
                local_70 = json_object_get_int(iVar2);
              }
              else {
                iVar3 = json_object_get_type(iVar2);
                if (iVar3 != 2) goto LAB_004438a8;
LAB_00444d78:
                uVar12 = json_object_get_double(iVar2);
                local_70 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
              }
            }
          }
          else {
            iVar2 = wportal_get_mode();
            if (iVar2 == 0) {
              iVar2 = json_object_object_get(iVar1,"serv_id");
              if (iVar2 != 0) {
                iVar3 = json_object_get_type(iVar2);
                if (iVar3 == 3) goto LAB_00444d3c;
                iVar3 = json_object_get_type();
                if (iVar3 == 2) goto LAB_00444d78;
              }
              if (jcs_err_switch == 0) {
                local_70 = 0xffffffff;
              }
              else {
                uVar9 = 0xd35;
LAB_00443a58:
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_radius_acct_update_message_process",uVar9);
                local_70 = 0xffffffff;
              }
            }
            else {
              iVar2 = wportal_get_mode();
              if (iVar2 == 2) {
                iVar2 = json_object_object_get(iVar1,"interface");
                if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                           ,"_radius_acct_update_message_process",0xd3a);
                  }
                  pcVar6 = "";
                }
                else {
                  pcVar6 = (char *)json_object_get_string(iVar2);
                }
                strncpy(acStack_50,pcVar6,0xf);
                local_41 = 0;
                iVar2 = json_object_object_get(iVar1,"vlan_id");
                if (iVar2 != 0) {
                  iVar3 = json_object_get_type(iVar2);
                  if (iVar3 == 3) goto LAB_00444d3c;
                  iVar3 = json_object_get_type(iVar2);
                  if (iVar3 == 2) goto LAB_00444d78;
                }
                if (jcs_err_switch != 0) {
                  uVar9 = 0xd3d;
                  goto LAB_00443a58;
                }
                local_70 = 0xffffffff;
              }
            }
          }
          iVar2 = json_object_object_get(iVar1,"apMac");
          if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_radius_acct_update_message_process",0xd41);
            }
            pcVar6 = "";
          }
          else {
            pcVar6 = (char *)json_object_get_string(iVar2);
          }
          strncpy(local_8b8,pcVar6,0x13);
          local_8a8 = local_8a8 & 0xffffff00;
          if (local_8b8[0] != '\0') {
            sscanf(local_8b8,"%2X-%2X-%2X-%2X-%2X-%2X",local_8a4,&local_8a0,&local_89c,&local_898,
                   &local_894,auStack_890);
            pcVar6 = local_8a4;
            iVar2 = 0;
            do {
              uVar9 = *(undefined4 *)pcVar6;
              iVar3 = iVar2 + 1;
              pcVar6 = pcVar6 + 4;
              local_bb[iVar2] = (char)uVar9;
              iVar2 = iVar3;
            } while (iVar3 != 6);
          }
          iVar2 = json_object_object_get(iVar1,&DAT_00679a24);
          if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_radius_acct_update_message_process",0xd51);
            }
            pcVar6 = "";
          }
          else {
            pcVar6 = (char *)json_object_get_string(iVar2);
          }
          strncpy(local_88c,pcVar6,0x27);
          local_865 = 0;
          uac_ipaddr_convert_str2binary(local_88c,auStack_a0);
        }
        iVar2 = json_object_object_get(iVar1,"mac");
        if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_radius_acct_update_message_process",0xd57);
          }
          pcVar6 = "";
        }
        else {
          pcVar6 = (char *)json_object_get_string(iVar2);
        }
        strncpy(local_8b8,pcVar6,0x13);
        local_8a8 = local_8a8 & 0xffffff00;
        if (local_8b8[0] != '\0') {
          sscanf(local_8b8,"%2X-%2X-%2X-%2X-%2X-%2X",local_8a4,&local_8a0,&local_89c,&local_898,
                 &local_894,auStack_890);
          pcVar6 = local_8a4;
          iVar2 = 0;
          do {
            uVar9 = *(undefined4 *)pcVar6;
            iVar3 = iVar2 + 1;
            pcVar6 = pcVar6 + 4;
            local_c1[iVar2] = (char)uVar9;
            iVar2 = iVar3;
          } while (iVar3 != 6);
        }
        iVar2 = json_object_object_get(iVar1,&DAT_00677c24);
        if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_radius_acct_update_message_process",0xd67);
          }
          pcVar6 = "";
        }
        else {
          pcVar6 = (char *)json_object_get_string(iVar2);
        }
        strncpy(local_88c,pcVar6,0x27);
        local_865 = 0;
        uac_ipaddr_convert_str2binary(local_88c,auStack_b4);
        iVar2 = json_object_object_get(iVar1,"auth_type");
        if (iVar2 == 0) {
LAB_00440954:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_radius_acct_update_message_process",0xd6b);
          }
          local_74 = 0xffff;
        }
        else {
          iVar3 = json_object_get_type(iVar2);
          if (iVar3 == 3) {
            local_74 = json_object_get_int(iVar2);
          }
          else {
            iVar3 = json_object_get_type();
            if (iVar3 != 2) goto LAB_00440954;
            uVar12 = json_object_get_double(iVar2);
            local_74 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
          }
        }
        iVar2 = json_object_object_get(iVar1,"sess_time");
        if (iVar2 == 0) {
LAB_004409c0:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_radius_acct_update_message_process",0xd6e);
          }
          local_80 = 0xffffffff;
        }
        else {
          iVar3 = json_object_get_type(iVar2);
          if (iVar3 == 3) {
            local_80 = json_object_get_int(iVar2);
          }
          else {
            iVar3 = json_object_get_type();
            if (iVar3 != 2) goto LAB_004409c0;
            uVar12 = json_object_get_double(iVar2);
            local_80 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
          }
        }
        iVar2 = json_object_object_get(iVar1,"username");
        if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_radius_acct_update_message_process",0xd71);
          }
          pcVar6 = "";
        }
        else {
          pcVar6 = (char *)json_object_get_string(iVar2);
        }
        strncpy(acStack_1dc,pcVar6,100);
        local_178 = 0;
        iVar2 = json_object_object_get(iVar1,"acctSessid");
        if (iVar2 == 0) {
LAB_00440a94:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int64 with error obj or value type is unmatch.\n",
                   "_radius_acct_update_message_process",0xd74);
          }
          local_88 = 0xffffffffffffffff;
        }
        else {
          iVar3 = json_object_get_type(iVar2);
          if (iVar3 == 3) {
            local_88 = json_object_get_int64(iVar2);
          }
          else {
            iVar3 = json_object_get_type();
            if (iVar3 != 2) goto LAB_00440a94;
            uVar12 = json_object_get_double(iVar2);
            local_88 = __fixunsdfdi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
          }
        }
        iVar2 = json_object_object_get(iVar1,"radius_index");
        if (iVar2 == 0) {
LAB_00440b08:
          uVar9 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_radius_acct_update_message_process",0xd77);
          }
        }
        else {
          iVar3 = json_object_get_type(iVar2);
          if (iVar3 == 3) {
            uVar9 = json_object_get_int(iVar2);
          }
          else {
            iVar3 = json_object_get_type();
            if (iVar3 != 2) goto LAB_00440b08;
            uVar12 = json_object_get_double(iVar2);
            uVar9 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
          }
        }
        memset(acStack_864,0,0x134);
        iVar2 = wportal_rds_srv_get_by_index(uVar9,acStack_864);
        if (iVar2 == -1) {
          if (radius_debug_switch != 0) {
            uVar8 = 0xd7d;
            pcVar6 = "_radius_acct_update_message_process";
            goto LAB_00443170;
          }
        }
        else if (local_754 != 0) {
          iVar2 = json_object_object_get(iVar1,"no_retry");
          if (iVar2 == 0) {
LAB_00440bac:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_acct_update_message_process",0xd88);
            }
LAB_00440bc0:
            local_3fc = local_74c;
            local_3f0 = uStack_74e;
          }
          else {
            iVar3 = json_object_get_type(iVar2);
            if (iVar3 == 3) {
              iVar2 = json_object_get_int(iVar2);
            }
            else {
              iVar3 = json_object_get_type();
              if (iVar3 != 2) goto LAB_00440bac;
              uVar12 = json_object_get_double(iVar2);
              iVar2 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
            if (iVar2 != 1) goto LAB_00440bc0;
            local_3f0 = 0;
            local_3fc = 0;
          }
          uac_ipaddr_convert_binary2str
                    (local_744,local_740,local_73c,local_738,local_734,acStack_5f4,0xff,"0.0.0.0");
          local_3f4 = local_754;
          uac_ipaddr_convert_str2binary(auStack_786,&local_414);
          memcpy(acStack_47c,auStack_7eb,100);
          memcpy(acStack_4f5,acStack_864,0x78);
          iVar1 = json_object_object_get(iVar1,"terminate_type");
          if (iVar1 != 0) {
            iVar2 = json_object_get_type(iVar1);
            if (iVar2 != 3) {
              iVar2 = json_object_get_type();
              if (iVar2 != 2) {
                if (jcs_err_switch != 0) {
                  uVar9 = 0xd9f;
                  pcVar6 = "_radius_acct_update_message_process";
                  goto LAB_0044148c;
                }
                goto LAB_00440cc0;
              }
              goto LAB_00444994;
            }
            goto LAB_004448dc;
          }
          goto LAB_00440cc4;
        }
      }
    }
    else if (iVar1 == 1) {
      local_8a4[0] = '\0';
      local_8a4[1] = '\0';
      local_8a4[2] = '\0';
      local_8a4[3] = '\0';
      local_8a0 = 0;
      local_89c = 0;
      local_898 = 0;
      local_894 = 0;
      memset(acStack_864,0,0x28);
      local_8b8[0] = '\0';
      local_8b8[1] = '\0';
      local_8b8[2] = '\0';
      local_8b8[3] = '\0';
      local_8b8[4] = '\0';
      local_8b8[5] = '\0';
      local_8b8[6] = '\0';
      local_8b8[7] = '\0';
      local_8b8[8] = '\0';
      local_8b8[9] = '\0';
      local_8b8[10] = '\0';
      local_8b8[0xb] = '\0';
      local_8b8[0xc] = '\0';
      local_8b8[0xd] = '\0';
      local_8b8[0xe] = '\0';
      local_8b8[0xf] = '\0';
      local_8a8 = 0;
      local_8bc = 0;
      iVar1 = json_object_object_get(param_1,"data");
      if (iVar1 != 0) {
        iVar2 = json_object_object_get(iVar1,"hasBackup");
        if (iVar2 == 0) {
LAB_0044155c:
          iVar2 = -1;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_radius_auth_messege_process",0xb38);
          }
        }
        else {
          iVar3 = json_object_get_type(iVar2);
          if (iVar3 == 3) {
            iVar2 = json_object_get_int(iVar2);
          }
          else {
            iVar3 = json_object_get_type();
            if (iVar3 != 2) goto LAB_0044155c;
            uVar12 = json_object_get_double(iVar2);
            iVar2 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
          }
        }
        iVar3 = json_object_object_get(iVar1,"useBackup");
        if (iVar3 == 0) {
LAB_004415c0:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_radius_auth_messege_process",0xb3b);
          }
          local_78 = 0xffffffff;
        }
        else {
          iVar4 = json_object_get_type(iVar3);
          if (iVar4 == 3) {
            local_78 = json_object_get_int(iVar3);
          }
          else {
            iVar4 = json_object_get_type();
            if (iVar4 != 2) goto LAB_004415c0;
            uVar12 = json_object_get_double(iVar3);
            local_78 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
          }
        }
        iVar3 = json_object_object_get(iVar1,"useChap");
        if (iVar3 == 0) {
LAB_0044162c:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_radius_auth_messege_process",0xb3e);
          }
        }
        else {
          iVar4 = json_object_get_type(iVar3);
          if (iVar4 == 3) {
            iVar3 = json_object_get_int(iVar3);
          }
          else {
            iVar4 = json_object_get_type();
            if (iVar4 != 2) goto LAB_0044162c;
            uVar12 = json_object_get_double(iVar3);
            iVar3 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
          }
          if (iVar3 == 1) {
            local_71 = local_71 | 1;
          }
        }
        iVar3 = json_object_object_get(iVar1,"nsa");
        if (iVar3 != 0) {
          iVar4 = json_object_get_type(iVar3);
          if (iVar4 == 3) {
            iVar3 = json_object_get_int(iVar3);
          }
          else {
            iVar4 = json_object_get_type();
            if (iVar4 != 2) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_radius_auth_messege_process",0xb47);
              }
              goto LAB_004416a0;
            }
            uVar12 = json_object_get_double(iVar3);
            iVar3 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
          }
          if (iVar3 == 1) {
            local_71 = local_71 | 2;
          }
        }
LAB_004416a0:
        iVar3 = json_object_object_get(iVar1,"is_common");
        if (iVar3 != 0) {
          iVar4 = json_object_get_type(iVar3);
          if (iVar4 == 3) {
            iVar3 = json_object_get_int(iVar3);
          }
          else {
            iVar4 = json_object_get_type();
            if (iVar4 != 2) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_radius_auth_messege_process",0xb51);
              }
              goto LAB_00441704;
            }
            uVar12 = json_object_get_double(iVar3);
            iVar3 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
          }
          if (iVar3 == 1) {
            local_71 = local_71 | 4;
          }
        }
LAB_00441704:
        iVar3 = json_object_object_get(iVar1,"username");
        if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_radius_auth_messege_process",0xb59);
          }
          pcVar6 = "";
        }
        else {
          pcVar6 = (char *)json_object_get_string(iVar3);
        }
        strncpy(acStack_1dc,pcVar6,100);
        local_178 = 0;
        if ((local_71 & 1) == 0) {
          iVar3 = json_object_object_get(iVar1,"password");
          if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_radius_auth_messege_process",0xb5e);
            }
            pcVar6 = "";
          }
          else {
            pcVar6 = (char *)json_object_get_string(iVar3);
          }
          strncpy((char *)local_177,pcVar6,100);
          local_113 = 0;
        }
        else {
          iVar3 = json_object_object_get(iVar1,"challenge1");
          if (iVar3 == 0) {
LAB_0044209c:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_auth_messege_process",0xb63);
            }
            uVar9 = 0xffffffff;
          }
          else {
            iVar4 = json_object_get_type(iVar3);
            if (iVar4 == 3) {
              uVar9 = json_object_get_int(iVar3);
            }
            else {
              iVar4 = json_object_get_type();
              if (iVar4 != 2) goto LAB_0044209c;
              uVar12 = json_object_get_double(iVar3);
              uVar9 = __fixunsdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
          }
          local_8bc._0_2_ = (undefined2)((uint)uVar9 >> 0x10);
          local_112 = local_8bc._0_2_;
          local_8bc._2_2_ = (undefined2)uVar9;
          local_110 = local_8bc._2_2_;
          local_8bc = uVar9;
          iVar3 = json_object_object_get(iVar1,"challenge2");
          if (iVar3 == 0) {
LAB_00442118:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_auth_messege_process",0xb67);
            }
            uVar9 = 0xffffffff;
          }
          else {
            iVar4 = json_object_get_type(iVar3);
            if (iVar4 == 3) {
              uVar9 = json_object_get_int(iVar3);
            }
            else {
              iVar4 = json_object_get_type();
              if (iVar4 != 2) goto LAB_00442118;
              uVar12 = json_object_get_double(iVar3);
              uVar9 = __fixunsdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
          }
          local_8bc._0_2_ = (undefined2)((uint)uVar9 >> 0x10);
          local_10e = local_8bc._0_2_;
          local_8bc._2_2_ = (undefined2)uVar9;
          local_10c = local_8bc._2_2_;
          local_8bc = uVar9;
          iVar3 = json_object_object_get(iVar1,"challenge3");
          if (iVar3 == 0) {
LAB_00442194:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_auth_messege_process",0xb6b);
            }
            uVar9 = 0xffffffff;
          }
          else {
            iVar4 = json_object_get_type(iVar3);
            if (iVar4 == 3) {
              uVar9 = json_object_get_int(iVar3);
            }
            else {
              iVar4 = json_object_get_type();
              if (iVar4 != 2) goto LAB_00442194;
              uVar12 = json_object_get_double(iVar3);
              uVar9 = __fixunsdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
          }
          local_8bc._0_2_ = (undefined2)((uint)uVar9 >> 0x10);
          local_10a = local_8bc._0_2_;
          local_8bc._2_2_ = (undefined2)uVar9;
          local_108 = local_8bc._2_2_;
          local_8bc = uVar9;
          iVar3 = json_object_object_get(iVar1,"challenge4");
          if (iVar3 == 0) {
LAB_00442210:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_auth_messege_process",0xb6f);
            }
            uVar9 = 0xffffffff;
          }
          else {
            iVar4 = json_object_get_type(iVar3);
            if (iVar4 == 3) {
              uVar9 = json_object_get_int(iVar3);
            }
            else {
              iVar4 = json_object_get_type();
              if (iVar4 != 2) goto LAB_00442210;
              uVar12 = json_object_get_double(iVar3);
              uVar9 = __fixunsdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
          }
          local_8bc._0_2_ = (undefined2)((uint)uVar9 >> 0x10);
          local_106 = local_8bc._0_2_;
          local_8bc._2_2_ = (undefined2)uVar9;
          local_104 = local_8bc._2_2_;
          local_8bc = uVar9;
          iVar3 = json_object_object_get(iVar1,"chapPassword1");
          if (iVar3 == 0) {
LAB_0044228c:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_auth_messege_process",0xb74);
            }
            local_8bc = 0xffffffff;
          }
          else {
            iVar4 = json_object_get_type(iVar3);
            if (iVar4 == 3) {
              local_8bc = json_object_get_int(iVar3);
            }
            else {
              iVar4 = json_object_get_type();
              if (iVar4 != 2) goto LAB_0044228c;
              uVar12 = json_object_get_double(iVar3);
              local_8bc = __fixunsdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
          }
          memcpy(local_177,&local_8bc,4);
          iVar3 = json_object_object_get(iVar1,"chapPassword2");
          if (iVar3 == 0) {
LAB_00442310:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_auth_messege_process",0xb78);
            }
            local_8bc = 0xffffffff;
          }
          else {
            iVar4 = json_object_get_type(iVar3);
            if (iVar4 == 3) {
              local_8bc = json_object_get_int(iVar3);
            }
            else {
              iVar4 = json_object_get_type();
              if (iVar4 != 2) goto LAB_00442310;
              uVar12 = json_object_get_double(iVar3);
              local_8bc = __fixunsdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
          }
          memcpy(local_177 + 4,&local_8bc,4);
          iVar3 = json_object_object_get(iVar1,"chapPassword3");
          if (iVar3 == 0) {
LAB_00442394:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_auth_messege_process",0xb7c);
            }
            local_8bc = 0xffffffff;
          }
          else {
            iVar4 = json_object_get_type(iVar3);
            if (iVar4 == 3) {
              local_8bc = json_object_get_int(iVar3);
            }
            else {
              iVar4 = json_object_get_type();
              if (iVar4 != 2) goto LAB_00442394;
              uVar12 = json_object_get_double(iVar3);
              local_8bc = __fixunsdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
          }
          memcpy(local_177 + 8,&local_8bc,4);
          iVar3 = json_object_object_get(iVar1,"chapPassword4");
          if (iVar3 == 0) {
LAB_00442418:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_auth_messege_process",0xb80);
            }
            local_8bc = 0xffffffff;
          }
          else {
            iVar4 = json_object_get_type(iVar3);
            if (iVar4 == 3) {
              local_8bc = json_object_get_int(iVar3);
            }
            else {
              iVar4 = json_object_get_type();
              if (iVar4 != 2) goto LAB_00442418;
              uVar12 = json_object_get_double(iVar3);
              local_8bc = __fixunsdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
          }
          memcpy(local_177 + 0xc,&local_8bc,4);
          iVar3 = json_object_object_get(iVar1,"chapid");
          if (iVar3 == 0) {
LAB_0044249c:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_auth_messege_process",0xb84);
            }
            local_72 = 0xff;
          }
          else {
            iVar4 = json_object_get_type(iVar3);
            if (iVar4 == 3) {
              local_72 = json_object_get_int(iVar3);
            }
            else {
              iVar4 = json_object_get_type();
              if (iVar4 != 2) goto LAB_0044249c;
              uVar12 = json_object_get_double(iVar3);
              local_72 = __fixunsdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
          }
          if (radius_debug_switch != 0) {
            printf("chapid: %x, chap password: ",(uint)local_72);
            iVar3 = 0;
            do {
              iVar4 = iVar3 + 1;
              printf("%02x ",(uint)local_177[iVar3]);
              iVar3 = iVar4;
            } while (iVar4 != 0x10);
            putchar(10);
            printf("chap challenge: ");
            iVar3 = 0;
            do {
              iVar4 = iVar3 + 1;
              printf("%02x ",(uint)*(byte *)((int)&local_112 + iVar3));
              iVar3 = iVar4;
            } while (iVar4 != 0x10);
            putchar(10);
          }
        }
        iVar3 = json_object_object_get(iVar1,"token");
        if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_radius_auth_messege_process",0xb9b);
          }
          pcVar6 = "";
        }
        else {
          pcVar6 = (char *)json_object_get_string(iVar3);
        }
        strncpy(acStack_102,pcVar6,0x40);
        local_c2 = 0;
        iVar3 = json_object_object_get(iVar1,"auth_type");
        if (iVar3 == 0) {
LAB_0044189c:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_radius_auth_messege_process",0xb9e);
          }
          local_74 = 0xffff;
        }
        else {
          iVar4 = json_object_get_type(iVar3);
          if (iVar4 == 3) {
            local_74 = json_object_get_int(iVar3);
          }
          else {
            iVar4 = json_object_get_type();
            if (iVar4 != 2) goto LAB_0044189c;
            uVar12 = json_object_get_double(iVar3);
            local_74 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
          }
        }
        iVar3 = json_object_object_get(iVar1,&DAT_00677c24);
        if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_radius_auth_messege_process",0xba1);
          }
          pcVar6 = "";
        }
        else {
          pcVar6 = (char *)json_object_get_string(iVar3);
        }
        strncpy(acStack_864,pcVar6,0x27);
        local_83d = 0;
        uac_ipaddr_convert_str2binary(acStack_864,auStack_b4);
        iVar3 = json_object_object_get(iVar1,&DAT_00679a24);
        if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_radius_auth_messege_process",0xba5);
          }
          pcVar6 = "";
        }
        else {
          pcVar6 = (char *)json_object_get_string(iVar3);
        }
        strncpy(acStack_864,pcVar6,0x27);
        local_83d = 0;
        uac_ipaddr_convert_str2binary(acStack_864,auStack_a0);
        iVar3 = json_object_object_get(iVar1,"mac");
        if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_radius_auth_messege_process",0xba9);
          }
          pcVar6 = "";
        }
        else {
          pcVar6 = (char *)json_object_get_string(iVar3);
        }
        strncpy(local_8a4,pcVar6,0x13);
        local_894 = local_894 & 0xffffff00;
        if (local_8a4[0] != '\0') {
          sscanf(local_8a4,"%2X-%2X-%2X-%2X-%2X-%2X",local_88c,auStack_888,auStack_884,auStack_880,
                 auStack_87c,auStack_878);
          pcVar6 = local_88c;
          iVar3 = 0;
          do {
            uVar9 = *(undefined4 *)pcVar6;
            iVar4 = iVar3 + 1;
            pcVar6 = pcVar6 + 4;
            local_c1[iVar3] = (char)uVar9;
            iVar3 = iVar4;
          } while (iVar4 != 6);
        }
        if ((local_71 & 4) == 0) {
          iVar3 = wportal_get_mode();
          if (iVar3 == 1) {
            iVar3 = json_object_object_get(iVar1,"vlan_id");
            if (iVar3 == 0) {
LAB_0044382c:
              if (jcs_err_switch != 0) {
                uVar9 = 0xbbe;
                goto LAB_00443a30;
              }
              local_70 = 0xffffffff;
            }
            else {
              iVar4 = json_object_get_type(iVar3);
              if (iVar4 == 3) {
LAB_00444d50:
                local_70 = json_object_get_int(iVar3);
              }
              else {
                iVar4 = json_object_get_type(iVar3);
                if (iVar4 != 2) goto LAB_0044382c;
LAB_00444dc8:
                uVar12 = json_object_get_double(iVar3);
                local_70 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
              }
            }
          }
          else {
            iVar3 = wportal_get_mode();
            if (iVar3 == 0) {
              iVar3 = json_object_object_get(iVar1,"serv_id");
              if (iVar3 != 0) {
                iVar4 = json_object_get_type(iVar3);
                if (iVar4 == 3) goto LAB_00444d50;
                iVar4 = json_object_get_type();
                if (iVar4 == 2) goto LAB_00444dc8;
              }
              if (jcs_err_switch == 0) {
                local_70 = 0xffffffff;
              }
              else {
                uVar9 = 0xbc3;
LAB_00443a30:
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_radius_auth_messege_process",uVar9);
                local_70 = 0xffffffff;
              }
            }
            else {
              iVar3 = wportal_get_mode();
              if (iVar3 == 2) {
                iVar3 = json_object_object_get(iVar1,"interface");
                if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                           ,"_radius_auth_messege_process",0xbc8);
                  }
                  pcVar6 = "";
                }
                else {
                  pcVar6 = (char *)json_object_get_string(iVar3);
                }
                strncpy(acStack_50,pcVar6,0xf);
                local_41 = 0;
                iVar3 = json_object_object_get(iVar1,"vlan_id");
                if (iVar3 != 0) {
                  iVar4 = json_object_get_type(iVar3);
                  if (iVar4 == 3) goto LAB_00444d50;
                  iVar4 = json_object_get_type(iVar3);
                  if (iVar4 == 2) goto LAB_00444dc8;
                  if (jcs_err_switch != 0) {
                    uVar9 = 0xbcd;
                    goto LAB_00443a30;
                  }
                  local_70 = 0xffffffff;
                }
              }
            }
          }
          iVar3 = json_object_object_get(iVar1,&DAT_00679a24);
          if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_radius_auth_messege_process",0xbd2);
            }
            pcVar6 = "";
          }
          else {
            pcVar6 = (char *)json_object_get_string(iVar3);
          }
          strncpy(acStack_864,pcVar6,0x27);
          local_83d = 0;
          uac_ipaddr_convert_str2binary(acStack_864,auStack_a0);
          iVar3 = json_object_object_get(iVar1,"apMac");
          if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_radius_auth_messege_process",0xbd6);
            }
            pcVar6 = "";
          }
          else {
            pcVar6 = (char *)json_object_get_string(iVar3);
          }
          strncpy(local_8a4,pcVar6,0x13);
          local_894 = local_894 & 0xffffff00;
          if (local_8a4[0] != '\0') {
            sscanf(local_8a4,"%2X-%2X-%2X-%2X-%2X-%2X",local_88c,auStack_888,auStack_884,auStack_880
                   ,auStack_87c,auStack_878);
            pcVar6 = local_88c;
            iVar3 = 0;
            do {
              uVar9 = *(undefined4 *)pcVar6;
              iVar4 = iVar3 + 1;
              pcVar6 = pcVar6 + 4;
              local_bb[iVar3] = (char)uVar9;
              iVar3 = iVar4;
            } while (iVar4 != 6);
          }
        }
        iVar3 = json_object_object_get(iVar1,&DAT_00681f70);
        if (iVar3 != 0) {
          iVar4 = json_object_object_get(iVar1,"mainindex");
          if (iVar4 == 0) {
LAB_00441aa4:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_auth_messege_process",0xbee);
            }
            local_3ec = 0xffffffff;
          }
          else {
            iVar5 = json_object_get_type(iVar4);
            if (iVar5 == 3) {
              local_3ec = json_object_get_int(iVar4);
            }
            else {
              iVar5 = json_object_get_type();
              if (iVar5 != 2) goto LAB_00441aa4;
              uVar12 = json_object_get_double(iVar4);
              local_3ec = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
          }
          iVar4 = json_object_object_get(iVar3,"auth_port");
          if (iVar4 == 0) {
LAB_00441b10:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_auth_messege_process",0xbf1);
            }
            local_3f8 = 0xffffffff;
          }
          else {
            iVar5 = json_object_get_type(iVar4);
            if (iVar5 == 3) {
              local_3f8 = json_object_get_int(iVar4);
            }
            else {
              iVar5 = json_object_get_type();
              if (iVar5 != 2) goto LAB_00441b10;
              uVar12 = json_object_get_double(iVar4);
              local_3f8 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
          }
          iVar4 = json_object_object_get(iVar3,"account_port");
          if (iVar4 == 0) {
LAB_00441b7c:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_auth_messege_process",0xbf4);
            }
            local_3f4 = -1;
          }
          else {
            iVar5 = json_object_get_type(iVar4);
            if (iVar5 == 3) {
              local_3f4 = json_object_get_int(iVar4);
            }
            else {
              iVar5 = json_object_get_type();
              if (iVar5 != 2) goto LAB_00441b7c;
              uVar12 = json_object_get_double(iVar4);
              local_3f4 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
          }
          iVar4 = json_object_object_get(iVar3,"retry_count");
          if (iVar4 == 0) {
LAB_00441be8:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_auth_messege_process",0xbf7);
            }
            local_3f0 = 0xffff;
          }
          else {
            iVar5 = json_object_get_type(iVar4);
            if (iVar5 == 3) {
              local_3f0 = json_object_get_int(iVar4);
            }
            else {
              iVar5 = json_object_get_type();
              if (iVar5 != 2) goto LAB_00441be8;
              uVar12 = json_object_get_double(iVar4);
              local_3f0 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
          }
          iVar4 = json_object_object_get(iVar3,"retry_interval");
          if (iVar4 == 0) {
LAB_00441c54:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_radius_auth_messege_process",0xbfa);
            }
            local_3fc = 0xffffffff;
          }
          else {
            iVar5 = json_object_get_type(iVar4);
            if (iVar5 == 3) {
              local_3fc = json_object_get_int(iVar4);
            }
            else {
              iVar5 = json_object_get_type();
              if (iVar5 != 2) goto LAB_00441c54;
              uVar12 = json_object_get_double(iVar4);
              local_3fc = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
          }
          iVar4 = json_object_object_get(iVar3,"nas_identifier");
          if ((iVar4 == 0) || (iVar5 = json_object_get_type(iVar4), iVar5 != 6)) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_radius_auth_messege_process",0xbfd);
            }
            pcVar6 = "";
          }
          else {
            pcVar6 = (char *)json_object_get_string(iVar4);
          }
          strncpy(acStack_47c,pcVar6,100);
          local_418 = 0;
          iVar4 = json_object_object_get(iVar3,"nas_ip");
          if ((iVar4 == 0) || (iVar5 = json_object_get_type(iVar4), iVar5 != 6)) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_radius_auth_messege_process",0xc00);
            }
            pcVar6 = "";
          }
          else {
            pcVar6 = (char *)json_object_get_string(iVar4);
          }
          strncpy(acStack_864,pcVar6,0x27);
          local_83d = 0;
          iVar4 = uac_ipaddr_convert_str2binary(acStack_864,&local_414);
          if (iVar4 != 0) {
            local_414 = 0;
            local_410 = 0;
            local_40c = 0;
            local_408 = 0;
            local_404 = 0;
          }
          iVar4 = json_object_object_get(iVar3,"radius_auth_type");
          local_8b8[0] = '\0';
          local_8b8[1] = '\0';
          local_8b8[2] = '\0';
          local_8b8[3] = '\0';
          local_8b8[4] = '\0';
          local_8b8[5] = '\0';
          local_8b8[6] = '\0';
          local_8b8[7] = '\0';
          local_8b8[8] = '\0';
          local_8b8[9] = '\0';
          local_8b8[10] = '\0';
          local_8b8[0xb] = '\0';
          local_8b8[0xc] = '\0';
          local_8b8[0xd] = '\0';
          local_8b8[0xe] = '\0';
          local_8b8[0xf] = '\0';
          local_8a8 = 0;
          if ((iVar4 == 0) || (iVar5 = json_object_get_type(iVar4), iVar5 != 6)) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_radius_auth_messege_process",0xc08);
            }
            pcVar6 = "";
          }
          else {
            pcVar6 = (char *)json_object_get_string(iVar4);
          }
          strncpy(local_8b8,pcVar6,0x13);
          local_8a8 = local_8a8 & 0xffffff00;
          local_400 = _radius_auth_type_str2int(local_8b8);
          iVar4 = json_object_object_get(iVar3,"share_key");
          if ((iVar4 == 0) || (iVar5 = json_object_get_type(iVar4), iVar5 != 6)) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_radius_auth_messege_process",0xc0c);
            }
            pcVar6 = "";
          }
          else {
            pcVar6 = (char *)json_object_get_string(iVar4);
          }
          strncpy(acStack_4f5,pcVar6,0x78);
          local_47d = 0;
          iVar3 = json_object_object_get(iVar3,"server_addr");
          if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_radius_auth_messege_process",0xc0f);
            }
            pcVar6 = "";
          }
          else {
            pcVar6 = (char *)json_object_get_string(iVar3);
          }
          strncpy(acStack_5f4,pcVar6,0xfe);
          local_4f6 = 0;
          if (iVar2 != 0) {
            iVar2 = json_object_object_get(iVar1,"backup");
            if (iVar2 == 0) goto LAB_0044068c;
            iVar1 = json_object_object_get(iVar1,"backupindex");
            if (iVar1 == 0) {
LAB_004425b8:
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_radius_auth_messege_process",0xc1c);
              }
              local_1e0 = 0xffffffff;
            }
            else {
              iVar3 = json_object_get_type(iVar1);
              if (iVar3 == 3) {
                local_1e0 = json_object_get_int(iVar1);
              }
              else {
                iVar3 = json_object_get_type();
                if (iVar3 != 2) goto LAB_004425b8;
                uVar12 = json_object_get_double(iVar1);
                local_1e0 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
              }
            }
            iVar1 = json_object_object_get(iVar2,"auth_port");
            if (iVar1 == 0) {
LAB_0044264c:
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_radius_auth_messege_process",0xc1f);
              }
              local_1ec = 0xffffffff;
            }
            else {
              iVar3 = json_object_get_type(iVar1);
              if (iVar3 == 3) {
                local_1ec = json_object_get_int(iVar1);
              }
              else {
                iVar3 = json_object_get_type();
                if (iVar3 != 2) goto LAB_0044264c;
                uVar12 = json_object_get_double(iVar1);
                local_1ec = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
              }
            }
            iVar1 = json_object_object_get(iVar2,"account_port");
            if (iVar1 == 0) {
LAB_004426e0:
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_radius_auth_messege_process",0xc22);
              }
              local_1e8 = 0xffffffff;
            }
            else {
              iVar3 = json_object_get_type(iVar1);
              if (iVar3 == 3) {
                local_1e8 = json_object_get_int(iVar1);
              }
              else {
                iVar3 = json_object_get_type();
                if (iVar3 != 2) goto LAB_004426e0;
                uVar12 = json_object_get_double(iVar1);
                local_1e8 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
              }
            }
            iVar1 = json_object_object_get(iVar2,"retry_count");
            if (iVar1 == 0) {
LAB_00442774:
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_radius_auth_messege_process",0xc25);
              }
              local_1e4 = 0xffff;
            }
            else {
              iVar3 = json_object_get_type(iVar1);
              if (iVar3 == 3) {
                local_1e4 = json_object_get_int(iVar1);
              }
              else {
                iVar3 = json_object_get_type();
                if (iVar3 != 2) goto LAB_00442774;
                uVar12 = json_object_get_double(iVar1);
                local_1e4 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
              }
            }
            iVar1 = json_object_object_get(iVar2,"retry_interval");
            if (iVar1 == 0) {
LAB_00442808:
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_radius_auth_messege_process",0xc28);
              }
              local_1f0 = 0xffffffff;
            }
            else {
              iVar3 = json_object_get_type(iVar1);
              if (iVar3 == 3) {
                local_1f0 = json_object_get_int(iVar1);
              }
              else {
                iVar3 = json_object_get_type();
                if (iVar3 != 2) goto LAB_00442808;
                uVar12 = json_object_get_double(iVar1);
                local_1f0 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
              }
            }
            iVar1 = json_object_object_get(iVar2,"nas_identifier");
            if ((iVar1 == 0) || (iVar3 = json_object_get_type(iVar1), iVar3 != 6)) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_radius_auth_messege_process",0xc2b);
              }
              pcVar6 = "";
            }
            else {
              pcVar6 = (char *)json_object_get_string(iVar1);
            }
            strncpy(acStack_270,pcVar6,100);
            local_20c = 0;
            iVar1 = json_object_object_get(iVar2,"nas_ip");
            if ((iVar1 == 0) || (iVar3 = json_object_get_type(iVar1), iVar3 != 6)) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_radius_auth_messege_process",0xc2e);
              }
              pcVar6 = "";
            }
            else {
              pcVar6 = (char *)json_object_get_string(iVar1);
            }
            strncpy(acStack_864,pcVar6,0x27);
            local_83d = 0;
            iVar1 = uac_ipaddr_convert_str2binary(acStack_864,&local_208);
            if (iVar1 != 0) {
              local_208 = 0;
              local_204 = 0;
              local_200 = 0;
              local_1fc = 0;
              local_1f8 = 0;
            }
            iVar1 = json_object_object_get(iVar2,"radius_auth_type");
            local_8b8[0] = '\0';
            local_8b8[1] = '\0';
            local_8b8[2] = '\0';
            local_8b8[3] = '\0';
            local_8b8[4] = '\0';
            local_8b8[5] = '\0';
            local_8b8[6] = '\0';
            local_8b8[7] = '\0';
            local_8b8[8] = '\0';
            local_8b8[9] = '\0';
            local_8b8[10] = '\0';
            local_8b8[0xb] = '\0';
            local_8b8[0xc] = '\0';
            local_8b8[0xd] = '\0';
            local_8b8[0xe] = '\0';
            local_8b8[0xf] = '\0';
            local_8a8 = 0;
            if ((iVar1 == 0) || (iVar3 = json_object_get_type(iVar1), iVar3 != 6)) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_radius_auth_messege_process",0xc36);
              }
              pcVar6 = "";
            }
            else {
              pcVar6 = (char *)json_object_get_string(iVar1);
            }
            strncpy(local_8b8,pcVar6,0x13);
            local_8a8 = local_8a8 & 0xffffff00;
            local_1f4 = _radius_auth_type_str2int(local_8b8);
            iVar1 = json_object_object_get(iVar2,"share_key");
            if ((iVar1 == 0) || (iVar3 = json_object_get_type(iVar1), iVar3 != 6)) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_radius_auth_messege_process",0xc3a);
              }
              pcVar6 = "";
            }
            else {
              pcVar6 = (char *)json_object_get_string(iVar1);
            }
            strncpy(acStack_2e9,pcVar6,0x78);
            local_271 = 0;
            iVar1 = json_object_object_get(iVar2,"server_addr");
            if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_radius_auth_messege_process",0xc3d);
              }
              pcVar6 = "";
            }
            else {
              pcVar6 = (char *)json_object_get_string(iVar1);
            }
            strncpy(acStack_3e8,pcVar6,0xfe);
            local_2ea = 0;
          }
          uVar9 = 1;
          goto LAB_00441ed0;
        }
      }
    }
LAB_0044068c:
    uVar9 = 0xffffffff;
  }
  return uVar9;
}

