// func _uac_report_jcs_set @ 004b4e8c size=2584

void _uac_report_jcs_set(int param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  int *piVar9;
  char *pcVar10;
  size_t __n;
  int iVar11;
  byte *pbVar12;
  undefined8 uVar13;
  undefined1 auStack_70 [16];
  int aiStack_60 [2];
  byte local_58 [8];
  int local_50;
  byte *local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int *local_38;
  int local_34;
  undefined1 *local_30;
  
  local_30 = auStack_70;
  if (param_1 == 0) {
    puVar1 = auStack_70;
    if (report_err_switch != 0) {
      printf("[REPORT_ERROR]%s()/line %d : _uac_report_jcs_set in_obj error.\n",
             "_uac_report_jcs_set",0x379);
      puVar1 = local_30;
    }
    local_30 = puVar1;
    uVar7 = json_object_new_boolean(0);
    json_object_object_add(param_2,&DAT_00676a24,uVar7);
    return;
  }
  local_30 = auStack_70;
  _uac_report_stop();
  local_50 = json_object_object_get(param_1,"state");
  local_48 = json_object_object_get(param_1,"protocol");
  local_3c = json_object_object_get(param_1,"server_address");
  iVar2 = json_object_object_get(param_1,"server_port");
  iVar3 = json_object_object_get(param_1,"apgroup");
  iVar4 = json_object_object_get(param_1,"content");
  local_44 = json_object_object_get(param_1,"interval");
  local_40 = json_object_object_get(param_1,"max_load");
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  uVar5 = apmngr_db_get_group_max();
  local_4c = (byte *)(uVar5 & 0xffff);
  if (DAT_00767d58 == (undefined2 *)0x0) {
    DAT_00767d58 = (undefined2 *)FUN_00408450((int)local_4c << 1,0x38e);
  }
  __n = (int)local_4c * 4;
  local_38 = (int *)((int)aiStack_60 - (__n + 0xe & 0xfffffff8));
  memset(DAT_00767d58,0,(int)local_4c << 1);
  memset(local_38,0,__n);
  if (local_50 == 0) {
    report_ctx = 0;
  }
  else {
    iVar6 = json_object_get_type(local_50);
    iVar11 = 0;
    if (iVar6 == 6) {
      do {
        while( true ) {
          if (state_map <= iVar11) {
            if (jcs_err_switch == 0) goto LAB_004b500c;
            pcVar10 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
            goto LAB_004b55f0;
          }
          local_34 = iVar11 * 0x10;
          pcVar10 = *(char **)(PTR_state_mpt_007319c8 + local_34);
          if (pcVar10 != (char *)0x0) break;
          iVar11 = iVar11 + 1;
        }
        pcVar8 = (char *)json_object_get_string(local_50);
        iVar6 = strcmp(pcVar10,pcVar8);
        iVar11 = iVar11 + 1;
      } while (iVar6 != 0);
      report_ctx = (undefined1)*(undefined4 *)(PTR_state_mpt_007319c8 + local_34 + 0xc);
    }
    else {
      if (jcs_err_switch != 0) {
        pcVar10 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_004b55f0:
        printf(pcVar10,"_uac_report_jcs_set",0x394);
      }
LAB_004b500c:
      if (jcs_err_switch == 0) {
        report_ctx = 0xff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_report_jcs_set",
               0x394);
        report_ctx = 0xff;
      }
    }
  }
  if (local_48 == 0) {
    DAT_00767c59 = 2;
  }
  else {
    iVar6 = json_object_get_type(local_48);
    iVar11 = 0;
    if (iVar6 == 6) {
      do {
        while( true ) {
          if (protocol_map <= iVar11) {
            if (jcs_err_switch == 0) goto LAB_004b5054;
            pcVar10 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
            goto LAB_004b560c;
          }
          local_50 = iVar11 * 0x10;
          pcVar10 = *(char **)(PTR_protocol_mpt_007319d0 + local_50);
          if (pcVar10 != (char *)0x0) break;
          iVar11 = iVar11 + 1;
        }
        pcVar8 = (char *)json_object_get_string(local_48);
        iVar6 = strcmp(pcVar10,pcVar8);
        iVar11 = iVar11 + 1;
      } while (iVar6 != 0);
      DAT_00767c59 = (undefined1)*(undefined4 *)(PTR_protocol_mpt_007319d0 + local_50 + 0xc);
    }
    else {
      if (jcs_err_switch != 0) {
        pcVar10 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_004b560c:
        printf(pcVar10,"_uac_report_jcs_set",0x395);
      }
LAB_004b5054:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_report_jcs_set",
               0x395);
      }
      DAT_00767c59 = 0xff;
    }
  }
  if ((local_3c == 0) || (iVar6 = json_object_get_type(local_3c), iVar6 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_uac_report_jcs_set",0x396);
    }
    pcVar10 = "";
  }
  else {
    pcVar10 = (char *)json_object_get_string(local_3c);
  }
  strncpy(&DAT_00767c5a,pcVar10,0xfa);
  DAT_00767d54 = 0;
  if (iVar2 == 0) {
LAB_004b50e4:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_uac_report_jcs_set",0x397);
    }
    DAT_00767d56 = 0xffff;
  }
  else {
    iVar6 = json_object_get_type(iVar2);
    if (iVar6 == 3) {
      DAT_00767d56 = json_object_get_int(iVar2);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 != 2) goto LAB_004b50e4;
      uVar13 = json_object_get_double(iVar2);
      DAT_00767d56 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
    }
  }
  if (iVar3 == 0) {
LAB_004b5130:
    pbVar12 = (byte *)0x0;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
             "_uac_report_jcs_set",0x398);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar3);
    if (iVar2 != 5) {
      iVar2 = json_object_get_type(iVar3);
      if (iVar2 == 4) {
        iVar2 = json_object_object_length(iVar3);
        pbVar12 = (byte *)0x0;
        if (iVar2 == 0) goto LAB_004b513c;
      }
      goto LAB_004b5130;
    }
    piVar9 = local_38;
    for (pbVar12 = (byte *)0x0;
        (iVar2 = json_object_array_length(iVar3), (int)pbVar12 < iVar2 && (pbVar12 < local_4c));
        pbVar12 = pbVar12 + 1) {
      iVar2 = json_object_array_get_idx(iVar3,pbVar12);
      if (iVar2 == 0) {
LAB_004b5588:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_report_jcs_set",0x398);
        }
        *piVar9 = -1;
      }
      else {
        iVar6 = json_object_get_type(iVar2);
        if (iVar6 == 3) {
          iVar2 = json_object_get_int(iVar2);
          *piVar9 = iVar2;
        }
        else {
          iVar6 = json_object_get_type();
          if (iVar6 != 2) goto LAB_004b5588;
          uVar13 = json_object_get_double(iVar2);
          iVar2 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
          *piVar9 = iVar2;
        }
      }
      piVar9 = piVar9 + 1;
    }
  }
LAB_004b513c:
  if (iVar4 == 0) {
LAB_004b516c:
    iVar3 = 0;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Trans intArray with error obj or value type is unmatch.\n",
             "_uac_report_jcs_set",0x399);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar4);
    if (iVar2 != 5) {
      iVar2 = json_object_get_type(iVar4);
      if (iVar2 == 4) {
        iVar2 = json_object_object_length(iVar4);
        iVar3 = 0;
        if (iVar2 == 0) goto LAB_004b517c;
      }
      goto LAB_004b516c;
    }
    local_4c = local_58;
    for (iVar3 = 0; iVar2 = json_object_array_length(iVar4), iVar3 < iVar2; iVar3 = iVar3 + 1) {
      if (iVar3 == 4) {
        iVar3 = 4;
        break;
      }
      local_50 = json_object_array_get_idx(iVar4,iVar3);
      if (local_50 == 0) {
LAB_004b54f0:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_report_jcs_set",
                 0x399);
        }
        *local_4c = 0xff;
      }
      else {
        iVar2 = json_object_get_type(local_50);
        iVar6 = 0;
        if (iVar2 != 6) {
          if (jcs_err_switch != 0) {
            pcVar10 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_004b5694:
            printf(pcVar10,"_uac_report_jcs_set",0x399);
          }
          goto LAB_004b54f0;
        }
        do {
          while( true ) {
            if (content_map <= iVar6) {
              if (jcs_err_switch == 0) goto LAB_004b54f0;
              pcVar10 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
              goto LAB_004b5694;
            }
            local_48 = iVar6 * 0x10;
            pcVar10 = *(char **)(PTR_content_mpt_007319d8 + local_48);
            if (pcVar10 != (char *)0x0) break;
            iVar6 = iVar6 + 1;
          }
          pcVar8 = (char *)json_object_get_string(local_50);
          iVar2 = strcmp(pcVar10,pcVar8);
          iVar6 = iVar6 + 1;
        } while (iVar2 != 0);
        *local_4c = (byte)*(undefined4 *)(PTR_content_mpt_007319d8 + local_48 + 0xc);
      }
      local_4c = local_4c + 1;
    }
  }
LAB_004b517c:
  if (local_44 == 0) {
LAB_004b51ac:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_uac_report_jcs_set",0x39a);
    }
    DAT_00767d5e = 0xffff;
  }
  else {
    iVar2 = json_object_get_type(local_44);
    if (iVar2 == 3) {
      DAT_00767d5e = json_object_get_int(local_44);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004b51ac;
      uVar13 = json_object_get_double(local_44);
      DAT_00767d5e = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
    }
  }
  if (local_40 != 0) {
    iVar2 = json_object_get_type(local_40);
    if (iVar2 == 3) {
      DAT_00767d60 = json_object_get_int(local_40);
      goto LAB_004b5210;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar13 = json_object_get_double(local_40);
      DAT_00767d60 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
      goto LAB_004b5210;
    }
  }
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_uac_report_jcs_set",0x39b);
  }
  DAT_00767d60 = 0xffff;
LAB_004b5210:
  DAT_00767d5c = 0;
  for (iVar2 = 0; iVar2 < iVar3; iVar2 = iVar2 + 1) {
    DAT_00767d5c = DAT_00767d5c | local_58[iVar2];
  }
  iVar2 = 0;
  piVar9 = local_38;
  do {
    if ((int)pbVar12 <= iVar2) {
LAB_004b5284:
      uVar7 = json_object_new_boolean(1);
      json_object_object_add(param_2,&DAT_00676a24,uVar7);
      _uac_report_run();
      return;
    }
    if (*piVar9 == -1) {
      *DAT_00767d58 = 1;
      DAT_00767d58[1] = 1;
      goto LAB_004b5284;
    }
    iVar2 = iVar2 + 1;
    DAT_00767d58[*piVar9] = 1;
    piVar9 = piVar9 + 1;
  } while( true );
}

